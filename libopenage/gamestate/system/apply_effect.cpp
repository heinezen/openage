// Copyright 2024-2024 the openage authors. See copying.md for legal info.

#include "apply_effect.h"

#include <unordered_map>

#include "error/error.h"

#include "gamestate/api/effect.h"
#include "gamestate/api/resistance.h"
#include "gamestate/api/types.h"
#include "gamestate/component/api/apply_effect.h"
#include "gamestate/component/api/live.h"
#include "gamestate/component/api/resistance.h"
#include "gamestate/component/types.h"
#include "gamestate/game_entity.h"
#include "gamestate/game_state.h"


namespace openage::gamestate::system {

const time::time_t ApplyEffect::apply_effect(const std::shared_ptr<gamestate::GameEntity> &effector,
                                             const std::shared_ptr<openage::gamestate::GameState> &state,
                                             const std::shared_ptr<gamestate::GameEntity> &resistor,
                                             const time::time_t &start_time) {
	auto effects_component = std::dynamic_pointer_cast<component::ApplyEffect>(
		effector->get_component(component::component_t::APPLY_EFFECT));
	auto effect_ability = effects_component->get_ability();
	auto batches = effect_ability.get_set("ApplyEffect.batches");

	auto resistance_component = std::dynamic_pointer_cast<component::Resistance>(
		resistor->get_component(component::component_t::RESISTANCE));
	auto resistance_ability = resistance_component->get_ability();
	auto resistances_set = resistance_ability.get_set("Resistance.resistances");

	auto live_component = std::dynamic_pointer_cast<component::Live>(
		resistor->get_component(component::component_t::LIVE));

	// Extract the effects from the ability
	std::unordered_map<api::effect_t, std::vector<nyan::Object>> effects{};
	for (auto &batch : batches) {
		std::shared_ptr<nyan::ObjectValue> batch_obj_val = std::dynamic_pointer_cast<nyan::ObjectValue>(batch.get_ptr());
		auto batch_obj = effect_ability.get_view()->get_object(batch_obj_val->get_name());
		auto batch_effects = batch_obj.get_set("EffectBatch.effects");

		for (auto &batch_effect : batch_effects) {
			std::shared_ptr<nyan::ObjectValue> effect_obj_val = std::dynamic_pointer_cast<nyan::ObjectValue>(batch_effect.get_ptr());
			auto effect_obj = effect_ability.get_view()->get_object(effect_obj_val->get_name());
			auto effect_type = api::APIEffect::get_type(effect_obj);

			if (effects.contains(effect_type)) {
				effects.emplace(effect_type, std::vector<nyan::Object>{});
			}

			effects[effect_type].push_back(effect_obj);
		}
	}

	// Extract the resistances from the ability
	std::unordered_map<api::effect_t, std::vector<nyan::Object>> resistances{};
	for (auto &resistance : resistances_set) {
		std::shared_ptr<nyan::ObjectValue> resistance_obj_val = std::dynamic_pointer_cast<nyan::ObjectValue>(resistance.get_ptr());
		auto resistance_obj = resistance_ability.get_view()->get_object(resistance_obj_val->get_name());
		auto resistance_type = api::APIResistance::get_effect_type(resistance_obj);

		if (resistances.contains(resistance_type)) {
			resistances.emplace(resistance_type, std::vector<nyan::Object>{});
		}

		resistances[resistance_type].push_back(resistance_obj);
	}

	time::time_t end_time = start_time;

	// Check for matching effects and resistances
	for (auto &effect : effects) {
		auto effect_type = effect.first;
		auto effect_objs = effect.second;

		if (!resistances.contains(effect_type)) {
			continue;
		}

		auto resistance_objs = resistances[effect_type];

		switch (effect_type) {
		case api::effect_t::DISCRETE_FLAC_DECREASE:
		case api::effect_t::DISCRETE_FLAC_INCREASE: {
			// TODO: Filter effects by AttributeChangeType
			auto attribute_amount = effect_objs[0].get_object("FlatAttributeChange.change_value");
			auto attribute = attribute_amount.get_object("AttributeAmount.type");
			auto applied_value = get_applied_discrete_flac(effect_objs, resistance_objs);

			// TODO: Check if delay is necessary
			auto delay = effect_ability.get_float("ApplyDiscreteEffect.application_delay");
			auto reload_time = effect_ability.get_float("ApplyDiscreteEffect.reload_time");
			end_time += delay + reload_time;

			// Record the time when the effects were applied
			effects_component->set_init_time(start_time + delay);
			effects_component->set_last_used(end_time);

			// Apply the effect to the live component
			live_component->set_attribute(end_time, attribute.get_name(), applied_value);
		} break;
		default:
			throw Error(MSG(err) << "Effect type not implemented: " << static_cast<int>(effect_type));
		}
	}

	return end_time;
}


const component::attribute_value_t ApplyEffect::get_applied_discrete_flac(const std::vector<nyan::Object> &effects,
                                                                          const std::vector<nyan::Object> &resistances) {
	component::attribute_value_t applied_value = 0;
	component::attribute_value_t min_change = component::attribute_value_t::min_value();
	component::attribute_value_t max_change = component::attribute_value_t::max_value();

	for (auto &effect : effects) {
		auto change_amount = effect.get_object("FlatAttributeChange.value");
		auto min_change_amount = effect.get_optional<nyan::Object>("FlatAttributeChange.min_change_value");
		auto max_change_amount = effect.get_optional<nyan::Object>("FlatAttributeChange.max_change_value");

		// Get value from change amount
		// TODO: Ensure that the attribute is the same for all effects
		auto change_value = change_amount.get_int("AttributeAmount.amount");
		applied_value += change_value;

		// TODO: The code below creates a clamp range from the lowest min and highest max values.
		//       This could create some uintended side effects where the clamped range is much larger
		//       than expected. Maybe this should be defined better.

		// Get min change value
		if (min_change_amount) {
			component::attribute_value_t min_change_value = (*min_change_amount)->get_int("AttributeAmount.amount");
			min_change = std::min(min_change_value, min_change);
		}

		// Get max change value
		if (max_change_amount) {
			component::attribute_value_t max_change_value = (*max_change_amount)->get_int("AttributeAmount.amount");
			max_change = std::max(max_change_value, max_change);
		}
	}

	// TODO: Match effects to exactly one resistance to avoid multi resiatance.
	//       idea: move effect type to Effect object and make Resistance.resistances a dict.

	for (auto &resistance : resistances) {
		auto block_amount = resistance.get_object("FlatAttributeChange.value");
		auto min_block_amount = resistance.get_optional<nyan::Object>("FlatAttributeChange.min_change_value");
		auto max_block_amount = resistance.get_optional<nyan::Object>("FlatAttributeChange.max_change_value");

		// Get value from block amount
		// TODO: Ensure that the attribute is the same attribute used in the effects
		auto block_value = block_amount.get_int("AttributeAmount.amount");
		applied_value -= block_value;
	}

	// Clamp the applied value
	applied_value = std::clamp(applied_value, min_change, max_change);

	return applied_value;
}

} // namespace openage::gamestate::system
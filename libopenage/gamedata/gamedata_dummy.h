// Copyright 2013-2021 the openage authors. See copying.md for legal info.

// Warning: this file is a dummy file and was auto-generated by the v0.4.1 converter;
// its purpose is to keep the deprecated gamestate compilable and intact;
// these files keep only the minimum functionality and should not be changed;
// For details, see buildsystem/codegen.cmake and openage/codegen.

#pragma once

#include <cstddef>
#include <cstdint>
#include <string>
#include "civilisation_dummy.h"
#include "graphic_dummy.h"
#include "player_color_dummy.h"
#include "research_dummy.h"
#include "sound_dummy.h"
#include "tech_dummy.h"
#include "terrain_dummy.h"
#include "unit_dummy.h"
#include "util/csv.h"



namespace openage {
namespace gamedata {

/**
 * empires2_x1_p1.dat structure
 */
struct empiresdat {
	std::string versionstr;
	openage::util::csv_subdata<openage::gamedata::terrain_restriction> terrain_restrictions;
	openage::util::csv_subdata<openage::gamedata::player_color> player_colors;
	openage::util::csv_subdata<openage::gamedata::sound> sounds;
	openage::util::csv_subdata<openage::gamedata::graphic> graphics;
	int32_t virt_function_ptr;
	int32_t map_pointer;
	int32_t map_width;
	int32_t map_height;
	int32_t world_width;
	int32_t world_height;
	openage::util::csv_subdata<openage::gamedata::tile_size> tile_sizes;
	int16_t padding1;
	openage::util::csv_subdata<openage::gamedata::terrain_type> terrains;
	openage::util::csv_subdata<openage::gamedata::terrain_border> terrain_border;
	int32_t map_row_offset;
	float map_min_x;
	float map_min_y;
	float map_max_x;
	float map_max_y;
	float map_max_xplus1;
	float map_min_yplus1;
	int16_t current_row;
	int16_t current_column;
	int16_t block_beginn_row;
	int16_t block_end_row;
	int16_t block_begin_column;
	int16_t block_end_column;
	int32_t search_map_ptr;
	int32_t search_map_rows_ptr;
	int8_t any_frame_change;
	int8_t map_visible_flag;
	int8_t fog_flag;
	openage::util::csv_subdata<openage::gamedata::effect_bundle> effect_bundles;
	openage::util::csv_subdata<openage::gamedata::unit_header> unit_headers;
	openage::util::csv_subdata<openage::gamedata::civilisation> civs;
	openage::util::csv_subdata<openage::gamedata::tech> researches;
	int32_t time_slice;
	int32_t unit_kill_rate;
	int32_t unit_kill_total;
	int32_t unit_hitpoint_rate;
	int32_t unit_hitpoint_total;
	int32_t razing_kill_rate;
	int32_t razing_kill_total;
	int32_t total_unit_tech_groups;
	openage::util::csv_subdata<openage::gamedata::age_tech_tree> age_connections;
	openage::util::csv_subdata<openage::gamedata::building_connection> building_connections;
	openage::util::csv_subdata<openage::gamedata::unit_connection> unit_connections;
	openage::util::csv_subdata<openage::gamedata::research_connection> tech_connections;
	static constexpr size_t member_count = 49;
	int fill(const std::string &line);
	bool recurse(const openage::util::CSVCollection &storage, const std::string &basedir);

};

} // gamedata
} // openage

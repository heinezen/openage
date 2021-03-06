// Copyright 2013-2021 the openage authors. See copying.md for legal info.

// Warning: this file is a dummy file and was auto-generated by the v0.4.1 converter;
// its purpose is to keep the deprecated gamestate compilable and intact;
// these files keep only the minimum functionality and should not be changed;
// For details, see buildsystem/codegen.cmake and openage/codegen.

#pragma once

#include <cstddef>
#include <cstdint>
#include <string>
#include "util/csv.h"



namespace openage {
namespace gamedata {

/**
 * describes player color settings.
 */
struct player_color {
	int32_t id;
	int32_t player_color_base;
	int32_t outline_color;
	int32_t unit_selection_color1;
	int32_t unit_selection_color2;
	int32_t minimap_color1;
	int32_t minimap_color2;
	int32_t minimap_color3;
	int32_t statistics_text_color;
	static constexpr size_t member_count = 9;
	int fill(const std::string &line);
	bool recurse(const openage::util::CSVCollection &storage, const std::string &basedir);

};

} // gamedata
} // openage

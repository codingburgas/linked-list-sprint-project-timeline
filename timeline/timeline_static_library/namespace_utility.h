#pragma once
#include <cstdint>

namespace utility
{
	extern bool exit;

	struct struct_scene
	{
		enum enum_scene : std::uint8_t { menu };

		enum_scene current_scene = menu;
	};

	extern struct_scene scene;
}

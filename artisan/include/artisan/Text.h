#pragma once

#include "Colors.h"

#include <cstdio>
#include <cstdlib>
#include <string.h>
#include <Windows.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "../deps/fontstash.h"
#include "../deps/glfontstash.h"

typedef FONScontext font_manager;

typedef struct Font {
	int fn;
	FONScontext* context;
} Font;

Font load_font(const char* file_path, const char* name);

void draw_text(Font font_used, const char* text, float x, float y, float font_size, color color_drawn);
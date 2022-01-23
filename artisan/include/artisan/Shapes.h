#pragma once
#include "GLFW/glfw3.h"
#include "Colors.h"

typedef struct Rect {
	float x, y, width, height;
} Rect;

void draw_rectangle(int x, int y, int width, int height, color col);

void draw_rectangle_rec(Rect rec, color col);

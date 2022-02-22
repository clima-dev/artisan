#pragma once
#include "GLFW/glfw3.h"
#include "Colors.h"
#include "Math.h"
#include <cmath>


typedef struct Rect {
	float x, y, width, height;
} Rect;

void draw_rectangle(int x, int y, int width, int height, color col);

void draw_rectangle_rec(Rect rec, color col);

typedef struct Circle {
	int x, y;
	float radius;
} Circle;

void draw_circle(int x, int y, float radius, color col);
void draw_circle_obj(Circle circ, color col);

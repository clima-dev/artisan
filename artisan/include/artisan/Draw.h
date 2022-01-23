#pragma once
#include <GLFW/glfw3.h>
#include "Window.h"
#include "RGBColor.h"

void begin_drawing();
void end_drawing(artisan::Window window);
void clear_bg(artisan::RGBColor color);
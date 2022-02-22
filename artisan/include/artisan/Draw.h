#pragma once
#include <GLFW/glfw3.h>
#include "Window.h"
#include "RGBColor.h"

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl2.h"

void begin_drawing();
void end_drawing(artisan::Window window);
void clear_bg(artisan::RGBColor color);
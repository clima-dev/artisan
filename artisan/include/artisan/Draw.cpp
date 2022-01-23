#include "Draw.h"

void begin_drawing()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
}

void end_drawing(artisan::Window window)
{
	glfwSwapBuffers(window.m_Window);
	glfwPollEvents();

	glFlush();
}

void clear_bg(artisan::RGBColor color)
{
	glClearColor(color.r, color.g, color.b, color.alpha);
}
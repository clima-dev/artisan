#pragma once
#include "../Vector2.h"
#include <iostream>
#include <GLFW/glfw3.h>
namespace artisan {
	class Rect
	{
	public:
		Rect(artisan::Vect2 coord, artisan::Vect2 size);

		void Render();
	private:
		float x, y;
		float sizeX, sizeY;
	};
}


#include "Rect.h"

namespace artisan
{
	Rect::Rect(artisan::Vect2 coord, artisan::Vect2 size)
	{
		this->x = coord.x;
		this->y = coord.y;

		this->sizeX = size.x;
		this->sizeY = size.y;
	}

	void Rect::Render()
	{
		x = (x / 800.f) - 1.f;
		y = (y / 600.f) - 1.f;

		sizeX = (sizeX / 800.f) - 1.f;
		sizeY = (sizeY / 600.f) - 1.f;

		if (sizeX < 0)
		{
			sizeX = -sizeX;
		}

		if (sizeY < 0)
		{
			sizeY = -sizeY;
		}

		glPushMatrix();

		glBegin(GL_TRIANGLES);

		glVertex2f(x, y);
		glVertex2f(x + sizeX, y);
		glVertex2f(x, y + sizeY);

		glVertex2f(x + sizeX, y);
		glVertex2f(x, y + sizeY);
		glVertex2f(x + sizeX, y + sizeY);

		glEnd();

		glPopMatrix();
	}
}
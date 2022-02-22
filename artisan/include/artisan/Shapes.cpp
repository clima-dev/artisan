#include "Shapes.h"

void draw_rectangle(int x, int y, int width, int height, color col)
{

	glBegin(GL_TRIANGLES);
	
	glColor4ub(col.r, col.g, col.b, col.a);

	glVertex2i(x, y);
	glVertex2i(x, y + height);
	glVertex2i(x + width, y);

	glVertex2i(x + width, y + height);
	glVertex2i(x + width, y);
	glVertex2i(x, y + height);

	glEnd();
}

void draw_rectangle_rec(Rect rec, color col)
{
	glBegin(GL_TRIANGLES);

	glColor4ub(col.r, col.g, col.b, col.a);

	glVertex2i(rec.x, rec.y);
	glVertex2i(rec.x + rec.width, rec.y);
	glVertex2i(rec.x, rec.y + rec.height);

	glVertex2i(rec.x + rec.width, rec.y + rec.height);
	glVertex2i(rec.x + rec.width, rec.y);
	glVertex2i(rec.x, rec.y + rec.height);
	glEnd();
}

void draw_circle(int x, int y, float radius, color col)
{
	if (radius <= 0) radius = 0.1f;
	glBegin(GL_TRIANGLE_FAN);
	glColor4ub(col.r, col.g, col.b, col.a);
	glVertex2f(x, y);

	for (int i = 0; i <= 360; i++)
	{
		glVertex2f(x + sin(DEG2RAD * i) * radius, y + cos(DEG2RAD * i) * radius);
	}
	glEnd();

}
void draw_circle_obj(Circle data, color col)
{
	draw_circle(data.x, data.y, data.radius, col);
}
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
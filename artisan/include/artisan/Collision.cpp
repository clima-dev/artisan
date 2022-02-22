#include "Collision.h"

bool rec_colliding(Rect r1, Rect r2)
{
	if (
		r1.x + r1.width >= r2.x &&
		r1.x <= r2.x + r2.width &&
		r1.y + r1.height >= r2.y &&
		r1.y <= r2.y + r2.height
		) {
		return true;
	}

	return false;
}

bool circle_colliding(Circle c1, Circle c2)
{
	float distX = c1.x - c2.x;
	float distY = c1.y - c2.y;
	float distance = sqrt((distX * distX) + (distY * distY));

	if (distance <= c1.radius + c1.radius) { return true; };

	return false;
}
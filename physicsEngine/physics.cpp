#include "physics.h"

// Thing constructor
Thing::Thing(float x, float y, float radius)
: x{x},
  y{y},
  dX{0},
  dY{0},
  radius{radius}
{
}
// end of Thing constructor
void Thing::setPosition(float x, float y)
{
}
float Thing::getX()
{
	return this->x;
}
float Thing::getY()
{
	return this->y;
}
void Thing::applyForce(float xForce, float yForce)
{
	dX += xForce;
	dY += yForce;
}
void Thing::update()
{
	x += dX;
	y += dY;
}

bool Thing::didCollide(Thing otherThing)
{
	if (this->x - otherThing.x <= this->radius)
	{
		return true;
	}
	return false;
	
}

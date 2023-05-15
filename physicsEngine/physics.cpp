#include "physics.h"
#include <cmath>
#include <iostream>

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

bool Thing::didCollide(const Thing otherThing)
{
	//** distance algorithm uses pythagoras *//
	float distance = std::sqrt(std::pow(otherThing.x - this->x, 2) + std::pow(otherThing.y - this->y, 2));
	if (distance <= this->radius + otherThing.radius)
	{
		return true;
	}
	return false;
	
}

/** Create a world with the sent properties
	* @param width
	* @param height
	* @param gravity
	*/
World::World(float width, float height, float gravity)
	: width{width},
	height{height},
	gravity{gravity}
{

}
/**
* Add a thing to the world.
* @param thing - a pointer to a thing (pass this in with &aThing)
*/
void World::addThing(Thing* thing)
{
	things.push_back(*thing);
}
/**
* Checks if the two things collided,
* true if distance < radius1 + radius2
* @param thing1: a pointer to a thing (&thing)
* @param thing2: a pointer to another thing (&thing)
* @return bool
*/
//bool didThingsCollide(Thing* thing1, Thing* thing2);
/**
* Returns the number of things in the world
* @return int
*/
int World::countThings()
{
	return things.size();
}
/**
* Update the things in the world, including
* applying gravitational forces
* computing collisions
* and applying edge of world bounces
*/
void World::update()
{
	for (Thing& t : things)
	{
		t.applyForce(0.0, gravity);
		t.update();
	}
}
//private:
//	float width;
//	float height;
//	float gravity;
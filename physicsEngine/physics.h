#pragma once
class physics
{
};
class Thing
{
	public:
		/** create a thing with the sent properties
		* @param x - the horizontal position
		* @param y - the vertical position
		* @param radius - the radius (we assume it is circular)
		*/
		Thing(float x, float y, float radius);
		/**
		* set the position of the thing
		* @param x - the horizontal position
		* @param y - the vertical position
		*/
		void setPosition(float x, float y);
		/**
		* Get the horizontal position
		* @return float
		*/
		float getX();
		/**
		* Get the vertical position
		9
		* @return float
		*/
		float getY();
		/**
		* Apply a force of the sent magnitude to the
		* thing
		* @param xForce - horizontal force
		* @param yForce - vertical force
		*/
		void applyForce(float xForce, float yForce);
		/** update the position of the thing
		* New position = x + dx, y + dy
		*/
		void update();

		bool didCollide(Thing otherThing);
	private:
		float x;
		float y;
		float dX;
		float dY;
		float radius;
};


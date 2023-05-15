#include <cppunit/TestCase.h>
#include <cppunit/TestCaller.h>
#include <cppunit/ui/text/TestRunner.h>

#include "physics.h"
class FixtureTests : public CppUnit::TestFixture
{
public:
	void setUp() override
	{
	}
	void tearDown() override
	{
	}
	void testAddition()
	{
		CPPUNIT_ASSERT(2 + 2 == 4);
		CPPUNIT_ASSERT(3 + 3 == 6);
	}
	void testThingPosition()
	{
		Thing thing{ 5.0f, 10.0f, 1.0f };
		CPPUNIT_ASSERT(thing.getX() == 5.0f);
	}
	void testThingStartsStill()
	{
		Thing thing{ 5.0f, 10.0f, 1.0f };
		thing.update();
		CPPUNIT_ASSERT(thing.getX() == 5.0f);
	}
	void testThingMoves()
	{
		Thing thing{ 5.0f, 10.0f, 1.0f };
		thing.applyForce(1, 1);
		thing.update();
		// we'll assume a simple force model
		// where applying a force means it
		// adds that dX each time we update
		CPPUNIT_ASSERT(thing.getX() == 6.0f);
	}

	
	void testCollide()
	{
		Thing thing1{ 5.5f, 10.0f, 1.0f };
		Thing thing2{ 6.5f, 10.0f, 1.0f };
		CPPUNIT_ASSERT(thing1.didCollide(thing2));
	}

	void testWorld()
	{
		World world{ 5.5f, 10.0f, -1.0f };
		Thing thing{ 5.0f, 10.0f, 1.0f };
		world.addThing(&thing);
		CPPUNIT_ASSERT(world.countThings() == 1);
	}

	void testGravity()
	{
		World world{ 100.0f, 100.0f, -1.0f };
		Thing thing{ 5.0f, 10.0f, 1.0f };
		world.addThing(&thing);
		world.update();
		CPPUNIT_ASSERT(world.things[0].getY() == 9.0f);
	}



};
int main()
{
	CppUnit::TextUi::TestRunner runner{};
	runner.addTest(new CppUnit::TestCaller<FixtureTests>
	{
		"test the addition operator",
		&FixtureTests::testAddition
	});
	runner.addTest(new CppUnit::TestCaller<FixtureTests>
	{
		"test the thing position is correct",
		&FixtureTests::testThingPosition
	});
	runner.addTest(new CppUnit::TestCaller<FixtureTests>{
		"test starts still",
		&FixtureTests::testThingStartsStill
	});
	runner.addTest(new CppUnit::TestCaller<FixtureTests>{
		"test force",
		&FixtureTests::testThingMoves
	});
	runner.addTest(new CppUnit::TestCaller<FixtureTests>{
		"test Collision",
		&FixtureTests::testCollide
	});
	runner.addTest(new CppUnit::TestCaller<FixtureTests>{
		"test add things",
		&FixtureTests::testWorld
	});

	runner.addTest(new CppUnit::TestCaller<FixtureTests>{
		"Test Gravity",
		&FixtureTests::testGravity
	});

	
	
	runner.run();

	return 0;
}

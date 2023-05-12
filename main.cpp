// #include <cppunit/TestCase.h>
// #include <cppunit/TestCaller.h>
// #include <cppunit/ui/text/TestRunner.h>

// class BasicTest : public CppUnit::TestCase {
//     public:
//         BasicTest( std::string name ) : CppUnit::TestCase( name ) {}
    
//     void runTest() override
//     {
//         CPPUNIT_ASSERT( 2 + 2 == 4 );
//         CPPUNIT_ASSERT( 2 + 2 == 3 );
//     }
// };

// class FixtureTests : public CppUnit::TestFixture 
// {
//     public:
//         void setUp() override
//         {
//             printf("Setup is called\n");
//         }

//         void tearDown() override
//         {
//             printf("TearDown is called\n");
//         }

//         void testAddition()
//         {
//             CPPUNIT_ASSERT( 2 + 2 == 4 );
//             CPPUNIT_ASSERT( 2 + 2 == 3 );
//         }
//         void testLogic()
//         {
//             CPPUNIT_ASSERT( true == false );
//             CPPUNIT_ASSERT( false == false );
//         }

// };

// int main()
// {
//     // BasicTest test{"BasicTest"};
//     // test.runTest();
//     CppUnit::TextUi::TestRunner runner{};
//     runner.addTest(new CppUnit::TestCaller<FixtureTests>{
//         "Test the addidion Operator",
//         &FixtureTests::testAddition
//     });
//     runner.addTest(new CppUnit::TestCaller<FixtureTests>{
//         "Test Logic",
//         &FixtureTests::testLogic
//     });

//     runner.run();

//     return 0;
// }

#include <iostream>
#include <cppunit/extensions/HelperMacros.h>

class TestExample : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(TestExample);
    CPPUNIT_TEST(testMethod);
    CPPUNIT_TEST_SUITE_END();

public:
    void setUp() {}
    void tearDown() {}

    void testMethod()
    {
        // Add your test code here
        CPPUNIT_ASSERT(1 + 1 == 2);
    }
};

CPPUNIT_TEST_SUITE_REGISTRATION(TestExample);

int main()
{
    CppUnit::TextUi::TestRunner runner;
    runner.addTest(TestExample::suite());
    runner.run();
    return 0;
}
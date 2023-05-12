 #include <cppunit/TestCase.h>
 #include <cppunit/TestCaller.h>
 #include <cppunit/ui/text/TestRunner.h>

 //class BasicTest : public CppUnit::TestCase {
 //    public:
 //        BasicTest( std::string name ) : CppUnit::TestCase( name ) {}

 //    void runTest() override
 //    {
 //        CPPUNIT_ASSERT( 2 + 2 == 4 );
 //        CPPUNIT_ASSERT( 2 + 2 == 3 );
 //    }
 //};

 class FixtureTests : public CppUnit::TestFixture 
 {
     public:
         void setUp() override
         {
             printf("Setup is called\n");
         }

         void tearDown() override
         {
             printf("TearDown is called\n");
         }

         void testAddition()
         {
             CPPUNIT_ASSERT_MESSAGE("You Doufus", 2 + 2 == 4);
             CPPUNIT_ASSERT_MESSAGE("You Doufus", 2 + 2 == 4 );
         }
         void testLogic()
         {
             CPPUNIT_ASSERT( true == true );
             CPPUNIT_ASSERT( false == false );
         }
         void testFail()
         {
             //CPPUNIT_FAIL("Fail!!!");
         }
         void testEqual()
         {
             CPPUNIT_ASSERT_EQUAL(2, 2);
         }

};

int main()
{
    // BasicTest test{"BasicTest"};
    // test.runTest();
    CppUnit::TextUi::TestRunner runner{};
    runner.addTest(new CppUnit::TestCaller<FixtureTests>{
        "Test the addidion Operator",
        &FixtureTests::testAddition
    });
    runner.addTest(new CppUnit::TestCaller<FixtureTests>{
        "Test Logic",
        &FixtureTests::testLogic
    });
    runner.addTest(new CppUnit::TestCaller<FixtureTests>{
        "Test Fail",
        &FixtureTests::testFail
    });
    runner.addTest(new CppUnit::TestCaller<FixtureTests>{
        "Test Equal",
        &FixtureTests::testEqual
    });

    runner.run();

    return 0;
}
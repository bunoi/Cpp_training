/* Generated file, do not edit */

#ifndef CXXTEST_RUNNING
#define CXXTEST_RUNNING
#endif

#define _CXXTEST_HAVE_STD
#include <cxxtest/TestListener.h>
#include <cxxtest/TestTracker.h>
#include <cxxtest/TestRunner.h>
#include <cxxtest/RealDescriptions.h>
#include <cxxtest/TestMain.h>
#include <cxxtest/ErrorPrinter.h>

int main( int argc, char *argv[] ) {
 int status;
    CxxTest::ErrorPrinter tmp;
    CxxTest::RealWorldDescription::_worldName = "cxxtest";
    status = CxxTest::Main< CxxTest::ErrorPrinter >( tmp, argc, argv );
    return status;
}
bool suite_MyTestSuite1_init = false;
#include "/home/bun/Cpp_training/Int256/test/MyTestSuite1.h"

static MyTestSuite1 suite_MyTestSuite1;

static CxxTest::List Tests_MyTestSuite1 = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_MyTestSuite1( "MyTestSuite1.h", 4, "MyTestSuite1", suite_MyTestSuite1, Tests_MyTestSuite1 );

static class TestDescription_suite_MyTestSuite1_testAddition : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite1_testAddition() : CxxTest::RealTestDescription( Tests_MyTestSuite1, suiteDescription_MyTestSuite1, 7, "testAddition" ) {}
 void runTest() { suite_MyTestSuite1.testAddition(); }
} testDescription_suite_MyTestSuite1_testAddition;

static class TestDescription_suite_MyTestSuite1_testInt256 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite1_testInt256() : CxxTest::RealTestDescription( Tests_MyTestSuite1, suiteDescription_MyTestSuite1, 13, "testInt256" ) {}
 void runTest() { suite_MyTestSuite1.testInt256(); }
} testDescription_suite_MyTestSuite1_testInt256;

static class TestDescription_suite_MyTestSuite1_testInt256Addition : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite1_testInt256Addition() : CxxTest::RealTestDescription( Tests_MyTestSuite1, suiteDescription_MyTestSuite1, 19, "testInt256Addition" ) {}
 void runTest() { suite_MyTestSuite1.testInt256Addition(); }
} testDescription_suite_MyTestSuite1_testInt256Addition;

static class TestDescription_suite_MyTestSuite1_testInt256Multiplication : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite1_testInt256Multiplication() : CxxTest::RealTestDescription( Tests_MyTestSuite1, suiteDescription_MyTestSuite1, 28, "testInt256Multiplication" ) {}
 void runTest() { suite_MyTestSuite1.testInt256Multiplication(); }
} testDescription_suite_MyTestSuite1_testInt256Multiplication;

static class TestDescription_suite_MyTestSuite1_testInt256Division : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite1_testInt256Division() : CxxTest::RealTestDescription( Tests_MyTestSuite1, suiteDescription_MyTestSuite1, 44, "testInt256Division" ) {}
 void runTest() { suite_MyTestSuite1.testInt256Division(); }
} testDescription_suite_MyTestSuite1_testInt256Division;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";

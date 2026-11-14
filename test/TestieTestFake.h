/**************************************************************************************************
* Module with fake tests for the self test of Testie framework
**************************************************************************************************/

#ifndef _TESTIE_TEST_FAKE_
#define _TESTIE_TEST_FAKE_ 

/* Includes **************************************************************************************/

#include "Testie.h"


/* Type definitions ******************************************************************************/

typedef struct
{
    TESTIE_UINT8 SetupExecuted;
    TESTIE_UINT8 TearDownExecuted;
} S_TESTIE_TEST_FAKE;


/* Global variables ******************************************************************************/

extern S_TESTIE_TEST_FAKE TestieTestFake;


/* Test setup and teardown ***********************************************************************/

/**************************************************************************************************
* Desc  : Function that can be used as test setup
**************************************************************************************************/
void Testie_FakeSetup(void);


/**************************************************************************************************
* Desc  : Function that can be used as test tear down
**************************************************************************************************/
void Testie_FakeTearDown(void);


/* Test case declarations ************************************************************************/

TEST_DECLARATION(Testie_FailingTest);
TEST_DECLARATION(Testie_AssertionTrueSuccessful);
TEST_DECLARATION(Testie_AssertionTrueFailing);
TEST_DECLARATION(Testie_AssertionFalseSuccessful);
TEST_DECLARATION(Testie_AssertionFalseFailing);
TEST_DECLARATION(Testie_AssertionInt8Successful);
TEST_DECLARATION(Testie_AssertionInt8Failing);
TEST_DECLARATION(Testie_AssertionInt16Successful);
TEST_DECLARATION(Testie_AssertionInt16Failing);
TEST_DECLARATION(Testie_AssertionInt32Successful);
TEST_DECLARATION(Testie_AssertionInt32Failing);
TEST_DECLARATION(Testie_AssertionUInt8Successful);
TEST_DECLARATION(Testie_AssertionUInt8Failing);
TEST_DECLARATION(Testie_AssertionUInt16Successful);
TEST_DECLARATION(Testie_AssertionUInt16Failing);
TEST_DECLARATION(Testie_AssertionUInt32Successful);
TEST_DECLARATION(Testie_AssertionUInt32Failing);
TEST_DECLARATION(Testie_AssertionStringSuccessful);
TEST_DECLARATION(Testie_AssertionStringFailing);
TEST_DECLARATION(Testie_AssertionStringROMSuccessful);
TEST_DECLARATION(Testie_AssertionStringROMFailing);
TEST_DECLARATION(Testie_CaseWithExtremelyLongNameWhichIsTotallyAppropriateForThisUniqueAndExcellentTest);
TEST_DECLARATION(Testie_AssertionHexSuccessful);
TEST_DECLARATION(Testie_AssertionHexFailing);
TEST_DECLARATION(Testie_AssertionHexFailingWithValueZero);
TEST_DECLARATION(Testie_AssertionMemorySuccessful);
TEST_DECLARATION(Testie_AssertionMemoryFailing);
TEST_DECLARATION(Testie_AssertionMemoryROMSuccessful);
TEST_DECLARATION(Testie_AssertionMemoryROMFailing);


/* Test suite declarations ***********************************************************************/

TEST_SUITE_DECLARATION(Testie_EmptySuite);
TEST_SUITE_DECLARATION(Testie_TwoSuccessfulTestSuite);
TEST_SUITE_DECLARATION(Testie_TwoFailingTestSuite);


/* End of module *********************************************************************************/
#endif

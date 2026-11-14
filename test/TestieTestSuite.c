/**************************************************************************************************
* Test suite module for the Testie framework to show the architecture and examples
**************************************************************************************************/

/* Includes **************************************************************************************/

#include "Testie.h"


/* Test cases ************************************************************************************/

TEST_DECLARATION(Testie_IsSuiteHeaderCorrect);
TEST_DECLARATION(Testie_IsSuiteFooterCorrect);
TEST_DECLARATION(Testie_IsEmptyLineAfterSuiteFooter);
TEST_DECLARATION(Testie_IsTestCountCorrect);
TEST_DECLARATION(Testie_IsFailCountCorrect);
TEST_DECLARATION(Testie_AssertionTrue);
TEST_DECLARATION(Testie_AssertionFalse);
TEST_DECLARATION(Testie_AssertionFail);
TEST_DECLARATION(Testie_AssertionInt8);
TEST_DECLARATION(Testie_AssertionInt8InputRange);
TEST_DECLARATION(Testie_AssertionInt16);
TEST_DECLARATION(Testie_AssertionInt16InputRange);
TEST_DECLARATION(Testie_AssertionInt32);
TEST_DECLARATION(Testie_AssertionInt32InputRange);
TEST_DECLARATION(Testie_AssertionInt);
TEST_DECLARATION(Testie_AssertionUInt8);
TEST_DECLARATION(Testie_AssertionUInt8InputRange);
TEST_DECLARATION(Testie_AssertionUInt16);
TEST_DECLARATION(Testie_AssertionUInt16InputRange);
TEST_DECLARATION(Testie_AssertionUInt32);
TEST_DECLARATION(Testie_AssertionUInt32InputRange);
TEST_DECLARATION(Testie_AssertionUInt);
TEST_DECLARATION(Testie_AssertionString);
TEST_DECLARATION(Testie_AssertionStringROM);
TEST_DECLARATION(Testie_IsCaseOutputCorrectWithNameExceedingWidth);
TEST_DECLARATION(Testie_AssertionHexadecimal);
TEST_DECLARATION(Testie_AssertionHexadecimalWithValueZero);
TEST_DECLARATION(Testie_AssertionMemory);
TEST_DECLARATION(Testie_AssertionMemoryROM);
TEST_DECLARATION(Testie_IsTestSetupExecuted);
TEST_DECLARATION(Testie_IsTestTearDownExecuted);


/* Test suite ************************************************************************************/

/**************************************************************************************************
* Desc  : Test suite for Testie test cases
**************************************************************************************************/
TEST_SUITE(Testie_Self)
{
    TEST_RUN(Testie_IsSuiteHeaderCorrect);
    TEST_RUN(Testie_IsSuiteFooterCorrect);
    TEST_RUN(Testie_IsEmptyLineAfterSuiteFooter);
    TEST_RUN(Testie_IsTestCountCorrect);
    TEST_RUN(Testie_IsFailCountCorrect);
    TEST_RUN(Testie_AssertionTrue);
    TEST_RUN(Testie_AssertionFalse);
    TEST_RUN(Testie_AssertionFail);
    TEST_RUN(Testie_AssertionInt8);
    TEST_RUN(Testie_AssertionInt8InputRange);
    TEST_RUN(Testie_AssertionInt16);
    TEST_RUN(Testie_AssertionInt16InputRange);
    TEST_RUN(Testie_AssertionInt32);
    TEST_RUN(Testie_AssertionInt32InputRange);
    TEST_RUN(Testie_AssertionInt);
    TEST_RUN(Testie_AssertionUInt8);
    TEST_RUN(Testie_AssertionUInt8InputRange);
    TEST_RUN(Testie_AssertionUInt16);
    TEST_RUN(Testie_AssertionUInt16InputRange);
    TEST_RUN(Testie_AssertionUInt32);
    TEST_RUN(Testie_AssertionUInt32InputRange);
    TEST_RUN(Testie_AssertionUInt);
    TEST_RUN(Testie_AssertionString);
    TEST_RUN(Testie_AssertionStringROM);
    TEST_RUN(Testie_IsCaseOutputCorrectWithNameExceedingWidth);
    TEST_RUN(Testie_AssertionHexadecimal);
    TEST_RUN(Testie_AssertionHexadecimalWithValueZero);
    TEST_RUN(Testie_AssertionMemory);
    TEST_RUN(Testie_AssertionMemoryROM);
    TEST_RUN(Testie_IsTestSetupExecuted);
    TEST_RUN(Testie_IsTestTearDownExecuted);
}


/* End of module *********************************************************************************/

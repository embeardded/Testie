/**************************************************************************************************
* Self test module for the Testie framework to show the architecture and examples
**************************************************************************************************/

/* Includes **************************************************************************************/

#include "Compiler.h"
#include "Testie.h"

#include "OutputFake.h"
#include "TestieTestFake.h"


/* Global variables ******************************************************************************/

S_TESTIE sTestieBackup;


/* Private functions *****************************************************************************/

/**************************************************************************************************
* Desc  : Run one of the fake tests for the Testie self test
*
* Input : Test is the test function
* Input : TestSetup is the test setup function
* Input : TestTearDown is the test tear down function
**************************************************************************************************/
#define Testie_RunTestToBuffer(Test)        Output.Buffer.Enabled = TRUE;               \
                                            sTestieBackup = Testie;                     \
                                            Testie.Case.Setup    = Testie_FakeSetup;    \
                                            Testie.Case.TearDown = Testie_FakeTearDown; \
                                            TEST_RUN(Test);                             \
                                            Testie = sTestieBackup;                     \
                                            Output.Buffer.Enabled = FALSE


/**************************************************************************************************
* Desc  : Run one of the fake test suites for the Testie self test 
*
* Input : Suite is the test suite function
**************************************************************************************************/
#define Testie_RunSuiteToBuffer(Suite)      Output.Buffer.Enabled = TRUE;               \
                                            sTestieBackup = Testie;                     \
                                            Testie.Case.Setup    = Testie_FakeSetup;    \
                                            Testie.Case.TearDown = Testie_FakeTearDown; \
                                            TEST_SUITE_RUN(Suite);                      \
                                            Testie = sTestieBackup;                     \
                                            Output.Buffer.Enabled = FALSE


/* Test setup and teardown ***********************************************************************/

/**************************************************************************************************
* Desc  : Test case setup
**************************************************************************************************/
void Testie_Setup(void)
{
    TestieTestFake.SetupExecuted = FALSE;
    TestieTestFake.TearDownExecuted = FALSE;

    Output_ClearBuffer();
}


/**************************************************************************************************
* Desc  : Test case tear down
**************************************************************************************************/
void Testie_TearDown(void)
{
}


/* Test cases ************************************************************************************/

/**************************************************************************************************
* Desc  : Test the suite header generation
**************************************************************************************************/
TEST(Testie_IsSuiteHeaderCorrect)
{
    Testie_RunSuiteToBuffer(Testie_EmptySuite);

    ASSERT_EQUAL_STRING_ROM("Testie_EmptySuite Test Suite                                                    ", Output.Buffer.Line[0]);
    ASSERT_EQUAL_STRING_ROM("------------------------------------------------------------------------------- ", Output.Buffer.Line[1]);
}


/**************************************************************************************************
* Desc  : Test the suite footer generation
**************************************************************************************************/
TEST(Testie_IsSuiteFooterCorrect)
{
    Testie_RunSuiteToBuffer(Testie_EmptySuite);

    ASSERT_EQUAL_STRING_ROM("------------------------------------------------------------------------------- ", Output.Buffer.Line[2]);
    ASSERT_EQUAL_STRING_ROM("0 Test Cases 0 Failed                                                           ", Output.Buffer.Line[3]);
}


/**************************************************************************************************
* Desc  : Test the empty line generation after suite footer
**************************************************************************************************/
TEST(Testie_IsEmptyLineAfterSuiteFooter)
{
    Testie_RunSuiteToBuffer(Testie_EmptySuite);
    Testie_RunSuiteToBuffer(Testie_EmptySuite);

    ASSERT_EQUAL_STRING_ROM("                                                                                ", Output.Buffer.Line[4]);
}


/**************************************************************************************************
* Desc  : Test the case count for the suite
**************************************************************************************************/
TEST(Testie_IsTestCountCorrect)
{
    Testie_RunSuiteToBuffer(Testie_TwoSuccessfulTestSuite);

    ASSERT_EQUAL_STRING_ROM("2 Test Cases 0 Failed                                                           ", Output.Buffer.Line[5]);
}


/**************************************************************************************************
* Desc  : Test the failed case count for the suite
**************************************************************************************************/
TEST(Testie_IsFailCountCorrect)
{
    Testie_RunSuiteToBuffer(Testie_TwoFailingTestSuite);

    ASSERT_EQUAL_STRING_ROM("3 Test Cases 2 Failed                                                           ", Output.Buffer.Line[8]);
}


/**************************************************************************************************
* Desc  : Test for assertion true
**************************************************************************************************/
TEST(Testie_AssertionTrue)
{
    Testie_RunTestToBuffer(Testie_AssertionTrueSuccessful);

    ASSERT_EQUAL_STRING_ROM("Testie_AssertionTrueSuccessful............................................ PASS ", Output.Buffer.Line[0]);

    Testie_RunTestToBuffer(Testie_AssertionTrueFailing);

    ASSERT_EQUAL_STRING_ROM("Testie_AssertionTrueFailing............................................... FAIL ", Output.Buffer.Line[1]);
    ASSERT_EQUAL_STRING_ROM(" - Expected TRUE was FALSE                                                      ", Output.Buffer.Line[2]);
}


/**************************************************************************************************
* Desc  : Test for assertion false
**************************************************************************************************/
TEST(Testie_AssertionFalse)
{
    Testie_RunTestToBuffer(Testie_AssertionFalseSuccessful);

    ASSERT_EQUAL_STRING_ROM("Testie_AssertionFalseSuccessful........................................... PASS ", Output.Buffer.Line[0]);

    Testie_RunTestToBuffer(Testie_AssertionFalseFailing);

    ASSERT_EQUAL_STRING_ROM("Testie_AssertionFalseFailing.............................................. FAIL ", Output.Buffer.Line[1]);
    ASSERT_EQUAL_STRING_ROM(" - Expected FALSE was TRUE                                                      ", Output.Buffer.Line[2]);
}


/**************************************************************************************************
* Desc  : Test for assertion that will always fail
**************************************************************************************************/
TEST(Testie_AssertionFail)
{
    Testie_RunTestToBuffer(Testie_FailingTest);

    ASSERT_EQUAL_STRING_ROM(" - Assertion set to fail                                                        ", Output.Buffer.Line[1]);
}


/**************************************************************************************************
* Desc  : Test for assertion equal integer 8bit
**************************************************************************************************/
TEST(Testie_AssertionInt8)
{
    Testie_RunTestToBuffer(Testie_AssertionInt8Successful);
    Testie_RunTestToBuffer(Testie_AssertionInt8Failing);

    ASSERT_EQUAL_STRING_ROM(" - Expected -112 was 5                                                          ", Output.Buffer.Line[2]);
}


/**************************************************************************************************
* Desc  : Test of input range for assertion equal integer 8bit
**************************************************************************************************/
TEST(Testie_AssertionInt8InputRange)
{
    ASSERT_EQUAL_INT8(-126, 127 + 3);
}


/**************************************************************************************************
* Desc  : Test for assertion equal integer 16bit
**************************************************************************************************/
TEST(Testie_AssertionInt16)
{
    Testie_RunTestToBuffer(Testie_AssertionInt16Successful);
    Testie_RunTestToBuffer(Testie_AssertionInt16Failing);

    ASSERT_EQUAL_STRING_ROM(" - Expected -31487 was 911                                                      ", Output.Buffer.Line[2]);
}


/**************************************************************************************************
* Desc  : Test of input range for assertion equal integer 16bit
**************************************************************************************************/
TEST(Testie_AssertionInt16InputRange)
{
    ASSERT_EQUAL_INT16(-32767, 32766 + 3);
}


/**************************************************************************************************
* Desc  : Test for assertion equal integer 32bit
**************************************************************************************************/
TEST(Testie_AssertionInt32)
{
    Testie_RunTestToBuffer(Testie_AssertionInt32Successful);
    Testie_RunTestToBuffer(Testie_AssertionInt32Failing);

    ASSERT_EQUAL_STRING_ROM(" - Expected -1004431487 was 7002                                                ", Output.Buffer.Line[2]);
}


/**************************************************************************************************
* Desc  : Test of input range for assertion equal integer 32bit
**************************************************************************************************/
TEST(Testie_AssertionInt32InputRange)
{
    ASSERT_EQUAL_INT32(-2147483647, 2147483649U);
}


/**************************************************************************************************
* Desc  : Test for assertion equal integer
**************************************************************************************************/
TEST(Testie_AssertionInt)
{
    ASSERT_EQUAL_INT(-1234567890, -1234567890);
}


/**************************************************************************************************
* Desc  : Test for assertion equal unsigned integer 8bit
**************************************************************************************************/
TEST(Testie_AssertionUInt8)
{
    Testie_RunTestToBuffer(Testie_AssertionUInt8Successful);
    Testie_RunTestToBuffer(Testie_AssertionUInt8Failing);

    ASSERT_EQUAL_STRING_ROM(" - Expected 248 was 13                                                          ", Output.Buffer.Line[2]);
}


/**************************************************************************************************
* Desc  : Test of input range for assertion equal unsigned integer 8bit
**************************************************************************************************/
TEST(Testie_AssertionUInt8InputRange)
{
    ASSERT_EQUAL_UINT8(4U, 250U + 10U);
}


/**************************************************************************************************
* Desc  : Test for assertion equal unsigned integer 16bit
**************************************************************************************************/
TEST(Testie_AssertionUInt16)
{
    Testie_RunTestToBuffer(Testie_AssertionUInt16Successful);
    Testie_RunTestToBuffer(Testie_AssertionUInt16Failing);

    ASSERT_EQUAL_STRING_ROM(" - Expected 62788 was 307                                                       ", Output.Buffer.Line[2]);
}


/**************************************************************************************************
* Desc  : Test of input range for assertion equal unsigned integer 16bit
**************************************************************************************************/
TEST(Testie_AssertionUInt16InputRange)
{
    ASSERT_EQUAL_UINT16(7U, 65533U + 10U);
}


/**************************************************************************************************
* Desc  : Test for assertion equal unsigned integer 32bit
**************************************************************************************************/
TEST(Testie_AssertionUInt32)
{
    Testie_RunTestToBuffer(Testie_AssertionUInt32Successful);
    Testie_RunTestToBuffer(Testie_AssertionUInt32Failing);

    ASSERT_EQUAL_STRING_ROM(" - Expected 4004431487 was 77856                                                ", Output.Buffer.Line[2]);
}


/**************************************************************************************************
* Desc  : Test of input range for assertion equal unsigned integer 32bit
**************************************************************************************************/
TEST(Testie_AssertionUInt32InputRange)
{
    ASSERT_EQUAL_UINT32(23U, 4294967294U + 25U);
}


/**************************************************************************************************
* Desc  : Test for assertion equal unsigned integer
**************************************************************************************************/
TEST(Testie_AssertionUInt)
{
    ASSERT_EQUAL_UINT(3234567890U, 3234567890U);
}


/**************************************************************************************************
* Desc  : Test for assertion equal two RAM strings
**************************************************************************************************/
TEST(Testie_AssertionString)
{
    Testie_RunTestToBuffer(Testie_AssertionStringSuccessful);
    Testie_RunTestToBuffer(Testie_AssertionStringFailing);

    ASSERT_EQUAL_STRING_ROM(" - Expected \"Monitor\" was \"Shack\"                                               ", Output.Buffer.Line[2]);
}


/**************************************************************************************************
* Desc  : Test for assertion equal expected ROM string to RAM string
**************************************************************************************************/
TEST(Testie_AssertionStringROM)
{
    Testie_RunTestToBuffer(Testie_AssertionStringROMSuccessful);
    Testie_RunTestToBuffer(Testie_AssertionStringROMFailing);

    ASSERT_EQUAL_STRING_ROM(" - Expected \"Monitor\" was \"Shack\"                                               ", Output.Buffer.Line[2]);
}


/**************************************************************************************************
* Desc  : Test for case output when case name exceeds max width
**************************************************************************************************/
TEST(Testie_IsCaseOutputCorrectWithNameExceedingWidth)
{
    Testie_RunTestToBuffer(Testie_CaseWithExtremelyLongNameWhichIsTotallyAppropriateForThisUniqueAndExcellentTest);

    ASSERT_EQUAL_STRING_ROM("Testie_CaseWithExtremelyLongNameWhichIsTotallyAppropriateForThisUniqueAndE PASS ", Output.Buffer.Line[0]);
}


/**************************************************************************************************
* Desc  : Test for assertion equal hexadecimal value
**************************************************************************************************/
TEST(Testie_AssertionHexadecimal)
{
    Testie_RunTestToBuffer(Testie_AssertionHexSuccessful);
    Testie_RunTestToBuffer(Testie_AssertionHexFailing);

    ASSERT_EQUAL_STRING_ROM(" - Expected A81h was F496EB3Ah                                                  ", Output.Buffer.Line[2]);
}


/**************************************************************************************************
* Desc  : Test for output of hexadecimal value 0x00
**************************************************************************************************/
TEST(Testie_AssertionHexadecimalWithValueZero)
{
    Testie_RunTestToBuffer(Testie_AssertionHexFailingWithValueZero);

    ASSERT_EQUAL_STRING_ROM(" - Expected FFh was 0h                                                          ", Output.Buffer.Line[1]);
}


/**************************************************************************************************
* Desc  : Test for assertion equal two memory arrays
**************************************************************************************************/
TEST(Testie_AssertionMemory)
{
    Testie_RunTestToBuffer(Testie_AssertionMemorySuccessful);
    Testie_RunTestToBuffer(Testie_AssertionMemoryFailing);

    ASSERT_EQUAL_STRING_ROM(" - Expected \"48h 65h 6Ch 6Ch 6Fh\" was \"0Fh D1h 2Eh C3h 4Bh\"                     ", Output.Buffer.Line[2]);
}


/**************************************************************************************************
* Desc  : Test for assertion equal expected ROM memory to RAM memory
**************************************************************************************************/
TEST(Testie_AssertionMemoryROM)
{
    //static TESTIE_ROM BYTE pvROMArray[] = {0x48, 0x65, 0x6C, 0x6C, 0x6F}; 
    //BYTE pvArray[] = {0x48, 0x65, 0x6C, 0x6C, 0x6F};

    //ASSERT_EQUAL_MEMORY_ROM(pvROMArray, pvArray, 5U);

    Testie_RunTestToBuffer(Testie_AssertionMemoryROMSuccessful);
    Testie_RunTestToBuffer(Testie_AssertionMemoryROMFailing);

    ASSERT_EQUAL_STRING_ROM(" - Expected \"48h 65h 6Ch 6Ch 6Fh\" was \"0Fh D1h 2Eh C3h 4Bh\"                     ", Output.Buffer.Line[2]);
}


/**************************************************************************************************
* Desc  : Test of setup fixture
**************************************************************************************************/
TEST(Testie_IsTestSetupExecuted)
{
    Testie_RunTestToBuffer(Testie_AssertionTrueSuccessful);

    ASSERT_TRUE(TestieTestFake.SetupExecuted);
}


/**************************************************************************************************
* Desc  : Test of tear down fixture
**************************************************************************************************/
TEST(Testie_IsTestTearDownExecuted)
{
    Testie_RunTestToBuffer(Testie_AssertionTrueSuccessful);

    ASSERT_TRUE(TestieTestFake.TearDownExecuted);
}


/* End of module *********************************************************************************/

/**************************************************************************************************
* Module with fake tests for the self test of Testie framework
**************************************************************************************************/

/* Includes **************************************************************************************/

#include "TestieTestFake.h"


/* Global variables ******************************************************************************/

S_TESTIE_TEST_FAKE TestieTestFake;

/* Test setup and teardown ***********************************************************************/

/**************************************************************************************************
* Desc  : Function that can be used as test setup
**************************************************************************************************/
void Testie_FakeSetup(void)
{
    TestieTestFake.SetupExecuted = true;
}


/**************************************************************************************************
* Desc  : Function that can be used as test tear down
**************************************************************************************************/
void Testie_FakeTearDown(void)
{
    TestieTestFake.TearDownExecuted = true;
}


/* Test cases ************************************************************************************/

/**************************************************************************************************
* Desc  : Test that will succeed
**************************************************************************************************/
TEST(Testie_SuccessfulTest)
{
    ASSERT_TRUE(true);
}


/**************************************************************************************************
* Desc  : Test that will fail
**************************************************************************************************/
TEST(Testie_FailingTest)
{
    ASSERT_FAIL();
}


/**************************************************************************************************
* Desc  : Test will use ASSERT_TRUE and succeed
**************************************************************************************************/
TEST(Testie_AssertionTrueSuccessful)
{
    ASSERT_TRUE(true);
}


/**************************************************************************************************
* Desc  : Test will use ASSERT_TRUE and fail
**************************************************************************************************/
TEST(Testie_AssertionTrueFailing)
{
    ASSERT_TRUE(false);
}


/**************************************************************************************************
* Desc  : Test will use ASSERT_FALSE and succeed
**************************************************************************************************/
TEST(Testie_AssertionFalseSuccessful)
{
    ASSERT_FALSE(false);
}


/**************************************************************************************************
* Desc  : Test will use ASSERT_FALSE and fail
**************************************************************************************************/
TEST(Testie_AssertionFalseFailing)
{
    ASSERT_FALSE(true);
}


/**************************************************************************************************
* Desc  : Test will use ASSERT_EQUAL_INT8 and succeed
**************************************************************************************************/
TEST(Testie_AssertionInt8Successful)
{
    ASSERT_EQUAL_INT8(-100, -100);
}


/**************************************************************************************************
* Desc  : Test will use ASSERT_EQUAL_INT8 and fail
**************************************************************************************************/
TEST(Testie_AssertionInt8Failing)
{
    ASSERT_EQUAL_INT8(-112, 5);
}


/**************************************************************************************************
* Desc  : Test will use ASSERT_EQUAL_INT16 and succeed
**************************************************************************************************/
TEST(Testie_AssertionInt16Successful)
{
    ASSERT_EQUAL_INT16(-30458, -30458);
}


/**************************************************************************************************
* Desc  : Test will use ASSERT_EQUAL_INT16 and fail
**************************************************************************************************/
TEST(Testie_AssertionInt16Failing)
{
    ASSERT_EQUAL_INT16(-31487, 911);
}


/**************************************************************************************************
* Desc  : Test will use ASSERT_EQUAL_INT32 and succeed
**************************************************************************************************/
TEST(Testie_AssertionInt32Successful)
{
    ASSERT_EQUAL_INT32(-2012345678, -2012345678);
}


/**************************************************************************************************
* Desc  : Test will use ASSERT_EQUAL_INT32 and fail
**************************************************************************************************/
TEST(Testie_AssertionInt32Failing)
{
    ASSERT_EQUAL_INT32(-1004431487, 7002);
}


/**************************************************************************************************
* Desc  : Test will use ASSERT_EQUAL_UINT8 and succeed
**************************************************************************************************/
TEST(Testie_AssertionUInt8Successful)
{
    ASSERT_EQUAL_UINT8(214U, 214U);
}


/**************************************************************************************************
* Desc  : Test will use ASSERT_EQUAL_UINT8 and fail
**************************************************************************************************/
TEST(Testie_AssertionUInt8Failing)
{
    ASSERT_EQUAL_UINT8(248U, 13U);
}


/**************************************************************************************************
* Desc  : Test will use ASSERT_EQUAL_UINT16 and succeed
**************************************************************************************************/
TEST(Testie_AssertionUInt16Successful)
{
    ASSERT_EQUAL_UINT16(60001U, 60001U);
}


/**************************************************************************************************
* Desc  : Test will use ASSERT_EQUAL_UINT16 and fail
**************************************************************************************************/
TEST(Testie_AssertionUInt16Failing)
{
    ASSERT_EQUAL_UINT16(62788U, 307U);
}


/**************************************************************************************************
* Desc  : Test will use ASSERT_EQUAL_UINT32 and succeed
**************************************************************************************************/
TEST(Testie_AssertionUInt32Successful)
{
    ASSERT_EQUAL_UINT32(4012345678U, 4012345678U);
}


/**************************************************************************************************
* Desc  : Test will use ASSERT_EQUAL_UINT32 and fail
**************************************************************************************************/
TEST(Testie_AssertionUInt32Failing)
{
    ASSERT_EQUAL_UINT32(4004431487U, 77856U);
}


/**************************************************************************************************
* Desc  : Test will use ASSERT_EQUAL_STRING and succeed
**************************************************************************************************/
TEST(Testie_AssertionStringSuccessful)
{
    TESTIE_CHAR pcText1[] = "Knife";
    TESTIE_CHAR pcText2[] = "Knife";

    ASSERT_EQUAL_STRING(pcText1, pcText2);
}


/**************************************************************************************************
* Desc  : Test will use ASSERT_EQUAL_STRING and fail
**************************************************************************************************/
TEST(Testie_AssertionStringFailing)
{
    TESTIE_CHAR pcText1[] = "Monitor";
    TESTIE_CHAR pcText2[] = "Shack";

    ASSERT_EQUAL_STRING(pcText1, pcText2);
}


/**************************************************************************************************
* Desc  : Test will use ASSERT_EQUAL_STRING_ROM and succeed
**************************************************************************************************/
TEST(Testie_AssertionStringROMSuccessful)
{
    static TESTIE_ROM TESTIE_CHAR pcText1[] = "Knife";
    TESTIE_CHAR pcText2[] = "Knife";

    ASSERT_EQUAL_STRING_ROM(pcText1, pcText2);
}


/**************************************************************************************************
* Desc  : Test will use ASSERT_EQUAL_STRING_ROM and fail
**************************************************************************************************/
TEST(Testie_AssertionStringROMFailing)
{
    static TESTIE_ROM TESTIE_CHAR pcText1[] = "Monitor";
    TESTIE_CHAR pcText2[] = "Shack";

    ASSERT_EQUAL_STRING_ROM(pcText1, pcText2);
}


/**************************************************************************************************
* Desc  : Test with long name that will succeed
**************************************************************************************************/
TEST(Testie_CaseWithExtremelyLongNameWhichIsTotallyAppropriateForThisUniqueAndExcellentTest)
{
    ASSERT_TRUE(true);
}


/**************************************************************************************************
* Desc  : Test will use ASSERT_EQUAL_HEX and succeed
**************************************************************************************************/
TEST(Testie_AssertionHexSuccessful)
{
    ASSERT_EQUAL_HEX(0xAABBCCDD, 0xAABBCCDD);
}


/**************************************************************************************************
* Desc  : Test will use ASSERT_EQUAL_HEX and fail
**************************************************************************************************/
TEST(Testie_AssertionHexFailing)
{
    ASSERT_EQUAL_HEX(0x0A81, 0xF496EB3A);
}


/**************************************************************************************************
* Desc  : Test will use ASSERT_EQUAL_HEX and 0x00 value then fail
**************************************************************************************************/
TEST(Testie_AssertionHexFailingWithValueZero)
{
    ASSERT_EQUAL_HEX(0xFF, 0x00);
}


/**************************************************************************************************
* Desc  : Test will use ASSERT_EQUAL_MEMORY and succeed
**************************************************************************************************/
TEST(Testie_AssertionMemorySuccessful)
{
    TESTIE_UINT8 pvArray1[] = {0x01, 0x02, 0x03};
    TESTIE_UINT8 pvArray2[] = {0x01, 0x02, 0x03};

    ASSERT_EQUAL_MEMORY(pvArray1, pvArray2, 3U);
}


/**************************************************************************************************
* Desc  : Test will use ASSERT_EQUAL_MEMORY and fail
**************************************************************************************************/
TEST(Testie_AssertionMemoryFailing)
{
    TESTIE_UINT8 pvArray1[] = {0x48, 0x65, 0x6C, 0x6C, 0x6F};
    TESTIE_UINT8 pvArray2[] = {0x0F, 0xD1, 0x2E, 0xC3, 0x4B};

    ASSERT_EQUAL_MEMORY(pvArray1, pvArray2, 5U);
}


/**************************************************************************************************
* Desc  : Test will use ASSERT_EQUAL_MEMORY_ROM and succeed
**************************************************************************************************/
TEST(Testie_AssertionMemoryROMSuccessful)
{
    static TESTIE_ROM TESTIE_UINT8 pvArray1[] = {0x01, 0x02, 0x03};
    TESTIE_UINT8 pvArray2[] = {0x01, 0x02, 0x03};

    ASSERT_EQUAL_MEMORY_ROM(pvArray1, pvArray2, 3U);
}


/**************************************************************************************************
* Desc  : Test will use ASSERT_EQUAL_MEMORY_ROM and fail
**************************************************************************************************/
TEST(Testie_AssertionMemoryROMFailing)
{
    static TESTIE_ROM TESTIE_UINT8 pvArray1[] = {0x48, 0x65, 0x6C, 0x6C, 0x6F};
    TESTIE_UINT8 pvArray2[] = {0x0F, 0xD1, 0x2E, 0xC3, 0x4B};

    ASSERT_EQUAL_MEMORY_ROM(pvArray1, pvArray2, 5U);
}


/* Test suites ***********************************************************************************/

/**************************************************************************************************
* Desc  : Test suite that is empty
**************************************************************************************************/
TEST_SUITE(Testie_EmptySuite)
{
}


/**************************************************************************************************
* Desc  : Test suite containing two successful tests
**************************************************************************************************/
TEST_SUITE(Testie_TwoSuccessfulTestSuite)
{
    TEST_RUN(Testie_SuccessfulTest);
    TEST_RUN(Testie_SuccessfulTest);
}


/**************************************************************************************************
* Desc  : Test suite containing three tests where two of them are failing
**************************************************************************************************/
TEST_SUITE(Testie_TwoFailingTestSuite)
{
    TEST_RUN(Testie_FailingTest);
    TEST_RUN(Testie_FailingTest);
    TEST_RUN(Testie_SuccessfulTest);
}


/* End of module *********************************************************************************/

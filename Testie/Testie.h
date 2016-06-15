#ifndef _TESTIE_
#define _TESTIE_

/* Includes **************************************************************************************/

#include "TestieInternals.h"


/* Test declarations *****************************************************************************/

#define TEST(Name)                                          void (Name)(void)
#define TEST_DECLARATION(Name)                              extern void (Name)(void)
#define TEST_RUN(Name)                                      Testie_RunTestCase((Name), #Name)

#define TEST_SUITE(Name)                                    void (Name)(void)
#define TEST_SUITE_DECLARATION(Name)                        extern void (Name)(void)
#define TEST_SUITE_RUN(Name)                                Testie_RunTestSuite((Name), #Name" "TESTIE_OUTPUT_SUITE)


/* Assertion declarations ************************************************************************/

#define ASSERT_TRUE(Actual)                                 Testie_Assert((Actual), TESTIE_OUTPUT_EXPECTED"TRUE"TESTIE_OUTPUT_WAS"FALSE"TESTIE_OUTPUT_END_LINE)
#define ASSERT_FALSE(Actual)                                Testie_Assert(!(Actual), TESTIE_OUTPUT_EXPECTED"FALSE"TESTIE_OUTPUT_WAS"TRUE"TESTIE_OUTPUT_END_LINE)

#define ASSERT_FAIL()                                       Testie_Assert(0U, TESTIE_OUTPUT_ASSERT_FAIL)

#define ASSERT_EQUAL_INT8(Expected, Actual)                 Testie_AssertSignedNumber((TESTIE_INT8) (Expected), (TESTIE_INT8) (Actual))
#define ASSERT_EQUAL_INT16(Expected, Actual)                Testie_AssertSignedNumber((TESTIE_INT16) (Expected), (TESTIE_INT16) (Actual))
#define ASSERT_EQUAL_INT32(Expected, Actual)                Testie_AssertSignedNumber((TESTIE_INT32) (Expected), (TESTIE_INT32) (Actual))
#define ASSERT_EQUAL_INT(Expected, Actual)                  ASSERT_EQUAL_INT32((Expected), (Actual))

#define ASSERT_EQUAL_UINT8(Expected, Actual)                Testie_AssertNumber((TESTIE_UINT8) (Expected), (TESTIE_UINT8) (Actual), 0U)
#define ASSERT_EQUAL_UINT16(Expected, Actual)               Testie_AssertNumber((TESTIE_UINT16) (Expected), (TESTIE_UINT16) (Actual), 0U)
#define ASSERT_EQUAL_UINT32(Expected, Actual)               Testie_AssertNumber((TESTIE_UINT32) (Expected), (TESTIE_UINT32) (Actual), 0U)
#define ASSERT_EQUAL_UINT(Expected, Actual)                 ASSERT_EQUAL_UINT32((Expected), (Actual))

#define ASSERT_EQUAL_HEX(Expected, Actual)                  Testie_AssertNumber((Expected), (Actual), 1U)

#define ASSERT_EQUAL_MEMORY(Expected, Actual, Length)       Testie_AssertMemory((void *) (Expected), (Actual), (Length), 0U)
#define ASSERT_EQUAL_MEMORY_ROM(Expected, Actual, Length)   Testie_AssertMemory((void *) (Expected), (Actual), (Length), 1U)

#define ASSERT_EQUAL_STRING(Expected, Actual)               Testie_AssertString((void *) (Expected), (Actual), 0U)
#define ASSERT_EQUAL_STRING_ROM(Expected, Actual)           Testie_AssertString((void *) (Expected), (Actual), 1U)


/* End of module *********************************************************************************/
#endif

#ifndef _TESTIE_INTERNALS_
#define _TESTIE_INTERNALS_

/* Includes **************************************************************************************/

#if defined(TESTIE_INCLUDE_CONFIG)
#include TESTIE_INCLUDE_CONFIG
#endif


/* Default settings ******************************************************************************/

// Variable settings
#if !defined(TESTIE_INTEGER_VARIABLE_WIDTH)
#define TESTIE_INTEGER_VARIABLE_WIDTH       32U
#endif

// General declaration settings
#if !defined(TESTIE_ROM)
#define TESTIE_ROM
#endif

// String functions
#if !defined(TESTIE_STRING_H_INCLUDE)
#define TESTIE_STRING_H_INCLUDE             <string.h>
#endif

#if !defined(TESTIE_STRING_LENGTH_ROM)
#define TESTIE_STRING_LENGTH_ROM            strlen
#endif

#if !defined(TESTIE_STRING_COMPARE)
#define TESTIE_STRING_COMPARE               strcmp
#endif

#if !defined(TESTIE_STRING_COMPARE_ROM)
#define TESTIE_STRING_COMPARE_ROM           strcmp
#endif

#if !defined(TESTIE_MEMORY_COMPARE)
#define TESTIE_MEMORY_COMPARE               memcmp
#endif

#if !defined(TESTIE_MEMORY_COMPARE_ROM)
#define TESTIE_MEMORY_COMPARE_ROM           memcmp
#endif

// Output functions
#if !defined(TESTIE_OUTPUT_CHAR_INCLUDE)
#define TESTIE_OUTPUT_CHAR_INCLUDE          <stdio.h>
#endif

#if !defined(TESTIE_OUTPUT_CHAR)
#define TESTIE_OUTPUT_CHAR                  putchar
#endif


/* Type definitions ******************************************************************************/

// Variable definitions
#if (TESTIE_INTEGER_VARIABLE_WIDTH == 16U)
typedef          char                       TESTIE_CHAR;
typedef signed   char                       TESTIE_INT8;
typedef signed   int                        TESTIE_INT16;
typedef signed   long                       TESTIE_INT32;
typedef unsigned char                       TESTIE_UINT8;
typedef unsigned int                        TESTIE_UINT16;
typedef unsigned long                       TESTIE_UINT32;
#elif (TESTIE_INTEGER_VARIABLE_WIDTH == 32U)
typedef          char                       TESTIE_CHAR;
typedef signed   char                       TESTIE_INT8;
typedef signed   short                      TESTIE_INT16;
typedef signed   int                        TESTIE_INT32;
typedef unsigned char                       TESTIE_UINT8;
typedef unsigned short                      TESTIE_UINT16;
typedef unsigned int                        TESTIE_UINT32;
#else
#error TESTIE_INTEGER_VARIABLE_WIDTH is not a valid value (16 or 32).
#endif

// Testie variable structure
typedef struct
{
    struct
    {
        TESTIE_UINT8 CurrentFails;
        TESTIE_UINT8 CurrentPasses;
        TESTIE_UINT8 Count;
        TESTIE_UINT8 CountFailed;
        void (*Setup)(void);
        void (*TearDown)(void);
    } Case;
} S_TESTIE;


/* Constants *************************************************************************************/

#define TESTIE_OUTPUT_WIDTH_MAX             79U
#define TESTIE_OUTPUT_CASE_NAME_WIDTH_MAX   74U

#define TESTIE_OUTPUT_FILL_CHARACTER        '-'

#define TESTIE_OUTPUT_END_LINE              "\r\n"

#define TESTIE_OUTPUT_SUITE                 "Test Suite"
#define TESTIE_OUTPUT_TEST_CASES            " Test Cases "
#define TESTIE_OUTPUT_TEST_CASES_FAILED     " Failed"TESTIE_OUTPUT_END_LINE""TESTIE_OUTPUT_END_LINE

#define TESTIE_OUTPUT_CASE_PASS             "PASS"TESTIE_OUTPUT_END_LINE
#define TESTIE_OUTPUT_CASE_FAIL             "FAIL"TESTIE_OUTPUT_END_LINE

#define TESTIE_OUTPUT_EXPECTED              " - Expected "
#define TESTIE_OUTPUT_WAS                   " was "

#define TESTIE_OUTPUT_ASSERT_FAIL           " - Assertion set to fail"TESTIE_OUTPUT_END_LINE


/* Global variables ******************************************************************************/

extern S_TESTIE Testie;


/* Public functions ******************************************************************************/

/**************************************************************************************************
* Desc  : Execute a test suite
*
* Input : TestSuite is a function pointer for the test suite
* Input : pcName is a ROM string with the test suite name
**************************************************************************************************/
void Testie_RunTestSuite(void (*TestSuite)(void), TESTIE_ROM const TESTIE_CHAR * pcName);


/**************************************************************************************************
* Desc  : Execute a test case
*
* Input : Test is a function pointer for the test case
* Input : pcName is a ROM string with the test case name
**************************************************************************************************/
void Testie_RunTestCase(void (*Test)(void), TESTIE_ROM const TESTIE_CHAR * pcName);


/**************************************************************************************************
* Desc  : Test if a condition is true
*
* Input : ui8Condition is a condition which will be checked if it is TRUE
* Input : pcErrorMsg is a custom error message for the condition
**************************************************************************************************/
void Testie_Assert(TESTIE_UINT8 ui8Condition, TESTIE_ROM const TESTIE_CHAR * pcErrorMsg);


/**************************************************************************************************
* Desc  : Test if two numbers are equal
*
* Input : ui32Expected is the expected number
* Input : ui32Actual is the actual number
* Input : ui8IsHex is 1 if expected and actual are hexadecimal else 0
**************************************************************************************************/
void Testie_AssertNumber(TESTIE_UINT32 ui32Expected, TESTIE_UINT32 ui32Actual, TESTIE_UINT8 ui8IsHex);


/**************************************************************************************************
* Desc  : Test if two signed numbers are equal
*
* Input : i32Expected is the expected number
* Input : i32Actual is the actual number
**************************************************************************************************/
void Testie_AssertSignedNumber(TESTIE_INT32 i32Expected, TESTIE_INT32 i32Actual);


/**************************************************************************************************
* Desc  : Test if two strings are equal
*
* Input : pExpected is a void pointer for the expected RAM or ROM string
* Input : pcActual is a pointer for the actual RAM string
* Input : ui8IsExpectedROM is 1 if pExpected is a ROM string else 0
**************************************************************************************************/
void Testie_AssertString(void * pExpected, TESTIE_CHAR * pcActual, TESTIE_UINT8 ui8IsExpectedROM);


/**************************************************************************************************
* Desc  : Test if two memory arrays are equal
*
* Input : pExpected is a void pointer for the expected RAM or ROM array
* Input : pui8Actual is a pointer for the actual RAM string
* Input : ui8IsExpectedROM is 1 if pExpected is a ROM string else 0
**************************************************************************************************/
void Testie_AssertMemory(void * pExpected, TESTIE_UINT8 * pui8Actual, TESTIE_UINT8 ui8Length, TESTIE_UINT8 ui8IsExpectedROM);


/* End of module *********************************************************************************/
#endif

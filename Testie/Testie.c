/* Includes **************************************************************************************/

#include "Testie.h"

#include TESTIE_STRING_H_INCLUDE
#include TESTIE_OUTPUT_CHAR_INCLUDE


/* Global variables ******************************************************************************/

S_TESTIE Testie;


/* Private functions *****************************************************************************/

/**************************************************************************************************
* Desc  : Compare two memory arrays
*
* Input : pArray1 is pointer for a RAM or ROM array
* Input : pArray2 is pointer for a RAM array
* Input : ui8Length is array the length
* Input : ui8IsROM is set to 1 if pArray1 is ROM memory else 0
**************************************************************************************************/
TESTIE_INT8 Testie_MemoryCompare(void * pArray1, void * pArray2, TESTIE_UINT8 ui8Length, TESTIE_UINT8 ui8IsROM)
{
    if (ui8IsROM)
        return TESTIE_MEMORY_COMPARE_ROM((TESTIE_ROM void *) pArray1, pArray2, ui8Length);

    return TESTIE_MEMORY_COMPARE(pArray1, pArray2, ui8Length);
}


/**************************************************************************************************
* Desc  : Compare two strings
*
* Input : pString1 is pointer for a RAM or ROM string
* Input : pString2 is pointer for a RAM string
* Input : ui8IsROM is set to 1 if pString1 is ROM string else 0
**************************************************************************************************/
TESTIE_INT8 Testie_StringCompare(void * pString1, void * pString2, TESTIE_UINT8 ui8IsROM)
{
    if (ui8IsROM)
        return TESTIE_STRING_COMPARE_ROM((TESTIE_ROM TESTIE_CHAR *)pString1, (TESTIE_CHAR *) pString2);

    return TESTIE_STRING_COMPARE((TESTIE_CHAR *) pString1, (TESTIE_CHAR *) pString2);
}


/**************************************************************************************************
* Desc  : Print a string
*
* Input : pcString is a pointer for a string
**************************************************************************************************/
void Testie_PrintString(TESTIE_CHAR * pcString)
{
    for (; *pcString != '\0'; pcString++)
        TESTIE_OUTPUT_CHAR(*pcString);
}


/**************************************************************************************************
* Desc  : Print a string from ROM
*
* Input : pcString is a pointer for a ROM string
**************************************************************************************************/
void Testie_PrintROMString(TESTIE_ROM const TESTIE_CHAR * pcString)
{
    for (; *pcString != '\0'; pcString++)
        TESTIE_OUTPUT_CHAR(*pcString);
}


/**************************************************************************************************
* Desc  : Print a substring starting from left side of a ROM string
*
* Input : pcString is a pointer for a ROM string
* Input : ui8Length is the size of the substring
**************************************************************************************************/
void Testie_PrintROMStringLeft(TESTIE_ROM const TESTIE_CHAR * pcString, TESTIE_UINT8 ui8Length)
{
    for (; (*pcString != '\0') && (ui8Length != 0U); ui8Length--)
        TESTIE_OUTPUT_CHAR(*pcString++);
}


/**************************************************************************************************
* Desc  : Repeatable print of a fill character
*
* Input : cFill is the ASCII fill character
* Input : ui8Length is the amount of the fill character that will be printed
**************************************************************************************************/
void Testie_PrintFill(TESTIE_CHAR cFill, TESTIE_UINT8 ui8Length)
{
    for (; ui8Length != 0; ui8Length--)
        TESTIE_OUTPUT_CHAR(cFill);
}


/**************************************************************************************************
* Desc  : Print a line with fill characters
*
* Input : cFill is the ASCII fill character that will be repeated
**************************************************************************************************/
void Testie_PrintFillLine(TESTIE_CHAR cFill)
{
    Testie_PrintFill(cFill, TESTIE_OUTPUT_WIDTH_MAX);
    Testie_PrintROMString(TESTIE_OUTPUT_END_LINE);
}


/**************************************************************************************************
* Desc  : Print a number
*
* Input : ui32Number is a unsigned number
**************************************************************************************************/
void Testie_PrintNumber(TESTIE_UINT32 ui32Number)
{
    TESTIE_UINT32 ui32Divisor;
    TESTIE_UINT32 ui32TempNumber = ui32Number;

    if (ui32Number == 0)
    {
        TESTIE_OUTPUT_CHAR('0');
        return;
    }

    for (ui32Divisor = 1000000000U; ui32Divisor != 0U; ui32Divisor /= 10U)
    {
        if (ui32Number >= ui32Divisor)
        {
            TESTIE_OUTPUT_CHAR('0' + (TESTIE_CHAR) (ui32TempNumber / ui32Divisor));
            ui32TempNumber %= ui32Divisor;
        }
    }
}


/**************************************************************************************************
* Desc  : Print a number that can be negative
*
* Input : i32Number is a signed number
**************************************************************************************************/
void Testie_PrintSignedNumber(TESTIE_INT32 i32Number)
{
    if (i32Number < 0)
    {
        TESTIE_OUTPUT_CHAR('-');
        i32Number *= -1;
    }
    Testie_PrintNumber((TESTIE_UINT32) i32Number);
}


/**************************************************************************************************
* Desc  : Print a hexadecimal ASCII character
*
* Input : ui8HexValue is a hexadecimal value for the character
**************************************************************************************************/
void Testie_PrintHexCharacter(TESTIE_UINT8 ui8HexValue)
{
    if (ui8HexValue >= 0x0A)
    {
        TESTIE_OUTPUT_CHAR(0x37 + ui8HexValue);
    }
    else
    {
        TESTIE_OUTPUT_CHAR('0' + ui8HexValue);
    }
}


/**************************************************************************************************
* Desc  : Print a hexadecimal number
*
* Input : ui32HexNumber is a hexadecimal value
* Input : ui8LengthMin is the minimum character length of the hexadecimal value
**************************************************************************************************/
void Testie_PrintHexNumber(TESTIE_UINT32 ui32HexNumber, TESTIE_UINT8 ui8LengthMin)
{
    TESTIE_INT8 i8BitShift;

    for (i8BitShift = 28; i8BitShift >= 0; i8BitShift -= 4)
    {
        if (ui32HexNumber >= (TESTIE_UINT32) 1U << i8BitShift || ui8LengthMin > (TESTIE_UINT8) (i8BitShift / 4) )
            Testie_PrintHexCharacter((ui32HexNumber >> i8BitShift) & 0x0F);
    }

    TESTIE_OUTPUT_CHAR('h');
}


/**************************************************************************************************
* Desc  : Print a memory array
*
* Input : pui8Array is the memory array
* Input : ui8Length is the memory  array length
**************************************************************************************************/
void Testie_PrintMemory(TESTIE_UINT8 * pui8Array, TESTIE_UINT8 ui8Length)
{
    TESTIE_UINT8 ui8Index;

    for (ui8Index = 0U; ui8Index < ui8Length; ui8Index++)
    {
        Testie_PrintHexNumber(pui8Array[ui8Index], 2U);
        if (ui8Index != ui8Length - 1U)
            TESTIE_OUTPUT_CHAR(' ');
    }
}


/**************************************************************************************************
* Desc  : Print a ROM memory array
*
* Input : pui8Array is the ROM memory array
* Input : ui8Length is the ROM memory  array length
**************************************************************************************************/
void Testie_PrintROMMemory(TESTIE_ROM const TESTIE_UINT8 * pui8Array, TESTIE_UINT8 ui8Length)
{
    TESTIE_UINT8 ui8Index;

    for (ui8Index = 0U; ui8Index < ui8Length; ui8Index++)
    {
        Testie_PrintHexNumber(pui8Array[ui8Index], 2U);
        if (ui8Index != ui8Length - 1U)
            TESTIE_OUTPUT_CHAR(' ');
    }
}


/* Public functions ******************************************************************************/

/**************************************************************************************************
* Desc  : Execute a test suite
*
* Input : TestSuite is a function pointer for the test suite
* Input : pcName is a ROM string with the test suite name
**************************************************************************************************/
void Testie_RunTestSuite(void (*TestSuite)(void), TESTIE_ROM const TESTIE_CHAR * pcName)
{
    Testie.Case.Count       = 0U;
    Testie.Case.CountFailed = 0U;

    Testie_PrintROMString(pcName);
    Testie_PrintROMString(TESTIE_OUTPUT_END_LINE);
    Testie_PrintFillLine(TESTIE_OUTPUT_FILL_CHARACTER);

    TestSuite();

    Testie_PrintFillLine(TESTIE_OUTPUT_FILL_CHARACTER);

    Testie_PrintNumber(Testie.Case.Count);
    Testie_PrintROMString(TESTIE_OUTPUT_TEST_CASES);
    Testie_PrintNumber(Testie.Case.CountFailed);
    Testie_PrintROMString(TESTIE_OUTPUT_TEST_CASES_FAILED);
}


/**************************************************************************************************
* Desc  : Execute a test case
*
* Input : Test is a function pointer for the test case
* Input : pcName is a ROM string with the test case name
**************************************************************************************************/
void Testie_RunTestCase(void (*Test)(void), TESTIE_ROM const TESTIE_CHAR * pcName)
{
    Testie.Case.Count++;
    Testie.Case.CurrentFails  = 0U;
    Testie.Case.CurrentPasses = 0U;

    Testie.Case.Setup();

    if (TESTIE_STRING_LENGTH_ROM(pcName) < TESTIE_OUTPUT_CASE_NAME_WIDTH_MAX)
    {
        Testie_PrintROMString(pcName);
        Testie_PrintFill('.', TESTIE_OUTPUT_CASE_NAME_WIDTH_MAX - TESTIE_STRING_LENGTH_ROM(pcName));
    }
    else
    {
        Testie_PrintROMStringLeft(pcName, TESTIE_OUTPUT_CASE_NAME_WIDTH_MAX);
    }
    TESTIE_OUTPUT_CHAR(' ');

    Test();

    if (Testie.Case.CurrentPasses >= 1U && Testie.Case.CurrentFails == 0U)
    {
        Testie_PrintROMString(TESTIE_OUTPUT_CASE_PASS);
    }
    else
    {
        Testie.Case.CountFailed++;
    }

    Testie.Case.TearDown();
}


/**************************************************************************************************
* Desc  : Test if a condition is true
*
* Input : ui8Condition is a condition which will be checked if it is TRUE
* Input : pcErrorMsg is a custom error message for the condition
**************************************************************************************************/
void Testie_Assert(TESTIE_UINT8 ui8Condition, TESTIE_ROM const TESTIE_CHAR * pcErrorMsg)
{
    if (ui8Condition == 1U)
    {
        Testie.Case.CurrentPasses++;
    }
    else
    {
        if (Testie.Case.CurrentFails++ == 0)
        {
            Testie_PrintROMString(TESTIE_OUTPUT_CASE_FAIL);
        }

        Testie_PrintROMString(pcErrorMsg);
    }
}


/**************************************************************************************************
* Desc  : Test if two numbers are equal
*
* Input : ui32Expected is the expected number
* Input : ui32Actual is the actual number
* Input : ui8IsHex is 1 if expected and actual are hexadecimal else 0
**************************************************************************************************/
void Testie_AssertNumber(TESTIE_UINT32 ui32Expected, TESTIE_UINT32 ui32Actual, TESTIE_UINT8 ui8IsHex)
{
    if (ui32Expected == ui32Actual)
    {
        Testie.Case.CurrentPasses++;
    }
    else
    {
        if (Testie.Case.CurrentFails++ == 0)
        {
            Testie_PrintROMString(TESTIE_OUTPUT_CASE_FAIL);
        }

        Testie_PrintROMString(TESTIE_OUTPUT_EXPECTED);
        if ( ui8IsHex == 1U)
        {
            Testie_PrintHexNumber(ui32Expected, 1U);
        }
        else
        {
            Testie_PrintNumber(ui32Expected);
        }


        Testie_PrintROMString(TESTIE_OUTPUT_WAS);
        if ( ui8IsHex == 1U)
        {
            Testie_PrintHexNumber(ui32Actual, 1U);
        }
        else
        {
            Testie_PrintNumber(ui32Actual);
        }

        Testie_PrintROMString(TESTIE_OUTPUT_END_LINE);
    }
}


/**************************************************************************************************
* Desc  : Test if two signed numbers are equal
*
* Input : i32Expected is the expected number
* Input : i32Actual is the actual number
**************************************************************************************************/
void Testie_AssertSignedNumber(TESTIE_INT32 i32Expected, TESTIE_INT32 i32Actual)
{
    if (i32Expected == i32Actual)
    {
        Testie.Case.CurrentPasses++;
    }
    else
    {
        if (Testie.Case.CurrentFails++ == 0)
        {
            Testie_PrintROMString(TESTIE_OUTPUT_CASE_FAIL);
        }

        Testie_PrintROMString(TESTIE_OUTPUT_EXPECTED);
        Testie_PrintSignedNumber(i32Expected);
        Testie_PrintROMString(TESTIE_OUTPUT_WAS);
        Testie_PrintSignedNumber(i32Actual);
        Testie_PrintROMString(TESTIE_OUTPUT_END_LINE);
    }
}


/**************************************************************************************************
* Desc  : Test if two strings are equal
*
* Input : pExpected is a void pointer for the expected RAM or ROM string
* Input : pcActual is a pointer for the actual RAM string
* Input : ui8IsExpectedROM is 1 if pExpected is a ROM string else 0
**************************************************************************************************/
void Testie_AssertString(void * pExpected, TESTIE_CHAR * pcActual, TESTIE_UINT8 ui8IsExpectedROM)
{
    if (Testie_StringCompare(pExpected, (void *) pcActual, ui8IsExpectedROM) == 0)
    {
        Testie.Case.CurrentPasses++;
    }
    else
    {
        if (Testie.Case.CurrentFails++ == 0)
        {
            Testie_PrintROMString(TESTIE_OUTPUT_CASE_FAIL);
        }

        Testie_PrintROMString(TESTIE_OUTPUT_EXPECTED"\"");
        if (ui8IsExpectedROM)
        {
            Testie_PrintROMString((TESTIE_ROM TESTIE_CHAR *) pExpected);
        }
        else
        {
            Testie_PrintString((TESTIE_CHAR *) pExpected);
        }
        Testie_PrintROMString("\""TESTIE_OUTPUT_WAS"\"");
        Testie_PrintString(pcActual);
        Testie_PrintROMString("\""TESTIE_OUTPUT_END_LINE);
    }
}


/**************************************************************************************************
* Desc  : Test if two memory arrays are equal
*
* Input : pExpected is a void pointer for the expected RAM or ROM array
* Input : pui8Actual is a pointer for the actual RAM string
* Input : ui8IsExpectedROM is 1 if pExpected is a ROM string else 0
**************************************************************************************************/
void Testie_AssertMemory(void * pExpected, TESTIE_UINT8 * pui8Actual, TESTIE_UINT8 ui8Length, TESTIE_UINT8 ui8IsExpectedROM)
{
    if (Testie_MemoryCompare(pExpected, (void *) pui8Actual, ui8Length, ui8IsExpectedROM) == 0)
    {
        Testie.Case.CurrentPasses++;
    }
    else
    {
        if (Testie.Case.CurrentFails++ == 0)
        {
            Testie_PrintROMString(TESTIE_OUTPUT_CASE_FAIL);
        }

        Testie_PrintROMString(TESTIE_OUTPUT_EXPECTED"\"");
        if (ui8IsExpectedROM)
        {
            Testie_PrintROMMemory((TESTIE_ROM TESTIE_UINT8 *) pExpected, ui8Length);
        }
        else
        {
            Testie_PrintMemory((TESTIE_UINT8 *) pExpected, ui8Length);
        }
        Testie_PrintROMString("\""TESTIE_OUTPUT_WAS"\"");
        Testie_PrintMemory(pui8Actual, ui8Length);
        Testie_PrintROMString("\""TESTIE_OUTPUT_END_LINE);
    }
}


/* End of module *********************************************************************************/

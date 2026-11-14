/**************************************************************************************************
* Configuration template for the Unit Test framework named Testie.
* Create a custom configuration by copy, edit and include this file with TESTIE_INCLUDE_CONFIG.
**************************************************************************************************/

#ifndef _TESTIE_CONFIG_TEMPLATE_
#define _TESTIE_CONFIG_TEMPLATE_

/* Settings - Variables **************************************************************************/

/**************************************************************************************************
* Name  : TESTIE_INTEGER_VARIABLE_WIDTH (default 32)
*
* Desc  : Setup bit width for int variable for the compiler. Values 16 or 32.
**************************************************************************************************/
//#define TESTIE_INTEGER_VARIABLE_WIDTH


/* Settings - General declarations ***************************************************************/

/**************************************************************************************************
* Name  : TESTIE_ROM (default nothing)
*
* Desc  : Required definition for some compilers
**************************************************************************************************/
//#define TESTIE_ROM                                 


/* Settings - String manipulation ****************************************************************/

/**************************************************************************************************
* Name  : TESTIE_STRING_H_INCLUDE (default string.h)
*
* Desc  : Include the compiler specific string.h file
**************************************************************************************************/
//#define TESTIE_STRING_H_INCLUDE

/**************************************************************************************************
* Name  : TESTIE_STRING_LENGTH_ROM (default strlen)
*
* Desc  : Function to find the length of a ROM string
*
* Input : A ROM CONST pointer to a string
**************************************************************************************************/
//#define TESTIE_STRING_LENGTH_ROM


/**************************************************************************************************
* Name  : TESTIE_STRING_COMPARE (default strcmp)
*
* Desc  : Function to compare two strings
*
* Input : A pointer to string 1
* Input : A pointer to string 2
**************************************************************************************************/
//#define TESTIE_STRING_COMPARE


/**************************************************************************************************
* Name  : TESTIE_STRING_COMPARE_ROM (default strcmp)
*
* Desc  : Function to compare a ROM string and a RAM string
*
* Input : A ROM CONST pointer to string 1
* Input : A pointer to string 2
**************************************************************************************************/
//#define TESTIE_STRING_COMPARE_ROM


/**************************************************************************************************
* Name  : TESTIE_MEMORY_COMPARE (default memcmp)
*
* Desc  : Function to compare two arrays
*
* Input : A pointer to array 1
* Input : A pointer to array 2
* Input : Length of the arrays for comparision
**************************************************************************************************/
//#define TESTIE_MEMORY_COMPARE


/**************************************************************************************************
* Name  : TESTIE_MEMORY_COMPARE_ROM (default memcmp)
*
* Desc  : Function to compare a ROM array and a RAM array
*
* Input : A ROM CONST pointer to array 1
* Input : A pointer to array 2
* Input : Length of the arrays for comparision
**************************************************************************************************/
//#define TESTIE_MEMORY_COMPARE_ROM


/* Settings - Output *****************************************************************************/

/**************************************************************************************************
* Name  : TESTIE_OUTPUT_CHAR_INCLUDE (default stdio.h)
*
* Desc  : Include a .h file if needed by output char function else uncomment
**************************************************************************************************/
//#define TESTIE_OUTPUT_CHAR_INCLUDE

/**************************************************************************************************
* Name  : TESTIE_OUTPUT_CHAR (default putchar)
*
* Desc  : Function to output one character
*
* Input : A 7bit ASCII character
**************************************************************************************************/
//#define TESTIE_OUTPUT_CHAR


/* End of module *********************************************************************************/
#endif

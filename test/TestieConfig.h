/**************************************************************************************************
* Special configuration for self test of the Unit Test framework named Testie.
**************************************************************************************************/

#ifndef _SELFTEST_CONFIG_
#define _SELFTEST_CONFIG_

/* Settings - Output *****************************************************************************/

/**************************************************************************************************
* Name  : TESTIE_OUTPUT_CHAR_INCLUDE (default stdio.h)
*
* Desc  : Include a .h file if needed by output char function else uncomment
**************************************************************************************************/
#define TESTIE_OUTPUT_CHAR_INCLUDE          "OutputFake.h"


/**************************************************************************************************
* Name  : TESTIE_OUTPUT_CHAR (default putchar)
*
* Desc  : Function to output one character
*
* Input : A 7bit ASCII character
**************************************************************************************************/
#define TESTIE_OUTPUT_CHAR                  Output_Character


/* End of module *********************************************************************************/
#endif

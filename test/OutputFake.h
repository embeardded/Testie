/**************************************************************************************************
* Modified output with buffer for self test of the Testie framework
**************************************************************************************************/

#ifndef _SELFTEST_OUTPUT_
#define _SELFTEST_OUTPUT_

/* Includes **************************************************************************************/

#include "Testie.h"


/* Constants *************************************************************************************/

#define OUTPUT_BUFFER_LINES                 9U
#define OUTPUT_BUFFER_WIDTH                 (TESTIE_OUTPUT_WIDTH_MAX + 2U)


/* Type definitions ******************************************************************************/ 

typedef struct
{
    struct
    {
        TESTIE_UINT8 Enabled;
        TESTIE_CHAR  Line[OUTPUT_BUFFER_LINES][OUTPUT_BUFFER_WIDTH];
    } Buffer;
} S_OUTPUT;


/* Global Variables ******************************************************************************/

extern S_OUTPUT Output;


/* Public functions ******************************************************************************/

/**************************************************************************************************
* Desc  : Clear all characters in the output buffer. A cleared character is " ".
**************************************************************************************************/
void Output_ClearBuffer(void);


/**************************************************************************************************
* Desc  : Send a character to output or buffer if it is enabled
*
* Input : cCharacter is the ASCII character
**************************************************************************************************/
void Output_Character(TESTIE_CHAR cCharacter);


/* End of module *********************************************************************************/ 
#endif

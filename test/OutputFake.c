/**************************************************************************************************
* Modified output with buffer for self test of the Testie framework
**************************************************************************************************/

/* Includes **************************************************************************************/

#include "Debug.h"

#include "OutputFake.h"

#include <string.h>


/* Global variables ******************************************************************************/

#if defined(__18CXX)
#pragma udata big_udata
#endif
S_OUTPUT Output;
#if defined(__18CXX)
#pragma udata
#endif

UINT8 vOutputLineNo;
UINT8 vOutputWidthNo;


/* Public functions ******************************************************************************/

/**************************************************************************************************
* Desc  : Clear all characters in the output buffer. A cleared character is " ".
**************************************************************************************************/
VOID Output_ClearBuffer(VOID)
{
    UINT8 vLineNo;

    vOutputLineNo  = 0U;
    vOutputWidthNo = 0U;

    for (vLineNo = 0; vLineNo < OUTPUT_BUFFER_LINES; vLineNo++)
    {
        memset(Output.Buffer.Line[vLineNo], ' ', OUTPUT_BUFFER_WIDTH - 1U);
        Output.Buffer.Line[vLineNo][OUTPUT_BUFFER_WIDTH - 1U] = '\0';
    }
}


/**************************************************************************************************
* Desc  : Send a character to output or buffer if it is enabled
*
* Input : cCharacter is the ASCII character
**************************************************************************************************/
VOID Output_Character(CHAR cCharacter)
{
    if (Output.Buffer.Enabled == 1U)
    {
        // Increase line number if character is line break
        if (cCharacter == '\n')
        {
            vOutputLineNo++;
            vOutputWidthNo = 0U;
        }
        else if (cCharacter != '\r')
        {
            // Write output to buffer
            Output.Buffer.Line[vOutputLineNo][vOutputWidthNo++] = cCharacter;
        }
    }
    else
    {
        // Write output
        Debug_OutputChar(cCharacter);
    }
}


/* End of module *********************************************************************************/

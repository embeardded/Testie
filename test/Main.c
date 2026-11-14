/**************************************************************************************************
* Main module for the Testie framework to show the architecture and examples
**************************************************************************************************/

/* Includes **************************************************************************************/

#include "Compiler.h"
#include "Testie.h"


/* Test suite declarations ***********************************************************************/

TEST_SUITE_DECLARATION(Testie_Self);
EXTERN VOID Testie_Setup(VOID);
EXTERN VOID Testie_TearDown(VOID);


/* Main function *********************************************************************************/

/**************************************************************************************************
* Desc  : Main function for Testie self tests
**************************************************************************************************/
MAIN()
{
    Testie.Case.Setup    = Testie_Setup;
    Testie.Case.TearDown = Testie_TearDown;
    TEST_SUITE_RUN(Testie_Self);

    MAIN_RETURN();
}


/* End of module *********************************************************************************/
/**************************************************************************************************
* Main module for the Testie framework to show the architecture and examples
**************************************************************************************************/

/* Includes **************************************************************************************/

#include "Testie.h"


/* Test suite declarations ***********************************************************************/

TEST_SUITE_DECLARATION(Testie_Self);
extern void Testie_Setup(void);
extern void Testie_TearDown(void);


/* Main function *********************************************************************************/

/**************************************************************************************************
* Desc  : Main function for Testie self tests
**************************************************************************************************/
int main(void)
{
    Testie.Case.Setup    = Testie_Setup;
    Testie.Case.TearDown = Testie_TearDown;
    TEST_SUITE_RUN(Testie_Self);

    return 0;
}


/* End of module *********************************************************************************/
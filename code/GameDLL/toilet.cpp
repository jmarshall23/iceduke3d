#include "gamedll.h"

static ConAction *TOILETWATERFRAMES = new ConAction(0, 4, 1, 1, 1);
void A_TOILETWATER()
{
    ifpdistl(8192)
    {
        imports->soundonce(WATER_GURGLE);
        ifspawnedby(TOILET)
            imports->sizeto(34, 34);
        else
        {
            ifspawnedby(WATERFOUNTAINBROKE)
                imports->sizeto(6, 15);
            else
                ifspawnedby(TOILETWATER)
                {
                }
                else
                    imports->sizeto(24, 32);
        }
        ifp(palive)
            ifpdistl(RETRIEVEDISTANCE)
                ifp(pfacing)
                    ifactioncount(32)
                        ifphealthl(MAXPLAYERHEALTH)
                            ifhitspace()
                                ifcansee()
                                {
                                    imports->addphealth(1);
                                    imports->globalsound(DUKE_DRINKING);
                                    imports->resetactioncount();
                                }
    }
}
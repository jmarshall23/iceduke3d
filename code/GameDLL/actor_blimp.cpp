// actor_blimp.cpp
//

#include "gamedll.h"

static ConAction *BLIMPWAITTORESPAWN = new ConAction();

void blimphitstate()
{
    imports->cstat(0);
    imports->spawn(FIRSTGUNSPRITE);
    imports->spawn(EXPLOSION2);
    imports->debris(SCRAP1, 40);
    imports->debris(SCRAP2, 32);
    imports->debris(SCRAP3, 32);
    imports->debris(SCRAP4, 32);
    imports->debris(SCRAP5, 32);
    imports->sound(PIPEBOMB_EXPLODE);
    ifrespawn()
    {
        imports->SetAction(BLIMPWAITTORESPAWN);
        imports->count(0);
        imports->cstat(32768);
    }
    else
        imports->killit();
}

void A_BLIMP()
{
    ifaction(BLIMPWAITTORESPAWN)
    {
        ifcount(BLIMPRESPAWNTIME)
        {
            imports->SetAction(NULL);
            imports->cstat(0);
        }
        return;
    }
    ifhitweapon()
    {
        ifwasweapon(RADIUSEXPLOSION)
            blimphitstate();
        ifwasweapon(RPG)
            blimphitstate();
        imports->strength(1);
    }
}
// gibs.cpp
//

#include "gamedll.h"

void standard_pjibs()
{
    imports->guts(JIBS1, 1);
    imports->guts(JIBS3, 2);
    imports->guts(JIBS4, 1);
    imports->guts(JIBS5, 1);
    imports->guts(JIBS6, 2);
    imports->guts(DUKETORSO, 1);
    imports->guts(DUKELEG, 2);
    imports->guts(DUKEGUN, 1);
    ifrnd(16)
        imports->money(1);
}

void random_wall_jibs()
{
    ifrnd(96)
        imports->shoot(BLOODSPLAT1);
    ifrnd(96)
        imports->shoot(BLOODSPLAT2);
    ifrnd(96)
        imports->shoot(BLOODSPLAT3);
    ifrnd(96)
        imports->shoot(BLOODSPLAT4);
    ifrnd(96)
        imports->shoot(BLOODSPLAT1);
}

void troop_body_jibs()
{
    ifrnd(64)
        imports->guts(HEADJIB1, 1);
    ifrnd(64)
        imports->guts(LEGJIB1, 2);
    ifrnd(64)
        imports->guts(ARMJIB1, 1);
    ifrnd(48)
        imports->spawn(BLOODPOOL);
}
void liz_body_jibs()
{
    ifrnd(64)
        imports->guts(LIZMANHEAD1, 1);
    ifrnd(64)
        imports->guts(LIZMANLEG1, 2);
    ifrnd(64)
        imports->guts(LIZMANARM1, 1);
    ifrnd(48)
        imports->spawn(BLOODPOOL);
}
static ConAction *BLOODFRAMES = new ConAction(0, 4, 1, 1, 15);
void A_BLOOD()
{
    imports->sizeto(72, 72);
    imports->sizeto(72, 72);
    imports->sizeto(72, 72);
    ifpdistg(3144)
        imports->killit();
    ifactioncount(4)
        imports->killit();
}
void jibfood()
{
    imports->sound(SQUISHED);
    imports->guts(JIBS6, 3);
    imports->killit();
}

void jib_sounds()
{
    ifrnd(SWEARFREQUENCY)
    {
        ifrnd(128)
        {
            ifrnd(128)
            {
                ifrnd(128)
                {
                    ifrnd(128)
                    {
                        ifrnd(128)
                            imports->globalsound(JIBBED_ACTOR12);
                        else
                            imports->globalsound(JIBBED_ACTOR1);
                    }
                    else
                    {
                        ifrnd(128)
                            imports->globalsound(JIBBED_ACTOR9);
                        else
                            imports->globalsound(JIBBED_ACTOR14);
                    }
                }
                else
                {
                    ifrnd(128)
                        imports->globalsound(SMACKED);
                    else
                        imports->globalsound(JIBBED_ACTOR2);
                }
            }
            else
            {
                ifrnd(128)
                    imports->globalsound(MDEVSPEECH);
                else
                    imports->globalsound(JIBBED_ACTOR5);
            }
        }
        else
        {
            ifrnd(128)
            {
                ifrnd(128)
                {
                    ifrnd(128)
                        imports->globalsound(JIBBED_ACTOR11);
                    else
                        imports->globalsound(JIBBED_ACTOR13);
                }
                else
                {
                    ifrnd(128)
                        imports->globalsound(JIBBED_ACTOR3);
                    else
                        imports->globalsound(JIBBED_ACTOR8);
                }
            }
            else
            {
                ifrnd(128)
                {
                    ifrnd(128)
                        imports->globalsound(JIBBED_ACTOR6);
                    else
                        imports->globalsound(JIBBED_ACTOR4);
                }
                else
                {
                    ifrnd(128)
                    {
                        ifrnd(128)
                            imports->globalsound(JIBBED_ACTOR10);
                        else
                            imports->globalsound(JIBBED_ACTOR15);
                    }
                    else
                        imports->globalsound(JIBBED_ACTOR7);
                }
            }
        }
    }
}
void standard_jibs()
{
    imports->guts(JIBS2, 1);
    imports->guts(JIBS3, 2);
    imports->guts(JIBS4, 3);
    imports->guts(JIBS5, 2);
    imports->guts(JIBS6, 3);
    ifrnd(6)
    {
        imports->guts(JIBS1, 1);
        imports->spawn(BLOODPOOL);
    }
    jib_sounds();
}
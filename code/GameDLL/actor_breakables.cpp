#include "gamedll.h"

void breakobject()
{
    ifaction(NULL)
    {
        imports->SetAction(ANULLACTION);
        imports->cstator(257);
        ifactor(ROBOTMOUSE)
            imports->clipdist(64);
    }
    else
        ifactor(ROBOTMOUSE)
        {
            ifdead()
            {
                ifcount(32)
                {
                    imports->globalsound(MOUSEANNOY);
                    imports->killit();
                }
                return;
            }
            ifcount(64)
                ifrnd(6)
                {
                    ifrnd(128)
                        imports->Move(MOUSEVELS, randomangle, geth, 0);
                    else
                    {
                        ifrnd(64)
                            imports->soundonce(HAPPYMOUSESND1);
                        else
                            ifrnd(64)
                                imports->soundonce(HAPPYMOUSESND2);
                            else
                                ifrnd(64)
                                    imports->soundonce(HAPPYMOUSESND3);
                                else
                                    imports->soundonce(HAPPYMOUSESND4);
                    }
                    imports->resetcount();
                }
        }
    ifhitweapon()
    {
        ifdead()
        {
            ifactor(FOODOBJECT6)
                jibfood();
            else
                ifactor(FOODOBJECT11)
                    jibfood();
                else
                    ifactor(FOODOBJECT12)
                        jibfood();
                    else
                        ifactor(FOODOBJECT13)
                            jibfood();
                        else
                            ifactor(FOODOBJECT14)
                                jibfood();
                            else
                                ifactor(FOODOBJECT15)
                                    jibfood();
                                else
                                    ifactor(FOODOBJECT16)
                                        jibfood();
                                    else
                                        ifactor(FOODOBJECT17)
                                            jibfood();
                                        else
                                            ifactor(SKINNEDCHICKEN)
                                                jibfood();
                                            else
                                                ifactor(SHOPPINGCART)
                                                {
                                                    imports->debris(SCRAP1, 5);
                                                    imports->debris(SCRAP2, 5);
                                                    imports->debris(SCRAP3, 5);
                                                    imports->sound(GLASS_HEAVYBREAK);
                                                    imports->killit();
                                                }
                                                else
                                                    ifactor(ROBOTDOG2)
                                                    {
                                                        imports->soundonce(DEAD_DOG);
                                                        imports->guts(JIBS2, 1);
                                                        imports->guts(JIBS3, 2);
                                                        imports->guts(JIBS6, 3);
                                                        imports->killit();
                                                    }
                                                    else
                                                        ifactor(FEATHEREDCHICKEN)
                                                            jibfood();
                                                        else
                                                            ifactor(DOLPHIN1)
                                                            {
                                                                imports->guts(JIBS2, 1);
                                                                imports->guts(JIBS3, 2);
                                                                imports->guts(JIBS4, 3);
                                                                imports->guts(JIBS5, 2);
                                                                jibfood();
                                                            }
                                                            else
                                                                ifactor(DOLPHIN2)
                                                                {
                                                                    imports->guts(JIBS2, 1);
                                                                    imports->guts(JIBS3, 2);
                                                                    imports->guts(JIBS4, 3);
                                                                    imports->guts(JIBS5, 2);
                                                                    jibfood();
                                                                }
                                                                else
                                                                    ifactor(SNAKEP)
                                                                    {
                                                                        imports->guts(JIBS2, 1);
                                                                        imports->guts(JIBS3, 2);
                                                                        imports->guts(JIBS4, 3);
                                                                        imports->guts(JIBS5, 2);
                                                                        jibfood();
                                                                    }
                                                                    else
                                                                        ifactor(DONUTS)
                                                                        {
                                                                            imports->spritepal(7);
                                                                            imports->guts(JIBS6, 2);
                                                                            imports->killit();
                                                                        }
                                                                        else
                                                                            ifactor(DONUTS2)
                                                                            {
                                                                                imports->debris(SCRAP1, 1);
                                                                                imports->spritepal(7);
                                                                                imports->guts(JIBS6, 2);
                                                                                imports->killit();
                                                                            }
                                                                            else
                                                                                ifactor(MAILBAG)
                                                                                {
                                                                                    imports->mail(30);
                                                                                    imports->debris(SCRAP3, 5);
                                                                                    imports->debris(SCRAP4, 3);
                                                                                    imports->killit();
                                                                                }
                                                                                else
                                                                                    ifactor(TEDDYBEAR)
                                                                                    {
                                                                                        imports->debris(SCRAP3, 5);
                                                                                        imports->spritepal(1);
                                                                                        imports->debris(SCRAP3, 6);
                                                                                    }
                                                                                    else
                                                                                    {
                                                                                        ifrnd(128)
                                                                                            imports->sound(GLASS_BREAKING);
                                                                                        else
                                                                                            imports->sound(GLASS_HEAVYBREAK);
                                                                                    }
            ifactor(CLOCK)
            {
                imports->cactor(BROKENCLOCK);
                return;
            }
            else
                ifactor(JOLLYMEAL)
                {
                    imports->spawn(ATOMICHEALTH);
                    imports->debris(SCRAP3, 1);
                    imports->debris(SCRAP4, 2);
                }
                else
                    ifactor(GUMBALLMACHINE)
                    {
                        imports->cactor(GUMBALLMACHINEBROKE);
                        imports->strength(1);
                        imports->debris(SCRAP4, 2);
                        imports->lotsofglass(10);
                        return;
                    }
                    else
                        ifactor(GUMBALLMACHINEBROKE)
                        {
                            imports->debris(SCRAP3, 3);
                            imports->debris(SCRAP4, 2);
                            imports->lotsofglass(10);
                        }
                        else
                            ifactor(DUKEBURGER)
                            {
                                imports->debris(SCRAP3, 14);
                                imports->debris(SCRAP1, 13);
                                imports->debris(SCRAP4, 12);
                                imports->debris(SCRAP2, 12);
                                imports->debris(SCRAP5, 11);
                            }
                            else
                                ifactor(POLICELIGHTPOLE)
                                {
                                    imports->debris(SCRAP3, 4);
                                    imports->debris(SCRAP1, 3);
                                    imports->debris(SCRAP4, 2);
                                    imports->debris(SCRAP2, 2);
                                    imports->debris(SCRAP5, 1);
                                }
                                else
                                    ifactor(TOPSECRET)
                                        imports->paper(10);
                                    else
                                        ifactor(GUNPOWDERBARREL)
                                        {
                                            imports->spawn(EXPLOSION2);
                                            imports->sound(PIPEBOMB_EXPLODE);
                                            imports->hitradius(2048, WEAKEST, WEAK, MEDIUMSTRENGTH, TOUGH);
                                            ifpdistl(2048)
                                                imports->wackplayer();
                                            imports->debris(SCRAP1, 10);
                                            imports->debris(SCRAP2, 13);
                                            imports->debris(SCRAP3, 4);
                                            imports->debris(SCRAP4, 17);
                                            imports->debris(SCRAP5, 6);
                                        }
                                        else
                                            ifactor(FLOORBASKET)
                                            {
                                                imports->spawn(PUKE);
                                                imports->debris(SCRAP1, 2);
                                                imports->debris(SCRAP3, 3);
                                                imports->debris(SCRAP4, 2);
                                            }
                                            else
                                                ifactor(ROBOTMOUSE)
                                                {
                                                    imports->debris(SCRAP2, 10);
                                                    imports->spritepal(1);
                                                    imports->debris(SCRAP3, 4);
                                                    imports->resetcount();
                                                    imports->cstat(32768);
                                                    return;
                                                }
                                                else
                                                    ifactor(ROBOTPIRATE)
                                                    {
                                                        imports->debris(SCRAP2, 10);
                                                        imports->debris(SCRAP1, 5);
                                                        imports->debris(SCRAP3, 3);
                                                        imports->lotsofglass(10);
                                                    }
                                                    else
                                                        ifactor(PIRATE1A)
                                                        {
                                                            imports->debris(SCRAP2, 10);
                                                            imports->debris(SCRAP1, 5);
                                                            imports->debris(SCRAP3, 3);
                                                            imports->lotsofglass(10);
                                                        }
                                                        else
                                                            ifactor(MAN)
                                                            {
                                                                imports->debris(SCRAP2, 10);
                                                                imports->debris(SCRAP1, 5);
                                                                imports->debris(SCRAP3, 3);
                                                                imports->lotsofglass(10);
                                                            }
                                                            else
                                                                ifactor(MAN2)
                                                                {
                                                                    imports->debris(SCRAP2, 10);
                                                                    imports->debris(SCRAP1, 5);
                                                                    imports->debris(SCRAP3, 3);
                                                                    imports->lotsofglass(10);
                                                                }
                                                                else
                                                                    ifactor(PIRATE2A)
                                                                    {
                                                                        imports->debris(SCRAP2, 10);
                                                                        imports->debris(SCRAP1, 5);
                                                                        imports->debris(SCRAP3, 3);
                                                                        imports->lotsofglass(10);
                                                                    }
                                                                    else
                                                                        ifactor(PIRATE3A)
                                                                        {
                                                                            imports->debris(SCRAP2, 10);
                                                                            imports->debris(SCRAP1, 5);
                                                                            imports->debris(SCRAP3, 3);
                                                                            imports->lotsofglass(10);
                                                                        }
                                                                        else
                                                                            ifactor(PIRATE4A)
                                                                            {
                                                                                imports->debris(SCRAP2, 10);
                                                                                imports->debris(SCRAP1, 5);
                                                                                imports->debris(SCRAP3, 3);
                                                                                imports->lotsofglass(10);
                                                                            }
                                                                            else
                                                                                ifactor(PIRATE4A)
                                                                                {
                                                                                    imports->debris(SCRAP2, 10);
                                                                                    imports->debris(SCRAP1, 5);
                                                                                    imports->debris(SCRAP3, 3);
                                                                                    imports->lotsofglass(10);
                                                                                }
                                                                                else
                                                                                    ifactor(PIRATE5A)
                                                                                    {
                                                                                        imports->debris(SCRAP2, 10);
                                                                                        imports->debris(SCRAP1, 5);
                                                                                        imports->debris(SCRAP3, 3);
                                                                                        imports->lotsofglass(10);
                                                                                    }
                                                                                    else
                                                                                        ifactor(PIRATE6A)
                                                                                        {
                                                                                            imports->debris(SCRAP2, 10);
                                                                                            imports->debris(SCRAP1, 5);
                                                                                            imports->debris(SCRAP3, 3);
                                                                                            imports->lotsofglass(10);
                                                                                        }
                                                                                        else
                                                                                        {
                                                                                            imports->lotsofglass(10);
                                                                                            imports->debris(SCRAP4, 3);
                                                                                        }
            imports->killit();
        }
        else
            ifactor(DOLPHIN1)
            {
                imports->guts(JIBS6, 1);
                imports->soundonce(DOLPHINSND);
                ifstrength(TOUGH)
                {
                    imports->cactor(DOLPHIN2);
                    imports->sound(SQUISHED);
                }
            }
            else
                ifactor(DOLPHIN2)
                {
                    imports->guts(JIBS6, 1);
                    imports->soundonce(DOLPHINSND);
                }
                else
                    ifactor(ROBOTDOG2)
                    {
                        imports->guts(JIBS6, 1);
                        imports->soundonce(WHINING_DOG);
                    }
    }
    else
    {
        ifactor(CLOCK)
        {
        }
        else
            ifactor(TOPSECRET)
            {
            }
            else
                ifactor(SKINNEDCHICKEN)
                {
                }
                else
                    ifactor(FEATHEREDCHICKEN)
                    {
                    }
                    else
                        ifactor(FOODOBJECT2)
                        {
                        }
                        else
                            ifactor(FOODOBJECT6)
                            {
                            }
                            else
                                ifactor(DOLPHIN1)
                                {
                                }
                                else
                                    ifactor(DOLPHIN2)
                                    {
                                    }
                                    else
                                        imports->fall();
    }
}

static ConAction *ABURGERROTS = new ConAction(0, 1, 5);
void A_DUKEBURGER()
{
    breakobject();
}
void A_MOP()
{
    breakobject();
}
void A_BROOM()
{
    breakobject();
}
void A_WETFLOOR()
{
    breakobject();
}
void A_DESKLAMP()
{
    breakobject();
}
void A_HATRACK()
{
    breakobject();
}
void A_GUNPOWDERBARREL()
{
    breakobject();
}
void A_COFFEEMACHINE()
{
    breakobject();
}
void A_TEDDYBEAR()
{
    breakobject();
}
void A_TOPSECRET()
{
    breakobject();
}
void A_ROBOTMOUSE()
{
    breakobject();
}
void A_MAN()
{
    breakobject();
}
void A_MAN2()
{
    breakobject();
}
void A_WOMAN()
{
    breakobject();
}
void A_PIRATE1A()
{
    breakobject();
}
void A_PIRATE2A()
{
    breakobject();
}
void A_PIRATE3A()
{
    breakobject();
}
void A_PIRATE4A()
{
    breakobject();
}
void A_PIRATE5A()
{
    breakobject();
}
void A_PIRATE6A()
{
    breakobject();
}
void A_ROBOTPIRATE()
{
    breakobject();
}
void A_PIRATEHALF()
{
    breakobject();
}
void A_CHESTOFGOLD()
{
    breakobject();
}
void A_ROBOTDOG()
{
    breakobject();
}
void A_ROBOTDOG2()
{
    breakobject();
}
void A_PLEASEWAIT()
{
    breakobject();
}
void A_FOODOBJECT1()
{
    breakobject();
}
void A_FOODOBJECT2()
{
    breakobject();
}
void A_FOODOBJECT3()
{
    breakobject();
}
void A_FOODOBJECT4()
{
    breakobject();
}
void A_FOODOBJECT5()
{
    breakobject();
}
void A_FOODOBJECT6()
{
    breakobject();
}
void A_FOODOBJECT7()
{
    breakobject();
}
void A_FOODOBJECT8()
{
    breakobject();
}
void A_FOODOBJECT9()
{
    breakobject();
}
void A_FOODOBJECT10()
{
    breakobject();
}
void A_FOODOBJECT11()
{
    breakobject();
}
void A_FOODOBJECT12()
{
    breakobject();
}
void A_FOODOBJECT13()
{
    breakobject();
}
void A_FOODOBJECT14()
{
    breakobject();
}
void A_FOODOBJECT15()
{
    breakobject();
}
void A_FOODOBJECT16()
{
    breakobject();
}
void A_FOODOBJECT17()
{
    breakobject();
}
void A_FOODOBJECT18()
{
    breakobject();
}
void A_FOODOBJECT19()
{
    breakobject();
}
void A_FOODOBJECT20()
{
    breakobject();
}
void A_JOLLYMEAL()
{
    breakobject();
}
void A_GUMBALLMACHINE()
{
    breakobject();
}
void A_GUMBALLMACHINEBROKE()
{
    breakobject();
}
void A_POLICELIGHTPOLE()
{
    breakobject();
}
void A_CLOCK()
{
    breakobject();
}
void A_MAILBAG()
{
    breakobject();
}
void A_FEATHEREDCHICKEN()
{
    breakobject();
}
void A_SKINNEDCHICKEN()
{
    breakobject();
}
void A_HEADLAMP()
{
    breakobject();
}
void A_DOLPHIN1()
{
    breakobject();
}
void A_DOLPHIN2()
{
    breakobject();
}
void A_SNAKEP()
{
    breakobject();
}
void A_DONUTS()
{
    breakobject();
}
void A_GAVALS()
{
    breakobject();
}
void A_GAVALS2()
{
    breakobject();
}
void A_CUPS()
{
    breakobject();
}
void A_DONUTS2()
{
    breakobject();
}
void A_FLOORBASKET()
{
    breakobject();
}
void A_METER()
{
    breakobject();
}
void A_DESKPHONE()
{
    breakobject();
}
void A_MACE()
{
    breakobject();
}
void A_SHOPPINGCART()
{
    breakobject();
}
void A_COFFEEMUG()
{
    breakobject();
}
#include "gamedll.h"

void toughgalspeech()
{
    ifrnd(64)
    {
        ifnosounds()
            imports->soundonce(TOUGHGALSND1);
    }
    else
        ifrnd(64)
        {
            ifnosounds()
                imports->soundonce(TOUGHGALSND2);
        }
        else
            ifrnd(64)
            {
                ifnosounds()
                    imports->soundonce(TOUGHGALSND3);
            }
            else
                ifnosounds()
                    imports->soundonce(TOUGHGALSND4);
}

static ConAction *FEMSHRUNK = new ConAction();
static ConAction *FEMFROZEN1 = new ConAction(1);
static ConAction *FEMGROW = new ConAction();
static ConAction *FEMFROZEN2 = new ConAction();
static ConAction *FEMDANCE1 = new ConAction(19, 1, 1, 1, 16);
static ConAction *FEMDANCE3 = new ConAction(19, 1, 1, 1, 26);
static ConAction *FEMDANCE2 = new ConAction(20, 2, 1, 1, 10);
static ConAction *FEMANIMATESLOW = new ConAction(0, 2, 1, 1, 100);
static ConAction *TOUGHGALANIM = new ConAction(0, 5, 1, 1, 25);
static ConAction *FEMANIMATE = new ConAction();
void femcode()
{
    ifactor(NAKED1)
    {
    }
    else
        ifactor(FEM6)
        {
        }
        else
        {
            imports->fall();
            ifactor(BLOODYPOLE)
                ifhitweapon()
                    ifdead()
                    {
                        standard_jibs();
                        imports->killit();
                    }
        }
    ifaction(FEMSHRUNK)
    {
        ifcount(SHRUNKDONECOUNT)
        {
            imports->SetAction(FEMANIMATE);
            imports->cstat(257);
        }
        else
            ifcount(SHRUNKCOUNT)
                imports->sizeto(40, 40);
            else
                genericshrunkcode();
    }
    else
        ifaction(FEMGROW)
        {
            ifcount(32)
            {
                imports->respawnhitag();
                imports->guts(JIBS4, 20);
                imports->guts(JIBS6, 20);
                imports->spritepal(6);
                imports->soundonce(LADY_SCREAM);
                ifactor(NAKED1)
                    imports->debris(SCRAP3, 4);
                else
                    ifactor(PODFEM1)
                        imports->debris(SCRAP3, 4);
                imports->sound(SQUISHED);
                imports->killit();
            }
            else
                imports->sizeto(MAXXSTRETCH, MAXYSTRETCH);
        }
        else
            ifaction(FEMDANCE1)
            {
                ifactioncount(2)
                    imports->SetAction(FEMDANCE2);
            }
            else
                ifaction(FEMDANCE2)
                {
                    ifactioncount(8)
                        imports->SetAction(FEMDANCE3);
                }
                else
                    ifaction(FEMDANCE3)
                    {
                        ifactioncount(2)
                            imports->SetAction(FEMANIMATE);
                    }
                    else
                        ifaction(FEMFROZEN1)
                        {
                            ifcount(THAWTIME)
                            {
                                imports->SetAction(FEMANIMATE);
                                imports->getlastpal();
                            }
                            else
                                ifcount(FROZENDRIPTIME)
                                {
                                    ifactioncount(26)
                                    {
                                        imports->spawn(WATERDRIP);
                                        imports->resetactioncount();
                                    }
                                }
                            ifhitweapon()
                            {
                                ifwasweapon(FREEZEBLAST)
                                {
                                    imports->strength(0);
                                    return;
                                }
                                imports->lotsofglass(30);
                                imports->sound(GLASS_BREAKING);
                                imports->respawnhitag();
                                ifrnd(84)
                                    imports->spawn(BLOODPOOL);
                                imports->killit();
                            }
                            else
                                ifp(pfacing)
                                    ifpdistl(FROZENQUICKKICKDIST)
                                        imports->pkick();
                            return;
                        }
                        else
                            ifaction(FEMFROZEN2)
                            {
                                ifcount(THAWTIME)
                                {
                                    ifactor(TOUGHGAL)
                                        imports->SetAction(TOUGHGALANIM);
                                    else
                                        ifactor(FEM10)
                                            imports->SetAction(FEMANIMATESLOW);
                                        else
                                            imports->SetAction(FEMANIMATE);
                                    imports->getlastpal();
                                }
                                else
                                    ifcount(FROZENDRIPTIME)
                                    {
                                        ifactioncount(26)
                                        {
                                            imports->spawn(WATERDRIP);
                                            imports->resetactioncount();
                                        }
                                    }
                                ifhitweapon()
                                {
                                    ifwasweapon(FREEZEBLAST)
                                    {
                                        imports->strength(0);
                                        return;
                                    }
                                    imports->lotsofglass(30);
                                    imports->sound(GLASS_BREAKING);
                                    ifrnd(84)
                                        imports->spawn(BLOODPOOL);
                                    imports->respawnhitag();
                                    ifrnd(128)
                                        imports->sound(DUKE_HIT_STRIPPER1);
                                    else
                                        imports->sound(DUKE_HIT_STRIPPER2);
                                    imports->killit();
                                }
                                else
                                    ifp(pfacing)
                                        ifpdistl(FROZENQUICKKICKDIST)
                                            imports->pkick();
                                return;
                            }
    ifhitweapon()
    {
        ifdead()
        {
            ifwasweapon(GROWSPARK)
            {
                imports->cstat(0);
                imports->Move2(0, 0);
                imports->sound(ACTOR_GROWING);
                imports->SetAction(FEMGROW);
                return;
            }
            else
                ifwasweapon(FREEZEBLAST)
                {
                    ifaction(FEMSHRUNK)
                        return;
                    ifactor(NAKED1)
                        imports->SetAction(FEMFROZEN2);
                    else
                        ifactor(FEM5)
                            imports->SetAction(FEMFROZEN2);
                        else
                            ifactor(FEM6)
                                imports->SetAction(FEMFROZEN2);
                            else
                                ifactor(FEM8)
                                    imports->SetAction(FEMFROZEN2);
                                else
                                    ifactor(FEM9)
                                        imports->SetAction(FEMFROZEN2);
                                    else
                                        ifactor(FEM10)
                                            imports->SetAction(FEMFROZEN2);
                                        else
                                            ifactor(TOUGHGAL)
                                                imports->SetAction(FEMFROZEN2);
                                            else
                                                ifactor(PODFEM1)
                                                    imports->SetAction(FEMFROZEN2);
                                                else
                                                    imports->SetAction(FEMFROZEN1);
                    imports->Move2(0, 0);
                    imports->spritepal(1);
                    imports->strength(0);
                    imports->sound(SOMETHINGFROZE);
                    return;
                }
            ifrnd(128)
                imports->sound(DUKE_HIT_STRIPPER1);
            else
                imports->sound(DUKE_HIT_STRIPPER2);
            imports->respawnhitag();
            standard_jibs();
            random_wall_jibs();
            imports->spawn(BLOODPOOL);
            ifactor(FEM1)
                imports->money(5);
            else
                ifactor(FEM2)
                {
                    imports->money(7);
                    imports->cactor(BARBROKE);
                    imports->cstat(0);
                }
                else
                    ifactor(FEM3)
                        imports->money(4);
                    else
                        ifactor(FEM7)
                            imports->money(8);
            ifactor(FEM5)
            {
                imports->strength(TOUGH);
                imports->cactor(BLOODYPOLE);
            }
            else
                ifactor(FEM6)
                {
                    imports->cstat(0);
                    imports->cactor(FEM6PAD);
                }
                else
                    ifactor(FEM8)
                    {
                        imports->strength(TOUGH);
                        imports->cactor(BLOODYPOLE);
                    }
                    else
                    {
                        imports->spritepal(6);
                        imports->soundonce(LADY_SCREAM);
                        ifactor(NAKED1)
                            imports->debris(SCRAP3, 18);
                        else
                            ifactor(PODFEM1)
                                imports->debris(SCRAP3, 18);
                        imports->killit();
                    }
        }
        else
        {
            ifwasweapon(SHRINKSPARK)
            {
                imports->sound(ACTOR_SHRINKING);
                imports->Move2(0, 0);
                imports->SetAction(FEMSHRUNK);
                imports->cstat(0);
                return;
            }
            else
                ifwasweapon(GROWSPARK)
                    imports->sound(EXPANDERHIT);
            ifactor(FEM8)
                return;
            ifactor(TOUGHGAL)
                toughgalspeech();
            else
                imports->sound(SQUISHED);
            imports->guts(JIBS6, 1);
        }
    }
}
void killme()
{
    ifinwater()
    {
    }
    else
        ifp(pfacing)
            ifpdistl(1280)
                ifhitspace()
                    imports->soundonce(KILLME);
}
void tipme()
{
    ifp(pfacing)
        ifpdistl(1280)
            ifhitspace()
            {
                imports->tip();
                ifrnd(128)
                    imports->soundonce(DUKE_TIP1);
                else
                    imports->soundonce(DUKE_TIP2);
                ifactor(FEM1)
                    imports->SetAction(FEMDANCE1);
            }
}
void toughgaltalk()
{
    ifp(pfacing)
        ifpdistl(1280)
            ifhitspace()
                toughgalspeech();
}
void A_FEM1()
{
    tipme();
    femcode();
}
void A_FEM2()
{
    tipme();
    femcode();
}
void A_FEM3()
{
    tipme();
    femcode();
}
void A_FEM4()
{
    femcode();
}
void A_FEM5()
{
    killme();
    femcode();
}
void A_FEM6()
{
    killme();
    femcode();
}
void A_FEM7()
{
    tipme();
    femcode();
}
void A_FEM8()
{
    femcode();
}
void A_FEM9()
{
    femcode();
}
void A_FEM10()
{
    tipme();
    femcode();
}
void A_TOUGHGAL()
{
    toughgaltalk();
    femcode();
}
void A_NAKED1()
{
    killme();
    femcode();
}
void A_PODFEM1()
{
    killme();
    femcode();
}
void A_BLOODYPOLE()
{
    femcode();
}
void A_STATUEFLASH()
{
    imports->fall();
    ifcount(32)
        imports->cactor(STATUE);
}
void A_STATUE()
{
    imports->fall();
    ifp(pfacing)
        ifpdistl(1280)
            ifhitspace()
            {
                imports->cactor(STATUEFLASH);
                imports->Move2(0, 0);
            }
}
void A_MIKE()
{
    ifp(pfacing)
        ifpdistl(1280)
            ifhitspace()
                imports->mikesnd();
}
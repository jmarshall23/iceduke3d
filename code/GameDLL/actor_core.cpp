#include "gamedll.h"

ConAction *ANULLACTION = new ConAction(0);
MoveAction *SHUTTLEVELS = new MoveAction(16);
void A_SPACESHUTTLE()
{
}
void A_SATELLITE()
{
}

void genericshrunkcode()
{
    ifcount(32)
    {
        ifpdistl(SQUISHABLEDISTANCE)
            imports->pstomp();
    }
    else
    {
        imports->sizeto(MINXSTRETCH, MINYSTRETCH);
        imports->spawn(FRAMEEFFECT1);
    }
}
void genericgrowcode()
{
    ifcount(32)
    {
        imports->guts(JIBS4, 24);
        imports->guts(JIBS6, 28);
        imports->addkills(1);
        imports->sound(SQUISHED);
        imports->sound(PIPEBOMB_EXPLODE);
        imports->hitradius(2048, 60, 70, 80, 90);
        imports->spawn(BLOODPOOL);
        imports->spawn(EXPLOSION2);
        imports->killit();
    }
    else
    {
        ifactor(COMMANDER)
            imports->sizeto(100, 100);
        else
            ifactor(SHARK)
                imports->sizeto(84, 84);
            else
                imports->sizeto(MAXXSTRETCH, MAXYSTRETCH);
        return;
    }
}


void rats()
{
    ifrnd(128)
        imports->spawn(RAT);
    ifrnd(128)
        imports->spawn(RAT);
    ifrnd(128)
        imports->spawn(RAT);
    ifrnd(128)
        imports->spawn(RAT);
    ifrnd(128)
        imports->spawn(RAT);
    ifrnd(128)
        imports->spawn(RAT);
    ifrnd(128)
        imports->spawn(RAT);
    ifrnd(128)
        imports->spawn(RAT);
}
MoveAction *RESPAWN_ACTOR_FLAG = new MoveAction();
MoveAction* MOUSEVELS = new MoveAction(32);
ConAction *UBCANDENT = new ConAction(1, 1, 1, 1, 1);
void A_RUBBERCAN()
{
    ifaction(RUBCANDENT)
    {
        ifactioncount(16)
        {
            imports->strength(0);
            imports->SetAction(ANULLACTION);
            return;
        }
    }
    else
        ifhitweapon()
        {
            ifwasweapon(RADIUSEXPLOSION)
            {
                rats();
                ifrnd(48)
                    imports->spawn(BURNING);
                imports->debris(SCRAP3, 12);
                imports->killit();
            }
            else
                imports->SetAction(RUBCANDENT);
        }
}


void headhitstate()
{
}

ConAction *EXPBARRELFRAME = new ConAction(0, 2, 1, 1, 15);
void A_EXPLODINGBARREL()
{
    imports->fall();
    ifaction(EXPBARRELFRAME)
    {
        ifactioncount(2)
        {
            imports->hitradius(1024, WEAKEST, WEAK, MEDIUMSTRENGTH, TOUGH);
            imports->spawn(EXPLOSION2);
            imports->debris(SCRAP2, 2);
            imports->sound(PIPEBOMB_EXPLODE);
            imports->killit();
        }
        return;
    }
    ifsquished()
    {
        imports->debris(SCRAP1, 5);
        imports->killit();
        return;
    }
    ifhitweapon()
        imports->SetAction(EXPBARRELFRAME);
}
ConAction *BURNING_FLAME = new ConAction(0, 12, 1, 1, 2);
MoveAction *BURNING_VELS = new MoveAction();
void burningstate()
{
    imports->sleeptime(300);
    ifspawnedby(BURNING)
    {
        ifgapzl(16)
            return;
    }
    else
        ifspawnedby(BURNING2)
        {
            ifgapzl(16)
                return;
        }
    ifpdistg(10240)
        return;
    ifcount(128)
    {
        ifspawnedby(TIRE)
        {
            ifactioncount(512)
                imports->killit();
            ifrnd(16)
                imports->sizeto(64, 48);
        }
        else
        {
            imports->sizeto(8, 8);
            imports->sizeto(8, 8);
            ifcount(192)
                imports->killit();
        }
    }
    else
    {
        ifmove(NULL)
            imports->Move(BURNING_VELS, 0, 0, 0);
        imports->sizeto(52, 52);
        ifp(palive)
            ifpdistl(844)
                ifrnd(32)
                    ifcansee()
                    {
                        imports->soundonce(DUKE_LONGTERM_PAIN);
                        imports->addphealth(-1);
                        imports->palfrom(24, 16, 0 , 0);
                    }
    }
}
void A_BURNING()
{
    burningstate();
}
void A_BURNING2()
{
    burningstate();
}

ConAction *WOODENHORSEFRAME = new ConAction(0, 1, 4);
ConAction *WOODENFALLFRAME = new ConAction(122, 1, 5);
void A_HORSEONSIDE()
{
    imports->cactor(WOODENHORSE);
    imports->SetAction(WOODENFALLFRAME);
}
void A_WOODENHORSE()
{
    imports->fall();
    ifhitweapon()
    {
        ifdead()
        {
            imports->debris(SCRAP1, 4);
            imports->debris(SCRAP2, 3);
            imports->killit();
        }
        else
            imports->SetAction(WOODENFALLFRAME);
    }
}
void steamcode()
{
    ifpdistl(6144)
        imports->soundonce(STEAM_HISSING);
    ifcount(20)
    {
        imports->resetcount();
        ifp(palive)
            ifpdistl(1024)
            {
                imports->addphealth(-1);
                imports->palfrom(16, 16, 0, 0);
            }
    }
    else
    {
        ifspawnedby(STEAM)
            return;
        else
            ifspawnedby(CEILINGSTEAM)
                return;
        imports->sizeto(24, 24);
    }
}
ConAction *STEAMFRAMES = new ConAction(0, 5, 1, 1, 1);
void A_STEAM()
{
    steamcode();
}
void A_CEILINGSTEAM()
{
    steamcode();
}
void A_WATERBUBBLEMAKER()
{
    ifpdistl(3084)
        ifrnd(24)
            imports->spawn(WATERBUBBLE);
}
ConAction  *BUBBLE = new ConAction();
ConAction  *CRACKEDBUBBLE = new ConAction(1);
MoveAction *BUBMOVE = new MoveAction(-10, -36);
MoveAction *BUBMOVEFAST = new MoveAction(-10, -52);
void A_WATERBUBBLE()
{
    ifaction(CRACKEDBUBBLE)
    {
        ifinwater()
            ifrnd(192)
                imports->killit();
        ifactioncount(7)
            imports->killit();
    }
    else
    {
        ifcount(4)
        {
            ifrnd(192)
                imports->Move(BUBMOVE, getv, geth, randomangle);
            else
                imports->Move(BUBMOVEFAST, getv, geth, randomangle);
            imports->resetcount();
            ifrnd(84)
                imports->sizeat(8, 10);
            else
                ifrnd(84)
                    imports->sizeat(10, 8);
                else
                    imports->sizeat(9, 9);
        }
        ifonwater()
        {
            iffloordistl(8)
                imports->SetAction(CRACKEDBUBBLE);
        }
        else
            ifactioncount(40)
                imports->SetAction(CRACKEDBUBBLE);
    }
}
MoveAction *SMOKEVEL = new MoveAction(8, -16);
MoveAction *ENGINE_SMOKE = new MoveAction(64, -64);
MoveAction *SMOKESHOOTOUT = new MoveAction(-192);
ConAction  *SMOKEFRAMES = new ConAction(0, 4, 1, 1, 10);
void A_SMALLSMOKE()
{
    ifmove(NULL)
    {
        ifspawnedby(RECON)
            imports->Move(SMOKESHOOTOUT, geth, 0, 0);
        else
            ifspawnedby(SECTOREFFECTOR)
                imports->Move(ENGINE_SMOKE, geth, getv, 0);
            else
                imports->Move(SMOKEVEL, geth, getv, faceplayer);
        ifspawnedby(RPG)
            imports->cstat(2);
    }
    ifpdistl(1596)
        ifspawnedby(RPG)
            imports->killit();
    ifactioncount(4)
        imports->killit();
}
ConAction  *BARREL_DENTING = new ConAction(2, 2, 1, 1, 6);
ConAction  *BARREL_DENTED = new ConAction(1);
ConAction  *BARREL_DENTED2 = new ConAction(2);
MoveAction *SPAWNED_BLOOD = new MoveAction();
void A_NUKEBARRELDENTED()
{
    imports->cactor(NUKEBARREL);
    imports->SetAction(BARREL_DENTED);
}
void A_NUKEBARRELLEAKED()
{
    imports->cactor(NUKEBARREL);
    imports->SetAction(BARREL_DENTED2);
}
void random_ooz()
{
    ifrnd(128)
        imports->spawn(OOZ2);
    else
        imports->spawn(OOZ);
}
void A_NUKEBARREL()
{
    ifsquished()
    {
        imports->debris(SCRAP1, 32);
        imports->spawn(BLOODPOOL);
        random_ooz();
        imports->killit();
    }
    imports->fall();
    ifaction(BARREL_DENTING)
    {
        ifactioncount(2)
        {
            imports->debris(SCRAP1, 10);
            ifrnd(2)
                imports->spawn(BLOODPOOL);
            imports->killit();
        }
    }
    else
        ifhitweapon()
        {
            ifdead()
            {
                imports->sound(VENT_BUST);
                ifrnd(128)
                    imports->spawn(BLOODPOOL);
                imports->SetAction(BARREL_DENTING);
            }
            else
            {
                ifaction(NULL)
                    imports->SetAction(BARREL_DENTED);
                else
                    ifaction(BARREL_DENTED)
                    {
                        imports->SetAction(BARREL_DENTED2);
                        imports->spawn(BLOODPOOL);
                    }
                    else
                        ifaction(BARREL_DENTED2)
                            imports->SetAction(BARREL_DENTING);
            }
        }
}
void burningbarrelcode()
{
    imports->fall();
    ifcount(32)
    {
        imports->resetcount();
        ifp(palive)
            ifpdistl(1480)
                ifp(phigher)
                {
                    imports->addphealth(-1);
                    imports->palfrom(16, 16, 0, 0);
                    ifrnd(96)
                        imports->sound(DUKE_LONGTERM_PAIN);
                }
    }
    ifhitweapon()
    {
        imports->sound(VENT_BUST);
        imports->debris(SCRAP1, 10);
        ifrnd(128)
            imports->spawn(BURNING);
        else
            imports->spawn(BURNING2);
        imports->killit();
    }
}
void A_FIREBARREL()
{
    burningbarrelcode();
}
void A_FIREVASE()
{
    burningbarrelcode();
}
ConAction *SHRINKERFRAMES = new ConAction(0, 4, 1, 1, 10);
void A_SHRINKEREXPLOSION()
{
    ifactioncount(4)
        imports->killit();
}
ConAction *EXPLOSION_FRAMES = new ConAction(0, 20, 1, 1, 4);
void A_EXPLOSION2()
{
    ifactioncount(20)
        imports->killit();
}
void A_EXPLOSION2BOT()
{
    ifactioncount(20)
        imports->killit();
}
ConAction *FFLAME_FR = new ConAction(0, 16, 1, 1, 1);
ConAction *FFLAME = new ConAction(0, 1, 1, 1, 1);
void A_FLOORFLAME()
{
    ifaction(FFLAME_FR)
    {
        ifpdistl(1024)
            imports->hitradius(1024, WEAKEST, WEAKEST, WEAKEST, WEAKEST);
        ifactioncount(16)
            imports->SetAction(FFLAME);
    }
    ifaction(FFLAME)
        ifrnd(4)
        {
            imports->SetAction(FFLAME_FR);
            imports->sound(CAT_FIRE);
            imports->resetactioncount();
        }
}
ConAction  *ASATNSPIN = new ConAction(0, 5, 1, 1, 4);
ConAction  *ASATSHOOTING = new ConAction(-10, 3, 5, 1, 40);
ConAction  *ASATWAIT = new ConAction(0, 1, 5, 1, 1);
MoveAction *TURRVEL = new MoveAction();
void A_ROTATEGUN()
{
    ifaction(NULL)
    {
        imports->SetAction(ASATSHOOTING);
        imports->Move(TURRVEL, faceplayer, 0, 0);
    }
    else
        ifaction(ASATNSPIN)
        {
            ifactioncount(32)
            {
                imports->SetAction(ASATWAIT);
                imports->Move(TURRVEL, faceplayer, 0, 0);
            }
        }
        else
            ifaction(ASATSHOOTING)
            {
                ifactioncount(12)
                    ifrnd(32)
                    {
                        imports->SetAction(ASATWAIT);
                        imports->Move2(0, 0);
                    }
                ifcount(32)
                    imports->resetcount();
                else
                    ifcount(16)
                    {
                        ifcount(17)
                        {
                        }
                        else
                        {
                            imports->sound(PRED_ATTACK);
                            imports->shoot(FIRELASER);
                        }
                    }
                    else
                        ifcount(4)
                        {
                            ifcount(5)
                            {
                            }
                            else
                            {
                                ifcansee()
                                    ifcanshoottarget()
                                    {
                                        imports->sound(PRED_ATTACK);
                                        imports->shoot(FIRELASER);
                                    }
                            }
                        }
            }
            else
                ifaction(ASATWAIT)
                {
                    ifactioncount(64)
                        ifrnd(32)
                            ifp(palive)
                                ifcansee()
                                {
                                    imports->SetAction(ASATSHOOTING);
                                    imports->Move(TURRVEL, faceplayer, 0, 0);
                                }
                }
    ifhitweapon()
    {
        ifdead()
        {
            imports->addkills(1);
            imports->sound(LASERTRIP_EXPLODE);
            imports->debris(SCRAP1, 15);
            imports->spawn(EXPLOSION2);
            imports->killit();
        }
        else
        {
            imports->SetAction(ASATNSPIN);
            imports->debris(SCRAP1, 4);
        }
        imports->Move2(0, 0);
    }
}
ConAction *RIP_F = new ConAction(0, 8, 1, 1, 1);
void A_FORCERIPPLE()
{
    ifactioncount(8)
        imports->killit();
}
ConAction *TRANSFOWARD = new ConAction(0, 6, 1, 1, 2);
ConAction *TRANSBACK = new ConAction(5, 6, 1, -1, 2);
void A_TRANSPORTERSTAR()
{
    ifaction(TRANSFOWARD)
    {
        ifactioncount(6)
            imports->SetAction(TRANSBACK);
    }
    else
        ifactioncount(6)
            imports->killit();
}
ConAction *BEAMFOWARD = new ConAction(0, 4, 1, 1, 9);
void A_TRANSPORTERBEAM()
{
    imports->sizeto(32, 64);
    imports->sizeto(32, 64);
    imports->sizeto(32, 64);
    ifactioncount(4)
        imports->killit();
}
void getcode()
{
    ifactor(ATOMICHEALTH)
        imports->globalsound(GETATOMICHEALTH);
    else
        imports->globalsound(DUKE_GET);
    imports->palfrom(16, 0, 32, 0);
    ifrespawn()
    {
        imports->Move(RESPAWN_ACTOR_FLAG, 0, 0, 0);
        imports->spawn(RESPAWNMARKERRED);
        imports->cstat(32768);
    }
    else
        imports->killit();
}
void randgetweapsnds()
{
    ifrnd(64)
        imports->globalsound(DUKE_GETWEAPON1);
    else
        ifrnd(96)
            imports->globalsound(DUKE_GETWEAPON2);
        else
            ifrnd(128)
                imports->globalsound(DUKE_GETWEAPON3);
            else
                ifrnd(140)
                    imports->globalsound(DUKE_GETWEAPON4);
                else
                    imports->globalsound(DUKE_GETWEAPON6);
}
void getweaponcode()
{
    randgetweapsnds();
    imports->palfrom(32, 0, 32, 0);
    ifgotweaponce(1)
        return;
    ifrespawn()
    {
        imports->Move(RESPAWN_ACTOR_FLAG, 0, 0, 0);
        imports->spawn(RESPAWNMARKERRED);
        imports->cstat(32768);
    }
    else
        imports->killit();
}
void respawnit()
{
    ifcount(RESPAWNITEMTIME)
    {
        imports->spawn(TRANSPORTERSTAR);
        imports->Move2(0, 0);
        imports->cstat(0);
        imports->sound(TELEPORTER);
    }
}
void quikget()
{
    ifactor(ATOMICHEALTH)
        imports->globalsound(GETATOMICHEALTH);
    else
        imports->globalsound(DUKE_GET);
    imports->palfrom(16, 0, 32, 0);
    imports->killit();
}
void quikweaponget()
{
    randgetweapsnds();
    imports->palfrom(32, 0, 32, 0);
    ifgotweaponce(1)
        return;
    imports->killit();
}

ConAction  *FIRE_FRAMES = new ConAction(-1, 14, 1, 1, 1);
MoveAction *FIREVELS = new MoveAction();
void firestate()
{
    ifaction(NULL)
        ifrnd(16)
        {
            imports->SetAction(FIRE_FRAMES);
            imports->cstator(128);
        }
    imports->sleeptime(300);
    ifspawnedby(FIRE)
    {
        ifgapzl(16)
            return;
    }
    else
        ifspawnedby(FIRE2)
        {
            ifgapzl(16)
                return;
        }
    ifinwater()
        imports->killit();
    ifp(palive)
        ifpdistl(844)
            ifrnd(32)
                ifcansee()
                {
                    imports->soundonce(DUKE_LONGTERM_PAIN);
                    imports->addphealth(-1);
                    imports->palfrom(32, 32, 0, 0);
                }
    ifactor(FIRE)
    {
        ifspawnedby(FIRE)
            return;
    }
    else
        ifactor(FIRE2)
            ifspawnedby(FIRE2)
                return;
    iffloordistl(128)
    {
        ifrnd(128)
        {
            ifcount(84)
                imports->killit();
            else
                ifcount(42)
                    imports->sizeto(0, 0);
                else
                    imports->sizeto(32, 32);
        }
    }
    else
        imports->killit();
}
void A_FIRE()
{
    firestate();
}
void A_FIRE2()
{
    firestate();
}
void A_FECES()
{
    ifcount(24)
    {
        ifpdistl(RETRIEVEDISTANCE)
        {
            ifrnd(SWEARFREQUENCY)
                imports->soundonce(DUKE_STEPONFECES);
            imports->sound(STEPNIT);
            imports->spawn(BLOODPOOL);
            imports->killit();
        }
    }
    else
        imports->sizeto(32, 32);
}
void drop_ammo()
{
    ifrnd(SPAWNAMMOODDS)
        imports->spawn(AMMO);
}
void drop_battery()
{
    ifrnd(SPAWNAMMOODDS)
        imports->spawn(BATTERYAMMO);
}
void drop_sgshells()
{
    ifrnd(SPAWNAMMOODDS)
        imports->spawn(SHOTGUNAMMO);
}
void drop_shotgun()
{
    ifrnd(SPAWNAMMOODDS)
        imports->spawn(SHOTGUNSPRITE);
}
void drop_chaingun()
{
    ifrnd(SPAWNAMMOODDS)
    {
        ifrnd(32)
            imports->spawn(CHAINGUNSPRITE);
        else
            imports->spawn(BATTERYAMMO);
    }
}

void A_KNEE()
{
}
void A_SPIT()
{
}
void A_CHAINGUN()
{
}
void A_SHOTGUN()
{
}
void A_FIRELASER()
{
}
void A_HEAVYHBOMB()
{
}
void A_BOUNCEMINE()
{
}
void A_MORTER()
{
}
void A_SHRINKSPARK()
{
}
void A_GROWSPARK()
{
    ifcount(18)
        imports->killit();
    else
        ifcount(9)
        {
            imports->sizeto(0, 0);
            imports->sizeto(0, 0);
            imports->sizeto(0, 0);
            imports->sizeto(0, 0);
        }
        else
        {
            imports->sizeto(28, 28);
            imports->sizeto(28, 28);
            imports->sizeto(28, 28);
            imports->sizeto(28, 28);
        }
}
void A_RPG()
{
}
void A_FREEZEBLAST()
{
}
void A_DEVISTATORBLAST()
{
}
void A_COOLEXPLOSION1()
{
}
void A_TRIPBOMB()
{
}
ConAction *WEAP2FRAMES = new ConAction(0, 4, 1, 1, 6);
void A_SHOTSPARK1()
{
    ifdead()
        imports->killit();
    ifactioncount(4)
        imports->killit();
    else
    {
        ifactioncount(3)
        {
            ifinwater()
                imports->spawn(WATERBUBBLE);
        }
        else
            ifcount(2)
            {
            }
            else
                ifonwater()
                    imports->spawn(WATERSPLASH2);
    }
}


void A_ORGANTIC()
{
    ifcount(48)
        imports->resetcount();
    else
    {
        ifcount(32)
            imports->sizeto(32, 32);
    }
    ifhitweapon()
    {
        ifdead()
        {
            imports->addkills(1);
            imports->sound(TURR_DYING);
            imports->guts(JIBS5, 10);
            imports->killit();
        }
        imports->sound(TURR_PAIN);
        return;
    }
    ifrnd(1)
        imports->soundonce(TURR_ROAM);
}
void rf()
{
    ifrnd(128)
        imports->cstat(4);
    else
        imports->cstat(0);
}

const int CANNONBALLSTRENGTH = 400;
MoveAction *CANNONBALL1 = new MoveAction(512, 0);
MoveAction *CANNONBALL2 = new MoveAction(512, 10);
MoveAction *CANNONBALL3 = new MoveAction(512, 20);
MoveAction *CANNONBALL4 = new MoveAction(512, 40);
MoveAction *CANNONBALL5 = new MoveAction(512, 80);
void A_CANNONBALL()
{
    ifaction(NULL)
    {
        imports->sizeat(32, 32);
        imports->cstat(257);
        imports->SetAction(ANULLACTION);
    }
    ifactioncount(46)
    {
        ifactioncount(47)
        {
        }
        else
            imports->Move(CANNONBALL5, geth, getv, 0);
    }
    else
        ifactioncount(44)
        {
            ifactioncount(45)
            {
            }
            else
                imports->Move(CANNONBALL4, geth, getv, 0);
        }
        else
            ifactioncount(40)
            {
                ifactioncount(41)
                {
                }
                else
                    imports->Move(CANNONBALL3, geth, getv, 0);
            }
            else
                ifactioncount(32)
                {
                    ifactioncount(33)
                    {
                    }
                    else
                        imports->Move(CANNONBALL2, geth, getv, 0);
                }
                else
                    ifactioncount(16)
                    {
                        ifactioncount(17)
                        {
                        }
                        else
                            imports->Move(CANNONBALL1, geth, getv, 0);
                    }
    ifnotmoving()
    {
        imports->spawn(EXPLOSION2);
        imports->sound(PIPEBOMB_EXPLODE);
        imports->hitradius(4096, WEAKEST, WEAK, MEDIUMSTRENGTH, TOUGH);
        imports->killit();
    }
    ifhitweapon()
    {
        ifdead()
        {
            imports->spawn(EXPLOSION2);
            imports->hitradius(4096, WEAKEST, WEAK, MEDIUMSTRENGTH, TOUGH);
            imports->killit();
        }
        else
            imports->debris(SCRAP1, 3);
    }
}
const int CANNONBALLS = 1818;
const int CANNONBALLSSTRENGTH = 10;
MoveAction *CANNONBALLSVEL = new MoveAction();
void A_CANNONBALLS()
{
    ifaction(NULL)
    {
        imports->cstator(257);
        imports->SetAction(ANULLACTION);
    }
    ifhitweapon()
    {
        ifdead()
        {
            imports->spawn(EXPLOSION2);
            imports->hitradius(4096, WEAKEST, WEAK, MEDIUMSTRENGTH, TOUGH);
            imports->killit();
        }
        else
            imports->debris(SCRAP1, 3);
    }
}
const int CANNON = 1810;
const int CANNONSTRENGTH = 400;
ConAction  *ACANNONWAIT = new ConAction(0, 1, 7, 1, 1);
ConAction  *ACANNONSHOOTING = new ConAction(0, 1, 7, 1, 1);
MoveAction *CANNONSTOP = new MoveAction();
void A_CANNON()
{
    ifaction(NULL)
    {
        imports->SetAction(ACANNONWAIT);
    }
    else
        ifaction(ACANNONSHOOTING)
        {
            imports->spawn(CANNONBALL);
            imports->SetAction(ACANNONWAIT);
        }
        else
            ifaction(ACANNONWAIT)
            {
                ifactioncount(64)
                {
                    ifrnd(128)
                        imports->SetAction(ACANNONSHOOTING);
                    else
                        imports->resetactioncount();
                }
            }
    ifhitweapon()
    {
        ifdead()
        {
            imports->addkills(1);
            imports->hitradius(4096, WEAKEST, WEAK, MEDIUMSTRENGTH, TOUGH);
            imports->spawn(EXPLOSION2);
            imports->killit();
        }
        else
            imports->debris(SCRAP1, 3);
    }
    ifpdistl(1024)
        ifhitspace()
        {
            ifp(pfacing)
                ifcanshoottarget()
                    imports->spawn(CANNONBALL);
                else
                    return;
        }
}
void A_HOTMEAT()
{
    ifaction(NULL)
    {
        imports->SetAction(ANULLACTION);
        imports->cstat(257);
    }
    ifhitweapon()
    {
        ifdead()
        {
            imports->sound(SQUISHED);
            imports->guts(JIBS5, 8);
            imports->guts(JIBS6, 9);
            imports->killit();
        }
        else
            imports->guts(JIBS6, 1);
    }
    ifrnd(1)
        imports->spawn(WATERDRIP);
}
ConAction *ASPEAKERBROKE = new ConAction(1);
void A_SPEAKER()
{
    ifaction(NULL)
    {
        ifhitweapon()
        {
            imports->stopsound(STORE_MUSIC);
            imports->soundonce(STORE_MUSIC_BROKE);
            imports->SetAction(ASPEAKERBROKE);
        }
        else
        {
            ifpdistl(10240)
                imports->soundonce(STORE_MUSIC);
            imports->cstat(289);
        }
    }
}
ConAction *ALAVABUBBLE = new ConAction();
ConAction *ALAVABUBBLEANIM = new ConAction(0, 5, 1, 1, 16);
void A_LAVABUBBLE()
{
    ifaction(NULL)
    {
        imports->cstat(32768);
        imports->SetAction(ALAVABUBBLE);
    }
    else
        ifaction(ALAVABUBBLE)
        {
            ifcount(72)
                ifrnd(2)
                {
                    imports->cstat(0);
                    imports->SetAction(ALAVABUBBLEANIM);
                }
        }
        else
        {
            ifactioncount(5)
            {
                imports->cstat(32768);
                imports->SetAction(ALAVABUBBLE);
            }
        }
}
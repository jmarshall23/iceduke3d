#include "gamedll.h"

void A_STEROIDS()
{
    imports->fall();
    ifmove(RESPAWN_ACTOR_FLAG)
        respawnit();
    else
    ifp(pshrunk)
    {
    }
    else
    ifp(palive)
        ifcount(6)
            ifpdistl(RETRIEVEDISTANCE)
                ifpinventory(GET_STEROIDS, STEROID_AMOUNT)
                    ifcanseetarget()
                    {
                        imports->addinventory(GET_STEROIDS, STEROID_AMOUNT);
                        imports->quote(37);
                        ifspawnedby(STEROIDS)
                            getcode();
                        else
                            quikget();
                    }
}
void A_BOOTS()
{
    imports->fall();
    ifmove(RESPAWN_ACTOR_FLAG)
        respawnit();
    else
    ifp(pshrunk)
    {
    }
    else
    ifp(palive)
        ifcount(6)
            ifpdistl(RETRIEVEDISTANCE)
                ifpinventory(GET_BOOTS, BOOT_AMOUNT)
                    ifcanseetarget()
                    {
                        imports->addinventory(GET_BOOTS, BOOT_AMOUNT);
                        imports->quote(6);
                        ifspawnedby(BOOTS)
                            getcode();
                        else
                            quikget();
                    }
}
void A_HEATSENSOR()
{
    imports->fall();
    ifmove(RESPAWN_ACTOR_FLAG)
        respawnit();
    else
    ifp(pshrunk)
    {
    }
    else
    ifp(palive)
        ifcount(6)
            ifpdistl(RETRIEVEDISTANCE)
                ifpinventory(GET_HEATS, HEAT_AMOUNT)
                    ifcanseetarget()
                    {
                        imports->addinventory(GET_HEATS, HEAT_AMOUNT);
                        imports->quote(101);
                        ifspawnedby(HEATSENSOR)
                            getcode();
                        else
                            quikget();
                    }
}
void A_SHIELD()
{
    imports->fall();
    ifmove(RESPAWN_ACTOR_FLAG)
        respawnit();
    else
    ifp(pshrunk)
    {
    }
    else
    ifp(palive)
        ifcount(6)
            ifpdistl(RETRIEVEDISTANCE)
                ifpinventory(GET_SHIELD, SHIELD_AMOUNT)
                    ifcanseetarget()
                    {
                        ifspawnedby(PIGCOP)
                        {
                            ifrnd(128)
                                imports->addinventory(GET_SHIELD, PIG_SHIELD_AMOUNT1);
                            else
                                imports->addinventory(GET_SHIELD, PIG_SHIELD_AMOUNT2);
                            imports->quote(104);
                            imports->sound(KICK_HIT);
                            imports->palfrom(24, 0, 32, 0);
                            imports->killit();
                        }
                        else
                            imports->addinventory(GET_SHIELD, SHIELD_AMOUNT);
                        imports->quote(38);
                        ifspawnedby(SHIELD)
                            getcode();
                        else
                            quikget();
                    }
}
void A_AIRTANK()
{
    imports->fall();
    ifmove(RESPAWN_ACTOR_FLAG)
        respawnit();
    else
    ifp(pshrunk)
    {
    }
    else
    ifp(palive)
        ifcount(6)
            ifpdistl(RETRIEVEDISTANCE)
                ifpinventory(GET_SCUBA, SCUBA_AMOUNT)
                    ifcanseetarget()
                    {
                        imports->addinventory(GET_SCUBA, SCUBA_AMOUNT);
                        imports->quote(39);
                        ifspawnedby(AIRTANK)
                            getcode();
                        else
                            quikget();
                    }
}
static ConAction *HOLODUKE_FRAMES = new ConAction(0, 4, 1, 1, 8);
void A_HOLODUKE()
{
    imports->fall();
    ifmove(RESPAWN_ACTOR_FLAG)
        respawnit();
    else
    ifp(pshrunk)
    {
    }
    else
    ifp(palive)
        ifcount(6)
            ifpdistl(RETRIEVEDISTANCE)
                ifpinventory(GET_HOLODUKE, HOLODUKE_AMOUNT)
                    ifcanseetarget()
                    {
                        imports->addinventory(GET_HOLODUKE, HOLODUKE_AMOUNT);
                        imports->quote(51);
                        ifspawnedby(HOLODUKE)
                            getcode();
                        else
                            quikget();
                    }
}
void A_JETPACK()
{
    imports->fall();
    ifmove(RESPAWN_ACTOR_FLAG)
        respawnit();
    else
    ifp(pshrunk)
    {
    }
    else
    ifp(palive)
        ifpdistl(RETRIEVEDISTANCE)
            ifcount(6)
                ifpinventory(GET_JETPACK, JETPACK_AMOUNT)
                    ifcanseetarget()
                    {
                        imports->addinventory(GET_JETPACK, JETPACK_AMOUNT);
                        imports->quote(41);
                        ifspawnedby(JETPACK)
                            getcode();
                        else
                            quikget();
                    }
}
void A_ACCESSCARD()
{
    imports->fall();
    ifmove(RESPAWN_ACTOR_FLAG)
        respawnit();
    else
    ifp(pshrunk)
    {
    }
    else
    ifp(palive)
        ifpdistl(RETRIEVEDISTANCE)
            ifcount(6)
                ifcanseetarget()
                {
                    ifpinventory(GET_ACCESS, 0)
                        return;
                    imports->addinventory(GET_ACCESS, 1);
                    imports->quote(43);
                    getcode();
                }
}
void A_AMMO()
{
    imports->fall();
    ifmove(RESPAWN_ACTOR_FLAG)
        respawnit();
    else
    ifp(pshrunk)
    {
    }
    else
    ifp(palive)
        ifcount(6)
            ifpdistl(RETRIEVEDISTANCE)
                ifcanseetarget()
                {
                    imports->addammo(PISTOL_WEAPON, PISTOLAMMOAMOUNT);
                    imports->quote(65);
                    ifspawnedby(AMMO)
                        getcode();
                    else
                        quikget();
                }
}
void A_FREEZEAMMO()
{
    imports->fall();
    ifmove(RESPAWN_ACTOR_FLAG)
        respawnit();
    else
    ifp(pshrunk)
    {
    }
    else
    ifp(palive)
        ifcount(6)
            ifpdistl(RETRIEVEDISTANCE)
                ifcanseetarget()
                {
                    imports->addammo(FREEZE_WEAPON, FREEZEAMMOAMOUNT);
                    imports->quote(66);
                    ifspawnedby(FREEZEAMMO)
                        getcode();
                    else
                        quikget();
                }
}
void A_SHOTGUNAMMO()
{
    imports->fall();
    ifmove(RESPAWN_ACTOR_FLAG)
        respawnit();
    else
    ifp(pshrunk)
    {
    }
    else
    ifp(palive)
        ifcount(6)
            ifpdistl(RETRIEVEDISTANCE)
                ifcanseetarget()
                {
                    imports->addammo(SHOTGUN_WEAPON, SHOTGUNAMMOAMOUNT);
                    imports->quote(69);
                    ifspawnedby(SHOTGUNAMMO)
                        getcode();
                    else
                        quikget();
                }
}
void A_AMMOLOTS()
{
    imports->fall();
    ifmove(RESPAWN_ACTOR_FLAG)
        respawnit();
    else
    ifp(pshrunk)
    {
    }
    else
    ifp(palive)
        ifcount(6)
            ifpdistl(RETRIEVEDISTANCE)
                ifcanseetarget()
                {
                    imports->addammo(PISTOL_WEAPON, 48);
                    imports->quote(65);
                    ifspawnedby(AMMOLOTS)
                        getcode();
                    else
                        quikget();
                }
}
void A_CRYSTALAMMO()
{
    imports->fall();
    ifmove(RESPAWN_ACTOR_FLAG)
        respawnit();
    else
    ifp(pshrunk)
    {
    }
    else
    ifp(palive)
        ifpdistl(RETRIEVEDISTANCE)
            ifcount(6)
                ifcanseetarget()
                {
                    imports->addammo(SHRINKER_WEAPON, CRYSTALAMMOAMOUNT);
                    imports->quote(78);
                    ifspawnedby(CRYSTALAMMO)
                        getcode();
                    else
                        quikget();
                }
}
void A_GROWAMMO()
{
    imports->fall();
    ifmove(RESPAWN_ACTOR_FLAG)
        respawnit();
    else
    ifp(pshrunk)
    {
    }
    else
    ifp(palive)
        ifpdistl(RETRIEVEDISTANCE)
            ifcount(6)
                ifcanseetarget()
                {
                    imports->addammo(GROW_WEAPON, GROWCRYSTALAMMOAMOUNT);
                    imports->quote(123);
                    ifspawnedby(GROWAMMO)
                        getcode();
                    else
                        quikget();
                }
}
void A_BATTERYAMMO()
{
    imports->fall();
    ifmove(RESPAWN_ACTOR_FLAG)
        respawnit();
    else
    ifp(pshrunk)
    {
    }
    else
    ifp(palive)
        ifpdistl(RETRIEVEDISTANCE)
            ifcount(6)
                ifcanseetarget()
                {
                    imports->addammo(CHAINGUN_WEAPON, CHAINGUNAMMOAMOUNT);
                    imports->quote(63);
                    ifspawnedby(BATTERYAMMO)
                        getcode();
                    else
                        quikget();
                }
}
void A_DEVISTATORAMMO()
{
    imports->fall();
    ifmove(RESPAWN_ACTOR_FLAG)
        respawnit();
    else
    ifp(pshrunk)
    {
    }
    else
    ifp(palive)
        ifpdistl(RETRIEVEDISTANCE)
            ifcount(6)
                ifcanseetarget()
                {
                    imports->addammo(DEVISTATOR_WEAPON, DEVISTATORAMMOAMOUNT);
                    imports->quote(14);
                    ifspawnedby(DEVISTATORAMMO)
                        getcode();
                    else
                        quikget();
                }
}
void A_RPGAMMO()
{
    imports->fall();
    ifmove(RESPAWN_ACTOR_FLAG)
        respawnit();
    else
    ifp(pshrunk)
    {
    }
    else
    ifp(palive)
        ifpdistl(RETRIEVEDISTANCE)
            ifcount(6)
                ifcanseetarget()
                {
                    imports->addammo(RPG_WEAPON, RPGAMMOBOX);
                    imports->quote(64);
                    ifspawnedby(RPGAMMO)
                        getcode();
                    else
                        quikget();
                }
}
void A_HBOMBAMMO()
{
    imports->fall();
    ifmove(RESPAWN_ACTOR_FLAG)
        respawnit();
    else
    ifp(pshrunk)
    {
    }
    else
    ifp(palive)
        ifpdistl(RETRIEVEDISTANCE)
            ifcount(6)
                ifcanseetarget()
                {
                    ifgotweaponce(0)
                        return;
                    imports->addweapon2(HANDBOMB_WEAPON, HANDBOMBBOX);
                    imports->quote(55);
                    ifspawnedby(HBOMBAMMO)
                        getweaponcode();
                    else
                        quikweaponget();
                }
}
void A_RPGSPRITE()
{
    imports->fall();
    ifmove(RESPAWN_ACTOR_FLAG)
        respawnit();
    else
    ifp(pshrunk)
    {
    }
    else
    ifp(palive)
        ifpdistl(RETRIEVEDISTANCE)
            ifcount(6)
                ifcanseetarget()
                {
                    ifgotweaponce(0)
                        return;
                    imports->addweapon2(RPG_WEAPON, RPGAMMOBOX);
                    imports->quote(56);
                    ifspawnedby(RPGSPRITE)
                        getweaponcode();
                    else
                        quikweaponget();
                }
}
void A_SHOTGUNSPRITE()
{
    imports->fall();
    ifmove(RESPAWN_ACTOR_FLAG)
        respawnit();
    else
    ifp(pshrunk)
    {
    }
    else
    ifp(palive)
        ifpdistl(RETRIEVEDISTANCE)
            ifcount(6)
                ifcanseetarget()
                {
                    ifspawnedby(PIGCOP)
                    {
                        imports->addweapon2(SHOTGUN_WEAPON, 0);
                        ifrnd(64)
                            imports->addammo(SHOTGUN_WEAPON, 4);
                        else
                        ifrnd(64)
                            imports->addammo(SHOTGUN_WEAPON, 3);
                        else
                        ifrnd(64)
                            imports->addammo(SHOTGUN_WEAPON, 2);
                        else
                            imports->addammo(SHOTGUN_WEAPON, 1);
                    }
                    else
                    {
                        ifgotweaponce(0)
                            return;
                        imports->addweapon2(SHOTGUN_WEAPON, SHOTGUNAMMOAMOUNT);
                        imports->quote(57);
                    }
                    ifspawnedby(SHOTGUNSPRITE)
                        getweaponcode();
                    else
                        quikweaponget();
                }
}
void A_SIXPAK()
{
    imports->fall();
    ifmove(RESPAWN_ACTOR_FLAG)
        respawnit();
    else
    ifp(pshrunk)
    {
    }
    else
    ifp(palive)
        ifpdistl(RETRIEVEDISTANCE)
            ifcount(6)
                ifphealthl(MAXPLAYERHEALTH)
                    ifcanseetarget()
                    {
                        imports->addphealth(30);
                        imports->quote(62);
                        ifspawnedby(SIXPAK)
                            getcode();
                        else
                            quikget();
                    }
}
void A_COLA()
{
    imports->fall();
    ifmove(RESPAWN_ACTOR_FLAG)
        respawnit();
    else
    ifp(pshrunk)
    {
    }
    else
    ifp(palive)
        ifpdistl(RETRIEVEDISTANCE)
            ifcount(6)
                ifphealthl(MAXPLAYERHEALTH)
                    ifcanseetarget()
                    {
                        imports->addphealth(10);
                        imports->quote(61);
                        ifspawnedby(COLA)
                            getcode();
                        else
                            quikget();
                    }
}
void A_ATOMICHEALTH()
{
    imports->fall();
    ifmove(RESPAWN_ACTOR_FLAG)
        respawnit();
    else
    ifp(pshrunk)
    {
    }
    else
    ifp(palive)
        ifpdistl(RETRIEVEDISTANCE)
            ifcount(6)
                ifphealthl(MAXPLAYERATOMICHEALTH)
                    ifcanseetarget()
                    {
                        imports->addphealth(50);
                        imports->quote(19);
                        ifspawnedby(ATOMICHEALTH)
                            getcode();
                        else
                            quikget();
                    }
}
void A_FIRSTAID()
{
    imports->fall();
    ifmove(RESPAWN_ACTOR_FLAG)
        respawnit();
    else
    ifp(pshrunk)
    {
    }
    else
    ifp(palive)
        ifpdistl(RETRIEVEDISTANCE)
            ifcount(6)
                ifpinventory(GET_FIRSTAID, FIRSTAID_AMOUNT)
                    ifcanseetarget()
                    {
                        imports->addinventory(GET_FIRSTAID, FIRSTAID_AMOUNT);
                        imports->quote(3);
                        ifspawnedby(FIRSTAID)
                            getcode();
                        else
                            quikget();
                    }
}
void A_FIRSTGUNSPRITE()
{
    imports->fall();
    ifmove(RESPAWN_ACTOR_FLAG)
        respawnit();
    else
    ifp(pshrunk)
    {
    }
    else
    ifp(palive)
        ifpdistl(RETRIEVEDISTANCE)
            ifcount(6)
                ifcanseetarget()
                {
                    ifgotweaponce(0)
                        return;
                    imports->addweapon2(PISTOL_WEAPON, 48);
                    ifspawnedby(FIRSTGUNSPRITE)
                        getweaponcode();
                    else
                        quikweaponget();
                }
}
void A_TRIPBOMBSPRITE()
{
    imports->fall();
    ifmove(RESPAWN_ACTOR_FLAG)
        respawnit();
    else
    ifp(pshrunk)
    {
    }
    else
    ifp(palive)
        ifpdistl(RETRIEVEDISTANCE)
            ifcount(6)
                ifcanseetarget()
                {
                    ifgotweaponce(0)
                        return;
                    imports->addweapon2(TRIPBOMB_WEAPON, 1);
                    imports->quote(58);
                    ifspawnedby(TRIPBOMBSPRITE)
                        getweaponcode();
                    else
                        quikweaponget();
                }
}
void A_CHAINGUNSPRITE()
{
    imports->fall();
    ifmove(RESPAWN_ACTOR_FLAG)
        respawnit();
    else
    ifp(pshrunk)
    {
    }
    else
    ifp(palive)
        ifpdistl(RETRIEVEDISTANCE)
            ifcount(6)
                ifcanseetarget()
                {
                    ifgotweaponce(0)
                        return;
                    imports->addweapon2(CHAINGUN_WEAPON, 50);
                    imports->quote(54);
                    ifspawnedby(CHAINGUNSPRITE)
                        getweaponcode();
                    else
                        quikweaponget();
                }
}
void A_SHRINKERSPRITE()
{
    imports->fall();
    ifmove(RESPAWN_ACTOR_FLAG)
        respawnit();
    else
    ifp(pshrunk)
    {
    }
    else
    ifp(palive)
        ifpdistl(RETRIEVEDISTANCE)
            ifcount(6)
                ifcanseetarget()
                {
                    ifgotweaponce(0)
                        return;
                    imports->addweapon2(SHRINKER_WEAPON, 10);
                    imports->quote(60);
                    ifspawnedby(SHRINKERSPRITE)
                        getweaponcode();
                    else
                        quikweaponget();
                }
}
void A_FREEZESPRITE()
{
    imports->fall();
    ifmove(RESPAWN_ACTOR_FLAG)
        respawnit();
    else
    ifp(pshrunk)
    {
    }
    else
    ifp(palive)
        ifpdistl(RETRIEVEDISTANCE)
            ifcount(6)
                ifcanseetarget()
                {
                    ifgotweaponce(0)
                        return;
                    imports->addweapon2(FREEZE_WEAPON, FREEZEAMMOAMOUNT);
                    imports->quote(59);
                    ifspawnedby(FREEZESPRITE)
                        getweaponcode();
                    else
                        quikweaponget();
                }
}
void A_DEVISTATORSPRITE()
{
    imports->fall();
    ifmove(RESPAWN_ACTOR_FLAG)
        respawnit();
    else
    ifp(pshrunk)
    {
    }
    else
    ifp(palive)
        ifpdistl(RETRIEVEDISTANCE)
            ifcount(6)
                ifcanseetarget()
                {
                    ifgotweaponce(0)
                        return;
                    imports->addweapon2(DEVISTATOR_WEAPON, DEVISTATORAMMOAMOUNT);
                    imports->quote(87);
                    ifspawnedby(DEVISTATORSPRITE)
                        getweaponcode();
                    else
                        quikweaponget();
                }
}
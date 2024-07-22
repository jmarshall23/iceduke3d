#include "gamedll.h"

static MoveAction *DUKENOTMOVING = new MoveAction();
void handle_dead_dukes()
{
    imports->fall();
    ifmove(NULL)
    {
        ifrnd(128)
            imports->cstat(4);
        else
            imports->cstat(0);
        imports->Move(DUKENOTMOVING, 0, 0, 0);
    }
    ifsquished()
    {
        imports->sound(SQUISHED);
        random_ooz();
        imports->killit();
    }
    else
    ifcount(1024)
        ifpdistg(4096)
            imports->killit();
        else
        {
            imports->strength(0);
            ifhitweapon()
                ifwasweapon(RADIUSEXPLOSION)
                {
                    standard_jibs();
                    imports->killit();
                }
        }
}
static ConAction *PLYINGFRAMES = new ConAction(0, 1, 0, 1, 1);
void A_DUKELYINGDEAD()
{
    handle_dead_dukes();
}
static ConAction *PGROWING = new ConAction(0);
static ConAction *PSTAND = new ConAction(0, 1, 5, 1, 1);
static ConAction *PEXPLODE = new ConAction(106, 5, 1, 1, 10);
static ConAction *PEXPLODEAD = new ConAction(113, 1, 1);
static ConAction *PJPHOUVER = new ConAction(15, 1, 5, 1);
static ConAction *PWALK = new ConAction(20, 4, 5, 1, 16);
static ConAction *PRUN = new ConAction(20, 4, 5, 1, 10);
static ConAction *PWALKBACK = new ConAction(45, 4, 5, -1, 16);
static ConAction *PRUNBACK = new ConAction(45, 4, 5, -1, 10);
static ConAction *PJUMPING = new ConAction(50, 4, 5, 1, 30);
static ConAction *PFALLING = new ConAction(65, 1, 5);
static ConAction *PDUCKING = new ConAction(86, 1, 5);
static ConAction *PCRAWLING = new ConAction(86, 3, 5, 1, 20);
static ConAction *PAKICKING = new ConAction(40, 2, 5, 1, 25);
static ConAction *PFLINTCHING = new ConAction(106, 1, 1, 1, 10);
static ConAction *PTHROWNBACK = new ConAction(106, 5, 1, 1, 18);
static ConAction *PFROZEN = new ConAction(20, 1, 5);
static ConAction *PLYINGDEAD = new ConAction(113, 1, 1);
static ConAction *PSWIMMINGGO = new ConAction(375, 1, 5, 1, 10);
static ConAction *PSWIMMING = new ConAction(375, 4, 5, 1, 13);
static ConAction *PSWIMMINGWAIT = new ConAction(395, 1, 5, 1, 13);
static ConAction *PTREDWATER = new ConAction(395, 2, 5, 1, 17);
static MoveAction *PSTOPED = new MoveAction();
static MoveAction *PSHRINKING = new MoveAction();
void check_pstandard()
{
    ifp(pwalking)
        imports->SetAction(PWALK);
    else
    ifp(pkicking)
        imports->SetAction(PAKICKING);
    else
    ifp(pwalkingback)
        imports->SetAction(PWALKBACK);
    else
    ifp(prunning)
        imports->SetAction(PRUN);
    else
    ifp(prunningback)
        imports->SetAction(PRUNBACK);
    else
    ifp(pjumping)
        imports->SetAction(PJUMPING);
    else
    ifp(pducking)
        imports->SetAction(PDUCKING);
}
static MoveAction *PGROWINGPOP = new MoveAction();
void A_APLAYER()
{
    ifaction(NULL)
        imports->SetAction(PSTAND);
    ifaction(PFROZEN)
    {
        imports->cstat(257);
        imports->fall();
        imports->palfrom(16, 0, 0, 24);
        ifmove(NULL)
        {
            ifhitweapon()
            {
                ifwasweapon(FREEZEBLAST)
                    return;
                imports->lotsofglass(60);
                ifrnd(84)
                    imports->spawn(BLOODPOOL);
                imports->sound(GLASS_BREAKING);
                imports->spawn(ATOMICHEALTH);
                imports->getlastpal();
                imports->Move2(1, 0);
                return;
            }
        }
        else
        {
            imports->cstat(32768);
            imports->quote(13);
            ifhitspace()
            {
                imports->SetAction(PSTAND);
                imports->resetplayer();
            }
            return;
        }
        ifactioncount(THAWTIME)
        {
            imports->getlastpal();
            imports->strength(1);
            imports->Move2(0, 0);
            imports->SetAction(PSTAND);
        }
        else
        ifactioncount(FROZENDRIPTIME)
        {
            ifrnd(32)
                imports->spawn(WATERDRIP);
        }
        ifp(pfacing)
            ifpdistl(FROZENQUICKKICKDIST)
                imports->pkick();
        return;
    }
    ifdead()
    {
        ifaction(PGROWING)
        {
            ifmove(PGROWINGPOP)
            {
                imports->quote(13);
                ifhitspace()
                {
                    imports->SetAction(NULL);
                    imports->resetplayer();
                }
                return;
            }
            else
            {
                ifcount(32)
                {
                    imports->sound(SQUISHED);
                    imports->palfrom(48, 64, 0, 0);
                    standard_pjibs();
                    imports->guts(JIBS4, 20);
                    imports->guts(JIBS6, 20);
                    imports->Move(PGROWINGPOP, 0, 0, 0);
                    imports->cstat(32768);
                    imports->tossweapon();
                    imports->hitradius(2048, 60, 70, 80, 90);
                }
                else
                    imports->sizeto(MAXXSTRETCH, MAXYSTRETCH);
            }
            return;
        }
        ifsquished()
            imports->palfrom(32, 63, 63, 63);
        else
            imports->fall();
        ifactioncount(7)
            imports->Move2(0, 0);
        else
        ifactioncount(6)
        {
            ifmultiplayer()
            {
            }
            else
            {
                ifrnd(32)
                    imports->sound(DUKE_KILLED5);
                else
                ifrnd(32)
                    imports->sound(DUKE_KILLED3);
                else
                ifrnd(32)
                    imports->sound(DUKE_KILLED1);
                else
                ifrnd(32)
                    imports->sound(DUKE_KILLED2);
            }
        }
        ifaction(PLYINGDEAD)
        {
            ifactioncount(3)
                imports->Move(PSTOPED, 0, 0, 0);
            imports->quote(13);
            ifhitspace()
            {
                imports->SetAction(PSTAND);
                imports->spawn(DUKELYINGDEAD);
                imports->resetplayer();
            }
            return;
        }
        ifaction(PTHROWNBACK)
        {
            ifactioncount(5)
            {
                imports->spawn(BLOODPOOL);
                imports->SetAction(PLYINGDEAD);
            }
            else
            ifactioncount(1)
                imports->Move2(0, 0);
            return;
        }
        ifaction(PEXPLODEAD)
        {
            imports->quote(13);
            ifhitspace()
            {
                imports->resetplayer();
                imports->SetAction(PSTAND);
            }
            return;
        }
        ifaction(PEXPLODE)
        {
            ifactioncount(5)
            {
                imports->SetAction(PEXPLODEAD);
                imports->spawn(BLOODPOOL);
            }
            return;
        }
        ifp(pshrunk)
        {
            standard_pjibs();
            imports->spawn(BLOODPOOL);
            imports->sound(SQUISHED);
            imports->sound(DUKE_DEAD);
            imports->cstat(32768);
            imports->SetAction(PLYINGDEAD);
        }
        else
        {
            ifinwater()
            {
                imports->SetAction(PLYINGDEAD);
                imports->spawn(WATERBUBBLE);
                imports->spawn(WATERBUBBLE);
            }
            else
            {
                imports->SetAction(PEXPLODE);
                standard_pjibs();
                imports->cstat(32768);
                imports->sound(SQUISHED);
                imports->sound(DUKE_DEAD);
            }
        }
        imports->tossweapon();
        return;
    }
    ifsquished()
    {
        imports->strength(-1);
        imports->sound(SQUISHED);
        random_ooz();
        return;
    }
    ifp(ponsteroids)
    {
        ifp(pstanding)
        {
        }
        else
            imports->spawn(FRAMEEFFECT1);
    }
    ifmove(PSHRINKING)
    {
        ifcount(32)
        {
            ifcount(SHRUNKDONECOUNT)
            {
                imports->Move2(0, 0);
                imports->cstat(257);
            }
            else
            ifcount(SHRUNKCOUNT)
            {
                imports->sizeto(42, 36);
                ifgapzl(24)
                {
                    imports->strength(0);
                    imports->sound(SQUISHED);
                    imports->palfrom(48, 64, 0, 0);
                    return;
                }
            }
            else
            ifp(ponsteroids)
                imports->count(SHRUNKCOUNT);
        }
        else
        {
            ifp(ponsteroids)
                imports->count(SHRUNKCOUNT);
            else
            {
                imports->sizeto(8, 9);
                imports->spawn(FRAMEEFFECT1);
            }
        }
    }
    else
ifhitweapon()
    {
        ifdead()
        {
            ifmultiplayer()
                imports->sound(DUKE_KILLED4);
            ifwasweapon(GROWSPARK)
            {
                imports->palfrom(48, 48, 0, 0);
                imports->SetAction(PGROWING);
                imports->count(0);
                imports->Move2(0, 0);
                imports->sound(ACTOR_GROWING);
                imports->cstat(0);
                return;
            }
        }
        else
        {
            ifmultiplayer()
            {
                ifphealthl(YELLHURTSOUNDSTRENGTHMP)
                {
                    ifrnd(64)
                        imports->sound(DUKE_LONGTERM_PAIN2);
                    else
                    ifrnd(64)
                        imports->sound(DUKE_LONGTERM_PAIN3);
                    else
                    ifrnd(64)
                        imports->sound(DUKE_LONGTERM_PAIN4);
                    else
                        imports->sound(DUKE_DEAD);
                }
                else
                {
                    ifrnd(64)
                        imports->sound(DUKE_LONGTERM_PAIN5);
                    else
                    ifrnd(64)
                        imports->sound(DUKE_LONGTERM_PAIN6);
                    else
                    ifrnd(64)
                        imports->sound(DUKE_LONGTERM_PAIN7);
                    else
                        imports->sound(DUKE_LONGTERM_PAIN8);
                }
            }
            else
            {
                ifphealthl(YELLHURTSOUNDSTRENGTH)
                {
                    ifrnd(74)
                        imports->sound(DUKE_LONGTERM_PAIN2);
                    else
                    ifrnd(8)
                        imports->sound(DUKE_LONGTERM_PAIN3);
                    else
                        imports->sound(DUKE_LONGTERM_PAIN4);
                }
                ifrnd(128)
                    imports->sound(DUKE_LONGTERM_PAIN);
            }
        }
        ifstrength(TOUGH)
        {
            headhitstate();
            imports->sound(DUKE_GRUNT);
            ifp(pstanding)
                imports->SetAction(PFLINTCHING);
        }
        ifwasweapon(RPG)
        {
            ifrnd(32)
                imports->spawn(BLOOD);
            ifdead()
                standard_pjibs();
            imports->palfrom(48, 52, 0, 0);
            return;
        }
        ifwasweapon(RADIUSEXPLOSION)
        {
            ifrnd(32)
                imports->spawn(BLOOD);
            ifdead()
                standard_pjibs();
            imports->palfrom(48, 52, 0, 0);
            return;
        }
        ifwasweapon(FIREEXT)
        {
            ifrnd(32)
                imports->spawn(BLOOD);
            ifdead()
                standard_pjibs();
            imports->palfrom(48, 52, 0, 0);
            return;
        }
        ifwasweapon(GROWSPARK)
        {
            imports->palfrom(48, 52, 0, 0);
            imports->sound(EXPANDERHIT);
            return;
        }
        ifwasweapon(SHRINKSPARK)
        {
            imports->palfrom(48, 0, 48, 0);
            imports->Move(PSHRINKING, 0, 0, 0);
            imports->sound(ACTOR_SHRINKING);
            imports->cstat(0);
            return;
        }
        ifwasweapon(SHOTSPARK1)
            imports->palfrom(24, 48, 0, 0);
        ifwasweapon(FREEZEBLAST)
        {
            imports->palfrom(48, 0, 0, 48);
            ifdead()
            {
                imports->sound(SOMETHINGFROZE);
                imports->spritepal(1);
                imports->Move2(0, 0);
                imports->SetAction(PFROZEN);
                return;
            }
        }
        ifwasweapon(COOLEXPLOSION1)
            imports->palfrom(48, 48, 0, 48);
        ifwasweapon(KNEE)
            imports->palfrom(16, 32, 0, 0);
        ifwasweapon(FIRELASER)
            imports->palfrom(32, 32, 0, 0);
        ifdead()
        {
            imports->SetAction(PTHROWNBACK);
            imports->tossweapon();
        }
        random_wall_jibs();
        return;
    }
    ifaction(PFLINTCHING)
    {
        ifactioncount(2)
            imports->SetAction(PSTAND);
        return;
    }
    ifinwater()
    {
        ifaction(PTREDWATER)
        {
            ifp(pwalking, prunning)
                imports->SetAction(PSWIMMINGGO);
        }
        else
        ifp(pstanding, pwalkingback, prunningback)
            imports->SetAction(PTREDWATER);
        else
        {
            ifaction(PSWIMMING)
            {
                ifrnd(4)
                    imports->spawn(WATERBUBBLE);
                ifactioncount(4)
                    imports->SetAction(PSWIMMINGWAIT);
            }
            else
            ifaction(PSWIMMINGWAIT)
            {
                ifactioncount(2)
                    imports->SetAction(PSWIMMINGGO);
            }
            else
            ifaction(PSWIMMINGGO)
            {
                ifactioncount(2)
                    imports->SetAction(PSWIMMING);
            }
            else
                imports->SetAction(PTREDWATER);
        }
        ifrnd(4)
            imports->spawn(WATERBUBBLE);
        return;
    }
    else
    ifp(pjetpack)
    {
        ifaction(PJPHOUVER)
        {
            ifactioncount(4)
                imports->resetactioncount();
        }
        else
            imports->SetAction(PJPHOUVER);
        return;
    }
    else
    {
        ifaction(PTREDWATER)
            imports->SetAction(PSTAND);
        ifaction(PSWIMMING)
            imports->SetAction(PSTAND);
        ifaction(PSWIMMINGWAIT)
            imports->SetAction(PSTAND);
        ifaction(PSWIMMINGGO)
            imports->SetAction(PSTAND);
        ifaction(PJPHOUVER)
            imports->SetAction(PFALLING);
    }
    ifaction(PFALLING)
    {
        ifp(ponground)
            imports->SetAction(PSTAND);
        else
        {
            ifp(pfalling)
                return;
            else
                check_pstandard();
        }
    }
    ifaction(PDUCKING)
    {
        ifgapzl(48)
        {
            ifp(pwalking, pwalkingback, prunning, prunningback)
                imports->SetAction(PCRAWLING);
        }
        else
        ifp(pducking)
        {
            ifp(pwalking, pwalkingback, prunning, prunningback)
                imports->SetAction(PCRAWLING);
        }
        else
        {
            ifp(pstanding)
                imports->SetAction(PSTAND);
            else
                check_pstandard();
        }
    }
    else
    ifaction(PCRAWLING)
    {
        ifgapzl(48)
        {
            ifp(pstanding)
                imports->SetAction(PCRAWLING);
        }
        else
        ifp(pducking)
        {
            ifp(pstanding)
                imports->SetAction(PDUCKING);
        }
        else
        {
            ifp(pstanding)
                imports->SetAction(PSTAND);
            else
                check_pstandard();
        }
    }
    else
    ifgapzl(48)
        imports->SetAction(PDUCKING);
    else
    ifaction(PJUMPING)
    {
        ifp(ponground)
            imports->SetAction(PSTAND);
        else
        ifactioncount(4)
            ifp(pfalling)
                imports->SetAction(PFALLING);
    }
    ifp(pfalling)
        imports->SetAction(PFALLING);
    else
    ifaction(PSTAND)
        check_pstandard();
    else
    ifaction(PAKICKING)
    {
        ifactioncount(2)
            imports->SetAction(PSTAND);
        return;
    }
    else
    ifaction(PWALK)
    {
        ifp(pfalling)
            imports->SetAction(PFALLING);
        else
        ifp(pstanding)
            imports->SetAction(PSTAND);
        else
        ifp(prunning)
            imports->SetAction(PRUN);
        else
        ifp(pwalkingback)
            imports->SetAction(PWALKBACK);
        else
        ifp(prunningback)
            imports->SetAction(PRUNBACK);
        else
        ifp(pjumping)
            imports->SetAction(PJUMPING);
        else
        ifp(pducking)
            imports->SetAction(PDUCKING);
    }
    else
    ifaction(PRUN)
    {
        ifp(pstanding)
            imports->SetAction(PSTAND);
        else
        ifp(pwalking)
            imports->SetAction(PWALK);
        else
        ifp(pwalkingback)
            imports->SetAction(PWALKBACK);
        else
        ifp(prunningback)
            imports->SetAction(PRUNBACK);
        else
        ifp(pjumping)
            imports->SetAction(PJUMPING);
        else
        ifp(pducking)
            imports->SetAction(PDUCKING);
    }
    else
    ifaction(PWALKBACK)
    {
        ifp(pstanding)
            imports->SetAction(PSTAND);
        else
        ifp(pwalking)
            imports->SetAction(PWALK);
        else
        ifp(prunning)
            imports->SetAction(PRUN);
        else
        ifp(prunningback)
            imports->SetAction(PRUNBACK);
        else
        ifp(pjumping)
            imports->SetAction(PJUMPING);
        else
        ifp(pducking)
            imports->SetAction(PDUCKING);
    }
    else
    ifaction(PRUNBACK)
    {
        ifp(pstanding)
            imports->SetAction(PSTAND);
        else
        ifp(pwalking)
            imports->SetAction(PWALK);
        else
        ifp(prunning)
            imports->SetAction(PRUN);
        else
        ifp(pwalkingback)
            imports->SetAction(PWALKBACK);
        else
        ifp(pjumping)
            imports->SetAction(PJUMPING);
        else
        ifp(pducking)
            imports->SetAction(PDUCKING);
    }
}
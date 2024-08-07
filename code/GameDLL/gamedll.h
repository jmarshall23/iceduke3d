// gamedll.h
//

#define DNGAMEDLL_VERSION       2

#include <stdlib.h>
#include "defs.h"

#ifdef __cplusplus
class MoveAction;
#else
// If you update here update MoveAction in the class too!
typedef struct {
public:
    int horizontal;
    int vertical;
} MoveAction;
#endif

typedef struct GameDLLExports_s {
    int version;
    void (*G_Init)(void);
} GameDLLExports_t;

typedef struct GameDLLImports_s {
    void (*precachemodel)(int spritenum, const char* filename);
    void (*operatesector)(int sector);
    int (*FindEntityWithLotag)(int picnum, int lotag);
    int (*FindEntityWithHitag)(int picnum, int hitag);

    bool (*ParentalLockEnabled)();

    // Sector Accessor Functions
    void (*SetSectorWallPtr)(int sectNum, int value);
    void (*SetSectorWallNum)(int sectNum, int value);
    void (*SetSectorCeilingZ)(int sectNum, int value);
    void (*SetSectorFloorZ)(int sectNum, int value);
    void (*SetSectorCeilingStat)(int sectNum, int value);
    void (*SetSectorFloorStat)(int sectNum, int value);
    void (*SetSectorCeilingPicNum)(int sectNum, int value);
    void (*SetSectorCeilingHeinum)(int sectNum, int value);
    void (*SetSectorCeilingShade)(int sectNum, int value);
    void (*SetSectorCeilingPal)(int sectNum, int value);
    void (*SetSectorCeilingxpanning)(int sectNum, int value);
    void (*SetSectorCeilingypanning)(int sectNum, int value);
    void (*SetSectorFloorPicnum)(int sectNum, int value);
    void (*SetSectorFloorheinum)(int sectNum, int value);
    void (*SetSectorFloorShade)(int sectNum, int value);
    void (*SetSectorFloorpal)(int sectNum, int value);
    void (*SetSectorFloorxpanning)(int sectNum, int value);
    void (*SetSectorFloorypanning)(int sectNum, int value);
    void (*SetSectorVisbility)(int sectNum, int value);
    void (*SetSectorFiller)(int sectNum, int value);
    void (*SetSectorLotag)(int sectNum, int value);
    void (*SetSectorHitag)(int sectNum, int value);
    void (*SetSectorExtra)(int sectNum, int value);

    int (*GetSectorWallPtr)(int sectNum);
    int (*GetSectorWallNum)(int sectNum);
    int (*GetSectorCeilingZ)(int sectNum);
    int (*GetSectorFloorZ)(int sectNum);
    int (*GetSectorCeilingStat)(int sectNum);
    int (*GetSectorFloorStat)(int sectNum);
    int (*GetSectorCeilingPicNum)(int sectNum);
    int (*GetSectorCeilingHeinum)(int sectNum);
    int (*GetSectorCeilingShade)(int sectNum);
    int (*GetSectorCeilingPal)(int sectNum);
    int (*GetSectorCeilingxpanning)(int sectNum);
    int (*GetSectorCeilingypanning)(int sectNum);
    int (*GetSectorFloorPicnum)(int sectNum);
    int (*GetSectorFloorheinum)(int sectNum);
    int (*GetSectorFloorShade)(int sectNum);
    int (*GetSectorFloorpal)(int sectNum);
    int (*GetSectorFloorxpanning)(int sectNum);
    int (*GetSectorFloorypanning)(int sectNum);
    int (*GetSectorVisbility)(int sectNum);
    int (*GetSectorFiller)(int sectNum);
    int (*GetSectorLotag)(int sectNum);
    int (*GetSectorHitag)(int sectNum);
    int (*GetSectorExtra)(int sectNum);

    double (*DeltaTime)();
    int (*GetGlobalSpriteID)();

    // Sprite Accessor Functions
    int (*GetSpriteX)(int spriteID);
    int (*GetSpriteY)(int spriteID);
    int (*GetSpriteZ)(int spriteID);
    int (*GetCStat)(int spriteID);
    int (*GetPicNum)(int spriteID);
    int (*GetShade)(int spriteID);
    int (*GetPal)(int spriteID);
    int (*GetClipDist)(int spriteID);
    int (*GetFiller)(int spriteID);
    int (*GetXRepeat)(int spriteID);
    int (*GetYRepeat)(int spriteID);
    int (*GetXOffset)(int spriteID);
    int (*GetYOffset)(int spriteID);
    int (*GetSectNum)(int spriteID);
    int (*GetStatNum)(int spriteID);
    int (*GetAng)(int spriteID);
    int (*GetOwner)(int spriteID);
    int (*GetXVel)(int spriteID);
    int (*GetYVel)(int spriteID);
    int (*GetZVel)(int spriteID);
    int (*GetLotag)(int spriteID);
    int (*GetHitag)(int spriteID);
    int (*GetExtra)(int spriteID);

    void (*SetSpriteX)(int spriteID, int value);
    void (*SetSpriteY)(int spriteID, int value);
    void (*SetSpriteZ)(int spriteID, int value);
    void (*SetCStat)(int spriteID, int value);
    void (*SetPicNum)(int spriteID, int value);
    void (*SetShade)(int spriteID, int value);
    void (*SetPal)(int spriteID, int value);
    void (*SetClipDist)(int spriteID, int value);
    void (*SetFiller)(int spriteID, int value);
    void (*SetXRepeat)(int spriteID, int value);
    void (*SetYRepeat)(int spriteID, int value);
    void (*SetXOffset)(int spriteID, int value);
    void (*SetYOffset)(int spriteID, int value);
    void (*SetSectNum)(int spriteID, int value);
    void (*SetStatNum)(int spriteID, int value);
    void (*SetAng)(int spriteID, int value);
    void (*SetOwner)(int spriteID, int value);
    void (*SetXVel)(int spriteID, int value);
    void (*SetYVel)(int spriteID, int value);
    void (*SetZVel)(int spriteID, int value);
    void (*SetLotag)(int spriteID, int value);
    void (*SetHitag)(int spriteID, int value);
    void (*SetExtra)(int spriteID, int value);

    void (*RegisterVoxel)(const char* voxel);
    void (*tripbombresetposz)();
    void (*chaingunprojectileshift)(int sprite);
    void (*adjustspriteang)(int sprite, int ang);
    short (*ssp)(short i, unsigned int cliptype);
    void (*checkavailweapon)();
    int (*totalclock)();
    int (*sgn)(int i1);
    int (*sintable)(int index);
    int (*getspritepal)(int index);
    unsigned int (*krand)();
    void (*myospal)(int x, int y, int tilenum, int shade, int orientation, int p);

    void (*gamestartup)(int* parms, int count);

    void (*definemusic)(int episode, const char** music, int count);
    void (*definesound)(int id, const char* filename, int var1, int var2, int var3, int var4, int var5);
    void (*definelevelname)(int episode, int level, const char* mapfile, const char* time1, const char* time2, const char* name);
    void (*defineskillname)(int id, const char* name);
    void (*definevolumename)(int id, const char* name);
    void (*definequote)(int id, const char* str);
    void (*RegisterActor)(void* function, int picnum, int aiType, int aiType2, void* action, void* unknown2, int unknown3, int unknown4);

    bool (*ifnosounds)();
    bool (*ifangdiffl)(int value);
    bool (*ifspritepal)(int value);

    void (*respawnhitag)();
    bool (*ifnotmoving)();
    bool (*ifinouterspace)();
    void (*quote)(int value);
    bool (*ifawayfromwall)();
    void (*pstomp)();

    bool (*ifpinventory)(int val1, int val2);

    bool (*ifphealthl)(int value);
    void (*palfrom)(int v1, int v2, int v3, int v4);
    bool (*ifceilingdistl)(int val);
    bool (*iffloordistl)(int val);
    bool (*ifrespawn)();
    bool (*ifbulletnear)();
    void (*cactor)(int value);
    void (*spritepal)(int value);
    bool (*ifinspace)();
    void (*operate)();
    bool (*ifmultiplayer)();
    bool (*ifoutside)();
    bool (*ifhitspace)();
    bool (*ifgapzl)(int val);
    void (*wackplayer)();

    bool (*ifspawnedby)(int value);

    void (*guts)(int value1, int value2);

    bool (*ifstrength)(int value);

    bool (*ifp)(int value, void* notused, void* notused2, void* notused3, void* notused4);

    void (*hitradius)(int val1, int val2, int val3, int val4, int val5);

    void (*addinventory)(int val1, int val2);
    void (*resetcount)();
    bool (*ifactor)(int val1);
    bool (*ifcount)(int val);
    bool (*ifinwater)();
    bool (*ifonwater)();
    void (*resetplayer)();
    bool (*ifmove)(void* val1);

    void (*cstat)(int value);
    void (*clipdist)(int value);
    void (*cstator)(int value);
    void (*count)(int value);
    void (*debris)(int val1, int val2);
    bool (*ifrnd)(int val1);
    void (*resetactioncount)();
    bool (*ifactioncount)(int val1);

    void (*SetAction)(void* action);

    bool (*ifaction)(void* action);

    void (*Ai)(void* ai);
    bool (*ifai)(void* ai);

    bool (*ifwasweapon)(int val);
    int (*spawn)(int val);

    void (*Move)(MoveAction* val, int val2, int val3, int unknown1);
    void (*Move2)(int val, int val2);

    void (*addphealth)(int val);

    void (*endofgame)(int timebeforeexit);

    void (*debug)();

    void (*addweapon)(int val);
    void (*addweapon2)(int val, int val2);
    void (*killit)();
    void (*lotsofglass)(int val);
    void (*addkills)(int val);

    void (*paper)(int val);
    void (*sleeptime)(int val);
    void (*mail)(int val);

    void (*money)(int val);
    void (*addammo)(int val, int val2);
    void (*fall)();

    void (*tip)();
    void (*sound)(int val);
    void (*globalsound)(int val);
    void (*stopsound)(int val);
    void (*localsound)(int val);
    void (*soundonce)(int val);

    void (*shoot)(int val);
    void (*sizeat)(int val, int val2);
    void (*sizeto)(int val, int val2);
    void (*pkick)();
    void (*mikesnd)();
    void (*nullop)();
    void (*tossweapon)();

    void (*getlastpal)();
    bool (*ifgotweaponce)(int val);
    void (*strength)(int val);

    void (*addstrength)(int val);

    bool (*ifpdistg)(int val);

    bool (*ifpdistl)(int val);

    bool (*ifdead)();
    bool (*ifsquished)();

    bool (*ifhitweapon)();

    bool (*ifcansee)();

    bool (*ifactornotstayput)();

    bool (*ifcanseetarget)();
    bool (*ifcanshoottarget)();
} GameDLLImports_t;

extern GameDLLImports_t *imports;

#define ifnosounds() if(imports->ifnosounds())
#define ifangdiffl(v) if(imports->ifangdiffl(v))
#define ifspritepal(v) if(imports->ifspritepal(v))
#define ifnotmoving() if(imports->ifnotmoving())
#define ifinouterspace() if(imports->ifinouterspace())
#define ifawayfromwall() if(imports->ifawayfromwall())
#define ifpinventory(v1, v2) if(imports->ifpinventory(v1, v2))
#define ifphealthl(v) if(imports->ifphealthl(v))
#define ifceilingdistl(v) if(imports->ifceilingdistl(v))
#define iffloordistl(v) if(imports->iffloordistl(v))
#define ifrespawn() if(imports->ifrespawn())
#define ifbulletnear() if(imports->ifbulletnear())
#define ifinspace() if(imports->ifinspace())
#define ifmultiplayer() if(imports->ifmultiplayer())
#define ifoutside() if(imports->ifoutside())
#define ifhitspace() if(imports->ifhitspace())
#define ifgapzl(v) if(imports->ifgapzl(v))
#define ifspawnedby(v) if(imports->ifspawnedby(v))
#define ifstrength(v) if(imports->ifstrength(v))
#define ifp(v) if(imports->ifp(v, 0, 0, 0, 0))
#define ifactor(v) if(imports->ifactor(v))
#define ifcount(v) if(imports->ifcount(v))
#define ifinwater() if(imports->ifinwater())
#define ifonwater() if(imports->ifonwater())
#define ifmove(v) if(imports->ifmove(v))
#define ifrnd(v) if(imports->ifrnd(v))
#define ifactioncount(v) if(imports->ifactioncount(v))
#define ifaction(v) if(imports->ifaction(v))
#define ifai(v) if(imports->ifai(v))
#define ifwasweapon(v) if(imports->ifwasweapon(v))
#define ifpdistg(v) if(imports->ifpdistg(v))
#define ifpdistl(v) if(imports->ifpdistl(v))
#define ifdead() if(imports->ifdead())
#define ifsquished() if(imports->ifsquished())
#define ifhitweapon() if(imports->ifhitweapon())
#define ifcansee() if(imports->ifcansee())
#define ifactornotstayput() if(imports->ifactornotstayput())
#define ifcanseetarget() if(imports->ifcanseetarget())
#define ifcanshoottarget() if(imports->ifcanshoottarget())
#define ifgotweaponce(v) if(imports->ifgotweaponce(v))

// Macro definitions for define functions
#define definesound(id, filename, var1, var2, var3, var4, var5) imports->definesound(id, filename, var1, var2, var3, var4, var5)
#define definelevelname(episode, level, mapfile, time1, time2, name) imports->definelevelname(episode, level, mapfile, time1, time2, name)
#define definevolumename(id, name) imports->definevolumename(id, name)
#define defineskillname(id, name) imports->defineskillname(id, name)
#define definequote(id, str) imports->definequote(id, str)

// Definition of ConAction
#ifdef __cplusplus
struct ConAction {
#else
typedef struct {
#endif
    int startframe;
    int frames;
    int viewtype;
    int invvalue;
    int delay;

#ifdef __cplusplus
    ConAction()
    {
        this->startframe = 0;
        this->frames = 0;
        this->viewtype = 0;
        this->invvalue = 0;
        this->delay = 0;
    }
    ConAction(int startframe, int frames = 0, int viewtype = 0, int invvalue = 0, int delay = 0) {
        this->startframe = startframe;
        this->frames = frames;
        this->viewtype = viewtype;
        this->invvalue = invvalue;
        this->delay = delay;
    }
#endif

#ifdef __cplusplus
};
#else
} ConAction;
#endif

__forceinline int ConAction_get_index(const ConAction* action, int i) {
    switch (i) {
    case 0:
        return action->startframe;
    case 1:
        return action->frames;
    case 2:
        return action->viewtype;
    case 3:
        return action->invvalue;
    case 4:
        return action->delay;
    default:
        return -1; // Error value
    }
}

#ifdef __cplusplus
// If you update here update MoveAction in the struct too!
class MoveAction {
public:
    int horizontal;
    int vertical;

    MoveAction(int horizontal = 0, int vertical = 0)
        : horizontal(horizontal), vertical(vertical) {}

    int GetIndex(int i) const {
        switch (i) {
        case 0:
            return horizontal;
        case 1:
            return vertical;
        default:
            return -1;
        }
    }
};

class AIAction {
public:
    ConAction action;
    MoveAction moveAction;
    int val;

    AIAction(const ConAction& action, const MoveAction& moveAction, int val = 0, int unknown = 0)
        : action(action), moveAction(moveAction), val(val) {}
};

// Definition of ScriptActorRegistration
typedef void (*Function_t)();

typedef struct {
    Function_t func;
    int aiType;
    int aiType2;
    ConAction* action;
} ScriptActorRegistration;

__forceinline ScriptActorRegistration* ScriptActorRegistration_create(Function_t func, int aiType, int aiType2, ConAction* action) {
    ScriptActorRegistration* registration = (ScriptActorRegistration*)malloc(sizeof(ScriptActorRegistration));
    registration->func = func;
    registration->aiType = aiType;
    registration->aiType2 = aiType2;
    registration->action = action;
    return registration;
}

extern ConAction* ANULLACTION;
extern MoveAction* SHUTTLEVELS;
extern MoveAction* RESPAWN_ACTOR_FLAG;
extern MoveAction* MOUSEVELS;
extern ConAction* RUBCANDENT;
#endif

#include "gibs.h"
#include "actor_core.h"
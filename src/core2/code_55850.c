#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void func_80325794(ActorMarker *);

Actor *func_802DC7E0(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);
void func_802DC900(Actor *this);

/* .data */
f32 D_803680A0[3] = {0.0f, 0.0f, 0.0f};
ActorInfo D_803680AC = { 
    0x175, 0x1DC, 0x54D, 
    0x1, NULL, 
    func_802DC900, func_80326224, func_802DC7E0, 
    0, 0, 0.0f, 0
};

/* .bss */
ActorMarker *D_8037DE60;

/* .code */
Actor *func_802DC7E0(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx){
    Actor *this;
    f32 sp58[3];
    f32 sp4C[3];
    f32 sp40[3];
    f32 sp34[3];

    this = marker_getActor(marker);
    func_8033A2D4(func_803253A0, this);
    func_8033A2E8(func_80325794, marker);
    func_8024E258();
    sp58[0] = 0.0f;
    sp58[1] = 0.0f;
    sp58[2] = 860.0f;
    sp4C[0] = 0.0f;
    sp4C[1] = 0.0f;
    sp4C[2] = 0.0f;
    func_8024CD88(sp58);
    func_8024CE18(sp4C);
    func_8024CFD4();
    func_8024C904(gfx, mtx);
    sp40[0] = 0.0f;
    sp40[1] = 0.0f;
    sp40[2] = 0.0f;
    sp34[0] = 0.0f;
    sp34[1] = -87.0f;
    sp34[2] = 0.0f;
    func_803391A4(gfx, mtx, sp40, NULL, 1.0f, sp34, func_80330B1C(marker));
    func_8024E2FC();
    func_8024C904(gfx, mtx);
    return this;
}

void func_802DC8F0(Actor *this){
    D_8037DE60 = NULL;
}

void func_802DC900(Actor *this){
    if(!this->initialized){
        this->initialized = TRUE;
        this->unk124_9 = 0;
        actor_collisionOff(this);
        func_803300D8(this->marker, func_802DC8F0);
    }
}

void func_802DC960(void) {
    Actor *actor;
    if (D_8037DE60 == 0) {
        actor = func_8032813C(0x1DC, D_803680A0, 0);
        D_8037DE60 = actor->marker;
    }
}

void func_802DC9A4(s32 arg0, s32 arg1){
    if(D_8037DE60 == NULL){
        func_802C3BF8(func_802DC960);
    }
}

void func_802DC9DC(s32 arg0, s32 arg1){
    if(D_8037DE60 != NULL){
        func_80326310(marker_getActor(D_8037DE60));
    }
}

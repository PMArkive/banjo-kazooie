#include <ultra64.h>
#include "functions.h"
#include "variables.h"


void func_8038C0FC(Actor *this, s32 new_state);

void func_8038C204(Actor *this);

/* .data */
ActorInfo D_80390B10 = {
    0x199, 0x1CB, 0x0, 0x0, NULL,
    func_8038C204, NULL, func_80325340,
    {0, 0, 0, 0}, 0.0f, {0,0,0,0}
};

f32 D_80390B34[3] = {-5100.0f, -2550.0f, 1470.0f};

/* .code */
void func_8038C000(void){
    s32 sp1C = func_802F9AA8(SFX_7D_ANCHOR_LIFTING);
    func_802FA060(sp1C, 0x6978, 0x6978, 0.0f);
    func_802F9F80(sp1C, 0.5f, 7.0f, 0.5f);
}

void func_8038C058(void){
    func_8030E760(SFX_7F_HEAVYDOOR_SLAM, 0.8f, 0x55f0);
    func_8030E760(SFX_7F_HEAVYDOOR_SLAM, 0.9f, 0x55f0);
    func_8030E760(SFX_7F_HEAVYDOOR_SLAM, 1.0f, 0x55f0);
}

void func_8038C0A8(ActorMarker *marker, s32 arg1, s32 arg2){
    Actor *actor = marker_getActor(marker);
    jiggySpawn(JIGGY_53_RBB_SNORKEL, &D_80390B34);
    func_80324E60(0.5f, 0xb);
    func_8038C0FC(actor, 3);
}

void func_8038C0FC(Actor *this, s32 new_state){
    if(new_state == 2){
        func_802BAE20(0xC);
        func_80324E38(0.0f, 3);
        timedFunc_set_0(1.0f, func_8038C000);
        timedFunc_set_2(1.0f, (TFQM2)mapSpecificFlags_set, 8, TRUE);
        func_80324C88(2.1f, SFX_3F6_UNKNOWN, 0.6f, 0x7fbc);
        timedFunc_set_2(2.7f, (TFQM2)mapSpecificFlags_set, 4, TRUE);
        timedFunc_set_0(3.0f, func_8038C058);
        func_80324DBC(3.0f, 0xb9C, 7, NULL, this->marker, func_8038C0A8, NULL);
    }//L8038C1D8
    this->state = new_state;
}

void func_8038C204(Actor *this){
    if(!this->unk16C_4){
        this->unk16C_4 = 1;
        if(levelSpecificFlags_getSet(0x30, FALSE))
            func_8038C0FC(this, 2);
        else
            func_8038C0FC(this, 1);
        
        if(jiggyscore_80320F7C(JIGGY_53_RBB_SNORKEL))
            marker_despawn(this->marker);
    }//L8038C27C

    if(this->state == 3 && !mapSpecificFlags_get(4)){
        func_80324E88(0.0f);
        func_80324E38(0.0f, 0);
        timedFunc_set_0(0.0f, func_803228D8);
        timedFunc_set_3(0.0f, (TFQM3)func_802E4078, MAP_8B_RBB_ANCHOR_ROOM, 2, 0);
    }//L8038C2E4
}
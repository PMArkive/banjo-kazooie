#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern f32 func_80258640(f32[3], f32[3]);

typedef struct {
    s32 unk0;
} ActorLocal_lair_5640;

void func_8038BCF0(Actor *this);

/* .data */
ActorAnimationInfo D_80393710[] ={
    {0, 0.0f},
    {0x26B, 4.0f},
    {0x26C, 4.0f},
    {0x26B, 4.0f},
};
ActorInfo D_80393730 = { 0x1E0, 0x348, 0x539, 0x1, D_80393710, func_8038BCF0, func_80326224, func_80325888, { 0x7, 0xD0}, 0, 2.0f, { 0x0, 0x0, 0x0, 0x0}};

/* .code */
void func_8038BA30(ActorMarker *marker, enum asset_e text_id, s32 arg2){
    Actor *this;
    s32 phi_v1;

    this = marker_getActor(marker);
    phi_v1 = this->unk10_12*2;
    func_80320424(0x20 + this->unkF4_8*6 + phi_v1, 2);
}

void func_8038BA88(ActorMarker *marker, enum asset_e text_id, s32 arg2){
    Actor *this;

    this = marker_getActor(marker);
    item_set(ITEM_14_HEALTH, item_getCount(ITEM_15_HEALTH_TOTAL));
    func_80320004(this->unkF4_8 + 0xE8, TRUE);
}

void func_8038BADC(ActorMarker *marker, enum asset_e text_id, s32 arg2) {
    Actor *this;  

    this = marker_getActor(marker);
    if (text_id == ((ActorLocal_lair_5640 *)&this->local)->unk0 + 2) {
        if (!func_8031FF1C(this->unkF4_8 + 0xE8)) {
            if (item_getCount(ITEM_14_HEALTH) < item_getCount(ITEM_15_HEALTH_TOTAL)) {
                func_80311480(0x10A2, 0xF, this->position, this->marker, func_8038BADC, func_8038BA88);
                return;
            }
        }
        func_80311480(0xD38, 0xC, this->position, this->marker, func_8038BADC, NULL);
        return;
    }
    func_80328A84(this, 1);
}

void func_8038BBC0(Actor *this) {
    if (this->unk38_0) {
        comusic_8025AB44(COMUSIC_7A_BRENTILDA, 0, 10000);
        func_8025AABC(COMUSIC_7A_BRENTILDA);
        func_8032BB88(this, -1, 10000);
        this->unk38_0 = FALSE;
    }
}

void func_8038BC24(void) {
    s32 temp_v0;
    s32 phi_s0;
    s32 phi_s1;

    if (func_8031FF1C(0x5C) && !func_803203FC(0x62)) {
        func_8034A8BC(func_8031FF44(0xD3, 8));
        for(phi_s1 = 0; phi_s1 < func_8031A45C(3); phi_s1++){
            phi_s0 = 0x26 + 2*phi_s1;
                temp_v0 = randi2(0, 3);
                if (phi_s0 >= 0x61) {
                    func_80320524(0x26, temp_v0, 2);
                } else {
                    func_80320524(phi_s0, temp_v0, 2);
                }
        }
        func_803204E4(0x62, 1);
    }
}


void func_8038BCF0(Actor *this) {
    s32 sp78[6];
    s32 sp74;
    ActorLocal_lair_5640 *local;
    f32 sp64[3];
    f32 temp_f0;
    f32 phi_f2;
    f32 sp50[3];
    s16 sp48[3];


    local = (ActorLocal_lair_5640 *)&this->local;
    if (!this->initialized) {
        func_803300D8(this->marker, func_8038BBC0);
        actor_collisionOff(this);
        this->unk10_12 = 2;
        if (!func_8031FF1C(0x5C)) {
            func_80320044(0xD3, randi2(0, 0x100), 8);
            func_80320004(0x5C, TRUE);
        }
        func_8038BC24();
        actor_setOpacity(this, 0x40);
        this->initialized = TRUE;
    }

    if (!this->unk16C_4) {
        local->unk0 = this->unkF4_8*3 + 0x1080;
        this->unk16C_4 = TRUE;
    }

    func_8028E668(this->position, 280.0f, -40.0f, 160.0f);
    this->yaw_moving = (f32) func_80329784(this);
    func_80328FB0(this, 3.0f);
    func_8024E55C(0, sp78);
    player_getPosition(&sp64);
    temp_f0 = sp64[1] - this->position[1];
    if ((temp_f0 > -100.0f) && (temp_f0 < 350.0f)) {
        phi_f2 = func_80258640(sp64, this->position);
    } else {
        phi_f2 = 2000.0f;
    }
    if ((phi_f2 < 500.0) && (this->unk38_31  & 1)) {
        func_80329904(this->marker, 0x1F, sp50);
        sp48[0] = (s16)sp50[0];
        sp48[1] = (s16)sp50[1];
        sp48[2] = (s16)sp50[2];
        func_802F3B9C(sp48);
    }
    
    this->unk38_31++;
    switch (this->state) {
    case 1:
        sp74 = func_8032627C(this);
        if (phi_f2 < 500.0) {
            if (sp74 < 0xFF) {
                sp74 = (sp74 + 0xC < 0xFF) ? sp74 + 0xC : 0xFF;
                if (!this->unk138_24) {
                    func_8025A70C(COMUSIC_81_ACTIVATING_BRENTILDA);
                    func_80324D2C(1.0f, COMUSIC_81_ACTIVATING_BRENTILDA);
                    this->unk138_24 = TRUE;
                    this->unk138_23 = FALSE;
                }
            }
        }

        if (500.0 < phi_f2) {
            if (sp74 >= 0x41) {
                sp74 = (sp74 - 0xC >= 0x41) ? sp74 - 0xC : 0x40;
                if (!this->unk138_23) {
                    func_8025A70C(COMUSIC_8B_DEACTIVATE_BRENTILDA);
                    func_80324D2C(1.0f, COMUSIC_8B_DEACTIVATE_BRENTILDA);
                    this->unk138_23 = TRUE;
                    this->unk138_24 = FALSE;
                }
            }
        }
        actor_setOpacity(this, sp74);
        if (!func_803203FC(0x1F)) {
            if ((phi_f2 < 600.0) && !this->unk38_0) {
                comusic_8025AB44(COMUSIC_7A_BRENTILDA, -1, 0x1F4);
                func_8032BB88(this, 0, 0x1F4);
                this->unk38_0 = TRUE;
            }
            if ((600.0 < phi_f2) && this->unk38_0) {
                comusic_8025AB44(COMUSIC_7A_BRENTILDA, 0, 0x1F4);
                func_8025AABC(0x7A);
                func_8032BB88(this, -1, 0x1F4);
                this->unk38_0 = FALSE;
            }
        }
        if( (phi_f2 < 300.0) 
            && (func_8028ECAC() == 0) 
            && func_8028F20C()
            && !func_803114B0()) {
            if (!func_8031FF1C(0x96)) {
                func_80311480(0x10A1, 0xA, this->position, this->marker, func_8038BADC, NULL);
                func_80320004(0x96, TRUE);
                func_80328A84(this, 2);
                return;
            }
            if (func_8028EFC8() && (sp78[BUTTON_Z] == 1)) {
                this->unk10_12++;
                this->unk10_12 %= 3;
                func_80311174(local->unk0 + this->unk10_12, 0xB, this->position, this->marker, func_8038BADC, NULL, func_8038BA30);
                func_80328A84(this, 2);
                return;
            }
        } else {
            return;
        }
        break;
    case 2:
        if (actor_animationIsAt(this, 0.999f)) {
            func_80328A84(this, 3);
            return;
        }
        break;
    case 3:
        if (actor_animationIsAt(this, 0.999f)) {
            func_80328A84(this, 2);
        }
        break;
    }
}

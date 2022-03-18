#include <ultra64.h>
#include "functions.h"
#include "variables.h"


void func_8038E0C8(Actor *this);

/* .data */
extern ActorAnimationInfo D_8038F8F0[];

extern ActorInfo D_8038F908 = { 
    0x1F9, 0x1E9, 0x440,
    0x1, D_8038F8F0,
    func_8038E0C8, func_80326224, func_80325888,
    { 0x0, 0x0}, 0, 0.0f, { 0x0, 0x0, 0x0, 0x0}
};

/* .code */
void func_8038DFE0(Actor* actor) {
    func_80328B8C(actor, 1, 0.001f, 1);
    actor->unk38_31 = randi2(0, 0);
}

void func_8038E034(Actor* actor) {
    func_80328B8C(actor, 2, 0.001f, 1);
}

void func_8038E060(s32 arg0, ActorMarker *marker){
    Actor *this;
    f32 sp28[3];
    s32 pad24;
    f32 sp18[3];
    
    this = marker_getActor(marker);
    if(arg0){
        sp28[0] = 0.0f;
        sp28[1] = this->unk1C[0];
        sp28[2] = 0.0f;

        
        func_80345C78(sp18, sp28);
        func_8033A8F0(arg0, 1, sp18);
        func_8033A238(arg0);
    }
}

void func_8038E0C8(Actor *this) {
    f32 sp44[3];
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp34;

    sp34 = time_getDelta();

    if(!actor_playerIsWithinDist(this, 3000)) return;

    if (!this->unk16C_4) {
        this->unk16C_4 = TRUE;
        func_8028746C(this->animctrl, func_8038E060);
        func_8028748C(this->animctrl, (s32) this->marker);
        this->marker->propPtr->unk8_3 = TRUE;
        this->unk1C[0] = 0.0f;
        this->unk38_31 = 0;
    }

    if (player_getTransformation() == TRANSFORM_6_BEE) {
        actor_collisionOff(this);
    } else {
        actor_collisionOn(this);
        player_getPosition(&sp44);
        func_80258A4C(this->position, this->yaw - 90.0f, &sp44, &sp40, &sp3C, &sp38);
        if( (sp40 < 1050.0f) 
            && (sp38 > -1.0f)
            && (sp38 < 1.0f)
        ) {
            func_80258A4C(this->position, this->unk1C[0] + (this->yaw - 90.0f), &sp44, &sp40, &sp3C, &sp38);
            this->unk1C[0] += sp38 * 160.0f * sp34;
        } else {
            if (this->unk1C[0] > 0.0f) {
                this->unk1C[0] -= (30.0f * sp34);
                this->unk1C[0] = (this->unk1C[0] < 0.0f) ? 0.0f : this->unk1C[0];

            } else if (this->unk1C[0] < 0.0f) {
                this->unk1C[0] += (30.0f * sp34);
                this->unk1C[0] = (this->unk1C[0] > 0.0f) ? 0.0f : this->unk1C[0];
            }
        }
    }
    switch (this->state) {
    case 1:
        if (this->unk38_31 != 0) {
            this->unk38_31--; 
            break;
        }
        if( func_80329530(this, 0x2A8) 
            && (this->unk38_31 == 0) 
            && (player_getTransformation() == TRANSFORM_1_BANJO)
        ) {
            func_8038E034(this);
        }
        break;

    case 2:
        if (actor_animationIsAt(this, 0.999f)) {
            func_8038DFE0(this);
            break;
        }
        if( actor_animationIsAt(this, 0.18f)
            || actor_animationIsAt(this, 0.47f)
            || actor_animationIsAt(this, 0.78f)
        ) {
            FUNC_8030E8B4(SFX_80_YUMYUM_CLACK, 1000, 0x3ff, this->position, 0x5DC, 0xBB8);
        }
        break;
    }
}

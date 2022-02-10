#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern Actor *func_802EBAE0(UNK_TYPE(s32), f32 position[3], f32 rotation[3], f32 scale, UNK_TYPE(s32), UNK_TYPE(s32), UNK_TYPE(s32), f32, UNK_TYPE(s32));

Actor *func_8038C1F8(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);
void func_8038C9A0(Actor *this);

/* .data */
extern ActorAnimationInfo D_80391F50[];

extern ActorInfo D_80391F88 = { MARKER_200_TWINKLY_BLUE, ACTOR_332_TWINKLY_BLUE, ASSET_448_MODEL_TWINKLY_BLUE,
    0x1, D_80391F50,
    func_8038C9A0, func_80326224, func_8038C1F8,
    { 0x0, 0x0}, 0, 1.0f, { 0x0, 0x0, 0x0, 0x0}
};

extern ActorInfo D_80391FAC = { MARKER_201_TWINKLY_GREEN, ACTOR_333_TWINKLY_GREEN, ASSET_449_MODEL_TWINKLY_GREEN,
    0x1, D_80391F50,
    func_8038C9A0, func_80326224, func_8038C1F8,
    { 0x0, 0x0}, 0, 1.0f, { 0x0, 0x0, 0x0, 0x0}
};

extern ActorInfo D_80391FD0 = { MARKER_202_TWINKLY_ORANGE, ACTOR_334_TWINKLY_ORANGE, ASSET_44A_MODEL_TWINKLY_ORANGE,
    0x1, D_80391F50,
    func_8038C9A0, func_80326224, func_8038C1F8,
    { 0x0, 0x0}, 0, 1.0f, { 0x0, 0x0, 0x0, 0x0}
};

extern ActorInfo D_80391FF4 = { MARKER_203_TWINKLY_RED, ACTOR_335_TWINKLY_RED, ASSET_44B_MODEL_TWINKLY_RED,
    0x1, D_80391F50,
    func_8038C9A0, func_80326224, func_8038C1F8,
    { 0x0, 0x0}, 0, 1.0f, { 0x0, 0x0, 0x0, 0x0}
};

extern UNK_TYPE(u8) D_80392018;
extern struct43s D_80392028;
extern f32 D_80392070[3];
extern UNK_TYPE(u8) D_8039207C;

extern f64 D_80392DB8;
extern f64 D_80392DC0;
extern f64 D_80392DC8;

/* .code */
Actor *func_8038C0B0(ActorMarker *marker, UNK_TYPE(s32) arg1, f32 arg2, UNK_TYPE(s32) arg3){
    UNK_TYPE(s32) sp5C = func_8033A12C(func_80330B1C(marker));
    Actor *this = marker_getActor(marker);
    f32 sp4C[3];
    f32 sp40[3];
    f32 sp3C;

    sp4C[0] = (f32)marker->propPtr->x;
    sp4C[1] = (f32)marker->propPtr->y;
    sp4C[2] = (f32)marker->propPtr->z;

    sp40[0] = (f32)marker->pitch;
    sp40[1] = this->unk60;
    sp40[2] = (f32)marker->roll;
    sp3C = this->scale;
    if(func_802EA190(marker->unk20)){
        return func_802EBAE0(sp5C, sp4C, sp40, sp3C, NULL, marker->unk20, arg1, arg2, arg3);
    }
    else{
        return NULL;
    }
}

Actor *func_8038C1F8(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx){
    Actor *this = marker_getActor(marker);
    func_8033A45C(2, this->unk38_31);
    func_8033A45C(1, func_8033A0F0(2) ^ 1);
    return func_80325888(marker, gfx, mtx, vtx);
}

void func_8038C260(f32 position[3], s32 count, enum asset_e model_id){
    ParticleEmitter *pCtrl;

    pCtrl = partEmitList_pushNew(count);
    particleEmitter_setModel(pCtrl, model_id);
    particleEmitter_setPosition(pCtrl, position);
    particleEmitter_setPositionVelocityAndAccelerationRanges(pCtrl, &D_80392028);
    func_802EFE24(pCtrl,
        400.0f, 400.0f, 400.0f,
        800.0f, 800.0f, 800.0f
    );
    func_802EFB70(pCtrl, 0.1f, 0.2f);
    particleEmitter_setSpawnIntervalRange(pCtrl, 0.0f, 0.02f);
    func_802EFEC0(pCtrl, 1.5f, 1.5f);
    func_802EFA5C(pCtrl, 0.0f, 0.3f);
    func_802EF9F8(pCtrl, 0.6f);
    func_802EFA18(pCtrl, 0);
    func_802EFA20(pCtrl, 1.0f, 1.3f);
    func_802EF9EC(pCtrl, 0x7B, 8000);
    particleEmitter_emitN(pCtrl, count);
}

void func_8038C398(f32 position[3], enum marker_e marker_id){
    enum asset_e sp1C;
    switch(marker_id){
        case MARKER_200_TWINKLY_BLUE:
            sp1C = ASSET_497_MODEL_TWINKLY_SHARD_BLUE;
            break;

        case MARKER_201_TWINKLY_GREEN:
            sp1C = ASSET_499_MODEL_TWINKLY_SHARD_GREEN;
            break;
        
        case MARKER_202_TWINKLY_ORANGE:
            sp1C = ASSET_49A_MODLE_TWINKLY_SHARD_ORANGE;
            break;

        case MARKER_203_TWINKLY_RED:
            sp1C = ASSET_49B_MODLE_TWINKLY_SHARD_RED;
            break;
    }
    func_8038C260(position, 12, sp1C);
    func_8038C260(position, 4, ASSET_498_MODEL_TWINKLY_SHARD_YELLOW);
}

void func_8038C428(Actor *this, UNK_TYPE(s32) arg1, f32 arg2);
#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_5CC0/func_8038C428.s")

bool func_8038C718(Actor *this, f32 arg1){
    f32 tmp;

    this->position[0] += this->velocity[0];
    this->position_y += (this->velocity_y += D_80392DB8);
    this->position_z += this->velocity_z;
    tmp = D_80392DC0 < func_802877D8(this->animctrl) + this->unk1C[0] ? D_80392DC8 : func_802877D8(this->animctrl) + this->unk1C[0];
    func_8028764C(this->animctrl, tmp);

    if(arg1 == 0.0f)
        arg1 = func_80309724(this->position);

    if(this->position_y <= arg1){
        this->position_y = arg1;
        return FALSE;
    }
    return TRUE;
}

bool func_8038C844(f32 arg0[3], f32 arg1[3]){
    if( (arg0[0] - arg1[0] < 26.0f && -26.0f < arg0[0] - arg1[0])
        && (arg0[1] - arg1[1] < 26.0f && -26.0f < arg0[1] - arg1[1])
        && (arg0[2] - arg1[2] < 26.0f && -26.0f < arg0[2] - arg1[2])
    ){
        return TRUE;
    }
    return FALSE;
}

void func_8038C8F0(ActorMarker *marker){
    Actor *this;
    Actor *muncher;
    Actor *other;
    s32 pad;

    this = marker_getActor(reinterpret_cast(ActorMarker *, marker));
    other = marker_getActor(this->unk100);
    muncher = func_8032813C(ACTOR_337_TWINKLY_MUNCHER, D_80392070, 170);
    muncher->unk100 = other->marker;
    muncher->unkF4_8 = 1;

    if(pad);
}

void func_8038C94C(ActorMarker *caller, enum asset_e text_id, s32 arg2){
    Actor *this = marker_getActor(caller);
    if(!func_803203FC(0xC1)){
        func_80328A84(this, 6);
        func_802C3C88(func_8038C8F0, this->marker);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_5CC0/func_8038C9A0.s")
// void func_8038C9A0(Actor *this){
//     Actor *other; //sp34
//     void * sp30;

//     if(this->marker->unk14_20 == 0x200){
//         sp30 = func_8034C2C4(this->marker, 0x190);
//     }
//     other = marker_getActor(this->unk100);

//     if(!this->unk16C_4){
//         this->unk16C_4 = TRUE;
//         this->marker->unk18 = &D_80392018;
//         this->unk38_31 = 0;
//         if(0.0f != other->velocity[0]){
//             func_80328A84(this, 4);
//             this->unk1C[1] = this->position_y + 50.0f;
//             this->unk1C[2] = this->position_y;
//         }
//         else{
//             this->velocity_x = 0.0f;
//             this->velocity_y = 0.0f;
//             this->velocity_z = 0.0f;
//             this->unk1C[0] = 0.0f;
//             func_8028764C(this->animctrl, 0.0f);
//             func_8038C428(this, &D_8039207C, 0);
//             return;
//         }
//     }//L8038CA9C

//     if(1.0f == other->unk1C[1]){
//         func_8038C398(this->position, this->marker->unk14_20);
//         FUNC_8030E8B4(SFX_7B_ICE_BREAKING_1, 1000, 0x3ff, this->position, 0x6d6, 0xdac);\
//         marker_despawn(this->marker);
//         return;
//     }//L8038CB04

//     switch(this->state){

//     }
// }

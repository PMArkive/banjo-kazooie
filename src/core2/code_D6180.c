#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_8035D3D8(Actor *this);
extern void func_802DABA0(ParticleEmitter *, f32 position[3], f32 scale, enum asset_e model_id);

typedef struct {
    f32 unk0;
    f32 unk4;
    u8 unk8;
    u8 unk9;
    u8 unkA;
    u8 unkB;
    u32 unkC_31:3;
    u32 unkC_28:1;
    u32 padC_27:28;
    s16 unk10;
    s16 unk12;
    f32 unk14;
    f32 unk18;
    s16 unk1C;
    s16 unk1E;
    f32 unk20;
    f32 unk24;
    s16 unk28;
    s16 unk2A;
    f32 unk2C;
    void (*unk30)(ActorMarker *, s32);
    void (*unk34)(ActorMarker *, s32);
}ActorLocal_core2_D6180;

/* .data */ 
extern ActorAnimationInfo D_80372E20[];
extern ActorInfo D_80372E78 = { 
    0x219, 0x34F, 0x4C7, 
    0x1, D_80372E20, 
    func_8035D3D8, func_80326224, func_80325888, 
    2500, 0, 1.0f, 0
};

/* .rodata */
extern f32 D_80379860;
extern f32 D_80379864;
extern f32 D_80379868;

/* .code */
void func_8035D110(ParticleEmitter *p_emitter, Actor *this, enum asset_e model_id) {
    func_802DABA0(p_emitter, this->position, this->scale, model_id);
    particleEmitter_setParticleAccelerationRange(p_emitter, 0.0f, -1800.0f, 0.0f, 0.0f, -1800.0f, 0.0f);
    func_802EFE24(p_emitter, -600.0f, -600.0f, -600.0f, 600.0f, 600.0f, 600.0f);
    particleEmitter_setParticleVelocityRange(p_emitter, -50.0f, 750.0f, -50.0f, 120.0f, 900.0f, 120.0f);
    particleEmitter_emitN(p_emitter, 1);
}


void func_8035D1F0(ActorMarker *arg0, s32 arg1) {
    Actor *this;

    this = marker_getActor(arg0);
    func_802DAC84(partEmitList_pushNew(2), this, 0x4C9);
    func_802DAD08(partEmitList_pushNew(1), this, 0x4CA);
    func_802DAD8C(partEmitList_pushNew(2), this, 0x4C8);
    func_8035D110(partEmitList_pushNew(1), this, 0x4CB);
    FUNC_8030E8B4(SFX_119_FISH_DEATH, 0.8f, 32000, this->position, 1250, 2500);
    func_802C3F04((GenMethod_4) func_802C4140, ACTOR_4C_STEAM, reinterpret_cast(s32, this->position[0]), reinterpret_cast(s32, this->position[1]), reinterpret_cast(s32, this->position[2]));
    marker_despawn(arg0);
}

void func_8035D2C0(ActorMarker *marker, s32 arg1){
    Actor *actor = marker_getActor(marker);
    func_802DB4E0(marker, arg1);
    actor_collisionOn(actor);
}

void func_8035D2FC(Actor *this) {
    ActorLocal_core2_D6180 *local;
    u8 temp_t6;

    local = (ActorLocal_core2_D6180 *)&this->local;
    local->unk0 = 2.0f;
    local->unk4 = 4.0f;
    local->unk8 = 3;
    local->unk9 = 6;
    local->unkA = 8;
    local->unkB = 4;
    local->unkC_31 = 0;
    local->unk10 = 0x10C; //SFX_10C_MUMMY_TALKING
    local->unk12 = 20000;
    local->unk14 = 1.5f;
    local->unk18 = D_80379860;
    local->unk1C = 0x10D; //SFX_10D_ANCIENT_ONE_TALKING
    local->unk1E = 20000;
    local->unk20 = D_80379864;
    local->unk24 = D_80379868;
    local->unk28 = 0xC5; //SFX_C5_TWINKLY_POP
    local->unk2A = 20000;
    local->unk2C = 1.0f;
    local->unkC_28 = TRUE;
    local->unk30 = func_8035D2C0;
    local->unk34 = func_8035D1F0;
    this->unk154 |= 0x08000000;
}

void func_8035D3D8(Actor *this) {
    if (!this->unk16C_4) {
        func_8035D2FC(this);
    }
    func_802DB5A0(this);
    if (this->state == 9) {
        if (this->marker->unk14_20 != 0x298) {
            this->marker->unk14_20 = 0x298;
        }
    } else {
        if (this->marker->unk14_20 != 0x219) {
            this->marker->unk14_20 = 0x219;
        }
    }
}

/* BREAK??? */
void func_8035D490(ActorMarker *marker){
    Actor *sp1C;

    if (map_get() == MAP_13_GV_MEMORY_GAME) {
        sp1C = marker_getActor(marker);
        if (func_80329530(sp1C, 250) != 0) {
            func_802C9334(0x1C, sp1C);
            func_8035D2C0(marker, 0);
        }
    }
}

void func_8035D4F0(ActorMarker *marker, s32 arg1){
    s32 pad;
    Actor *actor;
    if(map_get() == MAP_13_GV_MEMORY_GAME){
        actor = marker_getActor(marker);
        if(actor->state != 9){
            if(func_8033F3E8(func_80309744(0), actor->position, 0x190, 0x1A0) == arg1){
                func_802C9334(0x1C, actor);
                func_8035D2C0(marker, 0);
            }
        }
    }
}
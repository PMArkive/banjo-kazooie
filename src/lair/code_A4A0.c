#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern func_802DB548(ActorMarker *, ActorMarker *);

typedef struct {
    f32 unk0;
    f32 unk4;
    s8  unk8;
    s8  unk9;
    s8  unkA;
    s8  unkB;
    u32 unkC_31:3;
    u32 unkC_28:1;
    u32 unkC_27:28;
    s16 unk10;
    s16 unk12;
    f32 unk14;
    u8 pad18[0x18];
    void (*unk30)(ActorMarker *, ActorMarker *);
    void (*unk34)(ActorMarker *, ActorMarker *);
    u8 pad38[0x4];
    f32 unk3C;
} ActorLocal_lair_A4A0;

void func_80390AE8(Actor *this);

/* .data */
ActorAnimationInfo D_803949B0[] ={
    {0x000, 0.0f},
    {0x26D, 4.0f},
    {0x26D, 0.7f},
    {0x26F, 0.7f},
    {0x26E, 0.9f},
    {0x270, 1.6f},
    {0x26D, 1.5f},
    {0x26F, 0.5f},
    {0x26D, 1.5f},
    {0x26D, 1000000.0f},
    {0x26D, 1000000.0f},
};
ActorInfo D_80394A08 = { 0x1EA, 0x367, 0x54A, 0x1, D_803949B0, func_80390AE8, func_80326224, func_80325888, { 0x9, 0xC4}, 0, 1.0f, { 0x0, 0x0, 0x0, 0x0}};
ActorInfo D_80394A2C = { 0x295, 0x3BF, 0x561, 0x1, D_803949B0, func_80390AE8, func_80326224, func_80325888, { 0x9, 0xC4}, 0, 1.0f, { 0x0, 0x0, 0x0, 0x0}};
ActorInfo D_80394A50 = { 0x1F1, 0x3C0, 0x562, 0x1, D_803949B0, func_80390AE8, func_80326224, func_80325888, { 0x9, 0xC4}, 0, 1.0f, { 0x0, 0x0, 0x0, 0x0}};

/* .code */
void func_80390890(ActorMarker *marker, ActorMarker *other_marker) {
    Actor *this;
    ActorLocal_lair_A4A0 *local;

    this = marker_getActor(marker);
    local = (ActorLocal_lair_A4A0 *)&this->local;
    func_80328B8C(this, 5, 0.0f, 1);
    actor_playAnimationOnce(this);
    func_8030E878(SFX_C2_GRUBLIN_EGH, local->unkC_27*0.1 + 0.8, 32000, this->position, 1250.0f, 2500.0f);
    func_802C3F04(func_802C4140, ACTOR_4C_STEAM, reinterpret_cast(s32, this->position[0]), reinterpret_cast(s32, this->position[1]), reinterpret_cast(s32, this->position[2]));
    actor_collisionOff(this);
    this->unk138_24 = TRUE;
}

void func_80390994(Actor *this) {
    ActorLocal_lair_A4A0 *local;

    local = (ActorLocal_lair_A4A0 *)&this->local;
    local->unk0 = 5 - local->unkC_27;
    local->unk4 = 8 - local->unkC_27 * 2;
    local->unk8 = 6 - local->unkC_27;
    local->unk9 = 0xC - local->unkC_27 * 2;
    local->unkA = 0x10 - (local->unkC_27 * 3);
    local->unkB = 8 - local->unkC_27;
    local->unkC_31 = 1;
    local->unk10 = 0xFB;
    local->unk12 = 0x7530;
    local->unk14 = local->unkC_27 * 0.1 + 0.8;
    local->unk3C = local->unkC_27 * 0.2 + 1.1;
    local->unkC_28 = TRUE;
    local->unk30 = func_802DB548;
    local->unk34 = func_80390890;
}

void func_80390AE8(Actor *this) {
    ActorLocal_lair_A4A0 *local;

    local = (ActorLocal_lair_A4A0 *)&this->local;
    if (!this->unk16C_4) {
        local->unkC_27 = (this->modelCacheIndex == 0x367) ? 2
                       : (this->modelCacheIndex == 0x3bf) ? 1 
                       : 0;
        func_80390994(this);
    }
    func_802DB5A0(this);
    if (this->state == 5) {
        if (actor_animationIsAt(this, 0.18f)) {
            func_8030E8B4(0x7FFB5802, this->position, 0x09C404E2);
        }
        if (actor_animationIsAt(this, 0.7f)) {
            func_8030E8B4(0x7FFB581F, this->position, 0x09C404E2);
        }
    }
}

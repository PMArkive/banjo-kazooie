#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern f32  func_8025715C(f32, f32);
extern void func_8025727C(f32, f32, f32, f32, f32, f32, f32*, f32*);
extern void func_8028F4B8(f32[3], f32, f32);
extern void func_80320ED8(ActorMarker *, f32, s32);

extern s32 func_803297C8(Actor*, f32*);
extern void func_803900DC(ActorMarker *, f32 *, f32, f32);
extern void func_80324CFC(f32, enum comusic_e, s32);
extern void sfxsource_setSampleRate(u8, s32);
extern void func_80328FF0(Actor *arg0, f32 arg1);
extern f32 func_80257204(f32, f32, f32, f32);
extern void func_8028F85C(f32[3]);
extern void func_8028FAEC(f32[3]);
extern f32 func_8033229C(ActorMarker *);
extern void func_8034DF30(Struct6Ds *, f32[3], f32[3], f32);

extern f32 func_80391234();
extern f32 func_8038DFA0();
extern f32 func_80391240();

Actor *chfinalwitch_draw(ActorMarker *arg0, Gfx **arg1, Mtx **arg2, Vtx **arg3);
void chfinalwitch_update(Actor *this);

void func_8038856C(Actor *actor, f32 *arg1);

void chfinalwitch_phase1_setState(Actor *arg0, s32 arg1);
ActorMarker *func_8038A4E8(Actor *, f32);
void chfinalwitch_phase5_setState(Actor *, s32);
void chfinalwitch_phase1_init();
void func_8038C5F0(Actor *, s32, s32, f32);
void func_80391070(ActorMarker *, s32 arg1, s32 arg2);
void func_803911F8(ActorMarker *);

typedef struct ch_fight_180_s{
    u8 phase; //phase
    u8 hits;  //hits
    u8 egg_hits;
    u8 unk3;
    u8 unk4;
    u8 unk5;
    u8 unk6;
    u8 unk7;
    u8 unk8;
    u8 unk9;
    u8 unkA;
    u8 unkB;
    u8 unkC; //bone_5_visibility
    u8 unkD; //bone_3_visibility
    u8 unkE; //bone_4_visibility
    u8 unkF;
    s32 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    u8 pad24[4];
    f32 unk28;
    f32 unk2C;
}ActorLocal_fight_180;

/* .data */
static f32 D_80391380[4] = {1.0f, 1.0f, 1.0f, 1.0f};
static f32 D_80391390[4] = {0.33f, 0.33f, 0.33f, 1.0f};
ActorAnimationInfo D_803913A0[] = {
    { 0, 0.0f},
    { 0x1C5, 0.6f},
    { 0x1C5, 0.6f},
    { 0x1C5, 0.6f},
    { 0x1C5, 0.8f},
    { 0x1C5, 0.6f},
    { 0x25C, 1.0f},
    { 0x25C, 1.0f},
    { 0x25E, 6.5f},
    { 0x25E, 6.5f},
    { 0x25A, 1.1f},
    { 0x1C5, 1.0f},
    { 0x257, 2.5f},
    { 0x259, 1.4f},
    { 0x1C5, 0.6f},
    { 0x1C5, 0.8f},
    { 0x25A, 1.1f},
    { 0x257, 2.5f},
    { 0x1C5, 0.8f},
    { 0x258, 1.0f},
    { 0x259, 1.4f},
    { 0x1C5, 0.6f},
    { 0x1C5, 0.8f},
    { 0x1C5, 0.8f},
    { 0x25A, 1.1f},
    { 0x259, 1.4f},
    { 0x267, 3.0f},
    { 0x1C5, 0.8f},
    { 0x1C5, 0.6f},
    { 0x1C5, 0.8f},
    { 0x25A, 1.1f},
    { 0x1C5, 0.8f},
    { 0x259, 1.4f},
    { 0x263, 0.5f},
    { 0x25D, 7.0f},
    { 0x25F, 1.0f},
    { 0x25F, 1.0f},
    { 0x260, 1.1f},
    { 0x261, 2.5f},
    { 0x25F, 1.0f},
    { 0x279, 3.0f},
    { 0x283, 0.25f},
    { 0x27A, 1.0f},
    { 0x266, 4.0f}
};

ActorInfo D_80391500 = {
    MARKER_25E_GRUNTILDA_FINAL_BOSS, ACTOR_38B_GRUNTILDA_FINAL_BOSS, ASSET_53D_MODEL_GRUNTILDA_FINAL_BOSS, 
    1,  D_803913A0,
    chfinalwitch_update, func_80326224, chfinalwitch_draw,
    0, 0, 0.0f, 0
};


/* .bss */
// static f32 D_80392750;
f32 D_80392758[3];
f32 D_80392768[3];
f32 D_80392778[3];
f32 D_80392788[3];
f32 D_80392798[3];
ActorMarker *sFinalWitchShadowMarker; //D_803927A4
ActorMarker *sFlightPadMarker; //D_803927A8
ActorMarker *sJinjoStatueMarker[4]; //D_803927B0
f32 D_803927C0;
u8 D_803927C4;
u8 sFinalWitch_SpellBarrierActive;
u8 D_803927C6;
u8 D_803927C7;
u8 D_803927C8;
u8 D_803927C9;
f32 D_803927D0[0x13][3];
// static f32 D_803928B8[3];
// static s32 D_803928C4;
// static f32 D_803928C8[3];


/* .code */
Actor *chfinalwitch_draw(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx) {
    Actor *this = marker_getActor(marker);
    ActorLocal_fight_180 *localActor = (ActorLocal_fight_180 *)&this->local;

    func_8033A45C(3, localActor->unkD);
    func_8033A45C(4, localActor->unkE);
    func_8033A45C(5, localActor->unkC);
    if (localActor->phase == 1) {
        func_8033A25C(0);
    }
    return func_80325888(marker, gfx, mtx, vtx);
}

//set bone_5 visibility
void func_80386600(ActorMarker *marker, s32 arg1) {
    Actor *this;
    ActorLocal_fight_180 *local;

    this = marker_getActor(marker);
    local = (ActorLocal_fight_180 *)&this->local;
    local->unkC = arg1;
}

void func_80386628(ActorMarker *arg0, s32 arg1) {
    Actor *temp_v0;
    ActorLocal_fight_180 *local;


    temp_v0 = marker_getActor(arg0);
    local = (ActorLocal_fight_180 *)&temp_v0->local;
    local->unkD = arg1;
    local->unkE = arg1;
}

void func_80386654(f32 arg0, f32 arg1[4], f32 arg2[4]) {
    Struct6Ds *temp_v0;

    temp_v0 = func_8034C528(0x190);
    if (temp_v0 != NULL) {
        func_8034DF30(temp_v0, arg1, arg2, arg0);
    }
}

void func_80386698(f32 arg0) {
    static f32 D_80391524[3] = {0.0f, -8.0f, 400.0f};
    static f32 D_80391530[3] = {0.0f, -8.0f, 0.0f};
    Struct6Ds * temp_v0;

    temp_v0 = func_8034C528(0x19A);
    if (temp_v0 != NULL) {
        func_8034DDF0(temp_v0, D_80391524, D_80391530, arg0, 1);
    }
}

void func_803866E4(f32 position[3], enum asset_e model_id, s32 n) {
    static struct31s D_8039153C ={
            {1.0f, 1.0f},
            {1.0f, 1.0f},
            {0.0f, 0.01f},
            {2.8f, 3.2f},
            0.5f, 0.7f
    };
    static struct43s D_80391564 ={
        {{-300.0f, -300.0f, -300.0f}, {300.0f, 500.0f, 300.0f}},
        {{0.0f, -1200.0f, 0.0f}, {0.0f, -1200.0f, 0.0f}},
        {{-100.0f, -20.0f, -100.0f},{100.0f, 100.0f, 100.0f}}
    };
    ParticleEmitter *temp_s0;

    temp_s0 = partEmitList_pushNew(n);
    particleEmitter_setModel(temp_s0, model_id);
    particleEmitter_setPosition(temp_s0, position);
    func_802EFE24(temp_s0, -300.0f, -300.0f, -300.0f, 300.0f, 300.0f, 300.0f);
    particleEmitter_setPositionVelocityAndAccelerationRanges(temp_s0, &D_80391564);
    func_802EFB98(temp_s0, &D_8039153C);
    func_802EFA78(temp_s0, 1);
    particleEmitter_emitN(temp_s0, n);
}

void func_8038679C(f32 arg0[3], s32 arg1, f32 arg2[4]) {
    static s32 D_803915AC[3] = {0x24, 0x24, 0x24};
    static struct42s D_803915B8 = {
        {{-70.0f, -50.0f, -70.0f}, {70.0f, 50.0f, 70.0f}},
        {{-100.0f, -20.0f, -100.0f},{100.0f, 100.0f, 100.0f}}
    };
    ParticleEmitter *temp_s0;

    temp_s0 = partEmitList_pushNew(arg1);
    particleEmitter_setSprite(temp_s0, ASSET_70E_SPRITE_SMOKE_2);
    func_802EFFA8(temp_s0, D_803915AC);
    particleEmitter_setStartingFrameRange(temp_s0, 0, 7);
    particleEmitter_setPosition(temp_s0, arg0);
    particleEmitter_setPositionAndVelocityRanges(temp_s0, &D_803915B8);
    func_802EFB70(temp_s0, arg2[0], arg2[1]);
    func_802EFB84(temp_s0, arg2[2], arg2[3]);
    particleEmitter_setSpawnIntervalRange(temp_s0, 0.0f, 0.01f);
    func_802EFEC0(temp_s0, 2.8f, 3.2f);
    func_802EFA5C(temp_s0, 0.3f, 0.4f);
    func_802EFA78(temp_s0, 1);
    particleEmitter_emitN(temp_s0, arg1);
}

void func_803868A0(f32 arg0[3], s32 arg1[3]) {
    static struct40s D_803915E8 ={
        {
            {1.8f, 2.1f},
            {1.3f, 1.4f},
            {0.0f, 0.01f},
            {1.1f, 1.3f},
            0.15f, 0.3f
        },
        4.0f, 1.0f
    };
    static struct42s D_80391618 = {
        {{-10.0f, -10.0f, -10.0f}, {10.0f, 10.0f, 10.0f,}},
        {{0.0f, 30.0f, 0.0f}, {0.0f, 30.0f, 0.0f}}
    };
    ParticleEmitter * temp_s0;

    temp_s0 = partEmitList_pushNew(1);
    particleEmitter_setSprite(temp_s0, ASSET_45A_SPRITE_GREEN_GLOW);
    particleEmitter_setStartingFrameRange(temp_s0, 2, 2);
    func_802EFFA8(temp_s0, arg1);
    particleEmitter_setPosition(temp_s0, arg0);
    func_802EFA78(temp_s0, 1);
    particleEmitter_setPositionAndVelocityRanges(temp_s0, &D_80391618);
    func_802EFC28(temp_s0, &D_803915E8);
}

void func_80386934(f32 position[3], enum asset_e sprite_id) {
    static struct40s D_80391648 = {
        {{0.2f, 0.3f}, {0.5f, 0.6f}, {0.0f, 0.01f}, {1.1f, 1.3f}, 0.01, 0.7}, 4.0f, 1.0f
    };
    static struct43s D_80391678 = {
        {{-50, -50, -50}, {50, 50, 50}},
        {{0, -50, 0}, {0, -50, 0}},
        {{-60, 60, -60}, {60, 60, 60}}
    };
    ParticleEmitter * temp_s0;

    temp_s0 = partEmitList_pushNew(1);
    particleEmitter_setSprite(temp_s0, sprite_id);
    particleEmitter_setStartingFrameRange(temp_s0, 1, 6);
    particleEmitter_setPosition(temp_s0, position);
    func_802EFA78(temp_s0, 1);
    particleEmitter_setPositionVelocityAndAccelerationRanges(temp_s0, &D_80391678);
    func_802EFC28(temp_s0, &D_80391648);
}

void func_803869BC(Actor *this) {
    static s32 D_803916C0[3] = {0xff, 0xff, 0xff};
    static s32 D_803916CC[3] = {0xff, 0, 0};
    static s32 D_803916D8[3] = {0x4B, 0x4B, 0x4B};
    static f32 D_803916E4[4] = {0.1f, 0.2f, 1.9f, 3.9f};

    s32 sp3C;
    s32 sp30[3];
    s32 sp2C;
    f32 sp20[3];

    if (this->marker->unk14_21) {
        sp3C = func_8023DB5C();
        if ((this->state == 6) || (this->state == 7)) {
            sp30[0] = D_803916CC[0];
            sp30[1] = D_803916CC[1];
            sp30[2] = D_803916CC[2];
            sp2C = 0x715;
        } else if ((this->state == 8) || (this->state == 9)) {
            sp30[0] = D_803916D8[0];
            sp30[1] = D_803916D8[1];
            sp30[2] = D_803916D8[2];
            sp2C = 0x000;
        } else {
            sp30[0] = D_803916C0[0];
            sp30[1] = D_803916C0[1];
            sp30[2] = D_803916C0[2];
            sp2C = 0x713;
        }
        func_8034A174(this->marker->unk44, 7, sp20);
        if (((sp2C == 0x715) && ((sp3C & 1) != 0)) || ((sp2C == 0x713) && ((sp3C & 3) == 0))) {
            func_803868A0(sp20, sp30);
        }
        if (sp2C == 0) {
            func_8038856C(this, D_803916E4);
        }
        if ((sp2C != 0) && ((sp2C == 0x715) || (sp2C = sp2C, (randf() < 0.62)))) {
            func_80386934(sp20, sp2C);
        }
    }
}

void func_80386B54(f32 arg0[3], f32 arg1) {
    f32 sp34;
    f32 sp28[3];
    s32 i;

    sp34 = time_getDelta();
    player_getPosition(sp28);
    for(i = 0; i < 3; i++){
        arg0[i] = (i == 1) ? sp28[i] : sp28[i] + ((sp28[i] - D_80392788[i]) * arg1) / sp34;
    }
}

bool func_80386BEC(Actor *this, f32 arg1) {
    this->yaw_moving = (f32) func_80329784(this);
    func_80328FB0(this, arg1);
    if ((this->yaw_moving < (this->yaw + arg1)) && ((this->yaw - arg1) < this->yaw_moving)) {
        return TRUE;
    }
    return FALSE;
}

bool func_80386C68(Actor *this, f32 arg1) {
    f32 sp2C[3];

    func_8039129C(sp2C);
    this->yaw_moving = (f32) func_803297C8(this, sp2C);
    func_80328FB0(this, arg1);

    if ((this->yaw_moving < ( this->yaw + arg1)) && (( this->yaw - arg1) < this->yaw_moving)) {
        return TRUE;
    }
    return FALSE;
}

void func_80386CF8(Actor *actor) {
    f32 sp4C[3];
    f32 sp40[3];
    f32 sp34[3];
    f32 sp28[3];

    sp28[0] = actor->position[0];
    sp28[1] = actor->position[1];
    sp28[2] = actor->position[2];
    sp28[1] += 220.0f;
    sp34[1] = 0.0f;
    sp34[0] = 0.0f;
    sp34[2] = 1000.0f;
    ml_vec3f_yaw_rotate_copy(sp34, sp34, actor->yaw);
    sp4C[0] = sp28[0] + sp34[0];
    sp4C[1] = sp28[1] + sp34[1];
    sp4C[2] = sp28[2] + sp34[2];
    func_8025727C(sp28[0], sp28[1], sp28[2], sp4C[0], sp4C[1], sp4C[2], &sp40[0], &sp40[1]);
    sp40[0] = 360.0f - sp40[0];
    sp40[2] = 0.0f;
    func_802BAE6C(sp4C, sp40);
}

void __chfinalwitch_dropHealth(ActorMarker *arg0) {
    static f32 D_803916F4[3] = {0.0f, 0.0f, 0.0f};
    Actor *actor;

    actor = marker_getActor(arg0);
    func_802C8F70(func_803297C8(actor, D_803916F4));
    func_802C937C(0x14, actor->position);
}

void chfinalwitch_despawnFlightPad(void) {
    marker_despawn(sFlightPadMarker);
    sFlightPadMarker = NULL;
}

void chfinalwitch_spawnFlightPad(s32 arg0) {
    static f32 D_80391700[3] = {0.0f, 0.0f, 0.0f};
    static s32 D_8039170C = 0;
    Actor *temp_v0;

    temp_v0 = func_8032813C(ACTOR_39F_FIGHT_FLIGHT_PAD, D_80391700, D_8039170C);
    temp_v0->alpha_124_19 = 0;
    temp_v0->unk38_31 = 6;
    sFlightPadMarker = temp_v0->marker;
}

void func_80386EC0(ActorMarker *arg0) {
    ActorMarker *marker;

    marker = func_8032813C(0x38A, D_80392758, 0)->marker;
    func_8030E878(SFX_147_GRUNTY_SPELL_ATTACK_2, randf2(0.95f, 1.05f), 32000, D_80392758, 5000.0f, 12000.0f);
    func_803900DC(marker, D_80392758, D_80392768[1], D_80392768[2]);
}

void func_80386F5C(ActorMarker * arg0, f32 arg1[3], f32 arg2, f32 arg3) {
    arg1[1] += 100.0f;
    D_80392758[0] = (f32) arg1[0];
    D_80392758[1] = (f32) arg1[1];
    D_80392758[2] = (f32) arg1[2];
    D_80392768[1] = arg2;
    D_80392768[2] = arg3;
    func_802C3C88((GenMethod_1)func_80386EC0, reinterpret_cast(s32, arg0));
}

void func_80386FD8(s32 arg0) {
    ActorMarker *marker;

    marker = func_8032813C(0x389, D_80392758, 0)->marker;
    func_8030E878(SFX_146_GRUNTY_SPELL_ATTACK_1, randf2(0.95f, 1.05f), 32000, D_80392758, 5000.0f, 12000.0f);
    func_8038FB84(marker, D_80392758, D_80392768, D_80392778);
}

void func_80387074(s32 arg0) {
    ActorMarker *marker;

    marker = func_8032813C(0x3AA, D_80392758, 0)->marker;
    func_8030E878(SFX_146_GRUNTY_SPELL_ATTACK_1, randf2(0.95f, 1.05f), 32000, D_80392758, 5000.0f, 12000.0f);
    func_8038FB84(marker, D_80392758, D_80392768, D_80392778);
}

void func_80387110(ActorMarker *marker, f32 arg1[3], f32 arg2, s32 arg3) {
    static f32 D_80391710[3] = {0.0f, 0.0f, 600.0f};
    static f32 D_8039171C[3] = {0.0f, 0.0f, -600.0f};
    Actor *temp_v0;
    ActorLocal_fight_180 *local;
    f32 sp2C[3];
    s32 i;
    
    temp_v0 = (Actor*) marker_getActor(marker);
    local = (ActorLocal_fight_180 *)&temp_v0->local;
    D_80392758[0] = arg1[0];
    D_80392758[1] = arg1[1];
    D_80392758[2] = arg1[2];
    D_80392758[1] += 80.0f;
    
    if (arg3 == 0) {
        func_80386B54(sp2C, arg2);
    } else if (local->unk7 == 0) {
        sp2C[0] = D_80391710[0];
        sp2C[1] = D_80391710[1];
        sp2C[2] = D_80391710[2];
    } else {
        sp2C[0] = D_8039171C[0];
        sp2C[1] = D_8039171C[1];
        sp2C[2] = D_8039171C[2];
    }
    
    D_80392778[0] = 0.0f;
    D_80392778[1] = (arg3 == 0) ? -1000.0 : -500.0;
    D_80392778[2] = 0.0f;
        
    for(i = 0; i < 3; i++){
        D_80392768[i] = (sp2C[i] - arg1[i]) / arg2 - (D_80392778[i] * arg2 / 2);
    }
    if (arg3 == 0) {
        func_802C3C88((GenMethod_1)func_80386FD8, reinterpret_cast(s32, marker));
    }
    else{
        func_802C3C88((GenMethod_1)func_80387074, reinterpret_cast(s32, marker));
    }
}

void func_803872F8(Actor *arg0) { 
    f32 vec[3];

    func_8034A174(arg0->marker->unk44, 0xA, vec);
    func_80387110(arg0->marker, vec, 3.0f, 1);
}

s32 func_80387340(Actor *this, f32 arg1) {
    f32 sp24[3];

    if (actor_animationIsAt(this, 0.50f) != 0) {
        if (this->marker->unk14_21) {
            func_8034A174(this->marker->unk44, 5, sp24);
        } else {
            sp24[0] = this->position_x;
            sp24[1] = this->position_y;
            sp24[2] = this->position_z;
        }
        func_80387110(this->marker, sp24, arg1, 0);
        return 1;
    }
    return 0;
}

void func_803873DC(Actor *actor, f32 arg1, f32 arg2) {
    f32 vec[3];

    if (actor_animationIsAt(actor, 0.5f) != 0) {
        if (actor->marker->unk14_21) {
            func_8034A174(actor->marker->unk44, 6, vec);
        } else {
            vec[0] = actor->position[0];
            vec[1] = actor->position[1];
            vec[2] = actor->position[2];
        }
        func_80386F5C(actor->marker, vec, arg1, arg2);
    }
}

bool func_80387470(Actor *this, f32 arg1[3], f32 v_max, f32 arg3, f32 arg4, f32 arg5, f32 arg6) {
    f32 dt;
    f32 diff[3];
    f32 temp_0;
    f32 temp_1;
    f32 temp_2;
    f32 next[3];
    dt = time_getDelta();
    
    diff[0] = arg1[0] - this->position[0];
    diff[1] = arg1[1] - this->position[1];
    diff[2] = arg1[2] - this->position[2];

    if (arg5 != 0.00f) {
        if (ml_vec3f_distance(this->position, arg1) < arg5) {
            ml_vec3f_set_length(diff, arg3 * 4.00f);
        } else {
            ml_vec3f_set_length(diff, arg3 * 1.00f);
        }
    } else {
        ml_vec3f_set_length(diff, arg3);
    }

    this->position[0] += (this->velocity[0] * dt) + (diff[0] * dt * dt);
    this->position[1] += (this->velocity[1] * dt) + (diff[1] * dt * dt);
    this->position[2] += (this->velocity[2] * dt) + (diff[2] * dt * dt);

    this->velocity[0] += (diff[0] * dt);
    this->velocity[1] += (diff[1] * dt);
    this->velocity[2] += (diff[2] * dt);

    if (v_max < gu_sqrtf(
         (this->velocity[0] * this->velocity[0]) +
         (this->velocity[1] * this->velocity[1]) +
         (this->velocity[2] * this->velocity[2]) 
    )) {
        ml_vec3f_set_length(this->velocity, v_max);
    }  

    next[0] = this->position[0] + this->velocity[0];
    next[1] = this->position[1] + this->velocity[1];
    next[2] = this->position[2] + this->velocity[2];

    func_80258A4C(this->position, this->yaw - 90.0f, next, &temp_0, &temp_1, &temp_2);

    this->yaw += (arg4 * temp_2 * dt);

    if (ml_vec3f_distance(this->position, arg1) < arg6) {
        return TRUE;
    }
    return FALSE;
}

void func_8038770C(Actor *actor) {
    ActorLocal_fight_180 *local;

    local = (ActorLocal_fight_180 *)&actor->local;
    local->hits = 0;
    local->egg_hits = 0;
    local->unk3 = 0;
    local->unk4 = 0;
    local->unk6 = 0;
    local->unkA = 0;
}

void chfinalwitch_setPhase(ActorMarker *this, u32 next_phase)
{   
    Actor *actor = marker_getActor(this);
    ActorLocal_fight_180 *local = (ActorLocal_fight_180 *) &actor->local;
    
    local->phase = next_phase;
    func_8038770C(actor);
    func_80386600(actor->marker, 0);
    func_80386628(actor->marker, 1);

    switch(next_phase)
    {
        case 0:
            func_80328B8C(actor, 1, 0.0001f, 1);
            timed_setCameraToNode(0.0f, 0);
            func_80324E88(2.0f);
            timed_setCameraToNode(2.0f, 1);
            timedFunc_set_1(2.0f, (TFQM1)chfinalwitch_phase1_init, reinterpret_cast(s32, actor->marker));
            break;

        case 1:
            func_80328B8C(actor, 2, 0.0001f, 1);
            func_8030E878(SFX_EA_GRUNTY_LAUGH_1, randf2(0.95f, 1.05f), 32000, actor->position, 5000.0f, 12000.0f);
            local->unk5 = 0x0;
            actor->unk1C[0] = D_803927D0[(local->unk5)][0];
            actor->unk1C[1] = D_803927D0[(local->unk5)][1];
            actor->unk1C[2] = D_803927D0[(local->unk5)][2];
            local->unk10 = 0;
            if (actor->unk44_31 == 0)
            {
                actor->unk44_31 = (u8)func_8030D90C();
                sfxsource_setSfxId(actor->unk44_31, SFX_152_MOTOR_BREAKDOWN_01);
                func_8030DD14(actor->unk44_31, 3);
                func_8030DBB4(actor->unk44_31, 1.0f);
                sfxsource_setSampleRate(actor->unk44_31, 32000);
            }
            break;

        case 2:
            func_80328B8C(actor, 0xE, 0.0001f, 1);
            local->unk5 = 0x8;
            actor->unk1C[0] = D_803927D0[(local->unk5)][0];
            actor->unk1C[1] = D_803927D0[(local->unk5)][1];
            actor->unk1C[2] = D_803927D0[(local->unk5)][2];
            func_80311480(randi2(0, 5) + 0x1106, 4, NULL, NULL, NULL, NULL);
            break;

            
        case 3:
            func_80328B8C(actor, 0x15, 0.0001f, 1);
            local->unk5 = 0xC;
            actor->unk1C[0] = D_803927D0[(local->unk5)][0];
            actor->unk1C[1] = D_803927D0[(local->unk5)][1];
            actor->unk1C[2] = D_803927D0[(local->unk5)][2];
            actor->unk60 = 15.0f;
            break;

        case 4:
            func_80328B8C(actor, 0x1C, 0.0001f, 1);
            local->unk5 = 0x10;
            actor->unk1C[0] = D_803927D0[(local->unk5)][0];
            actor->unk1C[1] = D_803927D0[(local->unk5)][1];
            actor->unk1C[2] = D_803927D0[(local->unk5)][2];
            break;

        case 5:
            func_80386628(actor->marker, 0);
            chfinalwitch_phase5_setState(actor, 0x24);
            actor_loopAnimation(actor);
            break;
    }
}

void func_80387ACC(Actor *arg0, f32 arg1) {
    func_80328CA8(arg0, 0);
    func_80328FF0(arg0, arg1);
}

void func_80387B00(Actor *this) {
    ActorLocal_fight_180 *local;
    f32 sp28[3];
    
    local = (ActorLocal_fight_180 *) this->local;

    func_80386B54(sp28, 0.80f);
    this->unk1C_x = sp28[0];
    this->unk1C_y = sp28[1];
    this->unk1C_z = sp28[2];
    this->unk1C_y = 0;
    
    this->velocity_x = this->position_x - sp28[0];
    this->velocity_y = this->position_y - sp28[1];
    this->velocity_z = this->position_z - sp28[2];
    this->velocity_y = 0;
    
    local->unk14 = gu_sqrtf(
        (this->velocity_z * this->velocity_z) +
        ((this->velocity_x * this->velocity_x) +
        (this->velocity_y * (this->velocity_y)))
    );

    ml_vec3f_normalize(this->velocity);
    this->yaw_moving = func_8025715C(this->velocity_x, this->velocity_z) + 180.0f;
    
    local->unk18 = this->position_y;
    local->unk1C = (f64) sp28[1];
    local->unk20 = local->unk14;
}

void func_80387BFC(Actor *this, f32 arg1) {
    ActorLocal_fight_180 *local;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    f32 sp44[3];

    local = (ActorLocal_fight_180 *) this->local;
    sp58 = local->unk14 * local->unk14;
    sp54 = local->unk20 * local->unk20;
    sp50 = local->unk18 - local->unk1C;
    func_80328CA8(this, (s32)func_8025715C((2.0 * local->unk20 * sp50), sp58));
    func_80328FF0(this, arg1);
    this->position[0] = this->unk1C[0] + this->velocity[0] * local->unk20;
    this->position[1] = this->unk1C[1] + this->velocity[1] * local->unk20;
    this->position[2] = this->unk1C[2] + this->velocity[2] * local->unk20;
    this->position[1] = local->unk1C + ((sp50 * sp54) / sp58);
    sp44[0] = this->velocity[0] * sp58;
    sp44[1] = 2.0 * local->unk20 * sp50;
    sp44[2] = this->velocity[2] * sp58;
    ml_vec3f_normalize(sp44);
    sp44[0] *= this->unk28;
    sp44[1] *= this->unk28;
    sp44[2] *= this->unk28;
}

void func_80387D4C(Actor *actor) {
    ActorLocal_fight_180 *local;
    f32 sp20[3];

    local = (ActorLocal_fight_180 *) actor->local;

    actor->position[0] = actor->unk1C[0] + actor->velocity[0] * local->unk20;
    actor->position[2] = actor->unk1C[2] + actor->velocity[2] * local->unk20;
    actor->position[1] = local->unk1C - local->unk2C * local->unk20;

    sp20[0] = actor->velocity[0] * local->unk14;
    sp20[1] = -2.0 * (100.0f - local->unk1C);
    sp20[2] = actor->velocity[2] * local->unk14;

    ml_vec3f_normalize(sp20, actor);
    sp20[0] = sp20[0] * actor->unk28;
    sp20[1] = sp20[1] * actor->unk28;
    sp20[2] = sp20[2] * actor->unk28;
}

void func_80387E1C(Actor *this, f32 arg1[3]) {
    ActorLocal_fight_180 *local;
    f32 dz;
    f32 distance;
    f32 dx;
    f32 min_distance;
    s32 i;

    local = (ActorLocal_fight_180 *)&this->local;
    min_distance = 1e+8f;
    for(i = 0; i < 8; i++){
        dx = D_803927D0[i][0] - this->position[0];
        dz = D_803927D0[i][2] - this->position[2];
        distance = (dx * dx) + (dz * dz);
        if (distance < min_distance) {
            local->unk5 = i;
            min_distance = distance;
            arg1[0] = D_803927D0[local->unk5][0];
            arg1[1] = D_803927D0[local->unk5][1];
            arg1[2] = D_803927D0[local->unk5][2];
        }
    }
}

void func_80387F70(Actor *actor, f32 *arg1, f32 arg2) {
    ActorLocal_fight_180 *local;
    f32 vec[3];
    f32 playerPos[3];

    local = (ActorLocal_fight_180 *) &actor->local;
    player_getPosition(playerPos);
    vec[0] = D_803927D0[local->unk5][0] - playerPos[0];
    vec[1] = D_803927D0[local->unk5][1] - playerPos[1];
    vec[2] = D_803927D0[local->unk5][2] - playerPos[2];
    ml_vec3f_normalize(vec);
    arg1[0] = D_803927D0[local->unk5][0] + (arg2 * vec[0]);
    arg1[1] = D_803927D0[local->unk5][1] + (arg2 * vec[1]);
    arg1[2] = D_803927D0[local->unk5][2] + (arg2 * vec[2]);
}

void func_803880A0(Actor *actor, f32 arg1) {
    actor->velocity[2] = arg1;
    actor->velocity[1] = 0.0f;
    actor->velocity[0] = 0.0f;
    ml_vec3f_yaw_rotate_copy(actor->velocity, actor->velocity, actor->yaw);
}

void func_803880E0(ActorMarker *marker, enum asset_e text_id, s32 arg2) {
    chfinalwitch_phase1_setState(marker_getActor(marker), 0xC);
}

void func_80388110(ActorMarker *marker, enum asset_e text_id, s32 arg2) {
    Actor *actor;
    ActorLocal_fight_180 *actorLocal;

    actor = marker_getActor(marker);
    actorLocal = (ActorLocal_fight_180 *)&actor->local;
    func_802BAE4C();
    func_80311480(randi2(0, 5) + 0x1101, 4, NULL, actor->marker, func_803880E0, NULL);
    actorLocal->unk9 = (u8)1;
}

void chfinalwitch_phase1_setState(Actor *this, s32 next_state) {
    ActorLocal_fight_180 *local;
    s32 sp40;
    f32 sp3C;
    f32 temp_f12;

    local = (ActorLocal_fight_180 *)&this->local;
    sp40 = func_8023DB5C();
    sp3C = animctrl_getAnimTimer(this->animctrl);
    local->phase = 1;
    func_80328B8C(this, next_state, 0.0001f, 1);
    actor_loopAnimation(this);
    func_80386600(this->marker, 0);
    if (next_state != 9) {
        if (func_8030E3FC(this->unk44_31)) {
            func_8030E394(this->unk44_31);
            FUNC_8030E624(SFX_162_MOTOR_RUCKUS, 1.0f, 32000);

        }
    }
    switch (next_state) {
    case 2:
        func_80387E1C(this, this->unk1C);
        break;
    case 5:
        if ((sp40 & 1) == 0) {
            func_8030E878(SFX_142_GRUNTY_LAUGH_3, randf2(0.95f, 1.05f), 32000, this->position, 5000.0f, 12000.0f);
        } else {
            func_8030E878(SFX_14B_GRUNTY_LAUGH_4, randf2(0.95f, 1.05f), 32000, this->position, 5000.0f, 12000.0f);
        }
        this->unk28 = 0.0f;
        this->unk60 = 0.0f;
        break;
    case 6:
        local = local;
        func_80386600(this->marker, 1);
        func_80324D54(0.4f, SFX_C1_BUZZBOMB_ATTACK, 0.85f, 32000, this->position, 5000.0f, 12000.0f);
        this->unk28 = 0.0f;
        func_80387B00(this);
        local->unkA = 0;
        break;
    case 7:
        local->unk14 = (local->unk14 > 2000.0f) ? local->unk14 : 2000.0f;
        local->unk14 = (local->unk14 < 2700.0f) ? local->unk14 : 2700.0f;
        local->unk18 = 400.0f;
        local->unk28 = (-this->unk28 * this->unk28) / (2.0 * local->unk14);
        func_80386600(this->marker, 1);
        animctrl_setAnimTimer(this->animctrl, sp3C);
        break;
    case 8:
        temp_f12 = 1150.0f;
        local->unk28 = (-this->unk28 * this->unk28) / (2.0 * temp_f12);
        local->unk2C = (100.0f - local->unk1C) / temp_f12;
        break;
    case 9:
        actor_playAnimationOnce(this);
        animctrl_setAnimTimer(this->animctrl, sp3C);
        break;
    case 10:
        func_8030E878(SFX_EA_GRUNTY_LAUGH_1, randf2(0.95f, 1.05f), 32000, this->position, 5000.0f, 12000.0f);
        break;
    case 12:
        func_8025A6EC(SFX_GRUNTY_SPELL_POWERUP, 30000);
        break;
    case 13:
        func_8030E878(SFX_131_GRUNTY_WEEEGH, randf2(0.95f, 1.05f), 32000, this->position, 5000.0f, 12000.0f);
        if ((s32) local->hits >= 4) {
            func_802C3C88((GenMethod_1)__chfinalwitch_dropHealth, reinterpret_cast(s32, this->marker));
            func_80388110(this->marker, 0, 0);
        }
        break;
    }
}

void func_8038856C(Actor *actor, f32 *arg1) {
    f32 vec[3];
    ActorMarker *marker;

    marker = actor->marker;
    if (marker->unk14_21) {
        func_8034A174(marker->unk44, 7, vec);
    } else {
        vec[0] = actor->position[0];
        vec[1] = actor->position[1];
        vec[2] = actor->position[2];
    }
    func_8038679C(vec, 2, arg1);
}

void func_803885DC(Actor *this) {
    static f32 D_80391728[4] = {0.1f, 0.2f, 3.9f, 4.9f};
    s32 sp24 = func_8023DB5C();
    
    if (func_8030E3FC(this->unk44_31) == 0) {
        func_8030E2C4(this->unk44_31);
    }
    if (((sp24 & 7) == 0) && (randf() < 0.5)) {
        func_8038856C(this, D_80391728);
    }
    if ((actor_animationIsAt(this, 0.30f) != 0) || (actor_animationIsAt(this, 0.78f) != 0)) {
        FUNC_8030E8B4(SFX_1E_HITTING_AN_ENEMY_2, 1.0f, 25000, this->position, 2000, 10000);
        FUNC_8030E8B4(SFX_8E_GRUNTLING_DAMAGE, 1.0f, 25000, this->position, 2000, 10000);
    }
    if ((actor_animationIsAt(this, 0.40f) != 0) || (actor_animationIsAt(this, 0.88f) != 0)) {
        FUNC_8030E8B4(SFX_1E_HITTING_AN_ENEMY_2, 1.0f, 25000, this->position, 2000, 10000);
        FUNC_8030E8B4(SFX_8E_GRUNTLING_DAMAGE, 0.9f, 25000, this->position, 2000, 10000);

    }
}

bool func_8038871C(Actor *arg0, f32 arg1, f32 arg2) {
    if (arg0->position[1] + arg2 > arg1) {
        arg0->position[1] = arg1;
        return 1;
    }
    else
    {
        arg0->position[1] = arg0->position[1] + arg2;
        return 0;
    }
}

void chfinalwitch_phase1_update(ActorMarker *marker) {
    static s32 D_80391738[4] = {0xCE4, 0x10C2, 0x14A0, 0x187E};
    Actor *this;
    ActorLocal_fight_180 *local;
    f32 sp54;
    f32 sp50;
    s32 var_a0;
    f32 sp40[3];

    this = marker_getActor(marker);
    local = (ActorLocal_fight_180 *)&this->local;
    sp54 = time_getDelta();
    switch (this->state) {
    case 2:
        func_80386600(this->marker, 0);
        func_803869BC(this);
        func_80387ACC(this, 60.0f * sp54);
        func_80387F70(this, this->unk1C, 950.0f);
        if (func_80387470(this, this->unk1C, 1000.0f, 1800.0f, 200.0f, 1000.0f, 600.0f)) {
            chfinalwitch_phase1_setState(this, 3);
            this->unk1C[0] = D_803927D0[local->unk5][0];
            this->unk1C[1] = D_803927D0[local->unk5][1];
            this->unk1C[2] = D_803927D0[local->unk5][2];
        }
        break;
    case 3:
        func_80386600(this->marker, 0);
        func_803869BC(this);
        sp50 = ml_map_f(ml_vec3f_distance(this->position, this->unk1C), 300.0f, 1000.0f, 100.0f, 1000.0f);
        func_80387ACC(this, 60.0f * sp54);
        if (func_80387470(this, this->unk1C, sp50, 1800.0f, 200.0f, 500.0f, 300.0f)) {
            chfinalwitch_phase1_setState(this, 4);
        }
        break;
    case 4:
        func_80386600(this->marker, 0);
        func_803869BC(this);
        func_80387ACC(this, 60.0f * sp54);
        if (func_80386BEC(this, 240.0f * sp54)) {
            chfinalwitch_phase1_setState(this, 5);
            func_80386654(1.0f, D_80391380, D_80391390);
        }
        break;
    case 5:
        func_80387B00(this);
        this->unk60 += sp54;
        if (this->unk60 < 0.3333333333333333) {
            this->unk28 += 3300.0 * sp54;
        } else if (0.7333333333333334 < this->unk60) {
            this->unk28 -= 3300.0 * sp54;
        }
        local->unk20 += this->unk28 * sp54;
        func_80387BFC(this, 45.0f * sp54);
        func_80328FB0(this, 30.0f * sp54);
        if (this->unk60 > 1.0) {
            chfinalwitch_phase1_setState(this, 6);
        }
        break;
    case 6:
        func_803869BC(this);
        if (local->unk4 >= (local->hits + 1)) {
            this->unk28 += (D_80391738[local->hits] * sp54) * 0.66;
        } else {
            this->unk28 +=  D_80391738[local->hits] * sp54;
        }
        local->unk20 -= this->unk28 * sp54;
        func_80387BFC(this, 180.0f * sp54);
        func_80328FB0(this, 30.0f * sp54);
        if ((local->unkA == 0) && (local->unk20 < (local->unk14 * 0.65))) {
            local->unkA = 1U;
            FUNC_8030E8B4(SFX_C4_TWINKLY_MUNCHER_GRR, 0.6f, 28000, this->position, 2000, 10000);
        }
        if ((local->unk14 * 0.75) < local->unk20) {
            func_80386B54(sp40, 0);
            this->unk1C[0] = sp40[0];
            this->unk1C[1] = sp40[1];
            this->unk1C[2] = sp40[2];
            this->unk1C[1] = 0.0f;
            this->velocity[0] = this->position[0] - sp40[0];
            this->velocity[1] = this->position[1] - sp40[1];
            this->velocity[2] = this->position[2] - sp40[2];
            this->velocity[1] = 0.0f;
            ml_vec3f_normalize(this->velocity);
            this->yaw_moving = func_8025715C(this->velocity[0], this->velocity[2]) + 180.0f;
        }
        if (local->unk20 < 0.0) {
            var_a0 =  (local->hits == 0) ? 1 : 0;
            if (local->unk4 >= (var_a0 + local->hits)) {
                chfinalwitch_phase1_setState(this, 8);
                local->unk4 = 0;
            }
            else{
                chfinalwitch_phase1_setState(this, 7);
                local->unk4++;
            }
        }
        break;
    case 7:
        func_803869BC(this);
        this->unk28 = this->unk28 + local->unk28 * sp54;
        local->unk20 =  local->unk20 - this->unk28 * sp54;
        func_80387BFC(this, 180.0f * sp54);
        func_80328FB0(this, 30.0f * sp54);
        if (this->unk28 < 0) {
            chfinalwitch_phase1_setState(this, 4);
            func_80386654(1.5f, D_80391390, D_80391380);
        }
        break;
    case 8:
        func_803885DC(this);
        func_803869BC(this);
        this->unk28 = this->unk28 + local->unk28 * sp54;
        local->unk20 = local->unk20 - this->unk28 * sp54;
        func_80387ACC(this, 60.0f * sp54);
        func_80387D4C(this);
        func_80328FB0(this, 30.0f * sp54);
        if (this->unk28 < 0) {
            chfinalwitch_phase1_setState(this, 9);
            func_80386654(2.0f, D_80391390, D_80391380);
            this->unk60 = 4.0f;
        }
        break;
    case 9:
        func_803885DC(this);
        if (this->unk60 > 0.0) {
            this->unk60 -= sp54;
        }
        else{
            if (actor_animationIsAt(this, 0.9999f)) {
                chfinalwitch_phase1_setState(this, 2);
                func_803880A0(this, 2000.0f);
            }
        }
        break;
    case 10:
        func_80387ACC(this, 60.0f * sp54);
        func_80386BEC(this, 30.0f);
        func_8038871C(this, 460.0f, 400.0f * sp54);
        func_80387340(this, 1.0f);
        if (actor_animationIsAt(this, 0.9999f)) {
            chfinalwitch_phase1_setState(this, 2);
            func_803880A0(this, 2000.0f);
        }
        break;
    case 11:
        func_80387ACC(this, 60.0f * sp54);
        func_80386BEC(this, 30.0f);
        if (local->unk9) {
            func_8038871C(this, 460.0f, 400.0f * sp54);
        }
        break;
    case 12:
        func_80387ACC(this, 60.0f * sp54);
        func_80386BEC(this, 30.0f);
        func_8038871C(this, 460.0f, 400.0f * sp54);
        func_803873DC(this, 600.0f, 2000.0f);
        if (actor_animationIsAt(this, 0.9999f)) {
            func_8030DA44(this->unk44_31);
            this->unk44_31 = 0U;
            chfinalwitch_setPhase(this->marker, 2);
        }
        break;
    case 13:
        func_80387ACC(this, 60.0f * sp54);
        func_80386BEC(this, 30.0f);
        if (actor_animationIsAt(this, 0.9999f)) {
            if (local->hits >= 4) {
                chfinalwitch_phase1_setState(this, 0xB);
            }
            else{
                chfinalwitch_phase1_setState(this, 0xA);
            }
        }
        break;
    }
}

void chfinalwitch_phase2_setState(Actor *this, s32 next_state){
    ActorLocal_fight_180 *local;
    s32 sp28;

    local = (ActorLocal_fight_180 *)&this->local;
    sp28 = func_8023DB5C();
    local->phase = 2;
    func_80328B8C(this, next_state, 0.0001f, 1);
    actor_loopAnimation(this);
    switch (next_state) {
    case 14:
        local->unk5 = local->hits + 8;
        this->unk1C[0] = D_803927D0[local->unk5][0];
        this->unk1C[1] = D_803927D0[local->unk5][1];
        this->unk1C[2] = D_803927D0[local->unk5][2];
        break;
    case 19:
        if (sp28 & 1) {
            FUNC_8030E8B4(SFX_132_GRUNTY_YOW, 1.0f, 32000, this->position, 7000, 12000);
        }
        else{
            FUNC_8030E8B4(SFX_133_GRUNTY_OHW, 1.0f, 32000, this->position, 7000, 12000);
        }
        break;
    case 20:
        FUNC_8030E8B4(SFX_131_GRUNTY_WEEEGH, 1.0f, 32000, this->position, 5000, 12000);

        local->unkA = 0;
        break;
    case 17:
        func_8025A6EC(SFX_GRUNTY_SPELL_POWERUP, 30000);
        break;
    }
}

void chfinalwitch_phase2_endTextCallback(ActorMarker *marker, enum asset_e text_id, s32 arg2) {
    func_802C3C88((GenMethod_1)chfinalwitch_spawnFlightPad, reinterpret_cast(s32, marker));
}

void chfinalwitch_phase2_update(ActorMarker *marker) {
    static f32 D_80391748[4] = {1.4f, 1.1f, 0.8f, 0.5f};
    static f32 D_80391758[4] = {1000.0f, 1100.0f, 1200.0f, 1300.0f};
    Actor *this;
    ActorLocal_fight_180 *local;
    f32 sp4C;
    s32 sp48;

    this = marker_getActor(marker);
    local = (ActorLocal_fight_180 *)&this->local;
    sp4C = time_getDelta();
    sp48 = local->hits;
    switch (this->state) {
        case 14:
            func_803869BC(this);
            func_80387ACC(this, 30.0f * sp4C);
            if (func_80387470(this, this->unk1C, ml_map_f(ml_vec3f_distance(this->position, this->unk1C), 70.0f, 1000.0f, 100.0f, D_80391758[sp48]), D_80391758[sp48] * 2, 160.0f, 500.0f, 70.0f)) {
                local->unkA = 1;
                chfinalwitch_phase2_setState(this, 0xF);
            }
            break;

        case 15:
            if (func_80386BEC(this, 9.0f)) {
                chfinalwitch_phase2_setState(this, 0x10);
            }
            break;
        case 16:
            func_80386BEC(this, 3.0f);
            func_80387340(this, 1.3f);
            if (actor_animationIsAt(this, 0.9999f)) {
                chfinalwitch_phase2_setState(this, 0x12);
                local->unk3++;
                if (local->unk3 >= 4) {
                    local->unk3 = 0U;
                    this->unk60 = D_80391748[sp48] * 3.0f;
                }
                else{
                    this->unk60 = D_80391748[sp48];
                }
            }
            break;
        case 17:
            func_80386BEC(this, 3.0f);
            func_803873DC(this, 1200.0f, 2400.0f);
            if (actor_animationIsAt(this, 0.9999f)) {
                chfinalwitch_setPhase(this->marker, 3);
            }
            break;
        case 18:
            func_80386BEC(this, 3.0f);
            if (this->unk60 > 0.0) {
                this->unk60 = this->unk60 - sp4C;
                break;
            }
            if (func_80386BEC(this, 3.0f)) {
                chfinalwitch_phase2_setState(this, 0x10);
            }
            break;
        case 19:
            if (actor_animationIsAt(this, 0.9999f)) {
                chfinalwitch_phase2_setState(this, 0xE);
            }
            break;
        case 20:
            if (actor_animationIsAt(this, 0.9999f)) {
                if (local->hits >= 4) {
                    func_80311480(randi2(0, 5) + 0x1115, 0x20, NULL, NULL, NULL, NULL);
                    func_80311480(randi2(0, 3) + 0x111A, 4, NULL, this->marker, NULL, chfinalwitch_phase2_endTextCallback);
                    chfinalwitch_phase2_setState(this, 0x11);
                }
                else{
                    chfinalwitch_phase2_setState(this, 0xE);
                    func_803880A0(this, 2000.0f);
                }
            }
            break;
    }
}

void __chfinalwitch_spawnStatue(s32 statue_id) {
    Actor * sp24 = func_80326EEC(ACTOR_38B_GRUNTILDA_FINAL_BOSS);
    ActorLocal_fight_180 *local = (ActorLocal_fight_180 *)&sp24->local;
    Actor *sp1C;

    switch (statue_id) {
    case 1:
        {
            static f32 D_80391768[3] = {-1290.0f, 0.0f, 1290.0f};
            sp1C = func_8032813C(ACTOR_3A2_JINJO_STATUE, D_80391768, 135);
            sJinjoStatueMarker[0] = sp1C->marker;
        }
        break;
    case 2:
        {
            static f32 D_80391774[3] = {-1290.0f, 0.0f, -1290.0f};
            sp1C = func_8032813C(ACTOR_3A2_JINJO_STATUE, D_80391774, 45);
            sJinjoStatueMarker[1] = sp1C->marker;
        }
        break;
    case 3:
        {
            static f32 D_80391780[3] = {1290.0f, 0.0f, -1290.0f};
            sp1C = func_8032813C(ACTOR_3A2_JINJO_STATUE, D_80391780, 315);
            sJinjoStatueMarker[2] = sp1C->marker;
            break;
        }
    case 4:
        {
            static f32 D_8039178C[3] = {1290.0f, 0.0f, 1290.0f};
            sp1C = func_8032813C(ACTOR_3A2_JINJO_STATUE, D_8039178C, 225);
            sJinjoStatueMarker[3] = sp1C->marker;
            break;
        }

    case 5:
        {
            static f32 D_80392750;
            static f32 D_80391798[3] = {0.0f, 0.0f, 0.0f};
            D_80392750 = (local->unk7) ? 0.0f : 180.0f;
            sp1C = func_8032813C(ACTOR_3A9_JINJONATOR_STATUE, D_80391798, (s32)D_80392750);
        }
        break;
    }
    sp1C->unk60 = (statue_id == 5) ? 5.25f : 1.54f;
    sp1C->unkF4_8 = statue_id;
}

void chfinalwitch_spawnStatue(s32 statue_id) {
    func_802C3C88(&__chfinalwitch_spawnStatue, reinterpret_cast(s32, statue_id));
}

void __chfinalwitch_spawnSpellBarrier(ActorMarker *marker) {
    Actor *actor;

    actor = marker_getActor(marker);
    actor->unk100 = spawn_child_actor(ACTOR_3AB_GRUNTY_SPELL_BARRIER, &actor)->marker;
    sFinalWitch_SpellBarrierActive = (u8)1;
}

void chfinalwitch_spawnSpellBarrier(ActorMarker *arg0) {
    func_802C3C88((GenMethod_1)__chfinalwitch_spawnSpellBarrier, reinterpret_cast(s32, arg0));
}

void chfinalwitch_phase3_endTextCallback(ActorMarker *marker, enum asset_e text_id, s32 arg2) {
    Actor *actor;

    actor = marker_getActor(marker);
    func_802BAE4C();
    func_80324E38(0, 0);
    chfinalwitch_setPhase(actor->marker, 4);
}

void chfinalwitch_phase3_setState(Actor *this, s32 next_state) {
    ActorLocal_fight_180 *local;
    s32 i;

    local = (ActorLocal_fight_180 *)&this->local;
    local->phase = 3;
    func_80328B8C(this, next_state, 0.0001f, 1);
    switch (next_state) {
    case 21:
        if((local->unk5 + 1) < 0x10) {
            local->unk5++;
        } else{
            local->unk5 =  0xC;
        }
        this->unk1C[0] = D_803927D0[local->unk5][0];
        this->unk1C[1] = D_803927D0[local->unk5][1];
        this->unk1C[2] = D_803927D0[local->unk5][2];
        for(i = 0; i < 3; i++){
            this->unk1C[i] += randf2(-120.0f, 120.0f);
        };
        break;
    case 24:
        local->unk3 = 0;
        break;
    case 25:
        FUNC_8030E8B4(SFX_131_GRUNTY_WEEEGH, 1.0f, 32000, this->position, 5000, 12000);
        break;
    case 26:
        func_80386CF8(this);
        func_80324E38(0.0f, 1);
        func_80311480(randi2(0, 5) + 0x112C, 0xA8, NULL, this->marker, chfinalwitch_phase3_endTextCallback, NULL);
        break;
    }
}

void chfinalwitch_dropHealth(ActorMarker *marker) {
    func_802C3C88((GenMethod_1)__chfinalwitch_dropHealth, reinterpret_cast(s32, marker));
}

void chfinalwitch_phase3_update(ActorMarker *marker) {
    static f32 D_803917A4[4] = {500.0f, 650.0f, 800.0f, 950.0f};
    static f32 D_803917B4[4] = {3.75f, 3.0f, 2.25f, 1.5f}; 
    static s32 D_803917C4[3] = {230, 230, 230};
    static f32 D_803928B8[3];
    Actor *this;
    ActorLocal_fight_180 *local;
    f32 sp3C;
    s32 sp38;
    f32 sp34;

    this = marker_getActor(marker);
    local = (ActorLocal_fight_180 *)&this->local;
    sp3C = time_getDelta();
    sp38 = local->hits;
    sp34 = animctrl_getAnimTimer(this->animctrl);
    switch (this->state) {
    case 21:
        func_803869BC(this);
        this->unk60 -= sp3C;
        if (this->unk60 < 0.0) {
            if (local->unkA) {
                chfinalwitch_phase3_setState(this, 0x17);
            } else {
                chfinalwitch_phase3_setState(this, 0x16);
                this->unk60 = D_803917B4[local->hits];
            }
            local->unkA = NOT(local->unkA);
            break;
        }
        if (func_80387470(this, this->unk1C, D_803917A4[sp38], D_803917A4[sp38], 120.0f, 520.0f, 350.0f)) {
            chfinalwitch_phase3_setState(this, 0x15);
            if (local->unkB == 0) {
                local->unkB = 1;
                timedFunc_set_1(1.2f, (TFQM1)chfinalwitch_dropHealth, (s32) this->marker);
            }
        }
        break;
    case 22:
        this->unk60 -= sp3C;
        if (this->unk60 < 0.0) {
            chfinalwitch_phase3_setState(this, 0x15);
            this->unk60 = 5.0f;
        }
        break;
    case 23:
        if (func_80386BEC(this, 9.0f) && (func_80297C6C() != 3)) {
            chfinalwitch_phase3_setState(this, 0x18);
        }
        break;
    case 24:
        func_80386BEC(this, 3.0f);
        if (func_80387340(this, 1.3f)) {
            local->unk3++;
        }
        if (actor_animationIsAt(this, 0.9999f)) {
            if (local->unk3 >= local->hits) {
                if (local->hits >= 4) {
                    chfinalwitch_phase3_setState(this, 0x1A);
                }
                else{
                    this->unk60 = 5.0f;
                    chfinalwitch_phase3_setState(this, 0x15);
                }
            }
        }
        break;
    case 25:
        if (actor_animationIsAt(this, 0.9999f)) {
            chfinalwitch_phase3_setState(this, 0x17);
        }
        break;
    case 26:
        if (actor_animationIsAt(this, 0.1f) != 0) {
            func_80324CFC(0.0f, COMUSIC_43_ENTER_LEVEL_GLITTER, 0x7FFF);
        }
        if ((0.1 < sp34) && (sp34 < 0.8)) {
            func_8034A174(this->marker->unk44, 8, D_803928B8);
            func_80386934(D_803928B8, ASSET_716_SPRITE_SPARKLE_WHITE);
            func_8034A174(this->marker->unk44, 9, D_803928B8);
            func_80386934(D_803928B8, ASSET_716_SPRITE_SPARKLE_WHITE);
        }
        if (actor_animationIsAt(this, 0.38f) ) {
            chfinalwitch_spawnSpellBarrier(this->marker);
        }
        if (actor_animationIsAt(this, 0.9999f)) {
            func_80324D2C(0.0f, COMUSIC_43_ENTER_LEVEL_GLITTER);
            chfinalwitch_despawnFlightPad();
            chfinalwitch_phase3_setState(this, 0x1B);
        }
        break;
    case 27:
        break;
    }
}

void func_80389F54(void) {
    func_80320004(0xD2, TRUE);
    D_803927C4 = (u8)0;
}

void chfinalwitch_phase4_setState(Actor *this, s32 next_state) {
    static s32 D_803928C4;
    ActorLocal_fight_180 *local;
    f32 sp48;
    f32 sp3C[3];
    s32 i;

    local = (ActorLocal_fight_180 *)&this->local;
    sp48 = animctrl_getAnimTimer(this->animctrl);
    local->phase = 4;
    func_80328B8C(this, next_state, 0.0001f, 1);
    switch (next_state) {
    case 28:
        animctrl_setAnimTimer(this->animctrl, sp48);
        this->unk1C[0] = D_803927D0[0x10][0];
        this->unk1C[1] = D_803927D0[0x10][1];
        this->unk1C[2] = D_803927D0[0x10][2];
        break;

    case 30:
        if ((local->unk3 == 2) && (local->unkA == 0)) {
            D_803927C8 = 1;
            func_80311480(randi2(0, 5) + 0x1136, 4, NULL, NULL, NULL, NULL);
            if (func_8031FF1C(0xD2) == 0) {
                local->unkA = 1U;
                D_803927C4 = 1;
                func_80324E38(0.0f, 1);
                timedFunc_set_1(0.0f, chfinalwitch_spawnStatue, 1);
                timed_setCameraToNode(0.0f, 4);
                func_80324E88(2.2f);
                timedFunc_set_1(2.2f, chfinalwitch_spawnStatue, 2);
                timed_setCameraToNode(2.2f, 5);
                func_80324E88(4.4f);
                timedFunc_set_1(4.4f, chfinalwitch_spawnStatue, 3);
                timed_setCameraToNode(4.4f, 6);
                func_80324E88(6.6f);
                timedFunc_set_1(6.6f, chfinalwitch_spawnStatue, 4);
                timed_setCameraToNode(6.6f, 7);
                func_80324E88(8.8f);
                timedFunc_set_0(8.8f, func_80389F54);
                func_80324E38(8.8f, 0);
                break;
            }
            for(D_803928C4 = 1; D_803928C4 < 5; D_803928C4++){
                chfinalwitch_spawnStatue(D_803928C4);
            }
        }
        break;

    case 32:
        func_8030E878(SFX_131_GRUNTY_WEEEGH, randf2(0.95f, 1.05f), 32000, this->position, 5000.0f, 12000.0f);
        func_802C9334(0x24, this);
        return;
    case 33:
        FUNC_8030E624(SFX_131_GRUNTY_WEEEGH, 1.0f, 32000);
        timed_playSfx(0.6f, SFX_61_CARTOONY_FALL, 1.0f, 32000);
        func_802C3C88((GenMethod_1)__chfinalwitch_dropHealth, (s32)this->marker);
        FUNC_8030E624(SFX_D9_WOODEN_CRATE_BREAKING_1, 1.0f, 32000);
        func_80386628(this->marker, 0);
        func_803866E4(this->position, 0x552, 1);
        func_803866E4(this->position, 0x553, 0xC);
        func_803866E4(this->position, 0x554, 0x14);
        func_803866E4(this->position, 0x555, 2);
        sp3C[0] = D_803927D0[local->unk7 + 0x11][0] - this->position[0];
        sp3C[1] = D_803927D0[local->unk7 + 0x11][1] - this->position[1];
        sp3C[2] = D_803927D0[local->unk7 + 0x11][2] - this->position[2];
        this->velocity[0] = sp3C[0] / 1.7;
        this->velocity[1] = sp3C[1] / 1.7 - -1190.0;
        this->velocity[2] = sp3C[2] / 1.7;
        func_8028F94C(2, this->position, local);
        if (local->unk7 == 0) {
            timed_setCameraToNode(0.0f, 0xA);
            func_80324E88(1.7f);
            timed_setCameraToNode(1.7f, 0xB);
        }
        else{
            timed_setCameraToNode(0.0f, 0xC);
            func_80324E88(1.7f);
            timed_setCameraToNode(1.7f, 0xD);
        }
        break;
    case 34:
        actor_playAnimationOnce(this);
        func_80311480(randi2(0, 5) + 0x1145, 0x20, NULL, NULL, NULL, NULL);
        func_8030E6A4(SFX_1F_HITTING_AN_ENEMY_3, randf2(0.95f, 1.05f), 32000);
        func_8030E6A4(SFX_133_GRUNTY_OHW, randf2(0.95f, 1.05f), 32000);
        this->unk44_31 = func_8030D90C();
        D_803927C0 = 1.0f;
        sfxsource_setSfxId(this->unk44_31, SFX_2C_PULLING_NOISE);
        func_8030DD14(this->unk44_31, 2);
        func_8030DBB4(this->unk44_31, D_803927C0);
        sfxsource_setSampleRate(this->unk44_31, 26000);
        for(i = 0; i < 4; i++){
            if(sJinjoStatueMarker[i] != NULL){
                marker_despawn(sJinjoStatueMarker[i]);
                sJinjoStatueMarker[i] = NULL;
            }
        }
        break;
    }
}

ActorMarker *func_8038A4E8(Actor *this, f32 arg1) {
    Actor *actor;
    Prop *prop;
    enum marker_e marker_id;

    func_80320ED8(this->marker, arg1, 1);
    prop = func_8032F528();
    while(prop !=NULL){
        if (prop->markerFlag){
            actor = marker_getActor(prop->actorProp.marker);
            marker_id = actor->marker->unk14_20;
            if( (marker_id == MARKER_27B_BOSS_JINJO_ORANGE)
                || (marker_id == MARKER_27C_BOSS_JINJO_GREEN)
                || (marker_id == MARKER_27D_BOSS_JINJO_PINK)
                || (marker_id == MARKER_27E_BOSS_JINJO_YELLOW)
                || (marker_id == MARKER_285_JINJONATOR)
            ) {
                while (func_8032F528() != NULL) {}
                return actor->marker;
            }
        }
        prop = func_8032F528();
    }
    return NULL;
}

void chfinalwitch_phase4_update(ActorMarker *marker) {
    static f32 D_803917D0[4] = {2.4f, 2.1f, 1.8f, 1.5f};
    Actor *this;
    ActorLocal_fight_180 *local;
    f32 sp74;
    s32 sp70;
    ActorMarker *sp6C;
    f32 temp_f2;
    f32 sp5C[3];
    f32 sp58;
    u32 temp_t6;
    u8 var_a0;
    u8 var_v1;

    this = marker_getActor(marker);
    local = (ActorLocal_fight_180 *) &this->local;
    sp74 = time_getDelta();
    sp70 = local->hits;
    sp6C = func_8038A4E8(this, func_8033229C(this->marker));
    if (sp6C != NULL) {
        func_8038D214(sp6C);
        if (!func_8031FF1C(0xD1)) {
            func_80320004(0xD1, 1);
            D_803927C4 = 0;
            func_80324E88(1.0f);
            func_80324E38(1.0f, 0);
        }
        if (local->hits == 0) {
            func_80311480(randi2(0, 5) + 0x1140, 0x20, NULL, NULL, NULL, NULL);
        }
        if ((local->hits + 1) < 4) {
            local->hits++;
            chfinalwitch_phase4_setState(this, 0x20);
            return;
        }
        temp_t6 = marker_getActor(sp6C)->marker->unk14_20;
        if ((temp_t6 == MARKER_27B_BOSS_JINJO_ORANGE) || (temp_t6 == MARKER_27E_BOSS_JINJO_YELLOW)) {
            local->unk7 = FALSE;
        } else {
            local->unk7 = TRUE;
        }
        chfinalwitch_phase4_setState(this, 0x21);
        return;
    }
    switch (this->state) {
        case 28:
            func_803869BC(this);
            if (func_80387470(this, this->unk1C, 500.0f, 1000.0f, 140.0f, 500.0f, 120.0f)) {
                chfinalwitch_phase4_setState(this, 0x1D);
            }
            break;

        case 29:
            if ((func_80386BEC(this, 9.0f)) && (func_80297C6C() != 3) && (D_803927C4 == 0)) {
                chfinalwitch_phase4_setState(this, 0x1E);
            }
            break;

        case 30:
            func_80386BEC(this, 3.0f);
            if (D_803927C4 == 0) {
                func_80387340(this, 1.0f);
                if (actor_animationIsAt(this, 0.9999f)) {
                    local->unk3++;
                    chfinalwitch_phase4_setState(this, 0x1F);
                    this->unk60 = D_803917D0[sp70];
                }
            } else {
                chfinalwitch_phase4_setState(this, 0x1D);
            }
            break;

        case 31:
            func_80386BEC(this, 3.0f);
            if (this->unk60 > 0.0) {
                this->unk60 -= sp74;
                break;
            }
            if (func_80386BEC(this, 3.0f)) {
                chfinalwitch_phase4_setState(this, 0x1E);
            }
            break;

        case 32:
            if (actor_animationIsAt(this, 0.9999f)) {
                chfinalwitch_phase4_setState(this, 0x1C);
            }
            break;

        case 33:
            func_80386BEC(this, 3.0f);
            sp5C[0] = this->position[0] + (this->velocity[0] * sp74);
            sp5C[1] = this->position[1] + (this->velocity[1] * sp74);
            sp5C[2] = this->position[2] + (this->velocity[2] * sp74);
            temp_f2 = func_80309724(sp5C);
            if (sp5C[1] < temp_f2) {
                this->position[0] = sp5C[0];
                this->position[1] = sp5C[1];
                this->position[2] = sp5C[2];
                this->position[1] = temp_f2;
                chfinalwitch_phase4_setState(this, 0x22);
                func_8030E6A4(SFX_1F_HITTING_AN_ENEMY_3, randf2(0.95f, 1.05f), 32000);
                func_8030E6A4(SFX_132_GRUNTY_YOW, randf2(0.95f, 1.05f), 32000);
            }
            else{
                this->position[0] = sp5C[0];
                this->position[1] = sp5C[1];
                this->position[2] = sp5C[2];
                this->velocity[1] += -1400.0f * sp74;
            }
            break;

        case 34:
            sp58 = animctrl_getAnimTimer(this->animctrl);
            if (actor_animationIsAt(this, 0.17f) != 0) {
                func_8030E6A4(SFX_1F_HITTING_AN_ENEMY_3, randf2(0.95f, 1.05f), 32000);
                func_8030E6A4(SFX_133_GRUNTY_OHW, randf2(0.95f, 1.05f), 32000);
            }
            if (actor_animationIsAt(this, 0.1f) != 0) {
                func_8030E6A4(SFX_1F_HITTING_AN_ENEMY_3, randf2(0.95f, 1.05f), 32000);
                func_8030E6A4(SFX_12A_GRUNTY_AH, randf2(0.95f, 1.05f), 32000);
            }
            if ((sp58 >= 0.4) && (sp58 <= 0.65)) {
                func_8030DBB4(this->unk44_31, ((D_803927C0 += 0.005) > 1.99) ? 1.99 : (D_803927C0 += 0.005));
                func_8030E2C4(this->unk44_31);
            }
            if (actor_animationIsAt(this, 0.56f)) {
                func_8030E6A4(SFX_C5_TWINKLY_POP, randf2(0.95f, 1.05f), 32000);
            }
            else if (actor_animationIsAt(this, 0.9999f)) {
                func_80324E88(0.0f);
                func_80324E38(0.0f, 0);
                chfinalwitch_setPhase(this->marker, 5);
                func_8030DA44(this->unk44_31);
                this->unk44_31 = 0U;
            }
            break;
    }
}

void func_8038AC50(ActorMarker *arg0) {
    func_80328B8C(marker_getActor(arg0), 0x24, 0.0001f, 1);
}

void chfinalwitch_phase5_setState(Actor *this, s32 next_state) {
    ActorLocal_fight_180 *local;
    s32 sp28;
    u8 temp_v0;
    u8 temp_v0_2;


    local = (ActorLocal_fight_180 *)&this->local;
    sp28 = 0x12;
    local->phase = 5;
    func_80328B8C(this, next_state, 0.0001f, 1);
    switch (next_state) {
        case 35:
            func_80311480(randi2(0, 5) + 0x114F, 4, NULL, NULL, NULL, NULL);
            if (local->unk7) {
                sp28 = 0x13;
            }
            func_8028F94C(2, this->position);
            timedFunc_set_1(0.0f, chfinalwitch_spawnStatue, 5);
            timed_setCameraToNode(0.0f, sp28);
            func_80324E88(7.5f);
            timedFunc_set_1(7.5f, (TFQM1)func_8038AC50, (s32) this->marker);
            func_80324E38(7.5f, 0);
            break;

        case 36:
            func_8038AC50(this->marker);
            break;

        case 37:
            local->unk3 = 0;
            break;

        case 40:
            func_802BB41C(0);
            if (this->unk44_31 == 0) {
                this->unk44_31 = func_8030D90C();
                sfxsource_setSfxId(this->unk44_31, SFX_134_FREEZING_SHIVER);
                func_8030DD14(this->unk44_31, 2);
                func_8030DBB4(this->unk44_31, 1.0f);
                sfxsource_setSampleRate(this->unk44_31, 17000);
            }
            break;

        case 41:
            this->unk7C[2] = 0;
            if (this->unk44_31 == 0) {
                this->unk44_31 = func_8030D90C();
                sfxsource_setSfxId(this->unk44_31, SFX_134_FREEZING_SHIVER);
                func_8030DD14(this->unk44_31, 3);
                func_8030DBB4(this->unk44_31, 1.0f);
                sfxsource_setSampleRate(this->unk44_31, 17000);
                func_8030E2C4(this->unk44_31);
            }
            break;

        case 42:
            if (randf() < 0.5) {
                func_8030E878(SFX_131_GRUNTY_WEEEGH, randf2(0.95f, 1.05f), 32000, this->position, 5000.0f, 12000.0f);
            }
            else{
                func_8030E878(SFX_179_GRUNTY_DAMAGE, randf2(0.95f, 1.05f), 32000, this->position, 5000.0f, 12000.0f);
            }
            break;

        case 38:
            func_8025A6EC(SFX_GRUNTY_SPELL_POWERUP, 30000);
            break;

        case 43:
            func_8030E878(SFX_131_GRUNTY_WEEEGH, randf2(0.95f, 1.05f), 32000, this->position, 5000.0f, 12000.0f);
            actor_playAnimationOnce(this);
            break;
    }
}

void func_8038AF84(ActorMarker *arg0) {
    chfinalwitch_phase5_setState(marker_getActor(arg0), 0x29);
}

void func_8038AFB0(void) {
    func_802E4078(MAP_87_CS_SPIRAL_MOUNTAIN_5, 0, 1);
}

void chfinalwitch_phase5_update(ActorMarker *marker) {
    static f32 D_803917E0[3] = {0.0f, 186.0f, 0.0f};
    static f32 D_803917EC[3] = {-827.0f, 793.0f, 1700.0f};
    static f32 D_803917F8[3] = {827.0f, 793.0f, -1700.0f};
    static f32 D_803928C8[3];
    Actor *this;
    ActorLocal_fight_180 *local;
    f32 sp3C;
    s32 sp38;
    f32 sp34;
    ActorMarker *other_marker;
    s32 sp2C;
    s32 tmp_v0;

    this = marker_getActor(marker);
    local = (ActorLocal_fight_180 *)&this->local;
    sp3C = time_getDelta();
    sp38 = 0x14;
    sp34 = animctrl_getAnimTimer(this->animctrl);
    other_marker = func_8038A4E8(this, func_8033229C(this->marker) / 3.0f);
    if ((other_marker != NULL) && (other_marker->unk14_20 == 0x285)) {
        if (func_8039125C(other_marker)) {
            D_803927C6++;
            if (local->unk7) {
                sp38 = 0x23;
            }
            if (0xA > D_803927C6) {
                func_802BB3DC(0, 18.0f, 0.9f);
                func_80324E88(0.6f);
                timed_setCameraToNode(0.6f, sp38 + 3 + D_803927C6);
                func_80391070(other_marker, D_803927C6, local->unk7);
                chfinalwitch_phase5_setState(this, 0x2A);
                if (D_803927C6 == 9) {
                    sp2C = 0x16;
                    if(local->unk7) sp2C = 0x25;
                    timedFunc_set_1(2.4f, (TFQM1)func_8038AF84, (s32) this->marker);
                    timed_setCameraToNode(2.4f, sp2C);
                    func_80324E88(4.4f);
                    timed_setCameraToNode(4.4f, sp38 + 3 + D_803927C6);
                }
            } else {
                func_802BB3DC(0, 63.0f, 0.9f);
                func_803911F8(other_marker);
                func_8030E6D4(SFX_HEAVY_THUNDERSTORM_01);
                func_8025A6EC(SFX_JINJONATOR_HITS_GRUNTY_J, 20000);
                chfinalwitch_phase5_setState(this, 0x2B);
                func_80324E88(0.0f);
                timed_setCameraToNode(0.0f, sp38 + 0xD);
                func_8028F85C(D_803917E0);
                D_803928C8[0] = 0.0f;
                D_803928C8[1] = func_80257204(D_803917E0[0], D_803917E0[2], this->position[0], this->position[2]);
                D_803928C8[2] = 0.0f;
                func_8028FAEC(D_803928C8);
            }
            if (D_803927C6 == 3) {
                func_80311480(randi2(0, 5) + 0x1159, 0x20, NULL, NULL, NULL, NULL);
            }
        }
    }
    switch (this->state) {
        case 35:
            func_80386BEC(this, 3.0f);
            break;

        case 36:
            if (func_80386BEC(this, 9.0f) && (func_80297C6C() != 3)) {
                chfinalwitch_phase5_setState(this, 0x25);
            }
            break;

        case 37:
            func_80386BEC(this, 3.0f);
            if (func_80297C6C() == 3) {
                chfinalwitch_phase5_setState(this, 0x24);
                break;
            }
            if (func_80387340(this, 1.0f)) {
                local->unk3++;
            }
            if ((actor_animationIsAt(this, 0.9999f)) && (local->unk3 >= 5)) {
                chfinalwitch_phase5_setState(this, 0x26);
            }
            break;

        case 38:
            func_80386BEC(this, 3.0f);
            func_803873DC(this, 700.0f, 2400.0f);
            if (actor_animationIsAt(this, 0.9999f)) {
                chfinalwitch_phase5_setState(this, 0x27);
                this->unk60 = 4.0f;
            }
            break;

        case 39:
            if (local->unk8) {
                func_80386C68(this, 4.5f);
            } else {
                func_80386BEC(this, 3.0f);
            }
            if (this->unk60 > 0.0) {
                this->unk60 -= sp3C;
                break;
            }
            if (local->unk8 == 0) {
                if (!D_803927C9) {
                    D_803927C9 = TRUE;
                    chfinalwitch_phase5_setState(this, 0x23);
                }
                else{
                    chfinalwitch_phase5_setState(this, 0x25);
                }
            }
            break;

        case 40:
            if (actor_animationIsAt(this, 0.21f)) {
                FUNC_8030E8B4(SFX_163_GRUNTY_WILD_SCREAM, 1.0f, 32000, this->position, 5000, 12000);
            }
            if ((0.56 < sp34) && (sp34 < 0.99)) {
                func_8030E2C4(this->unk44_31);
            }
            if (actor_animationIsAt(this, 0.9999f)) {
                chfinalwitch_phase5_setState(this, 0x27);
                func_8030DA44(this->unk44_31);
                this->unk44_31 = 0;
            }
            break;

        case 41:
            if (actor_animationIsAt(this, 0.9999f)) {
                local->egg_hits++;
                if (local->egg_hits == 8) {
                    u8 v0;
                    func_802BB3DC(0, 12.0f, 1.0f);
                    v0 = this->unk44_31;
                    if (v0 != 0) {
                        func_8030E394(v0);
                        func_8030DA44(this->unk44_31);
                        this->unk44_31 = 0;
                    }
                }
            }
            break;

        case 42:
            if (actor_animationIsAt(this, 0.9999f)) {
                chfinalwitch_phase5_setState(this, 0x27);
            }
            break;

        case 43:
            if ((actor_animationIsAt(this, 0.1f)) || (actor_animationIsAt(this, 0.24f))) {
                func_8038C5F0(this, 0x718, 0x6C2, 2.0f);
            }
            if (actor_animationIsAt(this, 0.3f)) {
                FUNC_8030E624(SFX_164_EH, 1.0f, 25000);
            }
            if (actor_animationIsAt(this, 0.4f)) {
                FUNC_8030E624(SFX_164_EH, 1.075f, 25000);
            }
            if (actor_animationIsAt(this, 0.6f)) {
                FUNC_8030E624(SFX_164_EH, 1.1f, 25000);
            }
            if (actor_animationIsAt(this, 0.7f)) {
                FUNC_8030E624(SFX_164_EH, 1.15f, 25000);
            }
            if (actor_animationIsAt(this, 0.81f)) {
                FUNC_8030E624(SFX_130_GRUNTY_ECHOING_CRY, 1.0f, 32000);
            }
            if (actor_animationIsAt(this, 0.85f)) {
                func_803872F8(this);
            }
            if (actor_animationIsAt(this, 0.9f)) {
                func_802BAE4C();
                if (local->unk7 == 0) {
                    func_802BAEB4(D_803917EC, this->position);
                } else {
                    func_802BAEB4(D_803917F8, this->position);
                }
                func_8038FC2C(1);
                timedFunc_set_0(4.8, func_8038AFB0);
            }
            if (actor_animationIsAt(this, 0.9999f)) {
                marker_despawn(this->marker);
            }
            break;
    }
}

void chfinalwitch_phase1_init_textCallback(ActorMarker *marker, enum asset_e text_id, s32 arg2) {
    Actor *sp1C;

    sp1C = marker_getActor(marker);
    func_802BE720();
    func_80324E88(0);
    func_8028F784(0);
    chfinalwitch_setPhase(sp1C->marker, 1);
}

void chfinalwitch_phase1_init(ActorMarker *marker) {
    Actor *sp24;

    sp24 = marker_getActor(marker);
    if (!func_8031FF1C(0xCF)) {
        sp24 = sp24;
        func_80320004(0xCF, 1);
        func_80311480(0x10E7, 0x2A, sp24->position, sp24->marker, chfinalwitch_phase1_init_textCallback, NULL);
        return;
    }
    sp24 = sp24;
    func_80311480(randi2(0, 5) + 0x10E8, 0x2B, sp24->position, sp24->marker, chfinalwitch_phase1_init_textCallback, NULL);
}

void chfinalwitch_phase0_update(ActorMarker *marker) { return; }

bool func_8038B834(ActorMarker *marker, ActorMarker * arg1) {
    Actor *this;
    ActorLocal_fight_180 *local;

    this = marker_getActor(marker);
    local = (ActorLocal_fight_180 *)&this->local;
    switch (local->phase) {
    case 1:
        if ((this->state == 6) || (this->state == 7)) {
            marker->unk14_20 = 0x260;
        } else {
            marker->unk14_20 = 0x25E;
        }
        break;
    case 2:
        if (local->unkA == 0) {
            marker->unk14_20 = 0x260;
        } else {
            marker->unk14_20 = 0x281;
        }
        break;
    case 3:
        marker->unk14_20 = 0x282;
        break;
    case 4:
        marker->unk14_20 = 0x283;
        break;
    case 5:
        marker->unk14_20 = 0x283;
        break;
    default:
        marker->unk14_20 = 0x25E;
        break;
    }
    return TRUE;
}

void func_8038B9AC(ActorMarker *marker, ActorMarker *other_marker) {
    Actor *this;
    ActorLocal_fight_180 *local;

    this = marker_getActor(marker);
    local = (ActorLocal_fight_180 *)&this->local;
    switch (local->phase) {
    case 1:
        if (local->hits == 0) {
            func_80311480(randi2(0, 5) + 0x10F7, 0x20, NULL, NULL, NULL, NULL);
        }
        if ((local->hits + 1) < 5) {
            local->hits++;
            chfinalwitch_phase1_setState(this, 0xD);
            local->unk4 = 0;
        }
        break;

    case 2:
        if (this->state != 0x14) {
            if ((local->egg_hits + 1) >= 3) {
                local->egg_hits = 0;
                if (local->hits == 0) {
                    func_80311480(randi2(0, 5) + 0x1110, 0x20, NULL, NULL, NULL, NULL);
                }
                if ((local->hits + 1) < 5) {
                    local->hits++;
                    chfinalwitch_phase2_setState(this, 0x14);
                }
            } else {
                local->egg_hits++;
                chfinalwitch_phase2_setState(this, 0x13);
            }
        }
        break;
    case 3:
        if (local->hits == 0) {
            func_80311480(randi2(0, 5) + 0x1127, 0x20, NULL, NULL, NULL, NULL);
        }
        if ((local->hits + 1) < 5) {
            local->hits++;
            chfinalwitch_phase3_setState(this, 0x19);
            if (local->hits == 4) {
                func_802C3C88((GenMethod_1)__chfinalwitch_dropHealth, reinterpret_cast(s32, this->marker));
            }
        }
        break;
    }
}

void func_8038BB8C(ActorMarker *marker, ActorMarker *other_marker) {
    Actor *this;
    ActorLocal_fight_180 *local;
    u8 temp_v0_2;

    this = marker_getActor(marker);
    local = (ActorLocal_fight_180 *)&this->local;
    if (local->phase == 1) {
        func_8030E878(SFX_EA_GRUNTY_LAUGH_1, randf2(0.95, 1.05), 32000, this->position, 5000.0f, 12000.0f);
        if (local->unk10 == 0) {
            if (func_80311480(randi2(0, 5) + 0x10ED, 0, NULL, NULL, NULL, NULL)) {
                local->unk10++;
            }
        }
    }
    if (local->phase == 3) {
        temp_v0_2 = local->unk6;
        if ((local->unk6 == 0) && (this->state != 0x1A)) {
            local->unk6++;
            func_80311480(randi2(0, 5) + 0x111D, 0, NULL, NULL, NULL, NULL);
        }
    }
}

void chfinalwitch_spawnShadow(ActorMarker *marker) {
    Actor *sp1C;

    sp1C = marker_getActor(marker);
    sFinalWitchShadowMarker = spawn_child_actor(ACTOR_3AF_GRUNTY_SHADOW, &sp1C)->marker;
}

void chfinalwitch_update(Actor *this){
    static f32 D_80391804[3] = {0.0f, 0.0f, 1350.0f};
    ActorLocal_fight_180 *local = (ActorLocal_fight_180 *) &this->local;
    s32 i;
    s32 tmp_s0;
    Actor *shadow;
    f32 sp4C[3];
    f32 sp40[3];
    f32 sp34[3];

    if(!this->unk16C_4){
        this->unk16C_4 = TRUE;
        func_803300C0(this->marker, func_8038B834);
        marker_setCollisionScripts(this->marker, func_8038BB8C, func_8038B9AC, NULL);
        this->marker->propPtr->unk8_3 = 0;
        actor_collisionOn(this);
        for(i = 0x38C; i < 0x39F; i++){
            func_80304E24(i, D_803927D0[i - 0x38C]);
        }
        sFlightPadMarker = NULL;
        sFinalWitchShadowMarker = NULL;
        D_803927C4 = 0;
        sFinalWitch_SpellBarrierActive = 0;
        D_803927C6 = 0;
        D_803927C7 = 0;
        D_803927C8 = 0;
        D_803927C9 = 0;

        local->unk8 = 0;
        local->unk9 = 0;
        local->unkB = 0;

        for(i = 0; i < 4; i++){
            sJinjoStatueMarker[i] = NULL;
        }

        func_802C3C88((GenMethod_1)chfinalwitch_spawnShadow, (s32)this->marker);
        chfinalwitch_setPhase(this->marker, 0);
        local->hits = 0;
        func_80386600(this->marker, 0);
        func_80386628(this->marker, 1);
        func_8038FC00();

        func_80386654(1.0f, D_80391380, D_80391390);
        func_8028F784(1);
        func_8028F4B8(D_80391804, 2000.0f, -2800.0f);
        func_8028FA14(0x93, 2);
        func_8034C9B0(0);
        func_80386698(2.0f);
        tmp_s0 = func_802F9AA8(SFX_9A_MECHANICAL_CLOSING);
        func_802F9DB8(tmp_s0, 0.6, 0.6, 0.0f);
        func_802F9FD0(tmp_s0, 0.0f, 2.0f, 0.0f);
        func_802FA060(tmp_s0, 25000, 25000, 0);
        timed_playSfx(2.0f, SFX_7F_HEAVYDOOR_SLAM, 1.0f, 32000);
    }//L8038BF0C
    switch(local->phase){
        case 0:
            chfinalwitch_phase0_update(this->marker);
            break;
        case 1:
            chfinalwitch_phase1_update(this->marker);
            break;
        case 2:
            chfinalwitch_phase2_update(this->marker);
            break;
        case 3:
            chfinalwitch_phase3_update(this->marker);
            break;
        case 4:
            chfinalwitch_phase4_update(this->marker);
            break;
        case 5:
            chfinalwitch_phase5_update(this->marker);
            break;
    }
    func_80320524(0x23, local->phase, 3);
    player_getPosition(D_80392788);
    D_80392798[0] = this->position[0];
    D_80392798[1] = this->position[1];
    D_80392798[2] = this->position[2];
    if(this->unk100 && sFinalWitch_SpellBarrierActive){
        func_8038EB90(this->unk100, this->position);
    }

    if(sFinalWitchShadowMarker){
        shadow = marker_getActor(sFinalWitchShadowMarker);
        sp4C[0] = this->position[0];\
        sp4C[1] = this->position[1];\
        sp4C[2] = this->position[2];
        sp4C[1] = 200.0f;

        sp34[0] = this->position[0];\
        sp34[1] = this->position[1];\
        sp34[2] = this->position[2];
        sp34[1] = -50.0f;
        if(func_80309B48(sp4C, sp34, sp40, 0)){
            sp34[1] += 6.0f;
            shadow->position[0] = sp34[0];\
            shadow->position[1] = sp34[1];\
            shadow->position[2] = sp34[2];
            shadow->unk1C[0] = this->position_y - sp34[1];
            shadow->scale = this->scale;
            shadow->unk58_0 = 1;
        }
        else{//L8038C0B8
            shadow->unk58_0 = 0;
        }
    }//L8038C0C8
}

void func_8038C0DC(f32 arg0[3]) {
    arg0[0] = D_80392798[0];
    arg0[1] = D_80392798[1];
    arg0[2] = D_80392798[2];
}

void func_8038C100() {
    sFinalWitch_SpellBarrierActive = FALSE;
}

void func_8038C10C(ActorMarker *arg0) {
    chfinalwitch_phase5_setState(marker_getActor(arg0), 0x28);
}

void func_8038C138() {
    D_803927C7 = 1;
}

void func_8038C148(void) {
    Actor *witch = func_80326EEC(ACTOR_38B_GRUNTILDA_FINAL_BOSS);
    ActorLocal_fight_180 *witch_local;
    s32 pad44;
    f32 sp40;
    f32 temp_f20;
    s32 phi_s0;
    f32 sp34;

    witch_local = (ActorLocal_fight_180 *)&witch->local;
    sp34 = func_8038DFA0();
    temp_f20 =  sp34 + func_80391234();
    
    sp40 = func_80391240();
    phi_s0 = 0x14;
    func_80320004(0xFC, 1);
    if (witch_local->unk7 != 0) {
        phi_s0 = 0x23;
    }
    chfinalwitch_phase5_setState(witch, 0x27);
    witch_local->unk8 = (u8)1;
    func_80324E38(0, 1);
    timed_setCameraToNode(0, phi_s0);
    func_80324E88(temp_f20);
    timedFunc_set_0(temp_f20 * 0.08, &func_8038C138);
    timed_setCameraToNode(temp_f20, phi_s0 + 1);
    
    func_80324E88(temp_f20 + sp40);
    timedFunc_set_1(temp_f20 + sp40, (TFQM1)func_8038C10C, (s32)witch->marker);
    timed_setCameraToNode(temp_f20 + sp40, phi_s0 + 2);
    
    func_80324E88(temp_f20 + sp40 + 2.88f);
    timed_setCameraToNode(temp_f20 + sp40 + 2.88f, phi_s0 + 3);
}

void func_8038C27C(s32 arg0) {
    D_803927C4 = arg0;
}

f32 func_8038C288() {
    return 3.0f;
}

s32 func_8038C298() {
    return D_803927C7;
}

s32 func_8038C2A4() {
    return D_803927C8;
}

s32 func_8038C2B0() {
    return D_803927C9;
}


#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void func_80335A8C(Struct80s *, s32);
extern f32 func_8025715C(f32, f32);
extern f32 func_802575BC(f32);
extern void func_80255FE4(f32[3], f32[3], f32[3], f32);
extern bool func_80320DB0(f32[3], f32, f32[3], u32);
/* .h */
Actor *func_80358344(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);
void func_80358684(Actor *this);

typedef struct {
    u8 unk0;
    // u8 pad1[0x3];
    f32 unk4;
    f32 unk8[3];
    f32 unk14;
    f32 unk18[3];
    f32 unk24;
    f32 unk28;
    f32 unk2C;
    s16 unk30[3];
    s16 unk36;
    u8 unk38;
    u8 unk39;
}ActorLocal_core2_D0CA0;

/* .data */
extern ActorInfo D_803728A0 = { 
    0x253, ACTOR_380_SCARAB_BEETLE, ASSET_51B_MODEL_SCARAB_BEETLE, 
    0, NULL, 
    func_80358684, NULL, func_80358344, 
    0, 0, 1.0f, 0
};

extern struct31s D_803728C4;
extern struct43s D_803728EC;

/* .rodata */
extern f64 D_80379600;
extern f32 D_80379608;
extern f32 D_8037960C;
extern f32 D_80379610;
extern f32 D_80379614;
extern f32 D_80379618;
extern f32 D_8037961C;
extern f64 D_80379620;
extern f64 D_80379628;
extern f32 D_80379630;
extern f32 D_80379634;
extern f32 D_80379638;
extern f64 D_80379640;
extern f64 D_80379648;
extern f64 D_80379650;
extern f64 D_80379658;
extern f64 D_80379660;
extern f64 D_80379668;
extern f32 D_80379670;
extern f32 D_80379674;

/* .code */
bool func_80357C30(Actor *this) {
    ActorLocal_core2_D0CA0 *local;
    f32 pad;
    f32 sp2C[3];
    f32 sp20[3];

    local = (ActorLocal_core2_D0CA0 *)&this->local;
    if (!this->marker->unk14_21) {
        return TRUE;
    }
    func_80255FE4(sp20, local->unk8, local->unk18, func_802575BC(local->unk4 + D_80379600));
    sp20[1] += 60.0f;
    return !func_80320DB0(sp20, 50.0f, sp2C, 0);
}

void func_80357CD0(Actor *this, f32 arg1[3]) {
    ActorLocal_core2_D0CA0 *local;
    f32 var_f2;
    f32 sp1C[3];

    local = (ActorLocal_core2_D0CA0 *)&this->local;
    local->unk39 = 2;
    local->unk4 = 0.0f;
    local->unk8[0] = this->position[0];\
    local->unk8[1] = this->position[1];\
    local->unk8[2] = this->position[2];
    local->unk18[0] = arg1[0];
    local->unk18[1] = arg1[1];
    local->unk18[2] = arg1[2];
    local->unk14 = this->yaw;
    local->unk14 = (local->unk14 >= 360.0f) ? local->unk14 - 360.0f : local->unk14;
    local->unk14 = (local->unk14 <= -360.0f) ? local->unk14 + 360.0f : local->unk14;
    local->unk24 = local->unk14;
    sp1C[0] = local->unk18[0] - local->unk8[0];
    sp1C[1] = local->unk18[1] - local->unk8[1];
    sp1C[2] = local->unk18[2] - local->unk8[2];
    var_f2 = func_8025715C(sp1C[0], sp1C[2]);
    if ((var_f2 - local->unk14) > 180.0f) {
        var_f2 -= 360.0f;
    }
    if ((var_f2 - local->unk14) < -180.0f) {
        var_f2 += 360.0f;
    }
    local->unk24 = var_f2;
}

void func_80357E34(Actor *this, f32 arg1[3]) {
    f32 temp_f12;
    f32 var_f2;
    f32 sp1C[3];
    ActorLocal_core2_D0CA0 *local;

    local = (ActorLocal_core2_D0CA0 *)&this->local;
    local->unk18[0] = arg1[0];
    local->unk18[1] = arg1[1];
    local->unk18[2] = arg1[2];
    sp1C[0] = local->unk18[0] - local->unk8[0];
    sp1C[1] = local->unk18[1] - local->unk8[1];
    sp1C[2] = local->unk18[2] - local->unk8[2];
    var_f2 = func_8025715C(sp1C[0], sp1C[2]);
    temp_f12 = var_f2 - local->unk14;
    if (temp_f12 > 180.0f) {
        var_f2 -= 360.0f;
    } else if (temp_f12 < -180.0f) {
        var_f2 += 360.0f;
    }
    local->unk24 = var_f2;
}


void func_80357F0C(Actor *this, s32 next_state) {
    ActorLocal_core2_D0CA0 *local;
    s32 var_s0;
    f32 sp54[3];
    f32 sp48[3];

    local = (ActorLocal_core2_D0CA0 *)&this->local;
    if (this->state == 0) {
        func_80335924(this->unk148, 0x23A, 0.0f, 0.45f);
        func_80335A8C(this->unk148, 1);
    }

    this->state = next_state;
    local->unk36 = 0;
    local->unk28 = 0.0f;
    if (this->state == 1) {
        local->unk28 = randf2(0.0f, 2.0f);
    }
    if (this->state == 2) {
        func_80335924(this->unk148, 0x23A, 0.3f, 0.45f);
        func_80335A8C(this->unk148, 1);
        for(var_s0 = 0; var_s0 < 10; var_s0++){
            sp54[0] = this->position[0];
            sp54[1] = this->position[1];
            sp54[2] = this->position[2];
            sp54[1] = (f32) local->unk30[1];
            sp54[0] += randf2(-300.0f, 300.0f);
            sp54[1] += randf2(-100.0f, 100.0f);
            sp54[2] += randf2(-300.0f, 300.0f);
            if (func_80329210(this, sp54))
                break;
        }
        if (var_s0 == 0xA) {
            sp54[0] = (f32) local->unk30[0];
            sp54[1] = (f32) local->unk30[1];
            sp54[2] = (f32) local->unk30[2];
        }
        func_80357CD0(this, sp54);
    }
    if (this->state == 3) {
        player_getPosition(sp48);
        sp48[1] += 50.0f;
        func_80357CD0(this, sp48);
    }
    if (this->state == 5) {
        func_8028F55C(1, this->marker);
        FUNC_8030E624(SFX_1F_HITTING_AN_ENEMY_3, 1.2f, 32200);
        func_80335924(this->unk148, 0x23A, 0.4f, 1.0f);
        func_80335A8C(this->unk148, 1);
        timed_playSfx(D_80379610, 0x3FC, randf2(D_80379608, D_8037960C), 32000);
        local->unk39 = 0;
        local->unk28 = 2.0f;
    }
    if (this->state == 4) {
        local->unk28 = 3.5f;
    }
    if (this->state == 6) {
        this->unk138_27 = 1;
        this->marker->collidable = FALSE;
        this->unk10_1 = FALSE;
        FUNC_8030E624(SFX_1F_HITTING_AN_ENEMY_3, 1.2f, 32200);
        func_80335924(this->unk148, 0x23D, 0.3f, 0.45f);
        func_80335A8C(this->unk148, 1);
        local->unk36 = 0x3E8;
        local->unk39 = 0;
    }
    if (this->state == 7) {
        local->unk2C = 0.0f;
    }
    if (this->state == 8) {
        marker_despawn(this->marker);
    }
}

void func_803582C4(ActorMarker *marker, ActorMarker *other_marker){
    Actor *this;

    this = marker_getActor(marker);
    if(this->state < 5){
        func_80357F0C(this, 5);
    }
}

void func_80358304(ActorMarker *marker, ActorMarker *other_marker){
    Actor *this;

    this = marker_getActor(marker);
    if(this->state < 6){
        func_80357F0C(this, 6);
    }
}

Actor *func_80358344(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx) {
    Actor *this;
    ActorLocal_core2_D0CA0 *local;

    this = marker_getActor(marker);
    local = (ActorLocal_core2_D0CA0 *)&this->local;
    if (this->state == 0) {
        return this;
    }
    this->unk124_11 = 1;
    if (this->state == 7) {
        this->alpha_124_19 = (1.0f - local->unk2C)*255.0f;
    } else {
        this->alpha_124_19 = 0xff;
    }
    return func_80325888(marker, gfx, mtx, vtx);
}

void func_80358490(Actor *this) {
    ActorLocal_core2_D0CA0 *local;

    local = (ActorLocal_core2_D0CA0 *)&this->local;
    if(local->unk0 != 0){
        func_8030DA44(local->unk0);
    }
}

void func_803584BC(Actor *this) {
    ActorLocal_core2_D0CA0 *local;

    local = (ActorLocal_core2_D0CA0 *)&this->local;
    local->unk0 = func_8030D90C();
    func_8030DBB4(local->unk0, 0.9f);
    func_8030DA80(local->unk0, 0x3FA);
    func_8030DD14(local->unk0, 2);
    func_8030DABC(local->unk0, 0);
}


void func_80358524(f32 position[3], s32 count, enum asset_e model_id) {
    ParticleEmitter *p_ctrl;
    ParticleEmitter *temp_v0;

    temp_v0 = partEmitList_pushNew(count);
    p_ctrl = temp_v0;
    particleEmitter_setModel(temp_v0, model_id);
    particleEmitter_setPosition(p_ctrl, position);
    func_802EFE24(p_ctrl, -400.0f, -400.0f, -400.0f, 400.0f, 400.0f, 400.0f);
    func_802EF9F8(p_ctrl, 0.01f);
    func_802EFA18(p_ctrl, 3);
    func_802EFA20(p_ctrl, 1.0f, 1.3f);
    func_802EF9EC(p_ctrl, 0x2F, 16000);
    particleEmitter_setPositionVelocityAndAccelerationRanges(p_ctrl, &D_803728EC);
    func_802EFB98(p_ctrl, &D_803728C4);
    particleEmitter_emitN(p_ctrl, count);
}

void func_80358610(Actor *this) {
    func_80358524(this->position, 1, 0x51C);
    func_80358524(this->position, 2, 0x51D);
    func_80358524(this->position, 2, 0x51E);
    func_80358524(this->position, 1, 0x51F);
    func_80358524(this->position, 4, 0x520);
}

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_D0CA0/func_80358684.s")
#else
void func_80358684(Actor *this) {
    ActorLocal_core2_D0CA0 *local;
    f32 sp94[4];
    s32 next_state;
    f32 sp88;
    f32 sp84;
    f32 sp80;
    f32 sp7C;
    f32 sp70;
    f32 sp60[3];
    f32 sp54[3];
    f32 sp48[3];
    f32 sp3C[3];
    f32 *sp30;
    f32 sp2C;
    f32 temp_a3;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f2;
    f32 temp_f2_2;
    f32 temp_f2_3;
    f32 temp_f2_4;
    f32 var_f0;
    f32 var_f12;
    f32 var_f16;
    f32 var_f18;
    f32 var_f2;
    f32 var_f2_2;
    f64 temp_f0_3;
    f64 temp_f12;
    u32 temp_t1;
    u32 temp_t2;
    u32 temp_t3;
    u32 var_v0;

    local = (ActorLocal_core2_D0CA0 *)&this->local;
    next_state = 0;
    sp88 = time_getDelta();
    if (!this->unk16C_4) {
        this->unk16C_4 = TRUE;
        this->marker->unk30 = func_80358490;
        local->unk38 = 0;
        local->unk39 = 0;
        local->unk28 = 0.0f;
        local->unk30[0] = (s16) (s32) this->position[0];
        local->unk30[1] = (s16) (s32) this->position[1];
        local->unk30[2] = (s16) (s32) this->position[2];
        local->unk30[1] += 0xC8;
        marker_setCollisionScripts(this->marker, func_803582C4, NULL, func_80358304);
        local->unk0 = 0;
        func_80357F0C(this, 1);
    }

    if (!actor_playerIsWithinDist(this, 4000)) {
        if (local->unk0 != 0) {
            func_8030DA44(local->unk0);
            local->unk0 = 0U;
        }
        return;
    }

    if (local->unk0 == 0) {
        func_803584BC(this);
    }
    player_getPosition(sp94);
    if (this->state != 0 && (this->state < 6)) {
        temp_f0 = func_8030E200(local->unk0);
        if (local->unk39 == 1) {
            var_f16 = D_80379614;
            var_f18 = 1.0f;
        } else {
            var_f16 = D_80379618;
            var_f18 = D_8037961C;
        }
        if (temp_f0 < var_f16) {
            var_f2 = (f32) ((f64) temp_f0 + D_80379620);
        } else if (var_f18 < temp_f0) {
            var_f2 = (f32) ((f64) temp_f0 - D_80379628);
        } else {
            sp84 = temp_f0;
            sp80 = var_f16;
            sp7C = var_f18;
            temp_f2 = temp_f0 + randf2(D_80379630, D_80379634);
            if (temp_f2 < var_f16) {
                var_f2 = var_f16;
            } else {
                if (var_f18 < temp_f2) {
                    var_f0 = var_f18;
                } else {
                    var_f0 = temp_f2;
                }
                var_f2 = var_f0;
            }
        }
        func_8030DBB4(local->unk0, var_f2);
        temp_f2_2 = ml_vec3f_distance(sp94, this->position) / 2000.0f;
        var_f12 = 1.0f - temp_f2_2;
        if (temp_f2_2 > 1.0f) {
            var_f12 = 0.0f;
        }
        if (var_f12 > 0.0f) {
            func_8030DABC(var_f12, local->unk0, (s32) (var_f12 * D_80379638));
            func_8030E2C4(local->unk0);
        }
    }
    if (this->unk10_25) {
        if (func_8025773C(&local->unk28, sp88)) {
            next_state = 2;
        }
        if (local->unk39 == 2) {
            if (this->state == 3) {
                local->unk4 += 2 * sp88;
            } else {
                local->unk4 += 1 * sp88;
            }
            if (local->unk4 >= 1.0f) {
                local->unk4 = 1.0f;
                if (func_803203FC(0xC1)) {
                    local->unk39 = 0;
                } else {
                    if (this->state == 2) {
                        local->unk39 = 1;
                    } else if (this->state == 3) {
                        if (func_8033567C(this->unk148) != 0x23B) {
                            func_80335924(this->unk148, 0x23B, 0.2f, 0.75f);
                            func_80335A8C(this->unk148, 2);
                        } else if (D_80379640 <= func_80335684(this->unk148)) {
                            local->unk39 = 1U;
                        }
                    }
                }
            }
            if (local->unk39 == 2) {
                this->yaw = local->unk14 + (func_802575BC(local->unk4) * (local->unk24 - local->unk14));
            } else {
                local->unk4 = 0.0f;
                local->unk14 = local->unk24;
            }
        }
        if (local->unk39 == 1) {
            sp30 = this + 4;
            sp2C = 1.0f * sp88;
            if ((func_80357C30(this) == 0) || ((this->state == 3) && (func_80329210(this, sp30) == 0))) {
                local->unk18[0] = (f32) this->position[0];
                local->unk18[1] = (f32) this->position[1];
                local->unk18[2] = (f32) this->position[2];
                local->unk4 = 1.0f;
            }
            local->unk4 = (f32) (local->unk4 + sp2C);
            if (local->unk4 >= 1.0f) {
                local->unk39 = 0U;
                local->unk4 = 1.0f;
            }
            sp70 = func_802575BC(local->unk4);
            func_80255FE4(sp30, local->unk8, local->unk18, sp70);
            this->yaw = local->unk14 + (sp70 * (local->unk24 - local->unk14));
            if ((func_8033567C(this->unk148) == 0x23B) && (func_80335794(this->unk148) > 0)) {
                func_80335924(this->unk148, 0x23C, 0.1f, 0.45f);
                func_80335A8C(this->unk148, 1);
            }
            if ((local->unk39 == 0) || ((func_8033567C(this->unk148) == 0x23C) && (D_80379648 <= (f64) local->unk4))) {
                func_80335924(this->unk148, 0x23A, 0.3f, 0.45f);
                func_80335A8C(this->unk148, 1);
            }
            if (this->state == 3) {
                temp_f12 = D_80379650;
                temp_f0_3 = (f64) local->unk4;
                if (temp_f12 <= temp_f0_3) {
                    if (D_80379658 < temp_f0_3) {
                        var_f2_2 = 0.0f;
                    } else {
                        var_f2_2 = (f32) (1.0 - ((temp_f0_3 - temp_f12) / D_80379660));
                    }
                    func_8030DBB4(local->unk0, (f32) (((f64) var_f2_2 * D_80379668) + 1.0));
                }
            }
        }
        if (this->state == 1) {
            player_getPosition(sp60);
            sp60[1] += 50.0f;
            if (func_80329210(this, sp60) && (sp60[1] < (local->unk30[1] + 300)) && !func_8028F25C() && this->marker->unk14_21) {
                sp60[0] = 0.0f;
                sp54[0] = this->position[0];
                sp54[1] = this->position[1];
                sp54[2] = this->position[2];
                sp54[0] = 0.0f;
                if (ml_vec3f_distance(sp60, sp54) < 800.0f) {
                    next_state = 3;
                }
            }
        }
        if ((this->state == 2) && (local->unk39 == 0)) {
            next_state = 1;
        }
        if (this->state == 3) {
            if (local->unk39 == 0) {
                local->unk38++;
                if (local->unk38 == 3) {
                    next_state = 4;
                    local->unk38 = 0;
                } else {
                    next_state = 1;
                }
            } else if ((this->state == 2) || (local->unk4 < 0.5)) {
                sp48[0] = sp94[0];
                sp48[1] = sp94[1] + 50.0f;
                sp48[2] = sp94[2];
                func_80357E34(this, &sp48);
            }
        }
        if ((this->state == 5) || (this->state == 4)) {
            this->position[1] += 50.0f * sp88;
            this->yaw += 10.0f * sp88;
        }
        if (this->state == 6) {
            if (func_8033567C(this->unk148) == 0x23D) {
                sp3C[0] = this->position[0] - sp94[0];
                sp3C[1] = this->position[1] - sp94[1];
                sp3C[2] = this->position[2] - sp94[2];
                sp3C[1] = 0.0f;
                ml_vec3f_set_length(sp3C, 200.0f * sp88);
                this->position[0] += sp3C[0];
                this->position[1] += sp3C[1];
                this->position[2] += sp3C[2];
                this->position[1] += local->unk36;
                local->unk36 -= D_80379670 * sp88;
                if (this->position[1] < func_80309724(this->position)) {
                    this->position[1] = func_80309724(this->position);
                    next_state = 7;
                    FUNC_8030E624(SFX_1F_HITTING_AN_ENEMY_3, 1.2f, 32200);
                    timed_playSfx(D_80379674, SFX_66_BIRD_AUUGHH, 1.6f, 32000);
                }
            } else if (func_80335794(this->unk148) > 0) {
                next_state = 7;
            }
        }
        if (this->state == 7) {
            next_state = 8;
            func_80358610(this);
        }

        if (next_state != 0) {
            func_80357F0C(this, next_state);
        }
    }
}
#endif

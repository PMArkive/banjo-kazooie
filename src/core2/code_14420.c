#include <ultra64.h>
#include "functions.h"
#include "variables.h"

f32 func_8024DDD8(f32[3], f32);
extern void func_8024E71C(s32, f32*);
extern f32 ml_acosf(f32);
extern f32 func_8028EBA4(void);
extern void particleEmitter_setSphericalParticleVelocityRange(ParticleEmitter *this, f32 pitch_min, f32 yaw_min, f32 radial_min, f32 pitch_max, f32 yaw_max, f32 radial_max);
ParticleEmitter * func_802EDD8C(f32[3], f32, f32);
extern void func_80354030(f32[3], f32);
extern void func_80354380(f32[3], f32);
extern void func_80356074(f32[3], f32[3], f32, f32);
extern void func_80292864(f32, f32);

typedef struct {
    s16 state_id;
    s16 anim_id;
    f32 anim_duration;
} Struct_core2_13FC0;

/* .data */ 
s32 D_80364620;
s16 D_80364624[14];
u8 D_80364640[16];
Struct_core2_13FC0 D_80364650[14];
Struct_core2_13FC0 D_803646C0[14];
Struct_core2_13FC0 D_80364730[14];
Struct_core2_13FC0 D_803647A0[14];
Struct_core2_13FC0 D_80364810[14];
Struct_core2_13FC0 D_80364880[14];
Struct_core2_13FC0 D_803648F0[14];

/* .bss */
// extern struct {
//     s32 map_id;
//     s32 exit_id;
// }D_8037D1E0;
s32 D_8037D1E0[2];
extern u8  D_8037D1E8;

/* .code */
f32 func_8029B3B0(f32 arg0) {
    if (func_8028B128()) {
        return arg0 * 0.2;
    }
    if (func_8028B120()) {
        return arg0 * 0.2;
    }
    return arg0;
}

f32 func_8029B41C(void){
    f32 sp2C[3];
    f32 sp20[3];
    f32 sp1C;

    player_getPosition(sp2C);
    func_8024C5CC(sp20);
    func_80257F18(sp2C, sp20, &sp1C);
    return sp1C;
}

enum bs_e func_8029B458(void){
    enum bs_e sp1C;
    
    sp1C = bs_getState();
    switch(_player_getTransformation()){
        case TRANSFORM_2_TERMITE:
            return BS_38_ANT_FALL;

        case TRANSFORM_3_PUMPKIN:
            return BS_4B_PUMPKIN_FALL;

        case TRANSFORM_5_CROC:
            return BS_61_CROC_FALL;

        case TRANSFORM_4_WALRUS:
            if(func_802B8190(sp1C))
                return BS_82_WALRUS_SLED_LOSE_IN_AIR;
            return BS_6A_WALRUS_FALL;

        case TRANSFORM_6_BEE:
            return BS_88_BEE_FALL;

        default:
            if(bsbtrot_inSet(sp1C))
                return BS_71_BTROT_FALL;
            return BS_2F_FALL;
    }
}

enum bs_e func_8029B504(void){
    enum bs_e sp1C;

    if(func_802933C0(0xF))
        return 0;

    func_802933E8(0xF);
    sp1C = func_8029B458();
    if(bs_getState() != sp1C)
        return sp1C;
    return 0;

}

s32 func_8029B564(void){
    return 1;
}

f32 func_8029B56C(f32 arg0, f32 arg1, f32 arg2, f32 arg3) {
    f32 phi_f0;
    f32 phi_f2;

    phi_f0 = arg2;
    phi_f2 = 0.0f;
    while ((phi_f0 > 0.0f) || (arg1 < arg0)) {
            phi_f2 += 0.0166666675f;
            arg0 += phi_f0 * 0.0166666675f;
            phi_f0 += arg3 * 0.0166666675f;
    }
    return phi_f2;
}

void func_8029B5EC(void){
    func_802DC560(0, 0);
    func_802E412C(1, 0);
    func_802E4078(MAP_1F_CS_START_RAREWARE, 0, 1);
}

void func_8029B62C(void){
    if(item_empty(ITEM_16_LIFE)){
        if(!func_8031FF1C(BKPROG_BD_ENTER_LAIR_CUTSCENE) || func_8031FF1C(BKPROG_A6_FURNACE_FUN_COMPLETE)){
            func_8025A430(-1, 0x7D0, 3);
            func_8025A2B0();
            func_802DC528(0, 0);
            func_80324C58();
            timedFunc_set_0(5.0f, func_8029B5EC);
        }
        else{
            func_802E412C(1, 0);
            func_802E4078(MAP_83_CS_GAME_OVER_MACHINE_ROOM, 0, 1);

        }
    }
    else{
        func_802E4048(D_8037D1E0[0], D_8037D1E0[1], 1);
    }
}

void func_8029B6F0(void){
    if(item_empty(ITEM_16_LIFE)){
        func_8029B62C();
    }
    else{
        func_802E4078(D_8037D1E0[0], D_8037D1E0[1], 1);
    }
}

void func_8029B73C(f32 arg0[3], f32 arg1, f32 arg2, f32 arg3, f32 arg4) {
    f32 sp3C[3];
    f32 sp30[3];
    f32 temp_f20;

    func_8028FA74(sp3C);
    if(sp3C[1] < (arg0[1] + arg2))
        return;

    if(sp3C[1] > (arg0[1] + arg1))
        return;

    sp30[0] = sp3C[0] - arg0[0];
    sp30[1] = 0.0f;
    sp30[2] = sp3C[2] - arg0[2];
    temp_f20 = (sp30[0]*sp30[0] + sp30[1]*sp30[1] + sp30[2]*sp30[2]);

    if (!((arg3 * arg3) < temp_f20)) {
        temp_f20 = gu_sqrtf(temp_f20);
        ml_vec3f_set_length_copy(sp30, sp30, min_f(time_getDelta() * arg4, arg3 - temp_f20));
        ml_vec3f_add(sp3C, sp3C, sp30);
        func_8028FAB0(sp3C);
    }

}

void func_8029B85C(ActorMarker *caller, enum asset_e text_id, s32 arg2){
    func_8030E6D4(SFX_EB_GRUNTY_LAUGH_2);
    func_8029B62C();
}

void func_8029B890(void){
    if(!func_8031FF1C(BKPROG_A8_HAS_DIED) && !func_803203FC(2)){
        func_803114D0();
        if(bs_getState() == 0x54){
            func_8029B62C();
            return;
        }
        func_80311480(0xf81, 7, NULL, NULL, func_8029B85C, NULL);
        func_80320004(BKPROG_A8_HAS_DIED, TRUE);
    }
    else{
        func_8029B62C();
    }
}

void func_8029B930(void){
    func_803114D0();
}

ParticleEmitter *func_8029B950(f32 pos[3],f32 arg1){
    return func_802EDD8C(pos, arg1, func_80294500());
}

void func_8029B984(f32 dst[3]){
    f32 plyr_pos[3];
    f32 sp18[3];

    _player_getPosition(plyr_pos);
    func_8024C5CC(sp18);
    ml_vec3f_diff_copy(dst, sp18, plyr_pos);
}

f32 func_8029B9C0(void){
    f32 sp1C[3];

    func_8029B984(sp1C);
    return sp1C[0]*sp1C[0] + sp1C[1]*sp1C[1] + sp1C[2]*sp1C[2];
}

f32 func_8029B9FC(void){
    f32 sp1C[3];

    func_8029B984(sp1C);
    return gu_sqrtf(sp1C[0]*sp1C[0] + sp1C[1]*sp1C[1] + sp1C[2]*sp1C[2]);
}

f32 func_8029BA44(void){
    f32 sp1C[3];

    func_8029B984(sp1C);
    return gu_sqrtf(sp1C[0]*sp1C[0] + sp1C[2]*sp1C[2]);
}

enum bs_e func_8029BA80(void){
    switch (_player_getTransformation())
    {
    case TRANSFORM_3_PUMPKIN:
        return BS_4B_PUMPKIN_FALL;

    case TRANSFORM_2_TERMITE:
        return BS_38_ANT_FALL;

    case TRANSFORM_5_CROC:
        return BS_61_CROC_FALL;

    case TRANSFORM_4_WALRUS:
        return BS_6A_WALRUS_FALL;

    case TRANSFORM_6_BEE:
        return BS_88_BEE_FALL;

    case TRANSFORM_1_BANJO:
    default:
        return BS_2F_FALL;
    }
}

s32 func_8029BAF0(void){
    enum bs_e state_id = bs_getState();
    switch (_player_getTransformation())
    {
    case TRANSFORM_3_PUMPKIN://L8029BB2C
        return 1;

    case TRANSFORM_2_TERMITE://L8029BB34
        return 0;

    case TRANSFORM_5_CROC://L8029BB3C
        return 2;

    case TRANSFORM_4_WALRUS://L8029BB44
        if (func_802B8190(state_id)) {
            return 0xA;
        }
        return 3;

    case TRANSFORM_6_BEE://L8029BB64
        return 0xB;

    case TRANSFORM_1_BANJO://L8029BB6C
    default:
        if (bsclimb_inSet(state_id)) {
            return 0xC;
        }
        if (bsbfly_inSet(state_id)) {
            return 7;
        }
        if (bsbtrot_inSet(state_id)) {
            return 8;
        }
        if (func_80291670(2) != 0.0f) {
            return 9;
        }
        if (func_802933C0(0x18)) {
            return 5;
        }
        if (func_8028ECAC() == 3) {
            return 0xD;
        }
        if (player_inWater()) {
            switch(func_8028EE84()){
                case 2:
                    return 5;
                case 1: 
                default:
                    return 4;

            }
        }
        return 6;
        break;
    }
}

void func_8029BC60(enum asset_e *anim_id, f32 *anim_duration) {
    s32 indx;

    indx = func_8029BAF0();
    *anim_id = D_80364650[indx].anim_id;
    *anim_duration = D_80364650[indx].anim_duration;
}

void func_8029BCAC(enum asset_e *anim_id, f32 *anim_duration) {
    s32 indx;

    indx = func_8029BAF0();
    *anim_id = D_803646C0[indx].anim_id;
    *anim_duration = D_803646C0[indx].anim_duration;
}

void func_8029BCF8(enum asset_e *anim_id, f32 *anim_duration) {
    s32 indx;

    indx = func_8029BAF0();
    *anim_id = D_803647A0[indx].anim_id;
    *anim_duration = D_803647A0[indx].anim_duration;
}

void func_8029BD44(enum asset_e *anim_id, f32 *anim_duration) {
    s32 indx;

    indx = func_8029BAF0();
    *anim_id = D_80364730[indx].anim_id;
    *anim_duration = D_80364730[indx].anim_duration;
}

enum bs_e func_8029BD90(void) {
    return D_80364650[func_8029BAF0()].state_id;
}

enum bs_e func_8029BDBC(void) {
    return D_80364624[func_8029BAF0()];
}

enum bs_e func_8029BDE8(void) {
    return D_80364640[func_8029BAF0()];
}

void func_8029BE10(enum asset_e *anim_id, f32 *anim_duration) {
    s32 indx;

    indx = func_8029BAF0();
    *anim_id = D_80364810[indx].anim_id;
    *anim_duration = D_80364810[indx].anim_duration;
}

enum bs_e func_8029BE5C(void) {
    return D_80364810[func_8029BAF0()].state_id;
}

void func_8029BE88(enum asset_e *anim_id, f32 *anim_duration) {
    s32 indx;

    indx = func_8029BAF0();
    *anim_id = D_80364880[indx].anim_id;
    *anim_duration = D_80364880[indx].anim_duration;
}

enum bs_e func_8029BED4(void) {
    return D_80364880[func_8029BAF0()].state_id;
}

void func_8029BF00(enum asset_e *anim_id, f32 *anim_duration) {
    s32 indx;

    indx = func_8029BAF0();
    *anim_id = D_803648F0[indx].anim_id;
    *anim_duration = D_803648F0[indx].anim_duration;
}

enum bs_e func_8029BF4C(void) {
    return D_803648F0[func_8029BAF0()].state_id;
}

enum bs_e func_8029BF78(void){
    switch (_player_getTransformation()) {
        case TRANSFORM_3_PUMPKIN:
            return BS_48_PUMPKIN_IDLE;

        case TRANSFORM_2_TERMITE:
            return BS_35_ANT_IDLE;

        case TRANSFORM_5_CROC:
            return BS_5E_CROC_IDLE;

        case TRANSFORM_4_WALRUS:
            return BS_67_WALRUS_IDLE;

        case TRANSFORM_6_BEE:
            return BS_85_BEE_IDLE;

        case TRANSFORM_1_BANJO:
        default:
            if (func_802933C0(0x16)) {
                return BS_24_FLY;
            }
            if (func_802933C0(0x18)) {
                return BS_2B_DIVE_IDLE;
            }
            if (func_80291670(3) != 0.0f) {
                return BS_15_BTROT_IDLE;
            }
            if (func_80291670(2) != 0.0f) {
                return BS_26_LONGLEG_IDLE;
            }
            if (player_inWater()) {
                if (player_getYPosition() > (func_80294500() - 80.0f)) {
                    return BS_2D_SWIM_IDLE;
                }
                return BS_2B_DIVE_IDLE;
            }
            if (func_8029A918()) {
                return BS_15_BTROT_IDLE;
            }
            return BS_1_IDLE;
            break;
    }
}

void func_8029C0D0(void) {
    f32 sp3C[3];
    ParticleEmitter *p_ctrl;
    f32 sp34;

    if (func_80294574()) {
        _player_getPosition(sp3C);
        sp3C[1] = sp34 = func_80294500();
        p_ctrl = func_802F4094(&sp3C, 35.0f);
        func_802F3554(3, &sp3C);
        particleEmitter_setParticleVelocityRange(p_ctrl, -350.0f, 300.0f, -350.0f, 350.0f, 500.0f, 350.0f);
        particleEmitter_emitN(p_ctrl, 0xA);
        particleEmitter_setParticleVelocityRange(p_ctrl, -150.0f, 500.0f, -150.0f, 150.0f, 800.0f, 150.0f);
        particleEmitter_emitN(p_ctrl, 0xA);
        
        func_802F4200(sp3C);
        sp3C[1] -= 30.0f;
        p_ctrl = func_802EDD8C(sp3C, 20.0f, sp34);
        particleEmitter_setParticleVelocityRange(p_ctrl, -60.0f, -250.0f, -60.0f, 60.0f, -150.0f, 60.0f);
        particleEmitter_emitN(p_ctrl, 8);
    }
}


void func_8029C22C(void) {

    if(func_80294574() && func_80294500() > player_getYPosition())
        return;

    D_80364620 = D_80364620 ? FALSE : TRUE;
    if (func_80297AB8() > 100.0f) {
        if (D_80364620) {
            func_80292864(func_80297A7C() - 20.0f, 20.0f);
        }
        else{
            func_80292864(func_80297A7C() + 20.0f, 20.0f);
        }
    }
}

void func_8029C304(s32 arg0) {
    f32 sp1C[3];

    _player_getPosition(sp1C);
    sp1C[1] = func_80294500();
    func_802F3584(arg0, sp1C, func_802946CC());
}

void func_8029C348(void) {
    f32 sp1C[3];

    _player_getPosition(&sp1C);
    sp1C[0] += randf2(-30.0f, 30.0f);
    sp1C[1] += randf2(60.0f, 70.0f);
    sp1C[2] += randf2(-30.0f, 30.0f);
    func_803541C0(2);
    func_803541CC(0x50);
    func_80354030(sp1C, 0.5);
}

void func_8029C3E8(f32 arg0, f32 arg1) {
    f32 sp3C[3];
    f32 sp30[3];
    f32 sp2C;
    f32 sp28;

    _player_getPosition(sp30);
    sp28 = ml_map_f(func_80297AB8(), 0.0f, 1000.0f, arg0, arg1);
    sp2C = func_8028EBA4();
    func_802589E4(&sp3C, sp2C, sp28);
    sp3C[1] = 0.0f;
    sp30[0] += sp3C[0];\
    sp30[1] += sp3C[1];\
    sp30[2] += sp3C[2];
    sp30[0] += randf2(-10.0f, 10.0f);
    sp30[1] += 4.0f;
    sp30[2] += randf2(-10.0f, 10.0f);
    func_80354380(sp30, 0.45f);
}

void func_8029C4E4(bool arg0) {
    f32 sp3C[3];
    f32 sp38;
    ParticleEmitter *sp34;

    if (func_80294574()) {
        if (arg0) {
            func_80292260(sp3C);
        } else {
            func_8029223C(sp3C);
        }
        sp3C[1] = func_80294500();
        sp38 = yaw_get();
        sp34 = func_802F4094(sp3C, 8.0f);
        particleEmitter_setSphericalParticleVelocityRange(sp34, -140.0f, sp38 - 35.0f, 200.0f, -120.0f, sp38 + 35.0f, 250.0f);
        particleEmitter_emitN(sp34, 3);
        particleEmitter_setSphericalParticleVelocityRange(sp34, -100.0f, sp38 - 35.0f, 300.0f, -90.0f, sp38 + 35.0f, 400.0f);
        particleEmitter_emitN(sp34, 2);
    }
}

void func_8029C5E8(void){
    func_8029AE1C();
}

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_14420/func_8029C608.s")
#else
void func_8029C608(void) {
    enum level_e level_id;
    enum map_e sp18;
    s32 phi_v0;

    level_id = level_get();
    if ((level_id == 0) || (level_id == LEVEL_6_LAIR)) {
        sp18 = map_get();
        phi_v0 = func_803348CC();
    } else {
        sp18 = func_8030ADD8(level_id);
        phi_v0 = func_8030AE24(level_id);
    }
    D_8037D1E0[1] = phi_v0;
    D_8037D1E0[0] = sp18;
}
#endif

void func_8029C674(void) {
    f32 sp1C[3];

    D_8037D1E8 = FALSE;
    if (func_80298850() == 4) {
        D_8037D1E8 = TRUE;
        func_802933E8(0x17);
        func_802BE8D8();
        func_8028E9C4(5, sp1C);
        func_802C2A64(sp1C);
    }
}

void func_8029C6D0(void) {
    f32 sp3C[3];
    f32 sp30[3];
    f32 sp24[3];
    f32 sp18[3];

    if (func_80298850() == 4 && D_8037D1E8) {
        func_8028E9C4(5, sp18);
        func_802C2A64(sp18);
        func_8028E9C4(5, sp30);
        func_80298800(sp24);
        func_802BC434(sp3C, sp24, sp30);
        func_802C2A8C(sp3C);
    }
}

void func_8029C748(void) {
    if (D_8037D1E8) {
        func_802933FC(0x17);
        func_802BE91C();
    }
}

enum bs_e func_8029C780(void){
    if(button_held(BUTTON_Z) && can_flip())
        return BS_12_BFLIP;

    if(func_802933C0(2))
        return BS_5_JUMP;

    if(func_802933C0(1))
        return BS_23_FLY_ENTER;

    return BS_5_JUMP;
}

void func_8029C7F4(s32 arg0, s32 arg1, s32 arg2, s32 arg3){
    func_80289F10(arg0);
    func_802991A8(arg1);
    func_8029957C(arg2);
    func_802978DC(arg3);
}

void func_8029C834(enum map_e map_id, s32 exit_id){
    D_8037D1E0[0] = map_id;
    D_8037D1E0[1] = exit_id;
}

void func_8029C848(AnimCtrl *arg0) {
    switch(_player_getTransformation()) {
        case TRANSFORM_2_TERMITE: //L8029C880
            animctrl_setIndex(arg0, ANIM_TERMITE_IDLE);
            animctrl_setDuration(arg0, 2.0f);
            break;

        case TRANSFORM_3_PUMPKIN: //L8029C8A0
            animctrl_setIndex(arg0, 0xA0);
            animctrl_setDuration(arg0, 0.8f);
            break;

        case TRANSFORM_5_CROC: //L8029C8C4
            animctrl_setIndex(arg0, 0xE1);
            animctrl_setDuration(arg0, 1.0f);
            break;

        case TRANSFORM_4_WALRUS: //L8029C8E4
            animctrl_setIndex(arg0, 0x11F);
            animctrl_setDuration(arg0, 1.0f);
            break;

        case TRANSFORM_6_BEE: //L8029C904
            animctrl_setIndex(arg0, ASSET_1DC_ANIM_BEE_FLY);
            animctrl_setDuration(arg0, 0.38f);
            break;

        case TRANSFORM_1_BANJO:
        default:
            if (player_inWater()) {
                animctrl_setIndex(arg0, 0x57);
                animctrl_setDuration(arg0, 1.2f);
            }
            else{
                animctrl_setIndex(arg0, 0x6F);
                animctrl_setDuration(arg0, 5.5f);
            }
            break;
    }
}

void func_8029C984(void){
    func_8025AB00();
    func_8025A2FC(0, 4000);
    func_8025A70C(COMUSIC_1A_DEATH);
    func_8024BD08(0);
}

s32 func_8029C9C0(s32 arg0){
    if(func_802933C0(0xF))
        return arg0;
    
    if(button_pressed(BUTTON_A))
        arg0 = func_8029C780();

    if(button_pressed(BUTTON_B) && can_claw())
        arg0 = BS_CLAW;

    if(button_held(BUTTON_Z) && should_beak_barge())
        arg0 = BS_BBARGE;

    if(func_80294F78())
        arg0 = func_802926C0();
    
    if(player_isSliding())
        arg0  = BS_SLIDE;

    return arg0;
}

s32 func_8029CA94(s32 arg0){
    if(func_802933C0(0x19))
        arg0 = func_80292738();
    
    if(func_802933C0(0x1A))
        arg0 = (player_getTransformation() == TRANSFORM_6_BEE) ? 0x46 : BS_34_JIG_NOTEDOOR;

    if(func_802933C0(0xE))
        arg0 = BS_25_LONGLEG_ENTER;

    if(func_802933C0(0x10))
        arg0 = BS_14_BTROT_ENTER;

    if(func_802933C0(0x6))
        arg0 = 0x53;

    if(func_802933C0(0x7))
        arg0 = BS_44_JIG_JIGGY;

    if(func_802933C0(0x14))
        arg0 = (player_getTransformation() == TRANSFORM_4_WALRUS) ? 0x80 : 0x53;
    
    func_802933FC(0xF);

    return arg0;
}

void func_8029CB84(void){
    pitch_setIdeal(0.0f);
    pitch_applyIdeal();

    roll_setIdeal(0.0f);
    roll_applyIdeal();
}

void func_8029CBC4(void){
    func_8025A55C(-1, 4000, 0xc);
    func_8024BD08(1);
}

void func_8029CBF4(void){
    if(item_getCount(ITEM_E_JIGGY) == 10){
        if( jiggyscore_total() == 100 && func_8031FF1C(BKPROG_FC_DEFEAT_GRUNTY)){
            timedFunc_set_3(4.1f, func_802E4078, MAP_95_CS_END_ALL_100, 0, 1);
        }//L8029CC58

        timedFunc_set_0(4.0f, func_8029CBC4);
        func_8025A6EC(COMUSIC_42_NOTEDOOR_OPENING_FANFARE, -1);
    }//L8029CC7C
    else{
        if( jiggyscore_total() == 100 && func_8031FF1C(BKPROG_FC_DEFEAT_GRUNTY)){
            func_802E4078(MAP_95_CS_END_ALL_100, 0, 1);
        }
        func_8029CBC4();
    }

}

void func_8029CCC4(void){
    if(func_802933D0(7)) return;
    if( func_802933C0(0xF)
        && func_802933D0(6)
        && func_802933D0(20)
    ){
        func_802933FC(0xF);
    }
    func_802933FC(7);
    func_802B0CD8();
    item_inc(ITEM_E_JIGGY);
    if(jiggyscore_total() == 100 && func_8031FF1C(BKPROG_FC_DEFEAT_GRUNTY)){
        func_8028F918(2);
    }
    func_8024BD08(0);
    func_8025A55C(0, 4000, 0xC);
    func_8025A6EC(COMUSIC_D_JINGLE_JIGGY_COLLECTED, -1);
    timedFunc_set_0(4.0f, func_8029CBF4);
}

void func_8029CDA0(void){
    item_inc(ITEM_E_JIGGY);
}

void func_8029CDC0(void) {
    f32 sp2C[3];
    f32 sp20[3];

    _player_getPosition(sp20);
    sp20[0] += (randf() * 90.0f) - 45.0f;
    sp20[2] += (randf() * 90.0f) - 45.0f;
    sp2C[0]  = (randf() * 20.0f) - 10.0f;
    sp2C[1]  = (randf() * 50.0f) + 120.0f;
    sp2C[2]  = (randf() * 20.0f) - 10.0f;
    func_80356074(&sp20, &sp2C, 80.0f, 220.0f);
}

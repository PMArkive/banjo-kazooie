#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern ParticleEmitter *func_802F4094(f32[3], f32);
extern void func_802F494C(void *, f32);
extern void func_802F4884(void *, s32, f32);
extern f32  func_80294500(void);


void func_8029AE74(s32 arg0);
void func_8029AEE4(s32 arg0);

extern void *D_8037D190;
extern u8 D_8037D194;

/* .code */
void func_8029A990(void){
    f32 plyr_pos[3];
    ParticleEmitter *pCtrl;

    if(map_get() == MAP_2C_MMM_BATHROOM)
        func_8029C304(0);
    else
        func_8029C304(1);

    _player_getPosition(plyr_pos);
    plyr_pos[1] = func_80294500();
    pCtrl = func_802F4094(plyr_pos, 25.0f);
    particleEmitter_setParticleVelocityRange(pCtrl,
        -350.0f, 300.0f, -350.0f,
        350.0f, 500.0f, 350.0f
    );
    particleEmitter_emitN(pCtrl, 10);
}

void func_8029AA3C(void){
    f32 sp34[3];
    f32 sp30;
    ParticleEmitter *pCtrl;
    if(map_get() == MAP_2C_MMM_BATHROOM)
        func_8029C304(0);
    else
        func_8029C304(2);
    
    sp30 = ml_map_f(func_80297AB8(), 0.0f, 500.0f, 70.0f, 250.0f);
    func_8028E9C4(D_8037D194, sp34);
    sp34[1] = func_80294500();
    pCtrl = func_802F4094(sp34, 8.0f);
    particleEmitter_setParticleVelocityRange(pCtrl,
        -sp30, 300.0f, -sp30,
        sp30, 350.0f,sp30
    );
    particleEmitter_emitN(pCtrl, 5);
}

void func_8029AB14(s32 arg0, s32 arg1){
    int sp24 = (arg1 == 4) || (arg1 == 0xb);
    int sp20 = player_inWater();
    if(sp24){
        func_8029AA3C();
    }

    switch(player_getTransformation()){
        case TRANSFORM_3_PUMPKIN: //L8029AB9C
            if(arg1 == 7){
                func_802F4900(arg0, arg1);
            }
            if(sp24 || sp20){
                func_802F4900(arg0, 0xe);
            }
            else{
                func_802F4900(arg0, 0xd);
            }
            break;
        case TRANSFORM_4_WALRUS://L8029ABEC
            if(sp24){
                func_802F4900(arg0, 0x4);
            }
            else if(sp20){
                func_802F4900(arg0, 0xf);
            }
            else{
                func_802F4900(arg0, 0xd);
            }
            break;
        default: //L8029AC28
            break;
    }
}

void func_8029AC34(s32 arg0, s32 arg1){
    int sp1C;
    sp1C = (arg1 == 4) || (arg1 == 0xb || player_inWater());
    if(sp1C){
        func_8029A990();
    }

    switch(player_getTransformation()){
        case TRANSFORM_3_PUMPKIN:
        case TRANSFORM_4_WALRUS:
        case TRANSFORM_5_CROC:
            if(sp1C)
                FUNC_8030E624(SFX_10_BANJO_LANDING_07, 0x196, 0x398);
            else
                FUNC_8030E624(SFX_2F_ORANGE_SPLAT, 0xFA, 0x598);
            break;
        default:
            break;
    }
}

void func_8029ACD4(void){
    f32 plyr_pos[3];

    _player_getPosition(plyr_pos);
    func_802F4894(D_8037D190, plyr_pos);
    func_802F4884( D_8037D190, func_80294660(), func_80294500());
}

void func_8029AD28(f32 arg0, s32 arg1){
    AnimCtrl *plyr_animCtrl = _player_getAnimCtrlPtr();
    if(animctrl_isAt(plyr_animCtrl, arg0)){
        func_8029AE74(arg1);
    }
}


void func_8029AD68(f32 arg0, s32 arg1){
    AnimCtrl *plyr_animCtrl = _player_getAnimCtrlPtr();
    if(animctrl_isAt(plyr_animCtrl, arg0)){
        func_8029AEE4(arg1);
    }
}

void func_8029ADA8(void){
    func_802F4798(D_8037D190);
}

void func_8029ADCC(void){
    D_8037D190 = func_802F47D0();
    func_802F487C(D_8037D190, func_8029AC34);
    func_802F48B4(D_8037D190, func_8029AB14);
}

void func_8029AE1C(void){
    func_8029ACD4();
    func_802F48BC(D_8037D190);
}

void func_8029AE48(void){
    func_8029ACD4();
    func_802F48E0(D_8037D190);
}

void func_8029AE74(s32 arg0){
    s32 tmp_v0;
    func_8029ACD4();
    D_8037D194 = arg0;
    tmp_v0 = func_8028ECAC();
    if(tmp_v0 == 6 || tmp_v0 == 8 || tmp_v0 == 9){
        func_802F494C(D_8037D190, 0.2f);
    }
    else{
        func_802F4924(D_8037D190);
    }
}

void func_8029AEE4(s32 arg0){
    func_8029ACD4();
    D_8037D194 = arg0;
    func_802F4978(D_8037D190);

}

void func_8029AF1C(void){
    D_8037D190 = func_802F499C(D_8037D190);
}

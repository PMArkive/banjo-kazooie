#include <ultra64.h>
#include "functions.h"
#include "variables.h"

/* .bss */
extern u8  D_8037D3D0;
extern f32 D_8037D3D4;
extern u8  D_8037D3D8;

/* .code */
void func_802AB5C0(void){
    f32 sp2C[3];
    f32 sp28;
    f32 f2;

    sp28 = func_8029B2DC();
    if(mlAbsF(sp28) < 0.03){
        f2 = 0.0f; 
    }
    else{
        f2 = func_80257D30(sp28, 0.03f, 1.0f, 100.0f, 300.0f);
    }
    sp2C[0] = 0.0f;
    sp2C[1] = f2;
    sp2C[2] = 0.0f;
    func_80297930(sp2C);
}

void func_802AB654(void){
    func_8029957C(6);
    func_802991A8(3);
    func_80299234(500.0f, 15.0f);
    func_8029B324(0, 0.03f);
    func_8029B324(1, 1.0f);
    func_802978DC(0xA);
    func_80297B64(10.0f);
    func_80294378(5);
    func_80293D48(80.0f, 10.0f);
    func_802914CC(0x10);
}

void func_802AB6F0(void){
    if(!bsclimb_inSet(bs_getNextState())){
        func_80291548();
        func_8029B0C0();
        func_80289F10(1);
        func_802978DC(2);
        func_80294378(1);
        func_80293D74();
    }
}

void func_802AB750(f32 arg0, f32 arg1){
    D_8037D3D4 = randf()*arg1 + arg0;
}

int func_802AB788(void){    
    return (0.0f < mlAbsF(func_80297A70())) || (yaw_get() != yaw_getIdeal());
}

int bsclimb_inSet(s32 move_indx){
    return (move_indx == BS_4F_CLIMB_IDLE)
    || (move_indx == BS_50_CLIMB_MOVE)
    || (move_indx == 0x9e);
}

void bsclimb_idle_init(void){
    f32 angle_towards_pole;
    f32 plyr_pos[3];
    f32 pole_pos[3];

    player_getPosition(plyr_pos);
    climbGetBottom(pole_pos);
    if(!bsclimb_inSet(bs_getPrevState())){
        func_80257F18(plyr_pos, pole_pos, &angle_towards_pole);
        yaw_setIdeal(angle_towards_pole);
        func_802991FC();
    }
    func_80295610(4);
    func_8028A010(ASSET_B2_ANIM_BANJO_CLIMB_IDLE_2, 2.64f);
    func_80289F10(1);
    func_802AB654();
    
    D_8037D3D8 = 1;
    func_802AB750(1.0f, 0.5f);
    D_8037D3D0 = 0;
}

void bsclimb_idle_update(void){
    s32 next_state = 0;
    AnimCtrl *anim_ctrl = player_getAnimCtrlPtr();
    func_80293350();
    switch(D_8037D3D0){
        case 0:
            D_8037D3D4 -= time_getDelta();
            if(D_8037D3D4 <= 0.0f){
                func_8028A180(ASSET_B1_ANIM_BANJO_CLIMB_IDLE_1, 2.96f);
                D_8037D3D0 = 1;
            }
            break;
        case 1:
            if(animctrl_isStopped(anim_ctrl)){
                func_8028A010(ASSET_B2_ANIM_BANJO_CLIMB_IDLE_2, 2.64f);
                func_802AB750(3.0f, 4.0f);
                D_8037D3D0 = 0;
            }
            break;
    }
    func_802AB5C0();
    if(func_802AB788())
        next_state = BS_50_CLIMB_MOVE;
    

    if(button_pressed(BUTTON_A))
        next_state = BS_5_JUMP;

    if(D_8037D3D8 == 0)
        next_state = BS_1_IDLE;
    D_8037D3D8 = 0;
    bs_setState(next_state);
}

void bsclimb_idle_end(void){
    func_802AB6F0();
}

void bsclimb_move_init(void){
    func_8028A010(ASSET_A_ANIM_BANJO_CLIMB_MOVE, 0.9f);
    func_80289F10(3);
    func_80289EA8(0.3f, 1.5f);
    func_80289EC8(100.0f, 300.0f, 0.6f, 0.4f);
    func_802AB654();
}

void bsclimb_move_update(void){
    s32 next_state = 0;
    f32 plyr_pos[3];
    s32 map;

    func_80293350();
    func_802AB5C0();
    map = func_803348C0();

    if( map == MAP_B_CC_CLANKERS_CAVERN
        || map == MAP_1B_MMM_MAD_MONSTER_MANSION
        || map == MAP_31_RBB_RUSTY_BUCKET_BAY
    ){
        if(func_80289FE8(0.25f))
            func_80299D2C(SFX_D2_QUIET_METALLIC, 1.1f, 32000);
        
        if(func_80289FE8(0.75f))
            func_80299D2C(SFX_D2_QUIET_METALLIC, 1.2f, 32000);
    }
    else{//L802ABB34
        if(func_80289FE8(0.25f))
            func_80299D2C(SFX_D3_JINXIE_SNIFFLING_1, 0.77f, 22000);

        if(func_80289FE8(0.75f))
            func_80299D2C(SFX_D3_JINXIE_SNIFFLING_1, 0.87f, 22000);
    }//L802ABB84

    if(!func_802AB788() && func_80297AAC() < 30.0f)
        next_state = BS_4F_CLIMB_IDLE;

    _player_getPosition(plyr_pos);
    if(func_80297A70() < 0.0f && climbGetBottomY() == plyr_pos[1])
        next_state = BS_1_IDLE;

    if( func_8029825C() == 2
        && 0.0f < func_80297A70()
        && climbGetTopY() == plyr_pos[1]
    ){
        next_state = BS_51_CLIMB_EXIT;
    }

    if(button_pressed(BUTTON_A))
        next_state = BS_5_JUMP;

    if(!D_8037D3D8)
        next_state = BS_1_IDLE;
    
    D_8037D3D8 = FALSE;

    bs_setState(next_state);
}

void bsclimb_move_end(void){
    func_802AB6F0();
}

//bsclimb_unknown_9E_init
void func_802ABCCC(void){
    func_8028A010(ASSET_B2_ANIM_BANJO_CLIMB_IDLE_2, 2.64f);
    func_80289F10(1);
    func_802AB654();
    func_802978DC(7);
}

//bsclimb_unknown_9E_update
void func_802ABD0C(void){
    s32 next_state = 0;
    if(!func_80298850())
        next_state = BS_4F_CLIMB_IDLE;

    bs_setState(next_state);
}

//bsclimb_unknown_9E_end
void func_802ABD40(void){
    func_802AB6F0();
}

//bsclimb_interrupt
void func_802ABD60(void){
    s32 next_state = 0;
    if(bs_getInterruptType() == 0xC){
        D_8037D3D8 = TRUE;
    }
    else{
        func_80296608();
        return;
    }
    func_8029A86C(1);
    bs_setState(next_state);
}

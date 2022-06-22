#include <ultra64.h>
#include "functions.h"
#include "variables.h"


f32 mlDiffDegF(f32, f32);


/* .bss */
f32 D_8037DC20[3];
f32 D_8037DC30[3];
f32 D_8037DC3C;
f32 D_8037DC40;
u8  D_8037DC44;
f32 D_8037DC50[3];

/* .code */
void func_802C2250(void){}

void func_802C2258(void){
    D_8037DC44 = 0;
}

void func_802C2264(f32 arg0){
    D_8037DC40 = arg0;
    D_8037DC3C = D_8037DC40;
    func_802BD384(D_8037DC20);
    func_802BD3A8(D_8037DC30);
    D_8037DC44 = 1;
}

void func_802C22B4(void){
    D_8037DC44 = 0;
}


void func_802C22C0(f32 *arg0, f32 *arg1){
    f32 tmpf_1[3];
    f32 tmpf_2[3];
    f32 tmp;
    
    if(D_8037DC44 == 0)
        return;
    
    if(D_8037DC44 == 1){
        ml_vec3f_diff(D_8037DC20, arg0);
        D_8037DC30[0] = mlDiffDegF(D_8037DC30[0], arg1[0]);
        D_8037DC30[1] = mlDiffDegF(D_8037DC30[1], arg1[1]);
        D_8037DC30[2] = 0.0f;
        D_8037DC44 = 2;
    }
    D_8037DC3C -= time_getDelta();
    if(D_8037DC3C <= 0.0f)
        D_8037DC44 = 0;
    else {
        tmp = ml_map_f(D_8037DC3C, 0.0f, D_8037DC40, 0.0f, 1.0f);
        ml_vec3f_scale_copy(tmpf_1, D_8037DC20, tmp);
        ml_vec3f_scale_copy(tmpf_2, D_8037DC30, tmp);
        arg0[0] += tmpf_1[0];
        arg0[1] += tmpf_1[1];
        arg0[2] += tmpf_1[2];
        arg1[0] += tmpf_2[0];
        arg1[1] += tmpf_2[1];
        arg1[2] += tmpf_2[2];
        arg1[0] = mlNormalizeAngle(arg1[0]);
        arg1[1] = mlNormalizeAngle(arg1[1]);
        arg1[2] = 0.0f;
    }

}

void func_802C2460(void){
    f32 sp24[3];
    f32 sp12[3];

    func_8024C5CC(sp24);
    func_8024C764(sp12);
    func_802BD334(sp24);
    func_802BD35C(sp12);
    player_getPosition(D_8037DC50);
    func_80291488(5);
}

void func_802C24AC(void){}

void func_802C24B4(void){
    f32 sp24[3];
    f32 sp18[3];

    player_getPosition(sp24);
    ml_vec3f_diff_copy(sp18, D_8037DC50, sp24);
    if( !(gu_sqrtf(sp18[0]*sp18[0] + sp18[1]*sp18[1] + sp18[2]*sp18[2]) < 2.0f)){
        func_80291488(2);
        func_802BD0D8(0xB);
        func_802BE720();
    }
}

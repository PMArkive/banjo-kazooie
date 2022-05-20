#include <ultra64.h>
#include "functions.h"
#include "variables.h"


extern void func_80250E6C(f32, f32);
extern void func_80258E60(f32[3], f32[3], f32);
extern void func_80258EF4(f32[3], f32[3], f32);
extern void func_80258F88(f32[3], f32[3], f32);
extern void func_802BE720(void);

typedef struct {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
    u8  unk1C;
    // u8 pad1D[3];
}Struct_core2_33F90_0;

void func_802BB200(void);
void func_802BB22C(void);
void func_802BB318(s32 arg0);
void func_802BB360(s32 arg0, f32 arg1);
void func_802BB3AC(s32 arg0, f32 arg1);

/* .bss */
Struct_core2_33F90_0 D_8037D840[4];

/* .code */
void func_802BB2A0(void){}

void func_802BB2A8(void){
    s32 i;

    for(i = 0; i < 4; i++){
        D_8037D840[i].unk1C = 1;
        D_8037D840[i].unk18 = 0.0f;
        func_802BB318(i);
    }
}

void func_802BB318(s32 arg0){
    func_802BB360(arg0, 30.0f);
    func_802BB3AC(arg0, 0.65f);
}

f32 func_802BB34C(s32 arg0){
    return D_8037D840[arg0].unk10; 
}

void func_802BB360(s32 arg0, f32 arg1){
    D_8037D840[arg0].unk10 = arg1;
}

void func_802BB378(s32 arg0, f32 arg1, f32 arg2){
    D_8037D840[arg0].unkC = D_8037D840[arg0].unk10;
    D_8037D840[arg0].unk8 = D_8037D840[arg0].unk10 + arg1;
    D_8037D840[arg0].unk18 = arg2;
    D_8037D840[arg0].unk0 = arg2;
}

void func_802BB3AC(s32 arg0, f32 arg1){
    D_8037D840[arg0].unk4 = arg1;
}

void func_802BB3C4(s32 arg0){
    D_8037D840[arg0].unk1C = 2;
}

void func_802BB3DC(s32 arg0, f32 arg1, f32 arg2){
    func_802BB360(arg0, arg1);
    func_802BB3AC(arg0, arg2);
    func_802BB3C4(arg0);
}

void func_802BB41C(s32 arg0){
    D_8037D840[arg0].unk1C = 1;
}

void func_802BB434(s32 arg0, f32 dst[3], f32 src[3], f32 arg3) {
    switch (arg0) {
    case 1:
        func_80258F88(dst, src, arg3);
        return;
    case 0:
        func_80258E60(dst, src, arg3);
        return;
    case 2:
        func_80258EF4(dst, src, arg3);
        return;
    case 3:
        dst[1] += arg3;
        return;
    }
}

void func_802BB4D8(s32 arg0, s32 arg1) {
    f32 temp_f0;
    f32 temp_f22;
    s32 phi_s1;

    temp_f22 = time_getDelta();
    for(phi_s1 = 0; phi_s1 < 4; phi_s1++){
        switch (D_8037D840[phi_s1].unk1C) {
        case 2:
            if (D_8037D840[phi_s1].unk10 >= 0.0f) {
                D_8037D840[phi_s1].unk14 = 1.0f;
            } else {
                D_8037D840[phi_s1].unk14 = -1.0f;
            }
            func_802BB434(phi_s1, arg0, arg1, D_8037D840[phi_s1].unk10);
            D_8037D840[phi_s1].unk1C = 3;
            break;
        case 3:
            if (D_8037D840[phi_s1].unk18 != 0.0f) {
                temp_f0 = max_f(0.0f, D_8037D840[phi_s1].unk18 - temp_f22);
                D_8037D840[phi_s1].unk18 = temp_f0;
                D_8037D840[phi_s1].unk10 = ml_map_f(temp_f0, D_8037D840[phi_s1].unk0, 0.0f, D_8037D840[phi_s1].unkC, D_8037D840[phi_s1].unk8);
            } else {
                D_8037D840[phi_s1].unk10 *= D_8037D840[phi_s1].unk4;
            }
            if (level_get() != LEVEL_D_CUTSCENE) {
                func_80250E6C(D_8037D840[phi_s1].unk10 * 0.25, temp_f22);
            }
            func_802BB434(phi_s1, arg0, arg1, D_8037D840[phi_s1].unk14*D_8037D840[phi_s1].unk10);
            D_8037D840[phi_s1].unk14 = (f32) -D_8037D840[phi_s1].unk14;
            if (((f64) D_8037D840[phi_s1].unk4 != 1.0) && ((f64) mlAbsF(D_8037D840[phi_s1].unk10) < 0.001)) {
                D_8037D840[phi_s1].unk1C = 1U;
            }
            break;
        }
    }
}

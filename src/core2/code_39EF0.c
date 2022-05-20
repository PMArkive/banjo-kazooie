#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern f32 func_802453DC(struct56s *, f32, f32[3], s32);
extern f32 func_80259198(f32, f32);
extern f32 func_802BD51C(void);
extern f32 func_8028EBA4(void);
extern void func_802BE244(f32, f32);
extern void func_802BE230(f32, f32);
extern void func_802BD82C(f32, f32);

extern void func_802BD870(f32, f32, f32, f32);
extern void func_80323240(struct56s *, f32 , f32[3]);
extern f32  func_803243D0(struct56s *, f32[3]);
extern f32  func_80323540(struct56s *, f32, f32, f32);
extern f32  func_80323F74(struct56s *, f32, f32);
extern struct56s *func_80342038(s32);


void func_802C16CC(s32 arg0);

/* .bss */
struct {
    s32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC[3];
    f32 unk18;
    f32 unk1C[3];
    s32 unk28;
    u8 unk2C;
    u8 unk2D;
    u8 unk2E;
    u8 unk2F;
}D_8037DBE0;
f32 D_8037DC10;

/* .code */
bool func_802C0E80(void){
    return (map_get() == MAP_27_FP_FREEZEEZY_PEAK) && (func_8028ECAC() == 10);
}

struct56s *func_802C0EC0(void){
    return func_80342038(D_8037DBE0.unk0);
}

void func_802C0EE4(void) {
    D_8037DBE0.unk0 = -1;
    D_8037DBE0.unk28 = 0;
    D_8037DBE0.unk2C = 0;
    D_8037DBE0.unk2F = 0;
    D_8037DBE0.unk2E = 0;
    D_8037DBE0.unk4 = 0.0f;
    D_8037DBE0.unk8 = 0.0f;
    ml_vec3f_clear(D_8037DBE0.unkC);
    ml_vec3f_clear(D_8037DBE0.unk1C);
    D_8037DBE0.unk18 = 0.0f;
}

void func_802C0F4C(void){
    func_802C0EE4();
}

void func_802C0F6C(void){
    func_802C0150(4);
    func_802BE244(5.0f, 10.0f);
    func_802BE230(3.0f, 8.0f);
    func_802BD82C(100.0f, 100.0f);
}

void func_802C0FCC(void){
    func_802C0EE4();
    func_802BD840();
}

void func_802C0FF4(s32 arg0) {
    s32 sp1C;

    sp1C = func_802C0190();
    func_802C0150(5);
    func_802C02D4(arg0);
    func_802C0150(sp1C);
}

f32 func_802C1030(struct56s *arg0, f32 arg1[3], f32 arg2[3]) {
    f32 sp54[3];
    f32 sp48[3];
    f32 sp3C[3];
    f32 sp30[3];
    f32 sp2C;

    sp2C = func_803243D0(arg0, arg1);
    if ((sp2C == 0.0) || (sp2C == 1.0)) {
        func_80323240(arg0, sp2C, sp48);
        if (sp2C == 0.0) {
            func_80323240(arg0, sp2C + 0.001, sp3C);
        } else {
            func_80323240(arg0, sp2C - 0.001, sp3C);
        }
        ml_vec3f_diff_copy(sp30, sp3C, sp48);
        ml_vec3f_set_length_copy(sp30, sp30, 400.0f);
        ml_vec3f_add(sp3C, sp30, sp48);
        func_80259554(sp54, sp48, sp3C, arg1);
        return func_80256064(sp54, arg2);
    }
    else{
        func_80323240(arg0, sp2C, sp54);
        if (sp2C < D_8037DBE0.unk8) {
            return func_80323540(arg0, sp2C, D_8037DBE0.unk8, 15.0f);
        }
        else{
            return func_80323540(arg0, D_8037DBE0.unk8, sp2C, 15.0f);
        }
    }
}

s32 func_802C11C8(f32 arg0[3]) {
    f32 sp64[3];
    f32 sp58[3];
    f32 sp4C[3];
    f32 sp48;
    f32 sp44;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    struct56s *sp2C;
    f32 sp28;

    sp2C = func_802C0EC0();
    func_802C0FF4(sp4C);
    if (func_8028EE84() == 2) {
        func_802BD82C(20.0f, 200.0f);
    } else {
        func_802BD82C(80.0f, 200.0f);
    }
    sp30 = func_802C1030(sp2C, sp4C, arg0);
    sp40 = func_80323F74(sp2C, D_8037DBE0.unk8, 1000.0f);
    sp3C = func_80323F74(sp2C, D_8037DBE0.unk8, -1000.0f);
    func_80323240(sp2C, sp40, sp64);
    func_80323240(sp2C, sp3C, sp58);
    sp48 = func_80256064(sp4C, sp64);
    sp44 = func_80256064(sp4C, sp58);
    sp38 = 0.0f;
    sp38 = 0.0f;
    if (mlAbsF(sp48 - sp44) > 3.0f) {
        sp34 = (sp48 < sp44) ? 1.0f : -1.0f;
        if (550.0f < sp30) {
            sp38 = ml_map_f(sp30, 550.0f, 650.0f, 0.0f, 1500.0f) * sp34;
        } else if (sp30 < 500.0f) {
            sp38 = ml_map_f(sp30, 400.0f, 500.0f, 1500.0f, 0.0f) * -sp34;
        }
        sp28 = mlAbsF(D_8037DBE0.unk4);
        if (sp28 < mlAbsF(sp38)) {
            D_8037DBE0.unk4 = D_8037DBE0.unk4 + (sp38 - D_8037DBE0.unk4) * 0.08;
        } else {
            D_8037DBE0.unk4 = sp38;
        }
        D_8037DBE0.unk8 = func_80323F74(sp2C, D_8037DBE0.unk8, D_8037DBE0.unk4);
        if( ((sp38 > 0.0f) && (D_8037DBE0.unk8 == 1.0) && (D_8037DBE0.unk2F == 0)) 
            || ((sp38 < 0.0f) && (D_8037DBE0.unk8 == 0.0) && (D_8037DBE0.unk2E == 0))
        ) {
            return 0;
        }
        
    }
    else{
        return 1;
    }

    if (sp38 != 0.0f){
        return 1;
    }
    return 2;
}

void func_802C14E0(void) {
    f32 sp5C[3];
    f32 sp50[3];
    f32 sp4C;
    f32 sp40[3];
    f32 sp34[3];

    if (D_8037DBE0.unk0 != -1) {
        if (D_8037DBE0.unk2C == 1) {
            D_8037DBE0.unk2C = 2;
        }
        func_802BD384(sp40);
        if ((D_8037DBE0.unk28 == -1) || (func_802C11C8(sp40) == 0) || func_802C0E80()) {
            D_8037DBE0.unk28 = 0;
            return;
        }
        func_80323240(func_802C0EC0(), D_8037DBE0.unk8, sp40);
        if (D_8037DBE0.unk18 < 1.0) {
            sp4C = ml_map_f(D_8037DBE0.unk18, 0.5f, 1.0f, 0.05f, 0.01f);
            D_8037DBE0.unk18 += 30.0f * time_getDelta() * sp4C;
            if (D_8037DBE0.unk18 < 1.0) {
                ml_vec3f_diff_copy(sp50, sp40, D_8037DBE0.unkC);
                ml_vec3f_scale(sp50, D_8037DBE0.unk18);
                ml_vec3f_add(sp40, D_8037DBE0.unkC, sp50);
            }
        }
        func_802BD334(sp40);
        func_802C02D4(sp5C);
        func_802BE6FC(sp34, sp5C);
        func_802BD904(sp34);
    }
}

void func_802C1674(s32 arg0, s32 arg1){
    if(D_8037DBE0.unk28){
        D_8037DBE0.unk28 = -1;
    }
}

void func_802C169C(void *arg0, s32 arg1){
    func_802C16CC(func_8033451C(*((u16 *)((s32)arg0 + 8))));
}

void func_802C16CC(s32 arg0) {
    f32 sp54[3];
    f32 sp48[3];
    f32 sp3C[3];
    s32 sp38;
    s32 sp34;
    s16 *sp30;

    if ((func_8028ECAC() != 4) && !func_802C0E80()){
        sp38 = func_80334524(arg0);
        if(sp38 != D_8037DBE0.unk28 && D_8037DBE0.unk28 != -1){
            player_getPosition(sp54); 
            ml_vec3f_to_vec3w(sp48, sp54);
            sp30 = func_803049CC(sp38, sp48);
            if(sp30 != NULL) {
                func_80304D68(sp30, sp54);
                switch (func_80304DB8(sp30)) {                        /* irregular */
                default:
                    D_8037DBE0.unk2E = 0;
                    D_8037DBE0.unk2F = 0;
                    break;
                case 1:
                    D_8037DBE0.unk2E = 1;
                    D_8037DBE0.unk2F = 0;
                    break;
                case 2:
                    D_8037DBE0.unk2E = 0;
                    D_8037DBE0.unk2F = 1;
                    break;
                case 3:
                    D_8037DBE0.unk2E = 1;
                    D_8037DBE0.unk2F = 1;
                    break;
                }
                D_8037DBE0.unk2D = func_802BD0CC();
                func_802BD384(sp3C);
                ml_vec3f_copy(D_8037DBE0.unkC, sp3C);
                D_8037DBE0.unk18 = 0.0f;
                D_8037DBE0.unk28 = sp38;
                D_8037DBE0.unk0 = func_80341EC4(sp54);
                D_8037DBE0.unk8 = func_803243D0(func_802C0EC0(), sp3C);
                D_8037DBE0.unk8 = func_802453DC(func_802C0EC0(), D_8037DBE0.unk8, sp3C, func_8028D694() | 0x1E0000);
                D_8037DBE0.unk2C = 1;
                func_80323240(func_802C0EC0(), D_8037DBE0.unk8, D_8037DBE0.unk1C);
                if (func_802C11C8(D_8037DBE0.unk1C) == 1) {
                    func_802BD0D8(0x12);
                    func_80291488(0xA);
                    return;
                }
                D_8037DBE0.unk28 = 0;
            }
        }
    }
}


bool func_802C189C(void){
    return D_8037DBE0.unk28 < 1;
}

void func_802C18B0(void){
    func_802BD870(12.0f, 10.0f, 120.0f, 120.0f);
}

void func_802C18F0(void){}

void func_802C18F8(void) {
    f32 sp8C[3];
    f32 sp80[3];
    f32 sp74[3];
    f32 sp68[3];
    f32 sp5C[3];
    f32 sp50[3];
    f32 sp4C;
    f32 sp48;
    f32 temp_f20;
    f32 sp40;
    f32 sp3C;

    func_802BD384(sp74);
    func_802BD4C0(sp8C);
    sp3C = func_802BD8D4();
    temp_f20 = time_getDelta();
    ml_vec3f_diff_copy(sp50, sp74, sp8C);
    sp4C = gu_sqrtf((sp50[0] * sp50[0]) + (sp50[2] * sp50[2]));
    sp4C += func_80259198((sp3C - sp4C) * temp_f20 * 2, temp_f20 * 120.0f);
    func_8025801C(sp50, &sp48);
    sp40 = func_80259198(mlDiffDegF(mlNormalizeAngle(180.0f + func_8028EBA4()), sp48) * (temp_f20 * 1), temp_f20 * 50.0f);
    sp48 = mlNormalizeAngle(sp48 + sp40);
    func_80256E24(sp68, 0.0f, sp48, 0.0f, 0.0f, sp4C);
    ml_vec3f_add(sp80, sp8C, sp68);
    sp80[1] = sp74[1] + ((func_802BD51C() - sp74[1]) * temp_f20 * 2);
    func_802BD334(sp80);
    func_8025727C(sp8C[0], sp8C[1], sp8C[2], sp80[0], sp80[1], sp80[2], &sp5C[0], &sp5C[1]);
    sp5C[0] = -sp5C[0];
    sp5C[2] = 0.0f;
    func_802BD720(sp5C);
}

void func_802C1AD0(void){}

void func_802C1AD8(void){
    func_802BD870(10.0f, 20.0f, 120.0f, 200.0f);
    func_802C0150(4);
    D_8037DC10 = 600.0f;
}

void func_802C1B20(f32 arg0){
    D_8037DC10 = arg0;
}

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_39EF0/func_802C1B2C.s")
#else
void func_802C1B2C(void) {
    f32 sp7C[3];
    f32 sp70[3];
    f32 sp64[3];
    f32 sp58[3];
    f32 sp4C[3];
    f32 sp40[3];
    f32 sp3C;
    f32 sp34;
    f32 sp30;
    f32 phi_f0;

    func_802BD384(sp64);
    sp34 = D_8037DC10;
    func_802C02D4(sp7C);
    sp30 = time_getDelta();
    ml_vec3f_diff_copy(sp40, sp64, sp7C);
    sp3C = gu_sqrtf(sp40[0]*sp40[0] + sp40[2]*sp40[2]);
    sp3C += func_80259198((sp34 - sp3C) * sp30 * 2, sp30 * 800.0f);
    func_8025727C(sp7C[0], sp7C[1], sp7C[2], sp64[0], sp64[1], sp64[2], &sp4C[0], &sp4C[1]);
    sp40[1] = mlDiffDegF(mlNormalizeAngle(func_8028EBA4() + 180.0f), sp4C[1]) * sp30 * 0.77;
    sp40[1] = func_80259198(sp40[1], sp30 * 300.0f);
    sp4C[1] = mlNormalizeAngle(sp40[1] + sp4C[1]);
    func_80256E24(&sp58, 0.0f, sp4C[1], 0.0f, 0.0f, sp3C);
    sp70[0] = sp58[0] + sp7C[0];
    sp70[1] = sp64[1];
    sp70[2] = sp58[2] + sp7C[2];
    sp40[1] = sp7C[1] - sp64[1];
    if (mlAbsF(sp40[1]) > 200.0f) {
        if (sp40[1] > 0.0f) {
            phi_f0 = 2* sp30 * (200.0f - sp40[1]);
        } else {
            phi_f0 = sp30 *(-200.0f - sp40[1]) * 2;

        }
        sp70[1] = sp64[1] - phi_f0;
    }
    func_802BD334(sp70);
    if (func_802BE60C()) {
        func_802BC84C(0);
    }
    func_802BE6FC(sp4C, sp7C);
    func_802BD720(sp4C);
    if(sp30);
}
#endif

#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void func_80252C08(f32[3], f32[3], f32, f32[3]);
extern void func_80252CC4(f32[3], f32[3], f32, s32);

bool func_802EA760(BKModelUnk14List *arg0, s32 arg1, f32 arg2[3], f32 arg3[3], f32 arg4, f32 arg5[3], f32 arg6[3], f32 *arg7) {
    s32 start;
    BKModelUnk14_2 *temp_v0;

    if (arg1 >= arg0->unk4) {
        return FALSE;
    }
    start = sizeof(BKModelUnk14List) + arg0->cnt0*sizeof(BKModelUnk14_0) + (s32)arg0;
    temp_v0 = arg0->cnt2*sizeof(BKModelUnk14_1) + start + arg1 *sizeof(BKModelUnk14_2);

    arg6[0] = (f32) temp_v0->unk2[0];
    arg6[1] = (f32) temp_v0->unk2[1];
    arg6[2] = (f32) temp_v0->unk2[2];
    *arg7 = (f32) temp_v0->unk0;
    mlMtxIdent();
    func_80252C08(arg2, arg3, arg4, arg5);
    func_8025235C(arg6, arg6);
    *arg7 /= arg4;
    return TRUE;
}

s32 func_802EA864(BKModelUnk14List *arg0, f32 position[3], f32 rotation[3], f32 scale, f32 arg4[3], f32 arg5[3], f32 arg6) {
    BKModelUnk14_0 *start_ptr;
    f32 spB0[3];
    f32 spA4[3];
    f32 sp98[3];
    f32 sp8C[3];
    BKModelUnk14_0 *end_ptr;
    BKModelUnk14_0 *iPtr;
    f32 sp78[3];
    s32 j;

    start_ptr = (BKModelUnk14_0 *)(arg0 + 1);
    end_ptr = start_ptr + arg0->cnt0;
    for(iPtr = start_ptr; iPtr < end_ptr; iPtr++){
        spB0[0] = (f32) iPtr->unkC[0];
        spB0[1] = (f32) iPtr->unkC[1];
        spB0[2] = (f32) iPtr->unkC[2];

        spA4[0] = (f32) iPtr->unk0[0];
        spA4[1] = (f32) iPtr->unk0[1];
        spA4[2] = (f32) iPtr->unk0[2];

        sp98[0] = (f32) iPtr->unk6[0];
        sp98[1] = (f32) iPtr->unk6[1];
        sp98[2] = (f32) iPtr->unk6[2];

        sp8C[0] = (f32)iPtr->unk12[0];
        sp8C[1] = (f32)iPtr->unk12[1];
        sp8C[2] = (f32)iPtr->unk12[2];
        
        sp8C[0] *= 2;
        sp8C[1] *= 2;
        sp8C[2] *= 2;
        mlMtxIdent();
        func_80252EC8(spB0, sp8C);
        func_80252CC4(position, rotation, scale, arg4);
        func_8025235C(&sp78, arg5);
        for(j = 0; j < 3; j++){
            if (((sp78[j] + arg6 / scale) <= spA4[j]) || (sp98[j] <= (sp78[j] - arg6 / scale))) 
                break;
        }
        if (j == 3) {
            return iPtr->unk15;
        }
    }
    return 0;
}

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_637D0/func_802EAB34.s")
#else
s32 func_802EAB34(BKModelUnk14List *arg0, f32 position[3], f32 rotation[3], f32 scale, f32 arg4[3], f32 arg5[3], f32 arg6){
    BKModelUnk14_1 *iPtr;
    f32 spA0[3];
    f32 sp94[3];
    BKModelUnk14_0 *tmp;
    s32 start_ptr;
    BKModelUnk14_1 *end_ptr;
    f32 temp_f20;
    f32 sp78[3];
    f32 temp_f22;
    f32 temp_f24;

    // tmp = ;
    start_ptr = (s32)(arg0 + 1);
    // start_ptr += sizeof(BKModelUnk14List);
    start_ptr += arg0->cnt0*sizeof(BKModelUnk14_0);
    end_ptr = start_ptr + arg0->cnt2*sizeof(BKModelUnk14_1);
    for(iPtr = start_ptr; iPtr < end_ptr; iPtr++){
        spA0[0] = (f32) iPtr->unk4[0];
        spA0[1] = (f32) iPtr->unk4[1];
        spA0[2] = (f32) iPtr->unk4[2];

        sp94[0] = (f32) ((s32)iPtr->unkA[0] * 2);
        sp94[1] = (f32) ((s32)iPtr->unkA[1] * 2);
        sp94[2] = (f32) ((s32)iPtr->unkA[2] * 2);
        temp_f24 = (f32) iPtr->unk0;
        temp_f20 = (f32) iPtr->unk2;
        mlMtxIdent();
        func_80252DDC(spA0, sp94);
        func_80252CC4(position, rotation, scale, arg4);
        func_8025235C(&sp78, arg5);
        if (!(temp_f20 / 2 <= (sp78[2] - arg6 / scale)) && !((sp78[2] + arg6 / scale) <= -(temp_f20 / 2))) {
            if (!(((arg6 / scale + temp_f24) *  (arg6 / scale + temp_f24)) <= ((sp78[0] * sp78[0]) + (sp78[1] * sp78[1])))) {
                return iPtr->unkD;
            }
        }
    }
    return 0;
}
#endif


s32 func_802EAD5C(BKModelUnk14List *arg0, f32 position[3], f32 rotation[3], f32 scale, s32 arg4, f32 arg6[3], f32 arg7);
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_637D0/func_802EAD5C.s")

s32 func_802EAED4(BKModelUnk14List *arg0, f32 position[3], f32 rotation[3], f32 scale, s32 arg4, s32 arg5, f32 arg6[3], f32 arg7);
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_637D0/func_802EAED4.s")

s32 func_802EB458(BKModelUnk14List *arg0, f32 position[3], f32 rotation[3], f32 scale, s32 arg4, s32 arg5, f32 arg6[3], f32 arg7);
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_637D0/func_802EB458.s")

s32 func_802EB8A0(BKModelUnk14List *arg0, f32 position[3], f32 rotation[3], f32 scale, s32 arg4, s32 arg5, f32 arg6[3], f32 arg7);
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_637D0/func_802EB8A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_637D0/func_802EBA98.s")

extern Mtx D_80380880;

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_637D0/func_802EBAE0.s")
// s32 func_802EBAE0(BKModelUnk14List *arg0, f32 position[3], f32 rotation[3], f32 scale, s32 arg4, s32 arg5, f32 arg6[3], f32 arg7, f32 arg8[3]) {
//     f32 sp3C[3];
//     f32 temp_f0;
//     s32 phi_v0;

//     sp3C[0] = arg6[0] - position[0];
//     sp3C[1] = arg6[1] - position[1];
//     sp3C[2] = arg6[2] - position[2];
//     temp_f0 = (arg7 + (arg0->unk6 * scale));
//     if( (arg0->unk6 > 0) 
//         && ((temp_f0 * temp_f0) < (sp3C[0] * sp3C[0]) + (sp3C[1] * sp3C[1]) + (sp3C[2] * sp3C[2]))
//     ) {
//         return 0;
//     }
//     if (arg5 != NULL) {
//         mlMtxIdent();
//         func_80252C08(position, rotation, scale, arg4);
//         func_802513B0(&D_80380880);
//         phi_v0 = func_802EB8A0(arg0, position, rotation, scale, arg4, arg5, arg6, arg7);
//         if (phi_v0 == 0) {
//             phi_v0 = func_802EAED4(arg0, position, rotation, scale, arg4, arg5, arg6, arg7);
//         }
//         if (phi_v0 == 0) {
//             phi_v0 = func_802EB458(arg0, position, rotation, scale, arg4, arg5, arg6, arg7);
//         }
//     } else {
//         phi_v0 = func_802EAD5C(arg0, position, rotation, scale, arg4, arg6, arg7);
//         if(phi_v0 == 0){
//             phi_v0 = func_802EA864(arg0, position, rotation, scale, arg4, arg6, arg7);
//         }
//         if(phi_v0 == 0){
//             phi_v0 = func_802EAB34(arg0, position, rotation, scale, arg4, arg6, arg7);
//         }
//     }
//     if (phi_v0 != 0) {
//         arg8[0] = 0.0f;
//         arg8[1] = 1.0f;
//         arg8[2] = 0.0f;
//     }
//     return phi_v0;
// }

#ifndef NONMATCHING
s32 func_802EBD3C(BKModelUnk14List *arg0, f32 arg1[3], f32 arg2[3], f32 arg3, s32 arg4, f32 arg5[3], s32 arg6);
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_637D0/func_802EBD3C.s")
#else
s32 func_802EBD3C(BKModelUnk14List *arg0, f32 arg1[3], f32 arg2[3], f32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    s32 i;
    f32 spA0[3];
    f32 sp94[3];
    f32 sp88[3];
    f32 sp7C[3];
    BKModelUnk14_0 *phi_s0;
    BKModelUnk14_0 *temp_s4;
    f32 sp68[3];
    BKModelUnk14_0 *temp_s0;

    temp_s0 = (BKModelUnk14_0 *)(arg0 + 1);
    temp_s4 = temp_s0 + (arg0->cnt0);
    for(phi_s0 = temp_s0; phi_s0 < temp_s4; phi_s0++){
        if ((phi_s0->unk15 != 0) && ((arg6 == 0) || (arg6 == phi_s0->unk15))) {
            spA0[0] = (f32) phi_s0->unkC[0];
            spA0[1] = (f32) phi_s0->unkC[1];
            spA0[2] = (f32) phi_s0->unkC[2];
            sp94[0] = (f32) phi_s0->unk0[0];
            sp94[1] = (f32) phi_s0->unk0[1];
            sp94[2] = (f32) phi_s0->unk0[2];
            sp88[0] = (f32) phi_s0->unk6[0];
            sp88[1] = (f32) phi_s0->unk6[1];
            sp88[2] = (f32) phi_s0->unk6[2];
            sp7C[0] = (f32)phi_s0->unk12[0];
            sp7C[1] = (f32)phi_s0->unk12[1];
            sp7C[2] = (f32)phi_s0->unk12[2];

            sp7C[0] *= 2;
            sp7C[1] *= 2;
            sp7C[2] *= 2;
            mlMtxIdent();
            func_80252EC8(spA0, sp7C);
            func_80252CC4(arg1, arg2, arg3, arg4);
            func_8025235C(sp68, arg5);
            for(i = 0; i < 3; i++){
                if((sp68[i] <= sp94[i]) || (sp88[i] <= sp68[i])){
                    break;
                }
            }
            if(i == 3){
                return phi_s0->unk15;
            }
        }
    }
    return 0;
}
#endif

#ifndef NONMATCHING
s32 func_802EC000(BKModelUnk14List *arg0, s32 arg1, s32 arg2, f32 arg3, s32 arg4, s32 arg5, s32 arg6);
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_637D0/func_802EC000.s")
#else
s32 func_802EC000(BKModelUnk14List *arg0, f32 arg1[3], f32 arg2[3], f32 arg3, s32 arg4, f32 arg5[3], s32 arg6){
    BKModelUnk14_1 *temp_s2;
    f32 sp90[3];
    f32 sp84[3];
    BKModelUnk14_1 *phi_s0;
    f32 temp_f20;
    f32 temp_f22;
    f32 temp_f0;
    f32 sp68[3];

    phi_s0 = (BKModelUnk14_1 *)(sizeof(BKModelUnk14List) + arg0->cnt0*sizeof(BKModelUnk14_0) + (s32)arg0);
    temp_s2 = phi_s0 + arg0->cnt2;
    for( ; phi_s0 < temp_s2; phi_s0++){
        if ((phi_s0->unkD != 0) && ((arg6 == 0) || (arg6 == phi_s0->unkD))) {
            sp90[0] = (f32) phi_s0->unk4[0];
            sp90[1] = (f32) phi_s0->unk4[1];
            sp90[2] = (f32) phi_s0->unk4[2];
            sp84[0] = (f32) (phi_s0->unkA[0] * 2);
            sp84[1] = (f32) (phi_s0->unkA[1] * 2);
            sp84[2] = (f32) (phi_s0->unkA[2] * 2);
            temp_f20 = (f32) phi_s0->unk0;
            temp_f22 = (f32) phi_s0->unk2;
            mlMtxIdent();
            func_80252DDC(&sp90, &sp84);
            func_80252CC4(arg1, arg2, arg3, arg4);
            func_8025235C(&sp68, arg5);
            temp_f0 = (f32) (temp_f22 * 0.5);
            if (!(temp_f0 <= sp68[2]) && !(sp68[2] <= -temp_f0) && !((temp_f20 * temp_f20) <= (sp68[0] * sp68[0] + sp68[1]*sp68[1]))) {
                return phi_s0->unkD;
            }
        }
    }
    return 0;
}
#endif


s32 func_802EC238(BKModelUnk14List *arg0, s32 arg1, s32 arg2, f32 arg3, s32 arg4, s32 arg5, s32 arg6);
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_637D0/func_802EC238.s")

s32 func_802EC394(BKModelUnk14List *arg0, s32 arg1, s32 arg2, f32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    s32 phi_v0;

    phi_v0 = func_802EBD3C(arg0, arg1, arg2, arg3, arg4, arg5, arg6);
    if (phi_v0 != NULL) {
        return phi_v0;
    }

    phi_v0 = func_802EC000(arg0, arg1, arg2, arg3, arg4, arg5, arg6);
    if (phi_v0 != NULL) {
        return phi_v0;
    }
    return func_802EC238(arg0, arg1, arg2, arg3, arg4, arg5, arg6);
}

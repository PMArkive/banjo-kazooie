#include <ultra64.h>
#include "functions.h"
#include "variables.h"


void func_802DFA34(Actor *this);
Actor *func_802E0738(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);
void func_802E07E0(Actor *this);
void func_802E08F0(Actor *this);

/* .data */
extern ActorAnimationInfo D_803683B0[];

extern ActorInfo D_80368418 = {
    0x17A, 0x2B4, 0x565, 
    0x1, D_803683B0, 
    func_802DFA34, func_80326224, func_80325340, 
    { 0x0, 0x0, 0x0, 0x0}, 0.0f, { 0x0, 0x0, 0x0, 0x0}
};

extern ActorAnimationInfo D_80368440[];

extern ActorInfo D_80368450 = {
    0x72, 0xA2, 0x3AD, 
    0x1, D_80368440, 
    func_802E08F0, func_80326224, func_80325888, 
    { 0x0, 0x0, 0x0, 0x0}, 0.0f, { 0x0, 0x0, 0x0, 0x0}
};


extern ActorInfo D_80368474 = {
    0x8C, 0xBC, 0x45C,
    0, NULL,
    NULL, func_802E07E0, func_802E0738, 
    { 0x0, 0x0, 0x0, 0x0}, 0.0f, { 0x0, 0x0, 0x0, 0x0}
};

extern ActorInfo D_80368498 = {
    0x8D, 0xBD, 0x45E,
    0, NULL,
    NULL, func_802E07E0, func_802E0738, 
    { 0x0, 0x0, 0x0, 0x0}, 0.0f, { 0x0, 0x0, 0x0, 0x0}
};

extern ActorInfo D_803684BC = {
    0x13D, 0x2F4, 0x46E,
    0, NULL,
    NULL, func_802E07E0, func_802E0738, 
    { 0x0, 0x0, 0x0, 0x0}, 0.0f, { 0x0, 0x0, 0x0, 0x0}
};

extern ActorInfo D_803684E0 = {
    0x13E, 0x2F5, 0x46F,
    0, NULL,
    NULL, func_802E07E0, func_802E0738, 
    { 0x0, 0x0, 0x0, 0x0}, 0.0f, { 0x0, 0x0, 0x0, 0x0}
};

extern ActorInfo D_80368504 = {
    0x13F, 0x2F6, 0x3BB,
    0, NULL,
    NULL, func_802E07E0, func_802E0738, 
    { 0x0, 0x0, 0x0, 0x0}, 0.0f, { 0x0, 0x0, 0x0, 0x0}
};

extern ActorInfo D_80368528 = {
    0x140, 0x2F7, 0x3BB,
    0, NULL,
    NULL, func_802E07E0, func_802E0738, 
    { 0x0, 0x0, 0x0, 0x0}, 0.0f, { 0x0, 0x0, 0x0, 0x0}
};

extern ActorInfo D_8036854C = {
    0x141, 0x2F8, 0x3BB,
    0, NULL,
    NULL, func_802E07E0, func_802E0738, 
    { 0x0, 0x0, 0x0, 0x0}, 0.0f, { 0x0, 0x0, 0x0, 0x0}
};

extern ActorInfo D_80368570 = {
    0x142, 0x2F9, 0x3BB,
    0, NULL,
    NULL, func_802E07E0, func_802E0738, 
    { 0x0, 0x0, 0x0, 0x0}, 0.0f, { 0x0, 0x0, 0x0, 0x0}
};


/* .code */
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_584D0/func_802DF460.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_584D0/func_802DF4E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_584D0/func_802DF50C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_584D0/func_802DF5D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_584D0/func_802DF71C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_584D0/func_802DF8EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_584D0/func_802DF928.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_584D0/func_802DF99C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_584D0/func_802DF9CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_584D0/func_802DFA34.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_584D0/func_802E0538.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_584D0/func_802E055C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_584D0/func_802E0588.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_584D0/func_802E05AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_584D0/func_802E0664.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_584D0/func_802E068C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_584D0/func_802E06B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_584D0/func_802E06C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_584D0/func_802E06CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_584D0/func_802E0710.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_584D0/func_802E0738.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_584D0/func_802E07C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_584D0/func_802E07E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_584D0/func_802E08F0.s")

#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_400F0/func_802C7080.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_400F0/func_802C70DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_400F0/func_802C71F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_400F0/func_802C7318.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_400F0/func_802C73B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_400F0/func_802C7478.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_400F0/func_802C74F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_400F0/func_802C7568.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_400F0/func_802C75A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_400F0/func_802C75C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_400F0/func_802C75F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_400F0/func_802C7600.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_400F0/func_802C7630.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_400F0/func_802C7650.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_400F0/func_802C7670.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_400F0/func_802C7690.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_400F0/func_802C76D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_400F0/func_802C7718.s")

void func_802C775C(s32 arg0){
    func_802C75C8(arg0, 3);
}

void func_802C777C(s32 arg0){
    func_802C75C8(arg0, 2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_400F0/func_802C779C.s")

void func_802C79C4(void){
    int i;
    for(i = 0; i < 0x20; i++){
        if(mapSpecificFlags_get(i) && func_802C779C(i)){
            mapSpecificFlags_set(i, FALSE);
        }
    }
}
#include <ultra64.h>
#include "functions.h"
#include "variables.h"

typedef struct {
    s16 map_id; //map_id
    s16 unk2; //other_id
    s16 unk4;
    s16 unk6;
    s16 unk8;
    s16 unkA;
    s16 unkC;
    s16 unkE;
    s16 unk10;
    s16 unk12;
    s16 unk14;
}struct_core2_35520_1;

typedef struct {
    s32 overlay_id; //overlay_id
    struct_core2_35520_1 *unk4;
}struct_core2_35520;

/* .data */
struct_core2_35520_1 D_80365830[] ={
    {MAP_1_SM_SPIRAL_MOUNTAIN, 0x0001, 0x0320, 0x0352, 0x0177, 0x03B6, 0x03E8, 0x020D, 0x044C, 0x047E, 0x02A3},
    {0x0000, 0x0000, 0x0226, 0x0258, 0x00AF, 0x0352, 0x0384, 0x0177, 0x044C, 0x047E, 0x02A3}
};

struct_core2_35520_1 D_8036585C[] ={
    {MAP_2_MM_MUMBOS_MOUNTAIN, 0x0001, 0x0320, 0x0352, 0x0226, 0x03B6, 0x03E8, 0x02EE, 0x044C, 0x047E, 0x041A},
    {MAP_2_MM_MUMBOS_MOUNTAIN, 0x0000, 0x0226, 0x0258, 0x00AF, 0x0352, 0x0384, 0x0177, 0x044C, 0x047E, 0x02A3},
    {0x0000, 0x0000, 0x0226, 0x0258, 0x00AF, 0x0352, 0x0384, 0x0177, 0x044C, 0x047E, 0x02A3}
};

struct_core2_35520_1 D_803658A0[] = {
    {MAP_8F_TTC_SHARKFOOD_ISLAND,   0x0000, 0x0177, 0x01A9, 0x00AF, 0x020D, 0x023F, 0x023F, 0x02A3, 0x02D5, 0x03CF},
    {MAP_7_TTC_TREASURE_TROVE_COVE, 0x0004, 0x0226, 0x0258, 0x00AF, 0x0352, 0x0384, 0x0177, 0x044C, 0x047E, 0x02A3},
    {MAP_7_TTC_TREASURE_TROVE_COVE, 0x0003, 0x0226, 0x0258, 0x00AF, 0x0352, 0x0384, 0x0177, 0x044C, 0x047E, 0x02A3},
    {MAP_7_TTC_TREASURE_TROVE_COVE, 0x0002, 0x0226, 0x0258, 0x00AF, 0x0352, 0x0384, 0x01DB, 0x03B6, 0x03E8, 0x0307},
    {MAP_7_TTC_TREASURE_TROVE_COVE, 0x0001, 0x02BC, 0x02EE, 0x01C2, 0x0352, 0x0384, 0x02EE, 0x03E8, 0x041A, 0x041A},
    {MAP_7_TTC_TREASURE_TROVE_COVE, 0x0000, 0x0226, 0x0258, 0x00AF, 0x0352, 0x0384, 0x0177, 0x044C, 0x047E, 0x02A3},
    {0x0000, 0x0000, 0x0226, 0x0258, 0x00AF, 0x0352, 0x0384, 0x0177, 0x044C, 0x047E, 0x02A3}
};

struct_core2_35520_1 D_8036593C[] ={
    {MAP_B_CC_CLANKERS_CAVERN, 0x0001, 0x028A, 0x02BC, 0x0113, 0x036B, 0x039D, 0x01DB, 0x044C, 0x047E,0x02A3},
    {0x0000, 0x0000, 0x0226, 0x0258, 0x00AF, 0x0352, 0x0384, 0x0177, 0x044C, 0x047E, 0x02A3}
};

struct_core2_35520_1 D_80365968[] = {
    {MAP_D_BGS_BUBBLEGLOOP_SWAMP, 0x0005, 0x0226, 0x0258, 0x00E1, 0x0352, 0x0384, 0x01C2, 0x044C, 0x047E, 0x02EE},
    {MAP_D_BGS_BUBBLEGLOOP_SWAMP, 0x0003, 0x0226, 0x0258, 0x00E1, 0x0352, 0x0384, 0x0177, 0x044C, 0x047E, 0x02A3},
    {MAP_D_BGS_BUBBLEGLOOP_SWAMP, 0x0002, 0x0226, 0x0258, 0x00AF, 0x02EE, 0x0320, 0x01DB, 0x03B6, 0x03E8, 0x02EE},
    {MAP_D_BGS_BUBBLEGLOOP_SWAMP, 0x0001, 0x0226, 0x0258, 0x00AF, 0x0352, 0x0384, 0x01A9, 0x044C, 0x047E, 0x02A3},
    {0x0000, 0x0000, 0x0226, 0x0258, 0x00AF, 0x0352, 0x0384, 0x0177, 0x044C, 0x047E, 0x02A3}
};

struct_core2_35520_1 D_803659D8[] = {
    {0x0000, 0x0000, 0x0226, 0x0258, 0x00AF, 0x0352, 0x0384, 0x0177, 0x044C, 0x047E, 0x02A3}
};

struct_core2_35520_1 D_803659F0[] = {
    {MAP_12_GV_GOBIS_VALLEY, 0x0004, 0x0226, 0x0258, 0x00AF, 0x02EE, 0x0320, 0x0177, 0x03B6, 0x03E8, 0x02A3},
    {MAP_12_GV_GOBIS_VALLEY, 0x0003, 0x0226, 0x0258, 0x00AF, 0x0352, 0x0384, 0x0177, 0x044C, 0x047E, 0x02A3},
    {MAP_12_GV_GOBIS_VALLEY, 0x0002, 0x0226, 0x0258, 0x00AF, 0x02D5, 0x0307, 0x01DB, 0x0384, 0x03B6, 0x0307},
    {MAP_12_GV_GOBIS_VALLEY, 0x0001, 0x0226, 0x0258, 0x00AF, 0x02EE, 0x0320, 0x023F, 0x03B6, 0x03E8, 0x03CF},
    {0x0000, 0x0000, 0x0226, 0x0258, 0x00AF, 0x0352, 0x0384, 0x0177, 0x044C, 0x047E, 0x02A3}
};

struct_core2_35520_1 D_80365A60[] = {
    {MAP_26_MMM_NAPPERS_ROOM,        0x0001, 0x0226, 0x0258, 0x00AF, 0x0352, 0x0384, 0x00E1, 0x044C, 0x047E, 0x0113},
    {MAP_1B_MMM_MAD_MONSTER_MANSION, 0x0003, 0x0226, 0x0258, 0x00C8, 0x02EE, 0x0320, 0x0177, 0x03B6, 0x03E8, 0x02A3},
    {MAP_1B_MMM_MAD_MONSTER_MANSION, 0x0002, 0x0226, 0x0258, 0x00C8, 0x02EE, 0x0320, 0x0145, 0x03B6, 0x03E8, 0x01C2},
    {MAP_1B_MMM_MAD_MONSTER_MANSION, 0x0001, 0x0226, 0x0258, 0x00AF, 0x0352, 0x0384, 0x0177, 0x044C, 0x047E, 0x02A3},
    {0x0000, 0x0000, 0x0226, 0x0258, 0x00AF, 0x0352, 0x0384, 0x0177, 0x044C, 0x047E, 0x02A3}
};

struct_core2_35520_1 D_80365AD0[] = {
    {MAP_34_RBB_ENGINE_ROOM,      0x0001, 0x0226, 0x0258, 0x00AF, 0x0307, 0x0339, 0x023F, 0x0384, 0x03B6, 0x03E8}, 
    {MAP_34_RBB_ENGINE_ROOM,      0x0000, 0x0226, 0x0258, 0x00AF, 0x0307, 0x0339, 0x01DB, 0x0384, 0x03B6, 0x0307}, 
    {MAP_31_RBB_RUSTY_BUCKET_BAY, 0x0003, 0x0226, 0x0258, 0x015E, 0x02A3, 0x02D5, 0x02D5, 0x0320, 0x0352, 0x044C}, 
    {MAP_31_RBB_RUSTY_BUCKET_BAY, 0x0002, 0x0226, 0x0258, 0x00AF, 0x02EE, 0x0320, 0x020D, 0x03B6, 0x03E8, 0x036B}, 
    {MAP_31_RBB_RUSTY_BUCKET_BAY, 0x0001, 0x0226, 0x0258, 0x00AF, 0x0352, 0x0384, 0x0177, 0x044C, 0x047E, 0x02A3}, 
    {0x0000, 0x0000, 0x0226, 0x0258, 0x00AF, 0x0352, 0x0384, 0x0177, 0x044C, 0x047E, 0x02A3}
};

struct_core2_35520_1 D_80365B54[] = {
    {MAP_43_CCW_SPRING, 0x0002, 0x0226, 0x0258, 0x00E1, 0x0352, 0x0384, 0x01A9, 0x044C, 0x047E, 0x02A3},
    {MAP_44_CCW_SUMMER, 0x0002, 0x0226, 0x0258, 0x00E1, 0x0352, 0x0384, 0x01A9, 0x044C, 0x047E, 0x02A3},
    {MAP_45_CCW_AUTUMN, 0x0002, 0x0226, 0x0258, 0x00E1, 0x0352, 0x0384, 0x01A9, 0x044C, 0x047E, 0x02A3},
    {MAP_46_CCW_WINTER, 0x0002, 0x0226, 0x0258, 0x00E1, 0x0352, 0x0384, 0x01A9, 0x044C, 0x047E, 0x02A3},
    {MAP_43_CCW_SPRING, 0x0001, 0x0320, 0x0352, 0x0226, 0x03B6, 0x03E8, 0x0320, 0x044C, 0x047E, 0x041A}, 
    {MAP_44_CCW_SUMMER, 0x0001, 0x0320, 0x0352, 0x0226, 0x03B6, 0x03E8, 0x0320, 0x044C, 0x047E, 0x041A}, 
    {MAP_45_CCW_AUTUMN, 0x0001, 0x0320, 0x0352, 0x0226, 0x03B6, 0x03E8, 0x0320, 0x044C, 0x047E, 0x041A}, 
    {MAP_46_CCW_WINTER, 0x0001, 0x0320, 0x0352, 0x0226, 0x03B6, 0x03E8, 0x0320, 0x044C, 0x047E, 0x041A}, 
    {0x0000, 0x0000, 0x0226, 0x0258, 0x00AF, 0x0352, 0x0384, 0x0177, 0x044C, 0x047E, 0x02A3}
};

struct_core2_35520_1 D_80365C1C [] = {
    {0x0000, 0x0000, 0x0226, 0x0258, 0x0096, 0x0352, 0x0384, 0x0177, 0x044C, 0x047E, 0x02A3}
};

struct_core2_35520_1 D_80365C34 [] ={
    {MAP_90_GL_BATTLEMENTS, 0x0000, 0x0258, 0x028A, 0x00C8, 0x04B0, 0x0514, 0x0145, 0x0708, 0x076C, 0x01C2}
};

struct_core2_35520_1 D_80365C4C [] = {
    {0x0000, 0x0000, 0x0226, 0x0258, 0x00AF, 0x0352, 0x0384, 0x0177, 0x044C, 0x047E, 0x02A3}
};

struct_core2_35520 D_80365C64[] = {
    {OVERLAY_6_JUNGLE,   D_8036585C},
    {OVERLAY_5_BEACH,    D_803658A0},
    {OVERLAY_2_WHALE,    D_8036593C},
    {OVERLAY_7_SWAMP,    D_80365968},
    {OVERLAY_9_SNOW,     D_803659D8},
    {OVERLAY_D_WITCH,    D_80365C1C},
    {OVERLAY_4_DESERT,   D_803659F0},
    {OVERLAY_A_TREE,     D_80365B54},
    {OVERLAY_8_SHIP,     D_80365AD0},
    {OVERLAY_3_HAUNTED,  D_80365A60},
    {OVERLAY_B_TRAINING, D_80365830},
    {OVERLAY_E_BATTLE,   D_80365C34},
    {0}
};

/* .bss */
struct_core2_35520_1 *D_8037D930;

/* .code */
struct_core2_35520_1 *func_802BC4B0(s32 arg0) {
    s32 map_id;
    s32 i;

    map_id = map_get();
    for( i = 0; D_8037D930[i].map_id != 0; i++){
        if(map_id == D_8037D930[i].map_id && (arg0 == D_8037D930[i].unk2)){
            return &D_8037D930[i];
        }
    }
    return &D_8037D930[i];
}

void func_802BC538(s32 arg0, s32 *arg1, s32 *arg2, s32 *arg3, s32 *arg4, s32 *arg5, s32 *arg6, s32 *arg7, s32 *arg8, s32 *arg9) {
    struct_core2_35520_1 *temp_v0;

    temp_v0 = func_802BC4B0(arg0);
    *arg1 = (s32) temp_v0->unk4;
    *arg2 = (s32) temp_v0->unk6;
    *arg3 = (s32) temp_v0->unk8;
    *arg4 = (s32) temp_v0->unkA;
    *arg5 = (s32) temp_v0->unkC;
    *arg6 = (s32) temp_v0->unkE;
    *arg7 = (s32) temp_v0->unk10;
    *arg8 = (s32) temp_v0->unk12;
    *arg9 = (s32) temp_v0->unk14;
}

void func_802BC5CC(void){
    int i;
    int overlay;
    overlay = get_loaded_overlay_id();
    D_8037D930 = &D_80365C4C[0];
    for(i = 0; D_80365C64[i].overlay_id; i++){
        if(D_80365C64[i].overlay_id == overlay){
            D_8037D930 = D_80365C64[i].unk4;
        }
    }
}

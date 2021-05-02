#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "bsint.h"
#include "bs_funcs.h"


u8 D_80363820 = 0;
bsMap D_80363824[] ={
    {BS_IDLE,       bsstand_init,       bsstand_update,     bsstand_end,        func_802B5350},
    {BS_WALK_SLOW,  bswalk_slow_init,   bswalk_slow_upate,  NULL,               func_802B5350},
    {BS_WALK,       bswalk_init,        bswalk_update,      NULL,               func_802B5350},
    {BS_WALK_FAST,  bswalk_fast_init,   bswalk_fast_update, bswalk_fast_end,    func_802B5350},
    {BS_JUMP,       bsjump_init,        bsjump_update,      bsjump_end,         func_80296608},
    {BS_CLAW,       bsclaw_init,        bsclaw_update,      bsclaw_end,         func_80296608},
    {BS_CROUCH,     bscrouch_init,      bscrouch_update,    bscrouch_end,       func_802B5350},
    {BS_BTROT_JUMP, func_802A9328,      func_802A9478,      func_802A9864,      func_802B5350},
    {BS_SKID,       bsturn_init,        bsturn_update,      bsturn_end,         func_802B5350},
    {0xd,           func_802B63F8, func_802B64D0, func_802B6500, func_80296590},
    {BS_OW,         bsow_init, bsow_update, bsow_end, func_80296590},
    {BS_BUSTER,     func_8029FC64, func_8029FD8C, func_802A0278, func_80296608},
    {BS_BFLAP,      func_802A2690, func_802A2A1C, func_802A2D10, func_80296608},
    {BS_BPECK,      func_802A651C, func_802A66F0, func_802A6928, func_80296608},
    {BS_BFLIP,      func_802A2E6C, func_802A2F48, func_802A330C, func_80296608},
    {BS_BBARGE,     bsbarge_init,  bsbarge_update, bsbarge_end,  func_80296608},
    {BS_BTROT_ENTER, func_802A8E3C, func_802A8EA4, func_802A8F34, func_802B5350},
    {BS_BTROT_IDLE, func_802A8F60, func_802A8FB0, func_802A9010, func_802B5350},
    {BS_BTROT_WALK, func_802A90F8, func_802A914C, func_802A9300, func_802B5350},
    {BS_BTROT_EXIT, func_802A988C, func_802A98C8, func_802A9904, func_802B5350},
    {BS_FLY_KNOCKBACK, func_802A4D90, func_802A4EC8, func_802A4F44, func_80296608},
    {BS_WONDERWING_ENTER,   func_802AA630, func_802AA6DC, func_802AA728, func_80296608},
    {BS_WONDERWING_IDLE,    func_802AA754, func_802AA798, func_802AA7FC, func_80296608},
    {BS_WONDERWING_WALK,    func_802AA81C, func_802AA87C, func_802AA95C, func_80296608},
    {BS_WONDERWING_JUMP,    func_802AA97C, func_802AAAC4, func_802AAC1C, func_80296608},
    {BS_WONDERWING_EXIT,    func_802AAC44, func_802AACF0, func_802AAD2C, func_80296608},
    {BS_EGG_HEAD,   func_802A23E0, func_802A2468, func_802A2650, func_802B5350},
    {BS_EGG_ASS,    func_802A2170, func_802A21F8, func_802A23AC, func_802B5350},
    {BS_WALK_CREEP,      bswalk_creep_init, bswalk_creep_update, NULL, func_802B5350},  
    {BS_LANDING,    bsstand_landing_init, bsstand_landing_update, NULL, func_802B5350},
    {BS_BSHOCK_CHARGE, func_802A69B0, func_802A6B40, func_802A6DF4, func_80296608},
    {BS_BSHOCK_JUMP, func_802A6E60, func_802A6FC8, func_802A70D4, func_80296608},
    {BS_FLY_ENTER,  func_802A3820, func_802A38DC, func_802A3994, func_802A505C},
    {BS_FLY,        func_802A39BC, func_802A3AA8, func_802A3F70, func_802A505C},
    {BS_LONGLEG_ENTER,  func_802A55C0, func_802A5684, func_802A5718, func_802B5350},
    {BS_LONGLEG_IDLE,   func_802A5744, func_802A5798, func_802A587C, func_802B5350},
    {BS_LONGLEG_WALK,   func_802A589C, func_802A592C, func_802A5A90, func_802B5350},
    {BS_LONGLEG_JUMP,   func_802A5D20, func_802A5E70, func_802A611C, func_80296608},
    {BS_LONGLEG_EXIT,   func_802A5BB4, func_802A5C34, func_802A5CF4, func_802B5350},
    {BS_BOMB,       func_802A3F9C, func_802A411C, func_802A4404, func_802A505C},
    {BS_DIVE_IDLE,  func_802A762C, func_802A7674, func_802A7718, func_80296608},
    {BS_DIVE_B,     func_802A7738, func_802A7838, func_802A7A2C, func_80296608},
    {BS_SWIM_IDLE,  func_802B5774, func_802B5950, func_802B5AF8, func_80296608},
    {BS_SWIM,       func_802B5B18, func_802B5C40, func_802B5E10, func_80296608},
    {BS_FALL,       func_802B1660, func_802B1750, func_802B1920, func_80296608},
    {BS_DIVE_ENTER, func_802A7DAC, func_802A7E2C, func_802A7F4C, func_80296608},
    {BS_ROLL,       func_802B6A4C, func_802B6B70, func_802B6CD4, func_802B5350},
    {BS_SLIDE,      bsslide_init,   bsslide_update, bsslide_end, func_802B5350},
    {0x33,          func_802B9ACC, func_802B9B14, func_802B9AAC, func_802B9D00},
    {BS_JIG_NOTEDOOR, func_802B0F88, func_802B1090, func_802B0EF0, func_80296590},
    {BS_ANT_IDLE,   func_8029E618, func_8029E6B0, func_8029E73C, func_802B5350},
    {BS_ANT_WALK,   func_8029E764, func_8029E7D4, func_8029E8A0, func_802B5350},
    {BS_ANT_JUMP,   func_8029E8C8, func_8029EA04, func_8029EB94, func_802B5350},
    {BS_DIVE_A,     func_802A7A54, func_802A7AB0, func_802A7BA8, func_80296608},
    {BS_CARRY_IDLE, func_802AAF24, func_802AAFD0, func_802AB018, func_802AB1A4},
    {BS_CARRY_WALK, func_802AB038, func_802AB0DC, func_802AB164, func_802AB1A4},
    {0x3C,          func_802B6130, func_802B61E0, func_802B6218, func_802B6220},
    {BS_FALL_TUMBLING,  func_802B1DD0, func_802B1E80, func_802B1F6C, func_80296608},
    {BS_ANT_FALL,   func_8029EBBC, func_8029EC5C, func_8029ED3C, func_80296590},
    {BS_ANT_OW,     func_8029EFA8, func_8029EFC8, func_8029EFE8, func_80296590},
    {0x3F,          func_802B1BF4, func_802B1CF8, func_802B1DA4, func_80296590},
    {0x40,          func_802B2BF0, func_802B2C58, func_802B2D50, func_80296590},
    {BS_DIE,        func_802ADEA0, func_802AE058, func_802AE30C, func_80296590},
    {BS_DINGPOT,    func_802A5120, func_802A5190, func_802A51C0, func_80296590},
    {BS_ANT_DIE,    func_8029F068, func_8029F218, func_8029F348, func_80296590},
    {BS_JIG_JIGGY,  func_802B0A78, func_802B0BE4, func_802B0D1C, func_802B0EBC},
    {BS_BTROT_SLIDE,    func_802A9924, func_802A9A34, func_802A9B78, func_802B5350},
    {0x46,          func_802A2098, func_802A2130, func_802A2054, func_80296590},
    {BS_PUMPKIN_IDLE,   func_802B2384, func_802B242C, func_802B24AC, func_802B5350},
    {BS_PUMPKIN_WALK,   func_802B24D4, func_802B2580, func_802B2610, func_802B5350},
    {BS_PUMPKIN_JUMP,   func_802B2638, func_802B2750, func_802B2990, func_802B5350},
    {BS_PUMPKIN_FALL,   func_802B29C0, func_802B2A5C, func_802B2BD0, func_802B5350},
    {BS_LANDING_IN_WATER, func_802A846C, func_802A85EC, func_802A872C, func_80296608},
    {BS_PUMPKIN_OW,     func_802B2FDC, func_802B2FFC, func_802B301C, func_80296590},
    {BS_PUMPKIN_DIE,    func_802B309C, func_802B3240, func_802B3448, func_80296590},
    {BS_CLIMB_IDLE, func_802AB830, func_802AB8DC, func_802ABA10, func_802ABD60},
    {BS_CLIMB_MOVE, func_802ABA30, func_802ABAA4, func_802ABCAC, func_802ABD60},
    {BS_CLIMB_EXIT, func_802B1928, func_802B1A54, func_802B1BCC, func_80296608},
    {0x52,          func_802B5FD0, func_802B6064, func_802B60D0, func_802B60D8},
    {0x53, func_802B6270, func_802B6314, func_802B63C8, func_80296590},
    {BS_LONGLEG_SLIDE, func_802A6144, func_802A624C, func_802A6368, func_802B5350},
    {BS_RECOIL, func_802B3868, func_802B3954, func_802B3A20, func_80296590},
    {BS_BOMB_END, func_802A4430, func_802A4548, func_802A4664, func_802A505C},
    {0x58, func_802A4748, func_802A48B4, func_802A4A40, func_80296590},
    {0x59, func_802A4CD0, func_802A4CF0, func_802A4D10, func_802A505C},
    {BS_SWIM_DIE, func_802A7F6C, func_802A8098, func_802A82D4, func_80296590},
    {BS_CARRY_THROW, func_802B6540, func_802B65E0, func_802B66AC, func_802B66F8},
    {BS_CROC_IDLE, func_802AC0D4, func_802AC178, func_802AC224, func_802B5350},
    {BS_CROC_WALK, func_802AC24C, func_802AC2BC, func_802AC380, func_802B5350},
    {BS_CROC_JUMP, func_802AC3A8, func_802AC4DC, func_802AC6D0, func_802B5350},
    {BS_CROC_FALL, func_802AC6F8, func_802AC78C, func_802AC8CC, func_802B5350},
    {0x62, func_802A6394, func_802A63F0, func_802A6450, func_80296608},
    {BS_CROC_OW, func_802ACB38, func_802ACB58, func_802ACB78, func_80296590},
    {BS_CROC_DIE, func_802ACBF8, func_802ACDA0, func_802ACEFC, func_80296590},
    {BS_WALRUS_IDLE, func_802B8284, func_802B8330, func_802B83BC, func_802B5350},
    {BS_WALRUS_WALK, func_802B83E4, func_802B8454, func_802B84F0, func_802B5350},
    {BS_WALRUS_JUMP, func_802B8518, func_802B8654, func_802B8888, func_802B5350},
    {BS_WALRUS_FALL, func_802B88B0, func_802B894C, func_802B8AB4, func_802B5350},
    {0x6B, func_802A1F6C, func_802A1FC8, func_802A2014, func_80296608},
    {BS_WALRUS_OW, func_802B8C84, func_802B8CA4, func_802B8CC4, func_80296590},
    {BS_WALRUC_DIE, func_802B8D44, func_802B8F04, func_802B9010, func_80296590},
    {BS_CROC_BITE, func_802ACFCC, func_802AD024, func_802AD168, func_802B5350},
    {BS_CROC_EAT_BAD, func_802AD18C, func_802AD1D4, func_802AD288, func_802B5350},
    {BS_CROC_EAT_GOOD, func_802AD328, func_802AD3AC, func_802AD530, func_802B5350},
    {BS_BTROT_FALL, func_802A9C38, func_802A9D08, func_802AA068, func_80296608},
    {BS_SPLAT, func_802B45F0, func_802B4708, func_802B4844, func_80296590},
    {0x00000073, func_802B3CEC, func_802B3D1C, func_802B3D6C, func_80296608},
    {0x00000074, func_802B3E2C, func_802B3E64, func_802B3EF4, func_80296608},
    {0x00000075, func_802B3D8C, func_802B3DBC, func_802B3E0C, func_80296608},
    {0x00000076, func_802A4F74, func_802A4FC8, func_802A503C, func_80296608},
    {0x00000077, func_802B5E8C, func_802B5EFC, func_802B5F38, func_80296608},
    {0x00000078, func_802A83C0, func_802A8410, func_802A844C, func_80296608},
    {0x00000079, func_802AA088, func_802AA0E8, func_802AA134, func_80296608},
    {BS_WALK_MUD, bswalk_mud_init, bswalk_mud_update, NULL,          func_80296608},
    {BS_BTROT_OW, func_802AA15C, func_802AA27C, func_802AA338, func_80296590},
    {0x0000007C, func_802B3FA4, func_802B4004, func_802B4038, func_802B4080},
    {BS_WALRUS_SLED_IDLE, func_802B91A4, func_802B9214, func_802B92DC, func_802B98C0},
    {BS_WALRUS_SLED_JUMP, func_802B9304, func_802B9440, func_802B9578, func_802B98C0},
    {BS_DIVE_OW, func_802A7BD0, func_802A7CA8, func_802A7D74, func_80296590},
    {0x00000080, func_802B978C, func_802B9830, func_802B9880, func_80296590},
    {0x00000081, func_802B90D0, func_802B9130, func_802B917C, func_802B98C0},
    {0x00000082, func_802B95A0, func_802B963C, func_802B976C, func_802B98C0},
    {BS_BEE_IDLE, func_802A1080, func_802A10D4, func_802A117C, func_802B5350},
    {BS_BEE_WALK, func_802A11A4, func_802A1214, func_802A12D4, func_802B5350},
    {BS_BEE_JUMP, func_802A12FC, func_802A1438, func_802A163C, func_802B5350},
    {BS_BEE_FALL, func_802A1664, func_802A170C, func_802A18C8, func_802B5350},
    {BS_BEE_OW, func_802A1B68, func_802A1B88, func_802A1BA8, func_802B5350},
    {BS_BEE_DIE, bsbeemain_die_init, func_802A1DD8, func_802A1F2C, func_80296590},
    {0x0000008B, func_802A0590, func_802A0630, func_802A0704, func_802B5350},
    {BS_BEE_FLY, bsbeefly_enter, bsbeefly_update, bsbeefly_end, func_802B5350},
    {BS_CROC_LOCKED, func_802AD56C, func_802AD5C0, func_802AD614, func_802B5350},
    {0x0000008E, func_8029F398, func_8029F3F4, func_8029F440, func_802B5350},
    {BS_PUMPKIN_LOCKED, func_802B34A0, func_802B34F8, func_802B353C, func_802B5350},
    {BS_FLY_OW, func_802A4D30, func_802A4D50, func_802A4D70, func_802A505C},
    {BS_ANT_LOCKED, func_8029F468, func_8029F490, func_8029F4B0, func_802AE490},
    {0x00000093, func_802B3564, func_802B3584, func_802B35A4, func_802AE490},
    {BS_TRANSFORMING, func_802AD654, func_802AD674, func_802AD69C, func_802AE490},
    {BS_WALRUS_LOCKED, func_802B9060, func_802B9088, func_802B90A8, func_802AE490},
    {BS_SWIM_LOCKED, func_802B5F58, func_802B5F80, func_802B5FA0, func_802AE490},
    {BS_DIVE_LOCKED, func_802A874C, func_802A8774, func_802A8794, func_802AE490},
    {0x00000098, bswalk_unk98_init, bswalk_unk98_update, bswalk_unk98_end, func_802AE490},
    {0x00000099, func_802A50B0, func_802A50D8, func_802A50F8, func_802AE490},
    {0x0000009A, func_802AA378, func_802AA3A8, func_802AA3D0, func_802AE490},
    {0x0000009B, func_802A6478, func_802A64A0, func_802A64E0, func_802AE490},
    {0x0000009C, func_802B990C, func_802B9934, func_802B9954, func_802AE490},
    {0x0000009D, func_802A0478, func_802A04A0, func_802A04C0, func_802AE490},
    {0x0000009E, func_802ABCCC, func_802ABD0C, func_802ABD40, func_802ABD60},
    {BS_ANT_BOUNCE, func_8029F008, func_8029F028, func_8029F048, func_80296590},
    {BS_PUMPKIN_BOUNCE, func_802B303C, func_802B305C, func_802B307C, func_80296590},
    {BS_CROC_BOUNCE, func_802ACB98, func_802ACBB8, func_802ACBD8, func_80296590},
    {BS_WALRUS_BOUNCE, func_802B8CE4, func_802B8D04, func_802B8D24, func_80296590},
    {BS_BEE_BOUCE, func_802A1BC8, func_802A1BE8, func_802A1C08, func_80296590},
    {0x000000A4, func_802AAD4C, func_802AAD6C, func_802AAD94, func_80296608},
    {0x000000A5, func_802AADBC, func_802AAE08, func_802AAE4C, func_80296608},
    {0}
};

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_E910/func_802958A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_E910/func_80295914.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_E910/func_80295A8C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_E910/func_80295B04.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_E910/func_80295C08.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_E910/func_80295C14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_E910/func_80295D74.s")

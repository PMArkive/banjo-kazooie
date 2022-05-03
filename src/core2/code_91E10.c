#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void item_set(enum item_e, s32);
extern void func_8025A55C(s32, s32, s32);
extern void func_803184C8(gczoombox_t *, f32, s32, s32, f32, bool, bool);

enum question_type_e{
    Q_TYPE_0_TEXT,
    Q_TYPE_1_PICTURE,
    Q_TYPE_2_SOUND,
    Q_TYPE_3_GRUNTY,
};

typedef struct {
    u8 cmd;
    u8 string_size;
    //u8 str[];
}StringBin;

typedef struct {
    u8 unk0;
    u8 unk1;
}QuizQuestionBin_Struct_1;

typedef struct {
    u8 unk0;
    u8 unk1;
    u8 unk2;
}QuizQuestionBin;

typedef struct{
    s32 unk0[4][4];
}Struct_Core2_91E10_1;

typedef struct {
    s8 unk0; //question_type
    s8 unk1; //question_indx
    s8 unk2;
    u8 unk3;
    s32 unk4;
    void (*unk8)(s32, s32);
    QuizQuestionBin *unkC; //asset_bin
    u8 unk10; //state
    s8 unk11;
    s8 unk12;
    u8 unk13; //selected_box_indx
    u8 unk14;
    u8 unk15; //cursor_cooldown
    u8 unk16;
    u8 unk17;
    u8 unk18[4];
    s8 unk1C[4];
    s8 unk20[4]; //portrait_id
    gczoombox_t *unk24[4]; //zoombox
    Struct_Core2_91E10_1 unk34;
}Struct_Core2_91E10;

void func_803197AC(s32 arg0);
void func_80319E20(s32 arg0, s32 arg1);
void func_8031A3E4(void);

extern u8 D_8036D940[];

extern Struct_Core2_91E10 *D_803830E0;

void func_80318DA0(s8 *ptr, u8 min_indx, u8 max_indx, s32 min_value, s32 max_value){
    s32 i;
    s32 j;
    s32 unique;

    for(i = min_indx; i <= max_indx; i++){
            /* assign unique random value*/
            do{
                /*assign random value */
                ptr[i] = randi2(min_value, max_value + 1);
                unique = TRUE;
                /* test uniqueness */
                for(j = min_indx; j < i; j++){
                    if (ptr[i] == ptr[j]) {
                        unique = FALSE;
                        break;
                    }
                }
            }while(unique == FALSE);
    }
}

void func_80318E90(void) {
    D_803830E0->unk20[0] = 0;
    func_80318DA0(D_803830E0->unk20, 1, 3, 1, 0x2C);
}

//__gcquiz_get_type_start_id
enum asset_e func_80318ED8(enum question_type_e question_type){
    switch(question_type){
        case Q_TYPE_1_PICTURE: return 0x12DB;
        case Q_TYPE_2_SOUND:   return 0x13A3;
        case Q_TYPE_3_GRUNTY:  return 0x1407;
    }
    return 0x1213;
}

//__gcquiz_get_type_end_id
enum asset_e func_80318F1C(enum question_type_e question_type){
    switch(question_type){
        case Q_TYPE_1_PICTURE: return 0x12EE;
        case Q_TYPE_2_SOUND:   return 0x13D6;
        case Q_TYPE_3_GRUNTY:  return 0x1425;
    }
    return 0x1277;
}

s32 func_80318F60(enum question_type_e question_type, s32 q_indx, s32 arg2) {
    s32 phi_v1;
    s32 phi_a0;

    if (arg2 >= 0) {
        phi_v1 = arg2;
    } else {
        if (question_type == Q_TYPE_3_GRUNTY) {
            phi_a0 = func_80320424((q_indx * 2) + 0x26, 2);
        } else {
            phi_a0 = 0;
        }
        phi_v1 = phi_a0;
    }
    return phi_v1;
}

bool func_80318FB4(enum question_type_e question_type){
    return question_type == Q_TYPE_2_SOUND;
}

s32 func_80318FC0(s32 arg0){
    switch(arg0){
        case 1: return 40;
        case 2: return 80;
        case 3: return 120;
    }
    return 0;
}

s32 func_80319004(s32 arg0){
    return arg0 == 0 ? 3 : 2;     
}

s32 func_8031901C(s32 arg0){
    return 0;
}

bool func_80319028(s32 arg0){
    return arg0 != 0 ? FALSE : TRUE;
}

//__gcquiz_animation_duration
f32 func_80319040(s32 arg0){
    return 0.4f;
}

void func_80319050(void) {
    s32 i;

    D_803830E0 = malloc(0x74);
    D_803830E0->unkC = malloc(0x400);
    D_803830E0->unk16 = 0x14U;
    D_803830E0->unk17 = 0x1E;
    D_803830E0->unk20[0] = 0;
    D_803830E0->unk24[0] = gczoombox_new(func_80318FC0(0), 0, func_80319004(0), func_8031901C(0), func_80319E20);
    func_803184C8(D_803830E0->unk24[0], (f32)D_803830E0->unk16, 5, 2, func_80319040(0), func_80319028(0), 0);
    for(i = 1; i < 4; i++){
        D_803830E0->unk20[i] = 0;
        D_803830E0->unk24[i] = NULL;
    }
    func_803197AC(0);
}

void func_80319190(void) {
    s32 i;

    if (D_803830E0 != NULL) {
        free(D_803830E0->unkC);
        D_803830E0->unkC = NULL;
        for(i = 0; i < 4; i++){
            gczoombox_free(D_803830E0->unk24[i]);
            D_803830E0->unk24[i] = NULL;
        }
        free(D_803830E0);
        D_803830E0 = NULL;
    }
}

void func_80319214(Gfx **gfx, Mtx **mtx, Vtx **vtx) {
    s32 i;

    if (D_803830E0 != NULL) {
        for(i = 0; i < 4; i++){
            gczoombox_draw(D_803830E0->unk24[i], gfx, mtx, vtx);
        }
    }
}

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_91E10/func_803192A4.s")
#else
bool func_803192A4(enum question_type_e q_type, s32 q_indx, s32 arg2) {
    s32 sp60;
    s32 sp54;
    s32 sp50;
    s32 sp48;
    s32 sp44;
    s32 sp30;
    s32 sp2C;
    s32 temp_a1;
    s32 temp_a1_2;
    s32 temp_a2;
    s32 temp_a2_2;
    s32 temp_s0;
    s32 temp_s2;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v0_5;
    s32 temp_v0_7;
    s32 temp_v1;
    u8 *temp_s0_7;
    u8 temp_t0;
    u8 str_cnt;
    QuizQuestionBin *q_bin;
    QuizQuestionBin_Struct_1 *temp_s0_3;
    StringBin *temp_s0_4;
    u8 *temp_s0_5;
    s32 phi_v1;
    s32 phi_v1_2;
    s32 phi_v1_3;
    s32 phi_a3;
    s32 phi_a3_2;
    s32 phi_t0;
    s32 phi_a2;
    s32 phi_a3_3;
    s32 phi_a1;
    s32 phi_v1_4;
    s32 phi_a0;
    void *phi_s0;
    s32 phi_a0_2;
    s32 phi_a0_3;
    s32 phi_a1_2;
    s32 phi_a0_4;
    s32 phi_a0_5;

    temp_s0 = func_80318ED8(q_type) + q_indx;
    if (func_8031A3BC() != 0) {
        return 0;
    }
    if (func_8033BDAC(temp_s0, D_803830E0->unkC, 0x400) == 0) {
        free(D_803830E0->unkC);
        D_803830E0->unkC = (QuizQuestionBin *) assetcache_get(temp_s0);
    }
    q_bin = D_803830E0->unkC;
    sp50 = q_bin->unk2;
    phi_v1_4 = 0;
    if (q_bin->unk1 >= 2) {
        sp54 = q_bin->unk1;
        phi_v1_4 = func_80318F60(q_type, q_indx, arg2);
    }
    temp_s2 = phi_v1_4 + 1;
    phi_v1 = sp50 == 0;
    if (phi_v1 == 0) {
        sp54 = q_bin->unk1;
        phi_v1 = func_80318FB4(q_type) != 0;
    }
    phi_a0_2 = 0;
    phi_a0_3 = 0;
    if (phi_v1 != 0) {
        sp30 = q_bin->unk1 + sp50;
        sp2C = temp_s2 - 1;
        do {
            temp_v0 = randi2(0, sp30);
            sp2C = sp2C;
            sp48 = temp_v0 + 1;
        } while (temp_v0 == sp2C);
        do {
            temp_v0_2 = randi2(0, sp30);
            sp44 = temp_v0_2 + 1;
        } while (temp_v0_2 == sp2C || sp44 == sp48);
    } else {
        sp54 = q_bin->unk1;
        sp48 = randi2(0, sp50) + q_bin->unk1 + 1;
        phi_t0 = q_bin->unk1;
        do {
            sp44 = randi2(0, sp50) + sp54 + 1;
        } while (sp48 == sp44);
    }
    temp_s0_3 = (s32)q_bin +sizeof(QuizQuestionBin) + func_8031B5B0()*2;
    temp_s0_4 = (s32)D_803830E0->unkC + (temp_s0_3->unk0 + (temp_s0_3->unk1 << 8)) + 1;
    str_cnt = *((u8*)temp_s0_4 - 1);
    phi_a1_2 = 0;
    for(phi_a1 = 0; phi_a1 < 4; phi_a1++){
        D_803830E0->unk18[phi_a1] = 0;
    }

    for(phi_a1_2 = 0; phi_a1_2 < str_cnt; phi_a1_2++){
        temp_s0_5 = temp_s0_4 + 1;
        temp_v0_3 = temp_s0_4->cmd - 0x80;
        phi_a1_2 = 1;
        if ((temp_v0_3 == 0) || (temp_v0_3 == temp_s2) || (temp_v0_3 == sp48) || (temp_v0_3 == sp44)) {
            if (temp_v0_5 == 0) {
                sp60 = 0;
            } else if (temp_v0_5 == temp_s2) {
                sp60 = 1;
            } else if (temp_v0_5 == sp48) {
                sp60 = 2;
            } else if (temp_v0_5 == sp44) {
                sp60 = 3;
            }
        }
        D_803830E0->unk34.unk0[sp60][D_803830E0->unk18[sp60]] = temp_s0_5;
        D_803830E0->unk18[sp60]++;
        temp_s0_4 = (s32)temp_s0_5 + temp_s0_4->string_size;
    }
    return TRUE;
}
#endif


void func_803196D0(s32 arg0) {
    gczoombox_open(D_803830E0->unk24[arg0]);
    gczoombox_maximize(D_803830E0->unk24[arg0]);
    func_80318284(D_803830E0->unk24[arg0], D_803830E0->unk18[D_803830E0->unk1C[arg0]], D_803830E0->unk34.unk0[D_803830E0->unk1C[arg0]]);
}

//__gcquiz_set_box_highlight
void func_80319758(s32 indx, bool arg1){
    gczoombox_highlight(D_803830E0->unk24[indx], arg1);
    func_80318C48(D_803830E0->unk24[indx], arg1);
}

void func_803197AC(s32 arg0){
    s32 i;
    s32 j;

    switch(arg0){
        case 0: //803197F0
            D_803830E0->unk0 = 0;
            D_803830E0->unk1 = 0;
            D_803830E0->unk3 = 0;
            D_803830E0->unk8 = 0;
            D_803830E0->unk12 = -1;
            D_803830E0->unk14 = 0;
            D_803830E0->unk11 = -2;
            func_803184C8(D_803830E0->unk24[0], (f32) D_803830E0->unk16, 5, 2, func_80319040(0), func_80319028(0), 0);
            func_80318774(D_803830E0->unk24[0]);
            gczoombox_highlight(D_803830E0->unk24[0], 1);
            for(i = 0; i < 4; i++){
                D_803830E0->unk1C[i] = -1;
                for(j = 0; j < 4; j++){
                    D_803830E0->unk34.unk0[i][j] = 0;
                }
            }
            break;

        case 1: //80319910
            gczoombox_open(D_803830E0->unk24[0]);
            gczoombox_maximize(D_803830E0->unk24[0]);
            func_80318284(D_803830E0->unk24[0], D_803830E0->unk18[0], D_803830E0->unk34.unk0[0]);
            break;

        case 2: //8031994C
            if (D_803830E0->unk0 != -1) {
                func_80318E90();
                for(i = 1; i < 4; i++){
                    D_803830E0->unk24[i] = gczoombox_new(func_80318FC0(i), D_8036D940[D_803830E0->unk20[i]], func_80319004(i), func_8031901C(i), func_80319E20);
                    func_803184C8(D_803830E0->unk24[i], (f32)D_803830E0->unk17, 5, 2, func_80319040(i), func_80319028(i), 0);
                }
            } else {
                for(i = 1; i < 4; i++){
                    D_803830E0->unk24[i] = gczoombox_new(func_80318FC0(i), D_803830E0->unk20[i], 1, func_8031901C(i), func_80319E20);
                    func_803184C8(D_803830E0->unk24[i], (f32)D_803830E0->unk17, 5, 2, func_80319040(i), func_80319028(i), 0);
                }
            }
            timedFunc_set_1(0.0f, func_803197AC, 3);
            timedFunc_set_1(0.0f, func_803196D0, 1);
            timedFunc_set_1(0.2f, func_803196D0, 2);
            timedFunc_set_1(0.4f, func_803196D0, 3);
            break;

        case 3: //80319B78
        case 4: //80319B78
        case 5: //80319B78
            if(1){}
            break;

        case 6: //80319B84
            item_set(ITEM_0_HOURGLASS_TIMER, D_803830E0->unk3 * 60 - 1);
            item_set(ITEM_6_HOURGLASS, TRUE);
            D_803830E0->unk15 = 0;
            D_803830E0->unk13 = 1U;
            for(i = 1; i < 4; i++){
                func_80319758(i, (i == D_803830E0->unk13) ? TRUE : FALSE);
            }
            break;

        case 7: //80319C0C
            if (D_803830E0->unk0 != -1) {
                 D_803830E0->unk11 = (D_803830E0->unk12 == -1)                   ? -1
                                   : (D_803830E0->unk1C[D_803830E0->unk12] == 1) ? 1
                                   : 0;
            } else {
                D_803830E0->unk11 = (s8) D_803830E0->unk12;
            }
            if (D_803830E0->unk12 != -1) {
                for(i = 1; i < 4; i++){
                    if (i != D_803830E0->unk12) {
                        gczoombox_minimize(D_803830E0->unk24[i]);
                        gczoombox_close(D_803830E0->unk24[i]);
                    } else {
                        func_80318C48(D_803830E0->unk24[i], 0);
                    }
                }
            }
            timedFunc_set_1(1.0f, func_803197AC, 8);
            item_set(ITEM_6_HOURGLASS, FALSE);
            break;

        case 8: //80319CFC
            if (D_803830E0->unk0 != -1) {
                func_8025A70C((D_803830E0->unk11 == 1)? COMUSIC_2B_DING_B : COMUSIC_2C_BUZZER);
            } else {
                func_8025A70C(COMUSIC_2B_DING_B);
            }
            timedFunc_set_1(1.0f, func_803197AC, 9);
            break;

        case 9: //80319D6C
            func_8031A3E4();
            break;

        case 10: //80319D80
            if (D_803830E0->unk8 != NULL) {
                D_803830E0->unk8(D_803830E0->unk4, D_803830E0->unk11);
            }
            for(i = 1; i < 4; i++){
                gczoombox_free(D_803830E0->unk24[i]);
                D_803830E0->unk24[i] = NULL;
            }
            func_8025A55C(-1, 500, 10);
            break;
            
        default:
            break;
    }
    D_803830E0->unk10 = arg0;
}

void func_80319E20(s32 arg0, s32 arg1) {
    if (arg1 == 3) {
        if (arg0 == D_803830E0->unk20[0]) {
            if (D_803830E0->unk8 != NULL) {
                D_803830E0->unk8(D_803830E0->unk4, D_803830E0->unk11);
            }
        } else {
            func_803197AC(D_803830E0->unk10 + 1);
        }
    } else if (arg1 == 5) {
        D_803830E0->unk14++;
    }
}

void func_80319EA4(void) {
    s32 sp58[6];
    f32 sp4C[3];
    s32 phi_s0;
    f32 sp44;

    if(getGameMode() != GAME_MODE_3_NORMAL && func_802E4A08() == 0)
        return;
    
    if(D_803830E0 == NULL)
        return;

    func_8024E55C(0, sp58);
    func_8024E71C(0, sp4C);
    for(phi_s0 = 0; phi_s0 < 4; phi_s0++){
        func_80316EF4(D_803830E0->unk24[phi_s0]);
    }

    switch (D_803830E0->unk10) {
    case 1:
        if (func_8028EFC8() && (sp58[BUTTON_Z] == 1)) {
            sp44 = func_80319040(0);
            func_803184C8(D_803830E0->unk24[0], 100.0f, 2, 4, sp44, func_80319028(0), 0);
            return;
        }
        break;
    case 6:
        if (D_803830E0->unk15 > 0) {
            D_803830E0->unk15--;
        } else {
            if (sp4C[1] > 0.75) {
                if (D_803830E0->unk13 >= 2) {
                    func_80319758(D_803830E0->unk13, 0);
                    D_803830E0->unk13--;
                    func_80319758(D_803830E0->unk13, 1);
                    func_803160A8(D_803830E0->unk24[D_803830E0->unk13]);
                    D_803830E0->unk15 = 4U;
                }
            } else if (sp4C[1] < -0.75) {
                if (D_803830E0->unk13 < 3) {
                    func_80319758(D_803830E0->unk13, 0);
                    D_803830E0->unk13++;
                    func_80319758(D_803830E0->unk13, 1);
                    func_803160A8(D_803830E0->unk24[D_803830E0->unk13]);
                    D_803830E0->unk15 = 4U;
                }
            }
        }
        if ((sp58[BUTTON_START] == 1) || (item_empty(ITEM_0_HOURGLASS_TIMER))) {
            D_803830E0->unk12 = (u8) D_803830E0->unk13;
        }
        if ((s8) D_803830E0->unk12 != -1) {
            func_803197AC(7);
            return;
        }
        break;
    case 9:
        if (D_803830E0->unk14 == 4) {
            func_803197AC(0xA);
            return;
        }
        break;
    case 10:
        func_803197AC(0);
        break;
    }
}

bool func_8031A154(enum question_type_e q_type, s32 q_indx, s32 arg2, s32 arg3, s32 arg4, void (*arg5)(s32, s32)) {
    if (func_803192A4(q_type, q_indx, arg2) != 0) {
        D_803830E0->unk0 = q_type;
        D_803830E0->unk1 = q_indx;
        D_803830E0->unk2 = arg2;
        D_803830E0->unk3 = arg3;
        D_803830E0->unk4 = arg4;
        D_803830E0->unk8 = arg5;
        item_set(ITEM_6_HOURGLASS, 0);
        func_80318DA0(D_803830E0->unk1C, 1, 3, 1, 3);
        func_8025A55C(6000, 500, 10);
        func_803197AC(1);
        return TRUE;
    }
    return FALSE;
}

bool func_8031A22C(u8 *arg0, s8 *arg1, Struct_Core2_91E10_1 *arg2, s32 arg3, void (*arg4)(s32, s32)) {
    s32 temp_v0;
    s8 *temp_a2;
    s8 *temp_s0;
    s8 temp_a1;
    s8 temp_a1_2;
    u8 *phi_t0;
    s32 i;
    s8 *phi_a2;
    s32 *phi_a0;
    s32 phi_v1;
    s32 j;
    s8 *phi_s0;

    if (func_8031A3BC()) {
        return 0;
    }
    for(i = 0; i < 4; i++){
        D_803830E0->unk20[i] = arg0[i];
        D_803830E0->unk18[i] = arg1[i];
        for(j = 0; j < arg1[i]; j++){
            D_803830E0->unk34.unk0[i][j] = arg2->unk0[i][j];
        }
        D_803830E0->unk1C[i] = i;
    }
    if (D_803830E0->unk20[0] != 0) {
        func_803189C4(D_803830E0->unk24[0], D_803830E0->unk20[0]);
    }
    D_803830E0->unk0 = -1;
    D_803830E0->unk1 = -1;
    D_803830E0->unk2 = -1;
    D_803830E0->unk3 = (s8) arg3;
    D_803830E0->unk4 = 0;
    D_803830E0->unk8 = arg4;
    func_8025A55C(6000, 500, 10);
    func_803197AC(1);
    return TRUE;
}

void func_8031A388(u8 arg0, u8 arg1) {
    if (D_803830E0 != NULL) {
        D_803830E0->unk16 = arg0;
        D_803830E0->unk17 = arg1;
    }
}

bool func_8031A3BC(void){
    return (D_803830E0 != NULL)? D_803830E0->unk10 != 0: FALSE;
}

//gcquiz_close
void func_8031A3E4(void){
    s32 i;
    if(D_803830E0 != NULL){
        for(i = 0; i < 4; i++){
            gczoombox_minimize(D_803830E0->unk24[i]);
            gczoombox_close(D_803830E0->unk24[i]);
        }
    }
}

s32 func_8031A454(void){
    return 4;
}

//__gcquiz_get_type_count
s32 func_8031A45C(enum question_type_e question_type){
    return func_80318F1C(question_type) - func_80318ED8(question_type);
}

void func_8031A48C(void) {
    if ((D_803830E0 != NULL) && (D_803830E0->unk10 == 1)) {
        func_803197AC(2);
    }
}

//gcquiz_defrag
void func_8031A4CC(void) {
    s32 i;

    if (D_803830E0 != NULL) {
        for(i = 0; i < 4; i++){
            func_80318C0C(D_803830E0->unk24[i]);
            D_803830E0->unk24[i] = (gczoombox_t *)defrag(D_803830E0->unk24[i]);
        }

        if (func_8031A3BC() == 0) {
            D_803830E0->unkC = defrag(D_803830E0->unkC);
        }
        D_803830E0 = (Struct_Core2_91E10 *)defrag(D_803830E0);
    }
}

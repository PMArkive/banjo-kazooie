#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "core2/code_C9E70.h"

#define ARRLEN(x) ((s32)(sizeof(x) / sizeof(x[0])))

// ? FF question flags
#define FF_QNF_START (401)
#define FF_QNF_END   (496)
#define FF_QNF_CNT   (96)

struct FF_QuestionTypeInfo
{
    s16 startingFlagIdx;
    s16 totalQuestionCount;
};

enum FF_TileType
{
    FFTT_0_NIL,
    FFTT_1_BANJO,
    FFTT_2_PICTURE,
    FFTT_3_MUSIC,
    FFTT_4_MINIGAME,
    FFTT_5_GRUNTY,
    FFTT_6_SKULL,
    FFTT_7_JOKER
};

//this is states not actions
//actions occur when state is changed/set
enum FF_Action 
{
    FFA_0_NIL,
    FFA_1_UNK,
    FFA_2_ON_BOARD_FORGET_MOVES,
    FFA_3_TRIGGER_QUESTION,
    // clearing sound??
    FFA_4_UNK,
    FFA_5_FORGET_MOVES_2,
    FFA_6_TRIGGER_QUESTION_POST_EFFECTS,
    FFA_7_UNK,
    FFA_8_FURNACE_FUN_COMPLETE
};


/* .h */
void func_8038D670(enum FF_Action next_state);// ff_set_state
void func_8038C6BC(void);

/* extern */
extern void func_802FACA4(enum item_e);
extern void func_8028FA14(enum map_e, s32);
extern void func_803208C0(u32, int); // ff_isAsked_flag_set
extern int func_803207F0(u32); // ff_isAsked_flag_get

extern void func_8033F220(BKModel *model, s32 mesh_id, s16 [3]); //! $a2 type unk

extern s32  func_803203FC(s32);  // get volatile flag
extern void func_80295864(s32);  // set unlocked moves bitfield
extern s32  func_802957F0(void); // get unlocked moves bitfield

extern s32  func_80345FA0(s32); // item count get
extern void func_803463F4(s32, s32); // item count set

extern void func_80318614(gczoombox_t *, s32);
extern bool func_803183A4(gczoombox_t *, u8 *);
extern void func_8031841C(gczoombox_t *);
extern void func_803183FC(gczoombox_t *);

extern void func_8025AB44(s32, s32, s32);
extern void func_80250530(s32, u16, f32);

extern void func_8025A55C(s32, s32, s32);

extern void func_80324CFC(f32, s16, s16);
extern void func_803183EC(gczoombox_t *);
extern void func_8031840C(gczoombox_t *);

extern void *func_80309744(s32);
extern void  func_8029A95C(s32); // set transformation

//typedef migrated to "inlcude/core2/code_C9E70.h"
extern struct FF_StorageStruct *D_8037DCB8; 

/* .data */
extern Struct_lair_5ED0_0 D_80393760[FF_QNF_CNT - 1];
extern struct FF_QuestionTypeInfo FF_QuestionTypeInfoArr[5]; //D_80394340

extern struct {
    u8 unk0;
    // u8 pad1[1];
    s16 unk2;

    s16 unk4;
    u8 UNK_06;
    u8 UNK_07;

    f32 unk8;
} D_80394354[]; // unk size

// ?
extern struct {
    s16 unk0;
    s16 UNK_01;
} D_803945B8[];

extern struct {
    s16 unk0;
    s16 UNK_01;
} D_803945D0[];

/* .code */
// FF: get total number of questions per type
s16 func_8038C2C0(enum ff_question_type_e type)
{
    return FF_QuestionTypeInfoArr[type].totalQuestionCount;
}

// FF: clear isAsked flags for current question type
void func_8038C2D4(enum ff_question_type_e type)
{
    s32 i;

    for (i = 0; i < FF_QuestionTypeInfoArr[type].totalQuestionCount; i++)
        func_803208C0(FF_QuestionTypeInfoArr[type].startingFlagIdx + i, FALSE);
}

// FF: set isAsked flag for type and question
void func_8038C338(enum ff_question_type_e type, s32 questionIdx, int val)
{
    func_803208C0(FF_QuestionTypeInfoArr[type].startingFlagIdx + questionIdx, val);
}

// FF: get isAsked flag for type and question
int func_8038C370(enum ff_question_type_e type, s32 questionIdx)
{
    return func_803207F0(FF_QuestionTypeInfoArr[type].startingFlagIdx + questionIdx);
}

// i love stupid shit like this. these 3 lines of C compile into 150 lines of asm for type handling
void func_8038C3A0(u32 a0, BKVtxRef *a1, Vtx *a2, Struct_lair_5ED0_0 *a3)
{
    a2->v.cn[0] = a1->v.v.cn[0] * a3->unk10;
    a2->v.cn[1] = a1->v.v.cn[1] * a3->unk10;
    a2->v.cn[2] = a1->v.v.cn[2] * a3->unk10;
}

void *func_8038C5B8(s32 a0)
{
    Struct_lair_5ED0_0 *ptr;

    s32 v0;

    if (!a0)
        return NULL;

    v0  = FF_QNF_START;
    ptr = D_80393760;

    while (v0 < a0)
    {
        v0++;
        ptr++;
    }

    return ptr;
}

void func_8038C610(s32 a0)
{
    func_8034DEB4(func_8034C528(a0 + 200), -3000);
}

void func_8038C640(s32 a0, Struct_lair_5ED0_0 *a1)
{
    s32 i;

    for (i = 0; i < ARRLEN(a1->unk0); i++)
        if (a1->unk0[i])
            func_8038C610(a1->unk0[i]);

    a1->unk9 = 1;

    func_803208C0(a0 - FF_QNF_CNT, TRUE);
}

void func_8038C6BC(void)
{
    s32 s1, s3;

    Struct_lair_5ED0_0 *ptr;

    s3 = 1;

    for (ptr = D_80393760, s1 = FF_QNF_START; s1 != FF_QNF_END; s1++, ptr++)
    {
        ptr->unk9 = func_803207F0(s1 - FF_QNF_CNT) ? 1 : 0;

        if (ptr->unk9 == s3)
        {
            ptr->unk10 = 0.95f;
            func_8038C640(s1, ptr);
        }
        else
        {
            ptr->unk10 = 0.45f;
        }

        func_8033F220(D_8037DCB8->unk0, s1, &ptr->unkA);
    }
}

void func_8038C7A0(u32 a0, BKVtxRef *a1, Vtx *a2, Struct_lair_5ED0_0 *a3)
{
    a2->v.cn[0] = a1->v.v.cn[0] * D_8037DCB8->unk14;
    a2->v.cn[1] = a1->v.v.cn[1] * D_8037DCB8->unk14;
    a2->v.cn[2] = a1->v.v.cn[2] * D_8037DCB8->unk14;
}

void func_8038C9D0(void) {
    u8 temp_v0;
    Struct_lair_5ED0_0 *phi_s0;
    s32 phi_s1;

    for(phi_s0 = D_80393760, phi_s1 = 0x191; phi_s1 < 0x1F0; phi_s1++){
        if ((phi_s0->unk9 == 0) && (0.45 < phi_s0->unk10)) {
            phi_s0->unk10 = MAX(phi_s0->unk10 - 0.05, 0.45);
        } else if ((phi_s0->unk9 != 0) && (phi_s0->unk10 < 0.95)) {
            phi_s0->unk10 = MIN(phi_s0->unk10 + 0.05, 0.95);
        }
        func_8033F120(D_8037DCB8->unk0, phi_s1, func_8038C3A0, (s32) phi_s0);
        phi_s0++;
    }

    func_8033F120(D_8037DCB8->unk0, 0x1F1, func_8038C7A0, (s32) phi_s0);
    if ( !((D_8037DCB8->currFfMode != FFA_3_TRIGGER_QUESTION) && (D_8037DCB8->currFfMode != FFA_4_UNK)) 
         && (0.5 < D_8037DCB8->unk14)
    ) {
        D_8037DCB8->unk14 = MAX(D_8037DCB8->unk14 - 0.01 , 0.5);
    }
    else if ((D_8037DCB8->currFfMode != FFA_3_TRIGGER_QUESTION) && (D_8037DCB8->currFfMode != FFA_4_UNK) 
        &&(D_8037DCB8->unk14 < 1.0)
    ){
        D_8037DCB8->unk14 = MIN(D_8037DCB8->unk14 + 0.01 , 1.0);
    }
}

void func_8038CC10(void)
{
    if (D_8037DCB8->UNK_18)
        return;

    D_8037DCB8->UNK_18 = func_8030ED2C(0x1C, 3);
    func_8030DD90(D_8037DCB8->UNK_18, 0);
    sfxsource_setSampleRate(D_8037DCB8->UNK_18, 32760);
    func_8030DBB4(D_8037DCB8->UNK_18, 0.7f);
    func_8030E2C4(D_8037DCB8->UNK_18);
}

void func_8038CC9C(void)
{
    if (!D_8037DCB8->UNK_18)
        return;

    func_8030E394(D_8037DCB8->UNK_18);
    func_8030DA44(D_8037DCB8->UNK_18);
    D_8037DCB8->UNK_18 = 0;
}

void func_8038CCEC(void)
{
    free(D_8037DCB8->unk48);
    D_8037DCB8->unk48 = NULL;

    free(D_8037DCB8);
    D_8037DCB8 = NULL;

    func_80319190();
    func_80320818();
    func_802C5994();
}

void func_8038CD48(void)
{
    if (D_8037DCB8 == NULL)
        return;

    /**
     * //! EXPLOIT: FFM (Furnace Fun Moves)
     * Sets moves upon entering SM or MM from the Lair, FF asm code stays
     * latent until then
     */
    func_80295864(D_8037DCB8->unlockedMoves);

    D_8037DCB8->unk0 = NULL;

    gczoombox_free(D_8037DCB8->unk20);
    D_8037DCB8->unk20 = NULL;

    if (D_8037DCB8->UNK_18)
        func_8038CC9C();

    if (!func_803203FC(1) && !func_803203FC(2))
        func_803204E4(0, FALSE);

    if (!func_803203FC(0))
        func_8038CCEC();
}

void func_8038CE00(void)
{
    func_802BBC58(1);
    func_802BAE20(0);
}

void func_8038CE28(void)
{
    s32 i;

    func_80319050();
    D_8037DCB8 = malloc(sizeof(struct FF_StorageStruct));
    func_80320840();

    // dump currently unlocked moves to storage
    D_8037DCB8->unlockedMoves = func_802957F0();

    for (i = 0; i < ARRLEN(D_8037DCB8->unk3C); i++)
        D_8037DCB8->unk3C[i] = 0;

    // set joker card count to 0
    func_803463F4(ITEM_27_JOKER_CARD, func_80345FA0(0x27) * -1);

    D_8037DCB8->unk8     = 0;
    D_8037DCB8->unk4     = NULL;
    D_8037DCB8->unk20     = NULL;
    D_8037DCB8->unk14     = 1.f;
    D_8037DCB8->UNK_18     = 0;
    D_8037DCB8->currFfMode = 1;
    D_8037DCB8->unk48     = malloc(0x90);

    func_8038BC24();
}

void func_8038CF18(void)
{
    s32 i;

    struct FF_StorageStruct_48_sub *ptr;

    if (map_get() != MAP_8E_GL_FURNACE_FUN)
        return;

    D_8037DCB8->unk0 = func_80309744(0);
    D_8037DCB8->unk11 = 0;

    if (func_803203FC(2) && !func_803203FC(4))
    {
        func_80320818();
        func_80320840();

        for (i = 0; i < ARRLEN(D_8037DCB8->unk3C); i++)
            D_8037DCB8->unk3C[i] = 0;

        // set joker card count to 0
        func_803463F4(ITEM_27_JOKER_CARD, func_80345FA0(ITEM_27_JOKER_CARD) * -1);
    }

    func_8038C6BC();

    ptr = D_8037DCB8->unk48->data;

#if 0
    for (i = 0; i < ARRLEN(D_8037DCB8->unk48->data); i++)
        ptr[i].unk20 = 0;
#else
    // FIXME: weird
    ptr[1].unk20 = 0;
    ptr[2].unk20 = 0;
    ptr += 3;
    ptr[0].unk20 = 0;
    ptr[-3].unk20 = 0;
#endif

    func_8029A95C(TRANSFORM_1_BANJO);

    func_80347A14(0);

    if (func_803203FC(1))
    {
        levelSpecificFlags_clear();
        func_8038CE00();
        func_8038D670(FFA_4_UNK);
    }
    else
    {
        if (func_803203FC(2))
        {
            levelSpecificFlags_clear();
            func_8038D670(FFA_5_FORGET_MOVES_2);
        }
        else
        {
            if (func_8031FF1C(BKPROG_A6_FURNACE_FUN_COMPLETE))
                func_8038D670(FFA_8_FURNACE_FUN_COMPLETE);
            else
                func_8038D670(FFA_1_UNK);
        }
    }
}

s32 func_8038D0AC(s32 questionType, s32 a1)
{
    // :morphone: tf
    return 10;
}

void func_8038D0BC(s32 a0, s32 a1)
{
    if (a1 == 2)
    {
        func_80318614(D_8037DCB8->unk20, 1);
        func_803183A4(D_8037DCB8->unk20, "THIS IS A SLIGHTLY LONGER PIECE OF TEXT FOR THE QUIZ DIALOGS!");
    }

    if (a1 == 3)
    {
        func_80318614(D_8037DCB8->unk20, 0);
        func_8031841C(D_8037DCB8->unk20);
        func_803183FC(D_8037DCB8->unk20);
    }

    if (a1 == 6)
    {
        func_8038D670(FFA_4_UNK);
    }
}

void func_8038D16C(s32 a0, u16 a1)
{
    func_8025A6EC(a0, 0);
    func_8025AB44(a0, 28000, 500);
    func_80250530(func_8025ADD4(a0), a1, 0);
}

void func_8038D1BC(void)
{
    func_8025A55C(-1, 500, 9);
}

void func_8038D1E4(void)
{
    f32 cleanupDelay = -1.f;

    func_8025A55C(0, 500, 9);

    switch (D_80394354[D_8037DCB8->unkC].unk0)
    {
        case 0:
        {
            timed_playSfx(
                1.f,
                D_80394354[D_8037DCB8->unkC].unk2,
                D_80394354[D_8037DCB8->unkC].unk8,
                D_80394354[D_8037DCB8->unkC].unk4
            );

            cleanupDelay = 2.5f;

            break;
        }
        case 2:
        {
            D_8037DCB8->unk20 = gczoombox_new(
                -100,
                D_80394354[D_8037DCB8->unkC].unk2,
                0, 0, func_8038D0BC
            );
            func_80318614(D_8037DCB8->unk20, 0);
            func_803183EC(D_8037DCB8->unk20);
            func_8031840C(D_8037DCB8->unk20);

            break;
        }
        case 1:
        {
            func_80324CFC(
                1.f,
                D_80394354[D_8037DCB8->unkC].unk2,
                D_80394354[D_8037DCB8->unkC].unk4
            );

            cleanupDelay = D_80394354[D_8037DCB8->unkC].unk8;

            break;
        }
        case 3:
        {
            timedFunc_set_2(
                0.5f, (TFQM2)func_8038D16C,
                D_80394354[D_8037DCB8->unkC].unk2,
                D_80394354[D_8037DCB8->unkC].unk4
            );

            cleanupDelay = D_80394354[D_8037DCB8->unkC].unk8;

            break;
        }
    }

    if (cleanupDelay > 0.0) // f64
        timedFunc_set_1(cleanupDelay, (TFQM1)func_8038D670, FFA_4_UNK);
}

void func_8038D394(void)
{
    D_8037DCB8->unk12 = 1;
    func_802D5058(
        D_803945D0[D_8037DCB8->unkC].unk0,
        D_803945D0[D_8037DCB8->unkC].UNK_01,
        D_8037DCB8->unkD >= 9
    );
}

void func_8038D3F0(s32 a0, s32 a1)
{
    if (a1 == -2)
    {
        D_8037DCB8->unk12 = 0;

        if (D_8037DCB8->ffQuestionType == FFQT_2_SOUND)
            func_8038D1E4();
        else if (D_8037DCB8->ffQuestionType == FFQT_1_PICTURE)
            func_8038D394();
        else
            func_8038D670(FFA_4_UNK);
    }
    else
    {
        D_8037DCB8->unkF = a1;
        func_8038D670(FFA_6_TRIGGER_QUESTION_POST_EFFECTS);
    }
}

void func_8038D48C(void)
{
    func_8028F918(0);
    func_802BAE4C();
    func_802BC280();
}

void func_8038D4BC(void)
{
    func_803204E4(2, TRUE);
    func_802E4A70();

    // restore moves after a delay
    timedFunc_set_1(0.25f,
        func_80295864,
        D_8037DCB8->unlockedMoves
    );

    // trigger warp after a delay
    timedFunc_set_3(0.25f,
        (TFQM3)func_802E4078,
        D_803945B8[D_8037DCB8->unkC].unk0,
        D_803945B8[D_8037DCB8->unkC].UNK_01,
        1
    );
}

void func_8038D548(s32 a0)
{
    s32 s0;

    for (s0 = FF_QNF_START; s0 != FF_QNF_END; s0++)
        func_8038C610(s0);

    if (a0)
        func_8038C610(296);
}

void func_8038D5A0(void)
{
    s32 s0;
    Struct_lair_5ED0_0 *ptr = D_80393760;

    for (s0 = FF_QNF_START; s0 != FF_QNF_END; s0++, ptr++)
    {
        func_8038C610(s0);

        ptr->unk9 = 1;

        func_803208C0(s0 - FF_QNF_CNT, TRUE);
    }
}

s32 func_8038D60C(s32 a0)
{
    switch (a0)
    {
        // question bypass/replacement??

        case 405: return 400;
        case 413: return 401;
        case 417: return 402;
        case 460: return 403;
        case 479: return 404;
        default:
            return -1;
    }
}

// FF: process ff action
void func_8038D670(enum FF_Action next_state) {
    s32 pad3C;
    f32 sp30[3];

    switch(next_state){
        case FFA_1_UNK: //L8038D6A0
            if ((D_8037DCB8->currFfMode != FFA_5_FORGET_MOVES_2) && (D_8037DCB8->currFfMode != FFA_1_UNK)) {
                func_802FAD64(ITEM_14_HEALTH);
                func_802FAD64(ITEM_16_LIFE);
            }
            func_802FAD64(ITEM_27_JOKER_CARD);
            D_8037DCB8->unkF = -2;
            func_80295864(D_8037DCB8->unlockedMoves);
            func_80347A14(1);
            break;

        case FFA_2_ON_BOARD_FORGET_MOVES: //L8038D70C
            func_80295864(0);
            break;

        case FFA_3_TRIGGER_QUESTION: //L8038D720
            func_802FAD64(ITEM_14_HEALTH);
            func_802FAD64(ITEM_16_LIFE);
            D_8037DCB8->unk12 = 1;
            func_8030E6D4(SFX_12C_FF_QUESTION_START);
            func_8028F918(2);
            if (D_8037DCB8->ffQuestionType != FFQT_4_MINIGAME) {
                func_8038CE00();
                func_8031A154(D_8037DCB8->ffQuestionType, D_8037DCB8->unkD, D_8037DCB8->unkE, func_8038D0AC(D_8037DCB8->ffQuestionType, D_8037DCB8->unkC), 0, &func_8038D3F0);
            } else {
                func_8038D4BC();
            }
            break;

        case FFA_4_UNK: //L8038D7CC
            if (D_8037DCB8->ffQuestionType == FFQT_2_SOUND) {
                switch(D_80394354[D_8037DCB8->unkC].unk0){
                    case 3:
                        comusic_8025AB44(D_80394354[D_8037DCB8->unkC].unk2, 0, 0x1F4);
                        func_8025AABC(D_80394354[D_8037DCB8->unkC].unk2);
                        timedFunc_set_0(1.5f, func_8038D1BC);
                        break;
                    case 1: //L8038D870
                         if (func_8025AD7C(D_80394354[D_8037DCB8->unkC].unk2)) {
                            comusic_8025AB44(D_80394354[D_8037DCB8->unkC].unk2, 0, 0x1F4);
                            timedFunc_set_0(1.5f, func_8038D1BC);
                        } else {
                            func_8025A55C(-1, 0x1F4, 9);
                        }
                        func_8025AABC(D_80394354[D_8037DCB8->unkC].unk2);
                        break;
                    case 2: //L8038D908
                        gczoombox_free(D_8037DCB8->unk20);
                        D_8037DCB8->unk20 = 0;
                    default:
                        func_8025A55C(-1, 0x1F4, 9);
                        break;
                }//L8038D91C
            }
            func_8031A48C();
            break;

        case FFA_6_TRIGGER_QUESTION_POST_EFFECTS: //L8038D940
            func_8038D48C();
            if (D_8037DCB8->unkF == 1) {
                func_8038C640(D_8037DCB8->unk8, D_8037DCB8->unk4);
                func_8038C338(D_8037DCB8->ffQuestionType, D_8037DCB8->unkC, 1);
                D_8037DCB8->unk3C[D_8037DCB8->ffQuestionType]++;
                if (func_8038C2C0(D_8037DCB8->ffQuestionType) == D_8037DCB8->unk3C[D_8037DCB8->ffQuestionType]) {
                    D_8037DCB8->unk3C[D_8037DCB8->ffQuestionType] = 0;
                    func_8038C2D4(D_8037DCB8->ffQuestionType);
                }
                if (((s32) D_8037DCB8->unk4->unk8 >= 7) && (func_803207F0(func_8038D60C(D_8037DCB8->unk8)) == 0)) {
                    func_803463D4(ITEM_27_JOKER_CARD, D_8037DCB8->unk4->unk8 - 6);
                    func_803208C0(func_8038D60C(D_8037DCB8->unk8), TRUE);
                    func_80356540(0xA8);
                }
                if (D_8037DCB8->unk8 != 0x1EF) {
                    func_8030E6A4(SFX_126_AUDIENCE_BOOING, 1.0f, 0x7FF8);
                    if (D_8037DCB8->unk4->unk8 == FFTT_5_GRUNTY) {
                        func_80356540(0xA2);
                    }
                    if (func_803203FC(0xA0)) {
                        func_80356540(0xA1);
                    }
                    func_80356540(0xA0);
                }
            } else {
                if (D_8037DCB8->unk4->unk8 == FFTT_6_SKULL) {
                    func_80314AC8(0);
                    if (func_80305248(sp30, 0x377, D_8037DCB8->playerPosition)) {
                        func_8038D548(1);
                        func_8028F5F8(sp30);
                    } else {
                        func_8038D548(0);
                        func_8028F66C(0x13);
                    }
                    func_8030E6D4(SFX_125_AUDIENCE_CHEERING_2);
                } else {
                    if (D_8037DCB8->unkF != -2) {
                        if (item_getCount(ITEM_14_HEALTH) == 1) {
                            func_8038D548(0);
                        }
                        func_8028F530(0xD);
                    }
                    func_8030E6D4(SFX_124_AUDIENCE_CHEERING_1);
                }
                if (D_8037DCB8->unk4->unk8 >= 7) {
                    func_803208C0(func_8038D60C(D_8037DCB8->unk8), TRUE);
                    func_8038C640(D_8037DCB8->unk8, D_8037DCB8->unk4);
                }
                if (func_803203FC(0xA3)) {
                    func_80356540(0xA4);
                }
                func_80356540(0xA3);
            }
            break;

        case FFA_5_FORGET_MOVES_2: //L8038DBEC
            func_80295864(0);
            break;

        case FFA_8_FURNACE_FUN_COMPLETE: //L8038DC00
            if (func_8031FF1C(0xA6) == 0) {
                func_8025A55C(0, 0x1388, 0xB);
                func_8025AB00();
                func_8025A70C(JINGLE_DOOR_OF_GRUNTY_OPENED);
                func_80320004(0xA6, TRUE);
                func_803204E4(0, FALSE);
                func_803204E4(0xA6, TRUE);
                func_803204E4(0xA7, TRUE);
                next_state = 9;
                mapSpecificFlags_set(0xA, TRUE);
                func_8028F918(2);
                func_80347A14(0);
            }
            func_8038D5A0();
            func_80295864(D_8037DCB8->unlockedMoves);
            func_80347A14(1);
            func_802FAD64(ITEM_27_JOKER_CARD);
            break;
        default:
            break;

    }
    D_8037DCB8->currFfMode = next_state;
    if(D_8037DCB8);
}

// FF: get question type
enum ff_question_type_e func_8038DCD4(enum FF_TileType tile)
{
    switch (tile)
    {
        case FFTT_1_BANJO:    return FFQT_0_TEXT;
        case FFTT_2_PICTURE:  return FFQT_1_PICTURE;
        case FFTT_3_MUSIC:    return FFQT_2_SOUND;
        case FFTT_4_MINIGAME: return FFQT_4_MINIGAME;
        case FFTT_5_GRUNTY:   return FFQT_3_GRUNTY;
        default: // joker/skull squares
        {
            f32 rng = randf();

            if      (rng < 0.5)                return FFQT_0_TEXT;  // 50% chance
            else if (rng < 0.7)                return FFQT_1_PICTURE; // 20% chance of killing the run
            else if (rng < 0.8999999999999999) return FFQT_2_SOUND;   // 20% chance
            else                               return FFQT_3_GRUNTY;  // 10% chance
        }
    }
}

// FF: choose level (enum level_e) for picture question (?)
s32 func_8038DDAC(void)
{
    f32 rng = randf();

    if      (rng < 0.333333) return randi2(0, 4);
    else if (rng < 0.666666) return randi2(0, 4) + 4;
    else                     return randi2(0, 4) + 8; 
}

// FF: prepare random unasked question for type
void func_8038DE34(enum ff_question_type_e type)
{
    s32 randQuestionIdx;
    s32 rand;
    s32 tmp;

    D_8037DCB8->unkE = -1;

    if (type == FFQT_0_TEXT
     || type == FFQT_3_GRUNTY
     || type == FFQT_4_MINIGAME
     || type == FFQT_2_SOUND)
    {
        /**
         * Handle normal questions, fetch from specific question pool
         */

        do
        {
            // Generate random question index in the valid range for the type
            randQuestionIdx = randi2(0, func_8038C2C0(type));

            // Try again if question already asked
        } while (func_8038C370(type, randQuestionIdx));

        // Save to storage struct
        D_8037DCB8->unkC = randQuestionIdx;
        D_8037DCB8->unkD = D_8037DCB8->unkC;
    }
    else if (type == FFQT_1_PICTURE)
    {
        /**
         * Handle picture question (choosing a level, then choosing a pre-set angle within it)
         */

        D_8037DCB8->unkD = D_8037DCB8->unkC;

        do
        {
            rand = randi2(0, 10);
            tmp  = rand * 0xC;

            if (rand == 9)
            {
                D_8037DCB8->unkC = randi2(0, 10) + tmp;
                D_8037DCB8->unkD = D_8037DCB8->unkC - tmp + 9;
            }
            else
            {
                D_8037DCB8->unkC = func_8038DDAC() + tmp;
                D_8037DCB8->unkD = D_8037DCB8->unkC / 0xC;
            }

            // Try again if question already asked
        } while (func_8038C370(type, D_8037DCB8->unkC));
    }
}

// FF: play timer square sounds
void func_8038DFBC(void)
{
    if (D_8037DCB8->UNK_18)
        return;

    timed_playSfx(0.f,   0x2A, 0.5f, 32760);
    timed_playSfx(0.25f, 0x51, 0.5f, 32760);
    timed_playSfx(0.5f,  0x2A, 0.5f, 32760);
    timed_playSfx(0.75f, 0x51, 0.5f, 32760);

    timedFunc_set_0(1.0f, func_8038CC10);
    timedFunc_set_0(2.2f, func_8038CC9C);
}

void func_8038E070(void)
{
    func_8028F85C(&D_8037DCB8->playerPosition);
    func_8028F8A4(&D_8037DCB8->playerRotation);
    func_8028F918(2);
}

void func_8038E0B0(void) {
    s32 sp48[6]; //buttons
    s32 temp_v0;
    s32 sp3C[2]; //joystick
    s32 sp38;
    s32 sp28;

    if( (map_get() == MAP_8E_GL_FURNACE_FUN) 
        && (D_8037DCB8 != NULL) 
        && (D_8037DCB8->unk0 != NULL)
    ){
        func_80319EA4();
        func_8038C9D0();
        func_8024E55C(0, sp48);
        func_8024E60C(0, sp3C);
        if (D_8037DCB8->currFfMode < 3) {
            player_getPosition(D_8037DCB8->playerPosition);
            temp_v0 = func_8033F3E8(D_8037DCB8->unk0, D_8037DCB8->playerPosition, 0x191, 0x1F0);
            if ((temp_v0 != D_8037DCB8->unk8) && (D_8037DCB8->unk8 != 0)) {
                if (D_8037DCB8->unk4->unk9 == 2) {
                    D_8037DCB8->unk4->unk9 = 0U;
                }
            }
            D_8037DCB8->unk8 = temp_v0;
            D_8037DCB8->unk4 = func_8038C5B8(D_8037DCB8->unk8);
        }
        sp38 = MIN((D_8037DCB8->unk8 != 0) ? D_8037DCB8->unk4->unk8 : -1, FFTT_7_JOKER);
        if ((D_8037DCB8->unk8 != 0) && (D_8037DCB8->unk4->unk9 == 0) && func_8028F20C()) {
            D_8037DCB8->unk4->unk9 = 2;
            if (D_8037DCB8->unk11) {
                switch(sp38){
                    case FFTT_6_SKULL://L8038E26C
                        func_8025A70C(COMUSIC_7B_STEP_ON_SKULL_TILE);
                        break;

                    case FFTT_5_GRUNTY://L8038E280
                        func_8025A70C(COMUSIC_7C_STEP_ON_GRUNTY_TILE);
                        break;

                    case FFTT_1_BANJO://L8038E294
                        func_8025A70C(COMUSIC_7D_STEP_ON_BK_TILE);
                        break;

                    case FFTT_7_JOKER://L8038E2A8
                        func_8025A70C(COMUSIC_7E_STEP_ON_MINIGAME_TILE);
                        break;

                    case FFTT_3_MUSIC://L8038E2BC
                        func_8025A70C(COMUSIC_7F_STEP_ON_JOKER_TILE);
                        break;

                    case FFTT_2_PICTURE://L8038E2D0
                        func_8030E6D4(SFX_144_DOUBLE_CAMERA_CLICK);
                        break;

                    case FFTT_4_MINIGAME://L8038E2E4
                        func_8038DFBC();
                        break;
                }
                D_8037DCB8->unk11 = FALSE;
            }
        } else {
            D_8037DCB8->unk11 = TRUE;
        }
        
        if ((D_8037DCB8->currFfMode >= 2) && (D_8037DCB8->currFfMode < 8) 
            && (item_getCount(ITEM_27_JOKER_CARD) != 0)
        ) {
            func_802FACA4(ITEM_27_JOKER_CARD);
        }
        func_8028FA14(MAP_8E_GL_FURNACE_FUN, 2);
        switch(D_8037DCB8->currFfMode){
            case 1://L8038E388
                if(D_8037DCB8->unk8 != 0){
                    func_80347A14(0);
                    func_8038D670(2);
                }
                break;

            case 2://L8038E3AC
                if (D_8037DCB8->unk8 == 0) {
                    func_8038D670(1);
                    break;
                }
                func_802FACA4(0x14);
                func_802FACA4(0x16);
                if (sp38 != FFTT_0_NIL) {
                    sp28 = sp38 + 0x54;
                    if (!func_8031FF1C(sp28) && func_80311480(sp38 + 0x101E, 0, NULL, NULL, NULL, NULL)) {
                        func_80320004(sp28, TRUE);
                    }
                    if ((sp38 == FFTT_6_SKULL) && (item_getCount(ITEM_16_LIFE) == 1)) {
                        func_80356540(0xAB);
                    } else if (item_getCount(ITEM_14_HEALTH) == 1) {
                        func_80356540(0xAA);
                    }
                    if ((D_8037DCB8->unk4->unk9 == 2) && (func_8028ECAC() == 0)) {
                        if (func_8028EFEC() && (sp48[BUTTON_START] == 1)) {
                            func_803114D0();
                            player_getRotation(D_8037DCB8->playerRotation);
                            D_8037DCB8->ffQuestionType = func_8038DCD4(sp38);
                            func_8038DE34(D_8037DCB8->ffQuestionType);
                            func_8038D670(3);
                            return;
                        }
                        if (func_8028EFC8() && (sp48[BUTTON_Z] == 1)) {
                            if ((item_getCount(ITEM_27_JOKER_CARD) > 0) && (sp28 < 0x5B)) {
                                func_8038C640(D_8037DCB8->unk8, D_8037DCB8->unk4);
                                item_dec(ITEM_27_JOKER_CARD);
                                func_8030E6D4(SFX_3EA_UNKNOWN);
                                func_80356540(0xA9);
                                if (D_8037DCB8->unk8 == 0x1EF) {
                                    func_8038D670(8);
                                }
                            } else {
                                func_8025A70C(COMUSIC_2C_BUZZER);
                            }
                        }
                    }
                } else {
                    if (D_8037DCB8->unk4->unk9 == 2) {
                        func_8038C640(D_8037DCB8->unk8, D_8037DCB8->unk4);
                    }
                }
                break;

            case 3://L8038E5C8
                if ((D_8037DCB8->ffQuestionType == 2) && D_80394354[D_8037DCB8->unkC].unk0 == 2){
                    func_80316EF4(D_8037DCB8->unk20);
                }
                if ((D_8037DCB8->unk12 == 0) && func_8028EFC8() && (sp48[BUTTON_Z] == 1)) {
                    func_80324C58();
                    func_8038D670(4);
                }
                break;

            case 4://L8038E64C
                if (func_803203FC(1)) {
                    func_803204E4(1, 0);
                    func_8038E070();
                    func_8025A55C(6000, 500, 0xA);
                }
                break;

            case 5://L8038E684
                if (func_803203FC(2)) {
                    if (func_803203FC(4)) {
                        func_8038E070();
                        D_8037DCB8->unkF = func_803203FC(5);
                        func_8038D670(6);
                    } else {
                        func_8038D670(1);
                    }
                    func_803204E4(2, FALSE);
                    func_803204E4(4, FALSE);
                }
                break;

            case 6://L8038E6F8
                if ((D_8037DCB8->unk8 == 0x1EF) && ( D_8037DCB8->unkF == 1)) {
                    func_8038D670(8);
                }
                else{
                    func_8038D670(2);
                }
                break;

            case 9://L8038E738
                if (!func_8025AD7C(0x78)) {
                    mapSpecificFlags_set(6, TRUE);
                    func_8038D670(0);
                }
                break;
        }
    }
}

void func_8038E768(Gfx **dl, Mtx **m, Vtx **v)
{
    if (map_get() != MAP_8E_GL_FURNACE_FUN)
        return;

    func_80319214(dl, m, v);
    gczoombox_draw(D_8037DCB8->unk20, dl, m, v);
}

void func_8038E7C4(void)
{
    if (func_803203FC(0))
        return;

    func_8038CE28();
    func_803204E4(0, TRUE);
}

/**
 * // TODO: Fix this so it doesn't look like it was written while writhing in epileptic shock
 */
s32 func_8038E800(void)
{
    struct FF_StorageStruct_48_sub *ptr = D_8037DCB8->unk48->data;

#if 0
    //! doesn't match!
    {
        s32 i, j;

        for (i = 0; i < ARRLEN(D_8037DCB8->unk48->data); i++, ptr++)
        {
            if (ptr->unk20 == 0)
            {
                ptr->unk20 = 1;

                for (j = 0; j < ARRLEN(ptr->unk14); j++)
                    ptr->unk14[j] = 0xFF;

                for (j = 0; j < ARRLEN(ptr->unk0); j++)
                    ptr->unk0[j] = 0;

                ptr->unkC = 500;
                ptr->UNK_10 = 1000;

                return i;
            }
        }
    }
#else
    //! why does a loop not match but this bs does? grant kirkhope pls

    if (ptr->unk20 == 0)
    {
        ptr->unk14[0] = 0xFF;

        ptr->unkC    = 500;

        ptr->unk14[1] = 0xFF;
        ptr->unk14[2] = 0xFF;

        ptr->unk20    = 1;

        ptr->unk0[2] = 0;
        ptr->unk0[1] = 0;
        ptr->unk0[0] = 0;

        ptr->UNK_10    = 1000;

        return 0;
    }

    ptr++;

    if (ptr->unk20 == 0)
    {
        ptr->unkC    = 500;

        ptr->unk20    = 1;

        ptr->unk14[0] = 0xFF;
        ptr->unk14[1] = 0xFF;
        ptr->unk14[2] = 0xFF;

        ptr->unk0[2] = 0;
        ptr->unk0[1] = 0;
        ptr->unk0[0] = 0;

        ptr->UNK_10    = 1000;

        return 1;
    }

    ptr++;

    if (ptr->unk20 == 0)
    {
        ptr->unkC    = 500;

        ptr->unk20    = 1;

        ptr->unk14[0] = 0xFF;
        ptr->unk14[1] = 0xFF;
        ptr->unk14[2] = 0xFF;

        ptr->unk0[2] = 0;
        ptr->unk0[1] = 0;
        ptr->unk0[0] = 0;

        ptr->UNK_10    = 1000;

        return 2;
    }

    ptr++;

    if (ptr->unk20 == 0)
    {
        ptr->unk20    = 1;

        ptr->unk14[0] = 0xFF;
        ptr->unk14[1] = 0xFF;

        //! real match! yea just kidding
        do {ptr->unk14[2] = 0xFF; ptr->unk0[2] = 0; ptr->unk0[1] = 0; ptr->unk0[0] = 0; ptr->unkC = 500;
            ptr->UNK_10 = 1000;
        } while (0);

        return 3;
    }
#endif

    return -1;
}

void func_8038E968(s32 idx)
{
    if (D_8037DCB8 != NULL && D_8037DCB8->unk48 != NULL && idx >= 0)
        D_8037DCB8->unk48->data[idx].unk20 = 0;
}

void func_8038E9A4(s32 idx, f32 a1[3])
{
    if (D_8037DCB8 != NULL && D_8037DCB8->unk48 != NULL && idx >= 0)
    {
        D_8037DCB8->unk48->data[idx].unk0[0] = a1[0];
        D_8037DCB8->unk48->data[idx].unk0[1] = a1[1];
        D_8037DCB8->unk48->data[idx].unk0[2] = a1[2];
    }
}

void func_8038EA10(s32 idx, f32 a1[3])
{
    if (D_8037DCB8 != NULL && D_8037DCB8->unk48 != NULL && idx >= 0)
    {
        D_8037DCB8->unk48->data[idx].unkC = a1[0];
        D_8037DCB8->unk48->data[idx].UNK_10 = a1[1];
    }
}

void func_8038EA68(s32 idx, s32 a1[3])
{
    if (D_8037DCB8 != NULL && D_8037DCB8->unk48 != NULL && idx >= 0)
    {
        D_8037DCB8->unk48->data[idx].unk14[0] = a1[0];
        D_8037DCB8->unk48->data[idx].unk14[1] = a1[1];
        D_8037DCB8->unk48->data[idx].unk14[2] = a1[2];
    }
}

#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void func_80252CC4(f32[3], f32 [3], f32, f32[3]);
extern f32 func_8034A9D0(f32[4], f32);

/*.bss */
extern struct {
    s32 unk0;
    f32 unk4[3];
    f32 unk10[3];
    f32 unk1C;
    f32 unk20[3];
}D_803808C0;
extern f32 D_803808E0;

/* .code */
Vtx *vtxList_getVertices(BKVertexList *vtxList){
    return &vtxList->vtx_18[0];
}

//vtxList_getBoundingBox_i
void func_802EC458(BKVertexList *vtxList, s32 min[3], s32 max[3]){
    min[0] = vtxList->minCoord_0[0];
    min[1] = vtxList->minCoord_0[1];
    min[2] = vtxList->minCoord_0[2];

    max[0] = vtxList->maxCoord_6[0];
    max[1] = vtxList->maxCoord_6[1];
    max[2] = vtxList->maxCoord_6[2];
}

//vtxList_getBoundingBox_f
void func_802EC48C(BKVertexList *vtxList, f32 min[3], f32 max[3]){
    min[0] = (f32) vtxList->minCoord_0[0];
    min[1] = (f32) vtxList->minCoord_0[1];
    min[2] = (f32) vtxList->minCoord_0[2];

    max[0] = (f32) vtxList->maxCoord_6[0];
    max[1] = (f32) vtxList->maxCoord_6[1];
    max[2] = (f32) vtxList->maxCoord_6[2];
}

void func_802EC508(BKVertexList *arg0, f32 arg1[3], f32 arg2[3]) {
    Vtx *start_vtx;
    Vtx *end_vtx;
    Vtx *i_vtx;
    s32 i;
    f32 sp44[3];

    start_vtx = (Vtx *)(arg0 + 1);
    end_vtx = start_vtx + arg0->cnt_14;
    arg1[0] = (f32) start_vtx->v.ob[0];
    arg1[1] = (f32) start_vtx->v.ob[1];
    arg1[2] = (f32) start_vtx->v.ob[2];
    func_8025235C(arg1, arg1);
    arg2[0] = arg1[0];
    arg2[1] = arg1[1];
    arg2[2] = arg1[2];

    for( i_vtx = start_vtx + 1; i_vtx < end_vtx; i_vtx++){ 
        sp44[0] = (f32) i_vtx->v.ob[0];
        sp44[1] = (f32) i_vtx->v.ob[1];
        sp44[2] = (f32) i_vtx->v.ob[2];
        func_8025235C(sp44, sp44);

        for(i = 0; i < 3; i++){
            if( sp44[i] < arg1[i]){
                arg1[i] = sp44[i];
            }
            if( arg2[i] < sp44[i]){
                arg2[i] = sp44[i];
            }
        }
    }
}

void func_802EC680(BKVertexList *arg0, s32 arg1, f32 arg2[3], f32 arg3[3]) {
    Vtx *start_vtx;
    Vtx *end_vtx;
    Vtx *i_vtx;
    s32 i;
    f32 sp44[3];

    start_vtx = (Vtx*)(arg0 + 1);
    end_vtx = start_vtx + arg0->cnt_14;

    for(i_vtx = start_vtx; i_vtx < end_vtx; i_vtx++){
        sp44[0] = (f32) i_vtx->v.ob[0];
        sp44[1] = (f32) i_vtx->v.ob[1];
        sp44[2] = (f32) i_vtx->v.ob[2];
        func_8025235C(sp44, sp44);
        if ((i_vtx == start_vtx) || (sp44[1] < arg2[1])) {
            arg2[1] = sp44[1];
        }
    }

    arg3[1] = arg2[1]+ (f32) arg1;

    for(i_vtx = start_vtx; i_vtx < end_vtx; i_vtx++){
        sp44[0] = (f32) i_vtx->v.ob[0];
        sp44[1] = (f32) i_vtx->v.ob[1];
        sp44[2] = (f32) i_vtx->v.ob[2];
        func_8025235C(sp44, sp44);
        if (sp44[1] < arg3[1]) {

            arg2[0] = sp44[0];
            arg2[2] = sp44[2];
            
            arg3[0] = sp44[0];
            arg3[2] = sp44[2];
            break;
        } 
    }

    for(i_vtx = i_vtx + 1; i_vtx < end_vtx; i_vtx++) {
        sp44[0] = (f32) i_vtx->v.ob[0];
        sp44[1] = (f32) i_vtx->v.ob[1];
        sp44[2] = (f32) i_vtx->v.ob[2];
        func_8025235C(sp44, sp44);
        if (sp44[1] < arg3[1]) {
            for(i = 0; i < 3; i+=2){
                if (sp44[i] < arg2[i]) {
                    arg2[i] = sp44[i];
                }
                if (arg3[i] < sp44[i]) {
                    arg3[i] = sp44[i];
                }
            }
        }
    }
}

//vtxList_getBeginAndEndPtrs
void func_802EC8FC(BKVertexList *this, Vtx **vtx, Vtx **vtx_end){
    *vtx = &this->vtx_18[0];
    *vtx_end = &(*vtx)[this->cnt_14];
}

//vtxList_getVtxCount
s32 func_802EC918(BKVertexList *this){
    return this->cnt_14;
}

f32 func_802EC920(BKVertexList *this){
    return (f32)this->unk16;
}

void func_802EC930(BKVertexList *this, f32 arg1[3], f32 *arg2){
    arg1[0] = (f32)this->unkC[0];
    arg1[1] = (f32)this->unkC[1];
    arg1[2] = (f32)this->unkC[2];
    *arg2 = this->unk12; 
}

f32 func_802EC984(BKVertexList *this){
    return (f32)this->unk12;
}

void vtxList_free(BKVertexList *vtxList){
    free(vtxList);
}

BKVertexList *vtxList_clone(BKVertexList *vtxList){
    BKVertexList *out_v0;
    size_t list_size;
    
    list_size = sizeof(BKVertexList) + vtxList->cnt_14*sizeof(Vtx);
    out_v0 = (BKVertexList *) malloc(list_size);
    func_80254630(out_v0, vtxList, list_size);
    return out_v0;
}

// vtxList_copy_colors
void func_802EC9FC(BKVertexList *dst, BKVertexList *src) {
    Vtx *start_ptr;
    Vtx *end_ptr;
    Vtx *i_ptr;
    Vtx *src_ptr;
    s32 i;

    src_ptr = &src->vtx_18[0];
    start_ptr = &dst->vtx_18[0];
    end_ptr = start_ptr + dst->cnt_14;
    for(i_ptr = start_ptr; i_ptr < end_ptr; i_ptr++, src_ptr++){
            i_ptr->v.cn[0] = src_ptr->v.cn[0];
            i_ptr->v.cn[1] = src_ptr->v.cn[1];
            i_ptr->v.cn[2] = src_ptr->v.cn[2];
            i_ptr->v.cn[3] = src_ptr->v.cn[3];
    }
    osWritebackDCache(start_ptr, ((s32)(end_ptr - start_ptr)) * sizeof(Vtx));
}

void vtxList_tint(BKVertexList *dst, s32 target_color[3], f32 amount, BKVertexList *src) {
    Vtx *start_ptr;
    Vtx *end_ptr;
    Vtx *i_ptr;
    Vtx *src_ptr;
    s32 i;

    start_ptr = &dst->vtx_18[0];
    end_ptr = start_ptr + dst->cnt_14;
    for(i_ptr = start_ptr, src_ptr = &src->vtx_18[0]; i_ptr < end_ptr; i_ptr++, src_ptr++){
        for(i = 0; i < 3; i++){
            i_ptr->v.cn[i] = src_ptr->v.cn[i] + (target_color[i] - src_ptr->v.cn[i]) * amount;
        }
    }
    osWritebackDCache(start_ptr, ((s32)(end_ptr - start_ptr)) * sizeof(Vtx));
}

void func_802ECBD4(BKVertexList *dst, BKVertexList *src, f32 arg2[3], f32 arg3[3], f32 arg4[4]) {
    f32 sp74[3];
    f32 sp68[3];
    Vtx *dst_vtx;
    Vtx *start_vtx;
    Vtx *end_vtx;
    Vtx *src_vtx;
    f32 sp4C[3];
    s32 i;
    f32 temp_f0;
    s32 pad40;

    func_8024C5CC(sp74);
    func_8024C5A8(sp68);
    mlMtxIdent();
    func_80252CC4(arg2, arg3, 1.0f, NULL);
    func_8025235C(sp74, sp74);

    mlMtxIdent();
    func_80252CC4(NULL, arg3, 1.0f, NULL);
    func_8025235C(sp68, sp68);

    start_vtx = (Vtx *)(dst + 1);
    end_vtx = start_vtx + dst->cnt_14;
    for(dst_vtx = start_vtx, src_vtx = (Vtx *)(src + 1); dst_vtx < end_vtx; dst_vtx++, src_vtx++){
            sp4C[0] = dst_vtx->v.ob[0] - sp74[0];
            sp4C[1] = dst_vtx->v.ob[1] - sp74[1];
            sp4C[2] = dst_vtx->v.ob[2] - sp74[2];
            temp_f0 = sp68[0]*sp4C[0] + sp68[1]*sp4C[1] + sp68[2]*sp4C[2];
            temp_f0 = func_8034A9D0(arg4, temp_f0);
            for(i = 0; i < 3; i++){
                dst_vtx->v.cn[i] = temp_f0*src_vtx->v.cn[i];
            }
    }
    osWritebackDCache(start_vtx, (end_vtx - start_vtx) * sizeof(Vtx));
}

void func_802ECE30(BKVertexList *arg0) {
    Vtx *start_ptr;
    Vtx *end_ptr;
    Vtx *i_ptr;
    s32 i;

    start_ptr = &arg0->vtx_18[0];
    end_ptr = start_ptr + arg0->cnt_14;
    for(i_ptr = start_ptr; i_ptr < end_ptr; i_ptr++){
        for(i = 0; i < 3; i++){
            i_ptr->v.cn[i] = 0;
        }
        i_ptr->v.cn[0] = randf() * 255.0f;
    }
    osWritebackDCache(start_ptr, ((s32)(end_ptr - start_ptr)) * sizeof(Vtx));
}

void func_802ECF64(BKVertexList *arg0) {
    Vtx *start_ptr;
    Vtx *end_ptr;
    Vtx *i_ptr;
    s32 i;
    s32 phi_s0;

    start_ptr = &arg0->vtx_18[0];
    end_ptr = start_ptr + arg0->cnt_14;
    for(i_ptr = start_ptr; i_ptr < end_ptr; i_ptr++){
        for(i = 0; i < 3; i++){
            phi_s0 = i_ptr->v.cn[i];
            phi_s0 += randf()*21.0f - 10.0f;
            phi_s0 = (phi_s0 > 0xff) ? 0xff : phi_s0;
            phi_s0 =  (phi_s0 < 0) ? 0 : phi_s0;
            i_ptr->v.cn[i] = phi_s0;
        }
    }
    osWritebackDCache(start_ptr, ((s32)(end_ptr - start_ptr)) * sizeof(Vtx));
}

void vtxList_recolor(BKVertexList *arg0, s32 arg1[3]) {
    Vtx *start_ptr;
    Vtx *end_ptr;
    Vtx *i_ptr;
    s32 i;
    s32 phi_s0;

    start_ptr = &arg0->vtx_18[0];
    end_ptr = start_ptr + arg0->cnt_14;
    for(i_ptr = start_ptr; i_ptr < end_ptr; i_ptr++){
        for(i = 0; i < 3; i++){
            i_ptr->v.cn[i] = arg1[i];
        }
    }
    osWritebackDCache(start_ptr, ((s32)(end_ptr - start_ptr)) * sizeof(Vtx));
}

void func_802ED108(f32 arg0[3]){
    arg0[0] = D_803808C0.unk20[0];
    arg0[1] = D_803808C0.unk20[1];
    arg0[2] = D_803808C0.unk20[2];
}

s32 func_802ED12C(void){
    return  D_803808C0.unk0;
}

void func_802ED138(f32 arg0[3], f32 arg1[3], f32 arg2){
    D_803808C0.unk0 = 0;
    D_803808C0.unk10[0] = arg0[0];
    D_803808C0.unk10[1] = arg0[1];
    D_803808C0.unk10[2] = arg0[2];

    D_803808C0.unk4[0] = arg1[0];
    D_803808C0.unk4[1] = arg1[1];
    D_803808C0.unk4[2] = arg1[2];

    D_803808C0.unk1C = arg2;
}

void func_802ED180(BKVertexList *arg0, f32 arg1[3], f32 arg2[3], f32 arg3, f32 arg4[3]) {
    Vtx *phi_s0;
    f32 sp88[3];
    f32 sp7C[3];
    f32 sp70[3];
    Vtx *phi_s1;
    Vtx *start;
    f32 sp5C[3];
    f32 temp_f20;
    f32 temp_f0;


    mlMtxIdent();
    func_80252CC4(arg1, arg2, arg3, arg4);
    func_8025235C(sp88, D_803808C0.unk10);
    func_8025235C(sp7C, D_803808C0.unk4);
    temp_f20 = D_803808C0.unk1C / arg3;
    temp_f20 = temp_f20*temp_f20;
    start = (Vtx*)(arg0 + 1);
    phi_s1 = start + arg0->cnt_14;
    for(phi_s0 = start; phi_s0 < phi_s1; phi_s0++){
        sp70[0] = (f32) phi_s0->v.ob[0];
        sp70[1] = (f32) phi_s0->v.ob[1];
        sp70[2] = (f32) phi_s0->v.ob[2];

        sp5C[0] = sp70[0] - sp7C[0];
        sp5C[1] = sp70[1] - sp7C[1];
        sp5C[2] = sp70[2] - sp7C[2];

        temp_f0 = sp5C[0]*sp5C[0] + sp5C[1]*sp5C[1] + sp5C[2]*sp5C[2];
        if (!(temp_f20 <= temp_f0)) {
            D_803808C0.unk0 = 1;
            mlMtxIdent();
            func_80252C08(arg1, arg2, arg3, arg4);
            func_8025235C(D_803808C0.unk20, sp70);
        }
    }
}

void func_802ED340(BKVertexList *arg0, s32 indx, f32 dst[3]){
    Vtx *vtx;

    vtx = (s32)(arg0 + 1) + (indx * sizeof(Vtx));
    dst[0] = (f32) vtx->v.ob[0];
    dst[1] = (f32) vtx->v.ob[1];
    dst[2] = (f32) vtx->v.ob[2];
}

void func_802ED38C(BKVertexList *arg0, s32 indx, f32 arg2[3]){
    Vtx *vtx;
    s32 i;

    vtx = (s32)(arg0 + 1) + (indx * sizeof(Vtx));
    for(i = 0; i < 3; i++){
        vtx->v.ob[i] = (arg2[i] >= 0.0) ? arg2[i] + 0.5 :  arg2[i] - 0.5;
    }
}

#include <ultra64.h>
#include "functions.h"
#include "variables.h"

typedef struct{
    s16 map_id;
    s16 unk2;
    s16 unk4;
    s16 unk6;
}Struct_CCW_2270_0;

typedef struct{
    Struct_CCW_2270_0 *unk0;
    void *unk4;
    void *unk8;
}ActorLocal_CCW_2270;

void func_8038868C(Actor *this, s32 next_state);
Actor *func_803889AC(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);
void func_80388AA0(Actor *this);

/* .data */
extern Struct_CCW_2270_0 D_8038ECD0[];
extern ActorInfo D_8038ECE8 = { 0x1B1, 0x29E, 0x3E0, 0x0, NULL, func_80388AA0, func_80388AA0, func_803889AC, { 0x0, 0x0}, 0, 1.0f, { 0x0, 0x0, 0x0, 0x0}};

/* .rodata */

/* .code */
void func_80388660(ActorMarker* marker, s32 arg1) {
    func_8038868C(marker_getActor(marker), arg1);
}

void func_8038868C(Actor *this, s32 next_state) {
    ActorLocal_CCW_2270 *local;

    local = (ActorLocal_CCW_2270*)&this->local;

    if (next_state == 1) {
        func_80335924(this->unk148, 0xF4, 0.5f, 12.0f);
    }
    if (next_state == 2) {
        if (local->unk0->unk4 != 0) {
            func_80311480(local->unk0->unk4, 4, NULL, NULL, NULL, NULL);
        }
        func_80335924(this->unk148, 0xFC, 0.2f, 3.0f);
        func_80335A8C(this->unk148, 2);
        func_80335924(local->unk4, 0x100, 0.0f, 3.0f);
        func_80335A8C(local->unk4, 2);
        func_80324E38(0.0f, 3);
        timed_setCameraToNode(0.0f, (map_get() == MAP_44_CCW_SUMMER) ? 1 : 2);
        timed_playSfx(0.05f, SFX_84_GOBI_CRYING, 1.1f, 32000);
        timed_playSfx(0.8f, SFX_4B_GULPING, 0.8f, 28000);
        timed_playSfx(1.4f, SFX_4B_GULPING, 0.8f, 28000);
        timed_playSfx(2.0f, SFX_4B_GULPING, 0.8f, 28000);
        timedFunc_set_2(3.2f, (TFQM2) func_80388660, (s32) this->marker, 3);
    }
    if (next_state == 3) {
        func_803883F4();
    }
    if (next_state == 4) {
        func_80335924(this->unk148, 0x176, 0.5f, 4.0f);
        func_80335A8C(this->unk148, 2);
        func_80324E88(0.0f);
        func_80324E38(0.0f, 0);
    }
    if (next_state == 5) {
        if (local->unk0->unk6 != 0) {
            func_80311480((s32) local->unk0->unk6, 4, NULL, NULL, NULL, NULL);
        }
        func_80335924(this->unk148, 0xFD, 0.23f, 0.5f);
        timed_setCameraToNode(0.0f, 3);
    }
    if (next_state == 6) {
        func_80335924(this->unk148, 0xF8, 0.1f, 0.71f);
        func_80335A8C(this->unk148, 1);
    }
    if (next_state == 7) {
        func_80324E88(0.0f);
        func_80324E38(0.0f, 0);
        marker_despawn(this->marker);
    }
    
    this->state = next_state;
}


void func_8038894C(ActorMarker* marker, ActorMarker *other_marker) {
    Actor* actor = marker_getActor(marker);
    if (actor->state == 1) {
        actor_collisionOff(actor);
        timedFunc_set_2(0.5f, func_80388660, actor->marker, 2);
    }
}

Actor *func_803889AC(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx){
    Actor *this;
    ActorLocal_CCW_2270 *local;
    f32 sp2C[3];

    this = marker_getActor(marker);
    local = (ActorLocal_CCW_2270*)&this->local;

    if (this->state == 2) {
        sp2C[0] = this->pitch;
        sp2C[1] = this->yaw;
        sp2C[2] = this->roll;

        func_8033A238(func_803356A0(local->unk4, local));
        set_model_render_mode(2);
        func_803391A4(gfx, mtx, this->position, sp2C, 1.0f, NULL, local->unk8);
    }
    return func_80325888(marker, gfx, mtx, vtx);
}


void func_80388A70(Actor *this){
    ActorLocal_CCW_2270 *local = (ActorLocal_CCW_2270*)&this->local;

    func_80335874(local->unk4);
    assetcache_release(local->unk8);
}

void func_80388AA0(Actor *this) {
    ActorLocal_CCW_2270 *local;
    f32 sp48[3];
    f32 sp44;
    f32 sp40;

    local = (ActorLocal_CCW_2270*)&this->local;
    if (!this->unk16C_4) {
        this->unk16C_4 = TRUE;
        this->marker->propPtr->unk8_3 = TRUE;
        this->marker->unk30 = func_80388A70;
        this->unk138_24 = FALSE;
        local->unk4 = func_803358B4();
        local->unk8 = assetcache_get(0x3F3);
        marker_setCollisionScripts(this->marker, 0, func_8038894C, 0);
        if(!jiggyscore_isSpawned(JIGGY_4D_CCW_FLOWER)) {
            func_80320004(0xE5, 0);
        }
        local->unk0 = &D_8038ECD0[0];
        while((local->unk0->map_id != 0) && (map_get() != local->unk0->map_id)) {
            local->unk0++;
        }

        if( (map_get() == MAP_44_CCW_SUMMER) && func_8031FF1C(0xE3) && !func_8031FF1C(0xE4)) {
            func_8038868C(this, 1);
        } else if( (map_get() == MAP_45_CCW_AUTUMN) && func_8031FF1C(0xE4) && !func_8031FF1C(0xE5) ) {
            func_8038868C(this, 1);
        } else{
            marker_despawn(this->marker);
        }
        return;
    }
    if(this->state == 1){
        if (!this->unk138_24) {
            player_getPosition(sp48);
            if (func_80256064(this->position, sp48) < 600.0f) {
                if (local->unk0->unk2 != 0) {
                    func_80311480((s32) local->unk0->unk2, 4, NULL, NULL, NULL, NULL);
                }
                this->unk138_24 = TRUE;
            }
        }
    }

    if (this->state == 2) {
        func_80335A94(local->unk4, time_getDelta(), 1);
    }

    if(this->state == 3){
        if (!func_80388438()) {
            if (map_get() == 0x44) {
                func_8038868C(this, 4);
            } else {
                func_8038868C(this, 5);
            }
        }
    }

    if (this->state == 4) {
        if ((func_8033567C(this->unk148) == 0x176) && (func_80335794(this->unk148) > 0)) {
            func_80335924(this->unk148, 0x177, 0.1f, 4.0f);
            func_80335A8C(this->unk148, 1);
        }
        if (func_8033567C(this->unk148) == 0x177) {
            func_8033568C(this->unk148, &sp44, &sp40);
            if ((sp44 < 0.1) && (0.1 <= (f64) sp40)) {
                func_8030E8B4(0x664EA05E, this->position, 0x05DC01F4);
            }
            if ((sp44 < 0.8) && (0.8 <= (f64) sp40)) {
                func_8030E8B4(0x664EA05D, this->position, 0x05DC01F4);
            }
        }
    }

    if (this->state == 5){
        if(func_80335794(this->unk148) > 0) {
            func_8038868C(this, 6);
        }
    }

    if (this->state == 6) {
        func_80326224(this);
        if (0.99 < (f64) this->unk48) {
            func_8038868C(this, 7);
        }
    }
}


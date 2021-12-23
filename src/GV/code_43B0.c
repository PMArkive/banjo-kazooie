#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern f32 func_80309724(f32[3]);
void func_80329904(ActorMarker *, s32, void *);


void func_8038A948(Actor *this);
void func_8038A9C0(Actor *this);
Actor *func_8038A7A0(ActorMarker *this_marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);

/* .data */
ActorAnimationInfo D_80391000[] = {
    {0, 0.0f},
    {0xC9, 2.0f}
};

ActorInfo D_80391010 = { MARKER_A7_MAGIC_CARPET_1, ACTOR_119_MAGIC_CARPET_1, ASSET_3DC_MODEL_MAGIC_CARPET, 
    0x1, D_80391000, 
    func_8038A948, func_8038A9C0, func_8038A7A0, 
    { 0x9, 0xC4, 0x0, 0x0}, 0.0f, { 0x0, 0x0, 0x0, 0x0}
};


/* .code */
Actor *func_8038A7A0(ActorMarker *this_marker, Gfx **gfx, Mtx **mtx, Vtx **vtx){
    Actor * this;

    this = func_80325888(this_marker, gfx, mtx, vtx);
    
    if( this->velocity_y != 0.0f
        && this_marker->unk14_21
        && this->unk48 != this->unk1C[2]
    ){
        func_8033E73C(this->marker, 5, func_80329904);
        func_8033E3F0(0xa, this->marker->unk14_21);
        this->unk38_31++;
    }
    
    return this;
}

f32 func_8038A860(Actor *shadow, Actor* this){
    f32 out = 0.0f;
    
    if(this && shadow){
        out = this->scale * ml_map_f(this->position_y - shadow->position_y, 0.0f, 2200.0f, 1.2f, 0.35f);
    }
    
    return out;
}

void func_8038A8CC(ActorMarker *this_marker){
    Actor *this = marker_getActor(reinterpret_cast(ActorMarker *, this_marker));
    Actor *shadow = spawn_child_actor(ACTOR_122_MAGIC_CARPET_SHADOW, &this);
    s32 pad;

    this->unk100 = shadow->marker;
    shadow->position_y = func_80309724(this->position);
    shadow->unk1C[0] = func_8038A860(shadow, this);
    shadow->yaw = this->yaw;
    func_8032AA58(shadow, this->scale);
}

void func_8038A948(Actor *this){
    if(!this->initialized){
        this->initialized = TRUE;
        this->marker->propPtr->unk8_3 = TRUE;
        actor_collisionOff(this);
        func_802C3C88(func_8038A8CC, this->marker);
        this->velocity_y = 0.0f;
    }
}

void func_8038A9C0(Actor *this){
    Actor * sp24;
    if(!this->initialized){
        this->initialized = TRUE;
        this->velocity_y = 0.0f;
    }

    if(!this->unk16C_4){
        this->unk16C_4 = TRUE;
        this->marker->propPtr->unk8_3 = TRUE;
        actor_collisionOff(this);
        func_802C3C88(func_8038A8CC, this->marker);
        sp24 = func_80329980(this);
        this->unk1C[1] = this->unk48;
        this->pitch = 0.0f;
        this->yaw = 90.0f;
    }

    if(this->unk100)
        sp24 = func_80329980(this);

    if(this->velocity_y != 0.0f){
        func_80343DEC(this);
        if(this->unk48 < this->unk1C[1]){
            this->velocity_y = 0.0f;
        }
        this->unk1C[2] = this->unk1C[1];
        this->unk1C[1] = this->unk48;
        if(this->unk100 && sp24 && this->unk100->unk14_20 == MARKER_AF_MAGIC_CARPET_SHADOW){
            sp24->unk1C[0] = func_8038A860(sp24, this);
        }
    }
    this->pitch = 0.0f;
    this->yaw = 90.0f;
}

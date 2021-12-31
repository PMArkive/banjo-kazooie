#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "prop.h"

void func_8038D47C(Actor *this);

/* .data */
ActorAnimationInfo D_80391290[] = {
    {0, 0.0f},
    {0x144, 32000000.0f},
    {0x144, 0.95f},
    {0x145, 1.92f},
    {0x144, 32000000.0f}
};
ActorInfo D_803912B8 = { MARKER_F9_JINXY, ACTOR_1F7_JINXY, ASSET_422_MODEL_JINXY, 
    0x1, D_80391290, 
    func_8038D47C, func_80326224, func_80325888, 
    { 0x0, 0x0, 0x0, 0x0}, 0.0f, { 0x0, 0x0, 0x0, 0x0}
};

/* .code */
void func_8038D450(ActorMarker *this_marker){
    Actor *this = marker_getActor(this_marker);
    func_80328AC8(this, 3);
}

void func_8038D47C(Actor *this){
    f32 sp3C[3];
    s32 tmp_v0;
    this->marker->propPtr->unk8_3 = TRUE;
    actor_collisionOff(this);
    func_80287784(this->animctrl, 0);
    if(!this->initialized){
        if(!func_80304E24(0x331, this->spawn_position)){
            this->spawn_position_x = -2569.0f;
            this->spawn_position_y = 2997.0f;
            this->spawn_position_z = 5884.0f;
        }//L8038D4FC
        tmp_v0 = func_80304CAC(0x32f, this->spawn_position);
        if(!tmp_v0){
            this->unk1C_x = -1394.0f;
            this->unk1C_y = 2811.0f;
            this->unk1C_z = 6277.0f;
        }
        else{
            func_80304D68(tmp_v0, this->unk1C);
        }
        
        tmp_v0 = func_80304CAC(0x330, this->spawn_position);
        if(!tmp_v0){
            this->velocity_x = -1424.0f;
            this->velocity_y = 2811.0f;
            this->velocity_z = 5463.0f;
        }
        else{
            func_80304D68(tmp_v0, this->velocity);
        }

        this->initialized = TRUE;
    }//L8038D590

    if(!this->unk16C_4){
        mapSpecificFlags_set(0x10, 0);
        this->unk16C_4 = TRUE;
        if(func_803203FC(0xC1) && func_8031B4F4() == -3){
            timedFunc_set_1(1.5f, func_8038D450, reinterpret_cast(s32, this->marker));
        }
    }//L8038D5EC

    if(!mapSpecificFlags_get(0x14)){
        player_getPosition(sp3C);
        if(!func_8028ECAC()){
            if( func_80256064(sp3C, this->unk1C) < 100.0f || func_80256064(sp3C, this->velocity) < 100.0f){
                if(func_80311480(0xA7B, 0, NULL, NULL, NULL, NULL)){
                    mapSpecificFlags_set(0x14, 1);
                }
            }
        }
    }//L8038D688
    switch(this->state){
        case 1: //L8038D6C0
            if(!mapSpecificFlags_get(0xE) && mapSpecificFlags_get(0) + mapSpecificFlags_get(1) == 1){
                mapSpecificFlags_set(0xE, TRUE);
                func_80328AC8(this, 2);
                this->unk38_31 = 1;
            }
            else if(!mapSpecificFlags_get(0xF) && mapSpecificFlags_get(0) + mapSpecificFlags_get(1) == 2){
                mapSpecificFlags_set(0xF, TRUE);
                func_8028F918(2);
                func_80328AC8(this, 3);
                func_802BAFE4(0);
            }
            break;
        case 2: //L8038D78C
            if( actor_animationIsAt(this, 0.2f)
                || actor_animationIsAt(this, 0.45f)
                || actor_animationIsAt(this, 0.8f)
            ){
                FUNC_8030E624(SFX_D4_JINXIE_SNIFFLING_2, 0x3e8, 0x332);
            }
            if( actor_animationIsAt(this, 0.99f) ){
                if(--this->unk38_31 == 0){
                    func_80311480(0xA7C, 4, NULL, NULL, NULL, NULL);
                    mapSpecificFlags_set(0x14, TRUE);
                    func_80328AC8(this, 1);
                }
            }
            break;
        case 3: //L8038D84C
            if( actor_animationIsAt(this, 0.135f)
                || actor_animationIsAt(this, 0.3f)
            ){
                FUNC_8030E624(SFX_D4_JINXIE_SNIFFLING_2, 0x3e8, 0x332);
            }
            if(actor_animationIsAt(this, 0.63f)){
                FUNC_8030E624(SFX_D5_JINXIE_SNEEZING, 0x3ff, 0x332);
            }
            if(actor_animationIsAt(this, 0.83f)){
                FUNC_8030E624(SFX_D6_UGH, 0x3ff, 0x332);
            }
            if(actor_animationIsAt(this, 0.94f)){
                if(!func_803203FC(0xC1)){
                    mapSpecificFlags_set(0x10, 1);
                }
            }
            if(actor_animationIsAt(this, 0.99f)){
                func_80328AC8(this, 1);
            }
            break;
        case 4: //L8038D910
            break;
    }//L8038D910
}

#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_8038E3B0(Actor *this);

/* .data */
ActorAnimationInfo D_80391380[] = {
    {0, 0.0f},
    {0, 0.0f}
};
ActorInfo D_80391390 = { 0xFA, 0x1F8, 0x423,
    0x1, D_80391380,
    func_8038E3B0, func_80326224, func_80325888,
    0, 0x100, 0.0f, 0
};

ActorInfo D_803913B4 = { 0xFB, 0x1F9, 0x424,
    0x1, D_80391380,
    func_8038E3B0, func_80326224, func_80325888,
    0, 0x100, 0.0f, 0
};

/* .code */
void func_8038E3B0(Actor *this){
    this->marker->propPtr->unk8_3 = TRUE;
    actor_collisionOff(this);
}

#pragma once

#include "cocos2d.h"
#include "string"

USING_NS_CC;

class Creature: public Node {
public:
    Creature();
//    static Creature* create();
    
    void update(float delta);
    Size getSize();
    virtual bool onContact(PhysicsContact &contact) = 0;
protected:
    Sprite *sprite = nullptr;
    const int velocity = 300;
};

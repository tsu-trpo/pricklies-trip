#pragma once

#include "cocos2d.h"

USING_NS_CC;

class Creature: public Node {
public:
    Creature();
    static Creature* create();
    
    void update(float delta);
    Size getSize();

private:
    const int velocity = 300;
    Sprite *sprite = nullptr;
};

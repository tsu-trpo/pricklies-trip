#pragma once

#include "cocos2d.h"

USING_NS_CC;

class Creature: public Node {
public:
    void update(float delta);
    Size getSize();
    virtual void onContact() = 0;
    float getRadius();

protected:
    Sprite *sprite = nullptr;
    const int velocity = 300;
};


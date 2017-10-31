#pragma once
#include "cocos2d.h"

USING_NS_CC;

class Creature: public Node {
public:
    Creature();
    void update(float delta);
    Size getSize();
    CREATE_FUNC(Creature);

private:
    const int velocity = 300;
    Sprite * sprite;
};

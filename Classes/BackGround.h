#pragma once

#include "cocos2d.h"

USING_NS_CC;

class BackGround: public Node {
public:
    explicit BackGround(int number);
    
    void update(float delta);
    Size getSize();

private:
    const int velocity = 200;
    Sprite *sprite = nullptr;
};

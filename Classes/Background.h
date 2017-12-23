#pragma once

#include "cocos2d.h"

USING_NS_CC;

const int overlap = -10;

class Background: public Node {
public:
    explicit Background(int number);
    static Background* create(int number);

    void update(float delta);
    Size getSize();

private:
    const int velocity = 200;
    Sprite *sprite = nullptr;
};

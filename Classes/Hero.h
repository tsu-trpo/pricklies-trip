#pragma once

#include "cocos2d.h"
#include "HeroState.h"
#include "enum.h"
USING_NS_CC;

class HeroState;

class Hero: public Sprite {
public:
    static Hero* create();

    const HeroState* getState() const;
    void setState(HeroState* state);

    void input(Input input);
    void update(float delta) override;

private:
    HeroState* _state;

};

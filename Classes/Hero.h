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

    void onEnter() override;
    void onKeyPressed(EventKeyboard::KeyCode key, Event* event);
private:
    HeroState* _state;
};

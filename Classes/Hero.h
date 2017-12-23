#pragma once

#include <memory>
#include "cocos2d.h"
#include "HeroState.h"
USING_NS_CC;

class HeroState;

class Hero: public Sprite {
public:
    Hero();
    static Hero* create();

    void setState(HeroState* state);
    void onEnter() override;
    void onKeyPressed(EventKeyboard::KeyCode key, Event* event);
private:
    std::shared_ptr<HeroState> heroState;
};

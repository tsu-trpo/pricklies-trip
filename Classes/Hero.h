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

    void update(float delta) override;
    
    void onEnter() override;
    void onKeyPressed(EventKeyboard::KeyCode key, Event* event);

    float getVelocity();
    void setVelocity(float);
private:
    HeroState* _state;
    float _jumpVelocity;
};

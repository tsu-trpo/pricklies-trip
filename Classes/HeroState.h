#pragma once

#include "cocos2d.h"
#include "Hero.h"
#include "Input.h"
USING_NS_CC;

class RunState;
class JumpState;
class DieState;
class Hero;

class HeroState {
public:
    HeroState(Hero* heroPointer);
    virtual void handleInput(Input input) = 0;
    virtual void setAnimation() = 0;
protected:
    Hero* hero = nullptr;
};


class RunState: public HeroState {
public:
    using HeroState::HeroState;

    virtual void handleInput(Input input) override;
    virtual void setAnimation() override;
};


class JumpState: public HeroState {
public:
    using HeroState::HeroState;

    virtual void handleInput(Input input) override;
    virtual void setAnimation() override; 
};


class DieState: public HeroState {
public:
    using HeroState::HeroState;

    virtual void handleInput(Input input) override;
    virtual void setAnimation() override; 
};

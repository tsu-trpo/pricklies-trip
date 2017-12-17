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
    static RunState running;
    static JumpState jumping;
    static DieState dying;

    virtual void handleInput(Hero* hero, Input input) = 0;
    virtual void setAnimation(Hero* hero) = 0;
};


class RunState: public HeroState {
public:
    virtual void handleInput(Hero* hero, Input input);
    virtual void setAnimation(Hero* hero);
};


class JumpState: public HeroState {
public:
    virtual void handleInput(Hero* hero, Input input);
    virtual void setAnimation(Hero* hero); 
};


class DieState: public HeroState {
public:
    virtual void handleInput(Hero* hero, Input input);
    virtual void setAnimation(Hero* hero); 
};

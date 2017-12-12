#pragma once

#include "cocos2d.h"
#include "Hero.h"
#include "enum.h"
USING_NS_CC;

const float jumpDuration = 2;
const float deathDuration = 2;
const float runDelay = 0.2f;

class Run;
class Jump;
class Die;
class Hero;

class HeroState {
public:
    static Run running;
    static Jump jumping;
    static Die dying;

    virtual void handleInput(Hero* hero, Input input) = 0;
    virtual void setAnimation(Hero* hero) = 0;
};


class Run : public HeroState {
public:
    virtual void handleInput(Hero* hero, Input input);
    virtual void setAnimation(Hero* hero);
};


class Jump : public HeroState {
public:
    virtual void handleInput(Hero* hero, Input input);
    virtual void setAnimation(Hero* hero); 
};


class Die : public HeroState {
public:
    virtual void handleInput(Hero* hero, Input input);
    virtual void setAnimation(Hero* hero); 
};

#pragma once

#include "cocos2d.h"
#include "Hero.h"
#include "enum.h"
USING_NS_CC;

const float jumpOffset = 10.0f;
const float addAngle = 12.0f;

class Run;
class Jump;
class Fall;
class Die;
class Hero;

class HeroState {
public:
    static Run running;
    static Jump jumping;
    static Fall falling;
    static Die dying;

    virtual void handleInput(Hero* hero, Input input) = 0;
    virtual void handleUpdate(Hero* hero, float delta) = 0;
    virtual void setGraphics(Hero* hero) = 0;
};


class Run : public HeroState {
public:
    virtual void handleInput(Hero* hero, Input input);
    virtual void handleUpdate(Hero* hero, float delta);
    virtual void setGraphics(Hero* hero);
};


class Jump : public HeroState {
public:
    virtual void handleInput(Hero* hero, Input input);
    virtual void handleUpdate(Hero* hero, float delta);
    virtual void setGraphics(Hero* hero); 
};


class Fall : public HeroState {
public:
    virtual void handleInput(Hero* hero, Input input);
    virtual void handleUpdate(Hero* hero, float delta);
    virtual void setGraphics(Hero* hero);
};


class Die : public HeroState {
public:
    virtual void handleInput(Hero* hero, Input input);
    virtual void handleUpdate(Hero* hero, float delta);    
    virtual void setGraphics(Hero* hero); 
};

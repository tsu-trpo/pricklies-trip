#include "Hero.h"
USING_NS_CC;

Hero* Hero::create()
{
    Hero* hero = new (std::nothrow) Hero();
    hero->initWithFile("hedge_c_1.png");
    hero->autorelease();

    auto visibleSize = Director::getInstance()->getVisibleSize();
    hero->setPosition(Vec2(visibleSize.width / 4, visibleSize.height / 2.6));
    hero->setScale(0.8);
    hero->setState(&HeroState::running);
    hero->scheduleUpdate();

    return hero;
}

void Hero::setState(HeroState* state)
{
    _state = state;
    _state->setGraphics(this);
    CCLOG("New state %s", typeid(*_state).name());
}

const HeroState* Hero::getState() const
{
    return _state;
}

void Hero::input(Input input)
{
    _state->handleInput(this, input);
}

void Hero::update(float delta)
{
    _state->handleUpdate(this, delta);
}

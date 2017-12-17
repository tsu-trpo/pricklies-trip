#include "Hero.h"
#include "Input.h"
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

    return hero;
}

void Hero::setState(HeroState* state)
{
    _state = state;
    _state->setAnimation(this);
    CCLOG("New state %s", typeid(*_state).name());
}

const HeroState* Hero::getState() const
{
    return _state;
}

void Hero::onEnter()
{
    Sprite::onEnter();
    auto keyListener = EventListenerKeyboard::create();
    keyListener->onKeyPressed = CC_CALLBACK_2(Hero::onKeyPressed, this);
 
    _eventDispatcher->addEventListenerWithSceneGraphPriority(keyListener, this);
}
 
void Hero::onKeyPressed(EventKeyboard::KeyCode key, Event* event)
{
    if (key == EventKeyboard::KeyCode::KEY_UP_ARROW)     
        _state->handleInput(this,Input::JUMP_PRESS);
}

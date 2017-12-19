#include "Hero.h"
#include "Input.h"
USING_NS_CC;

Hero* Hero::create()
{
    Hero* hero = new Hero();
    hero->initWithFile("Creatures/Hedgehog/hedge_c_1.png");
    hero->autorelease();

    auto visibleSize = Director::getInstance()->getVisibleSize();
    hero->setPosition(Vec2(visibleSize.width / 4.0, visibleSize.height / 2.6));
    hero->setScale(0.8);
    RunState* running = new RunState(hero);
    hero->setState(running);

    return hero;
}

void Hero::setState(HeroState* state)
{
    heroState.reset(state);
    heroState->setAnimation();
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
    if (key == EventKeyboard::KeyCode::KEY_UP_ARROW) {    
        heroState->handleInput(Input::JUMP_PRESS);
    }
}

#include "HeroState.h"
#include <math.h>

Run  HeroState::running;
Jump HeroState::jumping;
Fall HeroState::falling;
Die  HeroState::dying;

void Run::handleInput(Hero* hero, Input input)
{
    if (input == Input::JUMP_PRESS) 
        hero->setState(&HeroState::jumping);
}

void Run::handleUpdate(Hero* hero, float delta) {}

void Run::setGraphics(Hero* hero)
{
    Vector<SpriteFrame*> frames;
    frames.reserve(2);
    auto position = hero->getTextureRect();
    frames.pushBack(SpriteFrame::create("hedge_c.png", position));        
    frames.pushBack(SpriteFrame::create("hedge_c_1.png", position));
    Animation* movingPaws = Animation::createWithSpriteFrames(frames, 0.2f);
    Animate* movePaws = Animate::create(movingPaws);
    hero->runAction(RepeatForever::create(movePaws));
}



void Jump::handleInput(Hero* hero, Input input) {}

void Jump::handleUpdate(Hero* hero, float delta)
{
    auto visibleSize = Director::getInstance()->getVisibleSize();
    float startY = visibleSize.height / 2.6; 
    float maxY = startY + hero->getContentSize().height * 0.7;
    float newOffset = hero->getVelocity() * delta - g * pow(delta,2.0) / 2;
    float newY = hero->getPosition().y + newOffset;
    hero->setVelocity(hero->getVelocity() - g * delta);
    if (newY <= maxY) { 
        auto move = MoveBy::create(delta, Vec2(0, newOffset));
        hero->runAction(move);
    }
    else {
        //hero->setVelocity(0);
        hero->setState(&HeroState::falling);
    }
}

void Jump::setGraphics(Hero* hero)
{
    hero->stopAllActions();
}



void Fall::handleInput(Hero* hero, Input input) {}
void Fall::handleUpdate(Hero* hero, float delta)
{
    auto visibleSize = Director::getInstance()->getVisibleSize();    
    float startY = visibleSize.height / 2.6;
    float newOffset = hero->getVelocity() * delta + g * pow(delta,2.0) / 2;
    float newY = hero->getPosition().y - newOffset;
    hero->setVelocity(hero->getVelocity() + g * delta);
    if (newY >= startY) {
        auto move = MoveBy::create(delta, Vec2(0, -newOffset));
        hero->runAction(move);
    }
    else {
        hero->setVelocity(170);
        hero->setState(&HeroState::running);
    }
}

void Fall::setGraphics(Hero* hero)
{
   hero->stopAllActions();
}


void Die::handleInput(Hero* hero, Input input) {}

void Die::handleUpdate(Hero* hero, float delta)
{
    float currentRotation = hero->getRotation();
    float newRotation = currentRotation + addAngle;
    if (newRotation <= 180.0f)
        hero->setRotation(newRotation);
}

void Die::setGraphics(Hero* hero)
{
    hero->stopAllActions();
    hero->setTexture("hedge_c.png");
}

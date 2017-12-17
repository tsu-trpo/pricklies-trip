#include "HeroState.h"

Run  HeroState::running;
Jump HeroState::jumping;
Die  HeroState::dying;

void Run::handleInput(Hero* hero, Input input)
{
    if (input == Input::JUMP_PRESS) { 
        hero->setState(&HeroState::jumping);
    }
}

void Run::setAnimation(Hero* hero)
{
    Vector<SpriteFrame*> frames;
    frames.reserve(2);
    auto position = hero->getTextureRect();
    frames.pushBack(SpriteFrame::create("hedge_c.png", position));        
    frames.pushBack(SpriteFrame::create("hedge_c_1.png", position));

    Animation* movingPaws = Animation::createWithSpriteFrames(frames, runDelay);
    Animate* movePaws = Animate::create(movingPaws);
    hero->runAction(RepeatForever::create(movePaws));
}

void Jump::handleInput(Hero* hero, Input input) 
{

}

void Jump::setAnimation(Hero* hero)
{
    hero->stopAllActions();

    float jumpHeight = hero->getContentSize().height * 0.9;
    auto jump = JumpBy::create(jumpDuration, Vec2(0,0), jumpHeight, 1);
    auto changeState = CallFunc::create([hero]() {
            hero->setState(&HeroState::running);        
        });
    hero->runAction(Sequence::create(jump, changeState, nullptr));
}

void Die::handleInput(Hero* hero, Input input) 
{

}

void Die::setAnimation(Hero* hero)
{
    hero->stopAllActions();
    hero->setTexture("died.png");
   
    float newY = -hero->getContentSize().height * 0.2;
    float jumpDeathHeight = hero->getContentSize().height * 0.8;

    auto rotate = RotateBy::create(deathDuration, 180);
    auto jump = JumpBy::create(2 * deathDuration, Vec2(0,newY), jumpDeathHeight, 1);
    auto ease = EaseElasticOut::create(jump);
    hero->runAction(Spawn::create(ease, rotate, nullptr));
}

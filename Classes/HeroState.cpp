#include "HeroState.h"

const float jumpDuration = 2.0;
const float deathDuration = 2.0;
const float runDelay = 0.2;

void RunState::handleInput(Hero* hero, Input input)
{
    if (input == Input::JUMP_PRESS) {
        JumpState* jumping = new JumpState();
        hero->setState(jumping);
    }
}

void RunState::setAnimation(Hero* hero)
{
    Vector<SpriteFrame*> frames;
    frames.reserve(2);
    auto position = hero->getTextureRect();
    frames.pushBack(SpriteFrame::create("Creatures/Hedgehog/hedge_c.png", position));        
    frames.pushBack(SpriteFrame::create("Creatures/Hedgehog/hedge_c_1.png", position));

    Animation* movingPaws = Animation::createWithSpriteFrames(frames, runDelay);
    Animate* movePaws = Animate::create(movingPaws);
    hero->runAction(RepeatForever::create(movePaws));
}

void JumpState::handleInput(Hero* hero, Input input) 
{

}

void JumpState::setAnimation(Hero* hero)
{
    hero->stopAllActions();

    float jumpHeight = hero->getContentSize().height * 0.9;
    auto jump = JumpBy::create(jumpDuration, Vec2(0,0), jumpHeight, 1);
    auto changeState = CallFunc::create([hero]() {
            RunState* running = new RunState();
            hero->setState(running);        
        });
    hero->runAction(Sequence::create(jump, changeState, nullptr));
}

void DieState::handleInput(Hero* hero, Input input) 
{

}

void DieState::setAnimation(Hero* hero)
{
    hero->stopAllActions();
    hero->setTexture("Creatures/Hedgehog/died.png");
   
    float newY = -hero->getContentSize().height * 0.2;
    float jumpDeathHeight = hero->getContentSize().height * 0.8;

    auto rotate = RotateBy::create(deathDuration, 180);
    auto jump = JumpBy::create(2 * deathDuration, Vec2(0,newY), jumpDeathHeight, 1);
    auto ease = EaseElasticOut::create(jump);
    hero->runAction(Spawn::create(ease, rotate, nullptr));
}

#pragma once

#include <memory>
#include "cocos2d.h"
#include "HeroState.h"

USING_NS_CC;

class HeroState;
//TODO: change base class to Node
class Hero: public Sprite {
public:
    Hero();
    static Hero* create();

    void setState(HeroState* state);
    void onEnter() override;
    void onKeyPressed(EventKeyboard::KeyCode key, Event* event);
    bool onContact(PhysicsContact &contact);

    PhysicsBody * getBody();
private:
    std::shared_ptr<HeroState> heroState;
    EventListenerPhysicsContact *contactListener = nullptr;
};


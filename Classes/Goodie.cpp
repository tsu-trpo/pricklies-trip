#include "Goodie.h"
#include "Events.h"

Goodie::Goodie()
{
    scheduleUpdate();
    
    const int numberOfpictures = 4;
    const int number = random(0, numberOfpictures - 1);

    std::string image = "Creatures/Goodies/" + std::to_string(number) + ".png";
    sprite = Sprite::create(image);
 
    setPhysicsBody(PhysicsBody::createCircle(30));
    this->_physicsBody->setDynamic(false);
    this->_physicsBody->setContactTestBitmask(0xFFFFFFFF);

    this->contactListener = EventListenerPhysicsContact::create();
    this->contactListener->onContactBegin = CC_CALLBACK_1(Goodie::onContact, this);
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(this->contactListener, this);

    addChild(sprite, 0);
}

Goodie *Goodie::create()
{
    Goodie *goodie = new Goodie();
    goodie->autorelease();

    return goodie;
}

bool Goodie::onContact(PhysicsContact &contact) 
{
    getEventDispatcher()->dispatchCustomEvent(eatGoodiesEvent);
    return true;
}

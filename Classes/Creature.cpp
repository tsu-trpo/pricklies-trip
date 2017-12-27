#include "Creature.h"

Creature::Creature()
{}

//Creature::Creature(std::string image)
//{   
//    sprite = Sprite::create(image);
//    
 //   scheduleUpdate();
    
///    setPhysicsBody(PhysicsBody::createCircle(30));
//    this->_physicsBody->setDynamic(false);
//    this->_physicsBody->setContactTestBitmask(0xFFFFFFFF);
//
//    this->contactListener = EventListenerPhysicsContact::create();
//    this->contactListener->onContactBegin = CC_CALLBACK_1(onContact, this);
//    this->getEventDispatcher()->addEventListener(this->contactListener, this);

//    addChild(sprite, 0);
//}

//Creature* Creature::create()
//{
//    Creature* creature = new Creature();
//    creature->autorelease();
//
//    return creature;
//}

Size Creature::getSize()
{
    Size creatureSize = sprite->getContentSize();
    return creatureSize;
}

void Creature::update(float delta)
{
    Point currentPosition = getPosition();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    Size creatureSize = getSize();
    
    bool isOutOfScreen = currentPosition.x < origin.x - creatureSize.width;
    if (!isOutOfScreen) {
        const int offset = - delta * velocity;
        
        setPositionX(currentPosition.x + offset);
    } else {
        runAction(RemoveSelf::create());
    }

    return;
}


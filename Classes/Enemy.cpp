#include "Enemy.h"
#include "Events.h"

Enemy * Enemy::create()
{
    Enemy * enemy = new Enemy();
    enemy->autorelease();

    return enemy;
}

Enemy::Enemy()
{ 
    scheduleUpdate();

    const int numberOfPictures = 2;
    const int number = random(0, numberOfPictures - 1);

    std::string image = "Creatures/Enemies/" + std::to_string(number) + ".png";
    sprite = Sprite::create(image);
    
    setPhysicsBody(PhysicsBody::createCircle(30));
    this->_physicsBody->setDynamic(false);
    this->_physicsBody->setContactTestBitmask(0xFFFFFFFF);

    this->contactListener = EventListenerPhysicsContact::create();
    this->contactListener->onContactBegin = CC_CALLBACK_1(Enemy::onContact, this);
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(this->contactListener, this);

    addChild(sprite, 0);
}

bool Enemy::onContact(PhysicsContact &contact)
{
    getEventDispatcher()->dispatchCustomEvent(dieEvent);
    return true;
}

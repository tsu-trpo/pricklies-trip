#include "Enemy.h"
#include "Events.h"
#include "Tag.h"

Enemy::Enemy()
{ 
    scheduleUpdate();

    const int numberOfPictures = 2;
    const int number = random(0, numberOfPictures - 1);

    std::string image = "Creatures/Enemies/" + std::to_string(number) + ".png";
    sprite = Sprite::create(image);

    setPhysicsBody(PhysicsBody::createCircle(getRadius()));
    _physicsBody->setDynamic(false);
    _physicsBody->setContactTestBitmask(0xFFFFFFFF);
    _physicsBody->setName(creatureTag);

    addChild(sprite, 0);
}

Enemy * Enemy::create()
{
    Enemy *enemy = new Enemy();
    enemy->autorelease();

    return enemy;
}

void Enemy::onContact()
{
    getEventDispatcher()->dispatchCustomEvent(dieEvent);
}


#include "Enemy.h"
#include "Events.h"
#include "Tag.h"
#include "Image.h"

Enemy::Enemy()
{ 
    scheduleUpdate();

    sprite = Sprite::create(creature::getEnemy());

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


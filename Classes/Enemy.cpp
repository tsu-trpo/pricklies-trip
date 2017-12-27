#include "Enemy.h"
#include "Events.h"

Enemy::Enemy()
{ 
    scheduleUpdate();

    const int numberOfPictures = 2;
    const int number = random(0, numberOfPictures - 1);

    std::string image = "Creatures/Enemies/" + std::to_string(number) + ".png";
    sprite = Sprite::create(image);
    
    int roughRadius = 30;
    setPhysicsBody(PhysicsBody::createCircle(roughRadius));
    _physicsBody->setDynamic(false);
    _physicsBody->setContactTestBitmask(0xFFFFFFFF);

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


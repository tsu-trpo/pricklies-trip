#include "Goodie.h"
#include "Events.h"

Goodie::Goodie()
{
    scheduleUpdate();

    const int numberOfpictures = 4;
    const int number = random(0, numberOfpictures - 1);

    std::string image = "Creatures/Goodies/" + std::to_string(number) + ".png";
    sprite = Sprite::create(image);

    int roughRadius = getRadius();
    setPhysicsBody(PhysicsBody::createCircle(roughRadius));
    _physicsBody->setDynamic(false);
    _physicsBody->setContactTestBitmask(0xFFFFFFFF);

    addChild(sprite, 0);
}

Goodie * Goodie::create()
{
    Goodie *goodie = new Goodie();
    goodie->autorelease();

    return goodie;
}

float Goodie::getRadius()
{
    float width = sprite->getContentSize().width;
    float height = sprite->getContentSize().height;

    float radius = width > height ? height : width;

    return radius / 2;
}

void Goodie::onContact()
{
    getEventDispatcher()->dispatchCustomEvent(eatGoodiesEvent);
}


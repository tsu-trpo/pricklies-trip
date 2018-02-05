#include "Goodie.h"
#include "Events.h"
#include "Tag.h"

Goodie::Goodie()
{
    scheduleUpdate();

    const int numberOfpictures = 4;
    const int number = random(0, numberOfpictures - 1);

    std::string image = "Creatures/Goodies/" + std::to_string(number) + ".png";
    sprite = Sprite::create(image);

    setPhysicsBody(PhysicsBody::createCircle(getRadius()));
    _physicsBody->setDynamic(false);
    _physicsBody->setContactTestBitmask(0xFFFFFFFF);
    _physicsBody->setName(creatureTag);

    addChild(sprite, 0);
}

Goodie * Goodie::create()
{
    Goodie *goodie = new Goodie();
    goodie->autorelease();

    return goodie;
}

void Goodie::onContact()
{
    getEventDispatcher()->dispatchCustomEvent(eatGoodiesEvent);
}


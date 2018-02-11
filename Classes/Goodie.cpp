#include "Goodie.h"
#include "Events.h"
#include "Tag.h"
#include "Image.h"

Goodie::Goodie()
{
    scheduleUpdate();

    sprite = Sprite::create(image::creature::getGoodie());

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


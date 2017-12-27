#include "Creature.h"

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


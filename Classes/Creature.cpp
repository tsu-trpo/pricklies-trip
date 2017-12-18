#include "Creature.h"

Creature::Creature()
{
    scheduleUpdate();
    
    const int numberOfPictures = 5;
    const int number = random(0, numberOfPictures);
    std::string image = "Creatures/" + std::to_string(number) + ".png";
    sprite = Sprite::create(image);
    addChild(sprite, 0);
}

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

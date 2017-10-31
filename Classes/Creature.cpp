#include "Creature.h"

Creature::Creature()
{
    const int numberOfPictures = 5;
    const int number = random(0, numberOfPictures);
    std::string image = "Creatures/" + std::to_string(number) + ".png";
    sprite = Sprite::create(image);
    this->addChild(sprite);
}

Size Creature::getSize()
{
    Size creatureSize = this->sprite->getContentSize();
    return creatureSize;
}

void Creature::update(float delta)
{
    Point currentPosition = this->getPosition();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    Size creatureSize = this->getSize();
    
    if (currentPosition.x > origin.x - creatureSize.width) {
        const int offset = -delta * velocity;
       
        auto move = MoveBy::create(delta, Vec2(offset, 0));
        this->runAction(move); 
    }
    else {
        this->runAction(RemoveSelf::create());
    }

    return;
}

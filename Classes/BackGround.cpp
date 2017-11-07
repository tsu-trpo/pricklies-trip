#include "BackGround.h"

BackGround::BackGround(int number)
{
    scheduleUpdate();
    
    sprite = Sprite::create("back-0" + std::to_string(number) + ".png");
    addChild(sprite, -1);
}

Size BackGround::getSize()
{
    Size backSize = sprite->getContentSize();
    return backSize;
}

void BackGround::update(float delta)
{
    Point currentPosition = getPosition();
    
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    Size backSize = getSize();
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    
    bool isOutOfScreen = currentPosition.x + backSize.width < origin.x;
    
    if (!isOutOfScreen) {
        const int offset = -delta * velocity;
        setPositionX(currentPosition.x + offset);
    } else {
        const int overlap = -20;
        setPositionX(currentPosition.x + 2 * backSize.width + overlap);
    }
}

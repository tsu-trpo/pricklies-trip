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
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    bool isOutOfScreen = getPosition().x + getSize().width < origin.x;
    
    if (!isOutOfScreen) {
        const int offset = -delta * velocity;
        setPositionX(getPosition().x + offset);
    } else {
        //константу overlap домножаем на 2, так как при перемещении первой из
        //двух картинок образуется щель, которую нужно закрыть
        setPositionX(getPosition().x + 2 * getSize().width + 2 * overlap);
    }
}

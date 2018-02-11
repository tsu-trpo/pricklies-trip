#include "Background.h"
#include "Image.h"

Background::Background(int number)
{
    scheduleUpdate();
    
    sprite = Sprite::create(image::background::get(number));
    addChild(sprite, -1);
}

Background* Background::create(int number)
{
    Background* background = new Background(number);
    background->autorelease();

    return background;
}

Size Background::getSize()
{
    Size backgroundSize = sprite->getContentSize();
    return backgroundSize;
}

void Background::update(float delta)
{
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    bool isOutOfScreen = getPosition().x + getSize().width < origin.x;
    
    if (!isOutOfScreen) {
        const int offset = -delta * velocity;
        setPositionX(getPosition().x + offset);
    } else {
        double screenOffset = getSize().width + overlap;
        setPositionX(getPosition().x + 2 * screenOffset);
    }
}

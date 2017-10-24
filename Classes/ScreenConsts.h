#pragma once

USING_NS_CC;

inline Vec2 getLeftUpCorner()
{
    Vec2 visibleOrigin = Director::getInstance()->getVisibleOrigin();
    Size visibleSize = Director::getInstance()->getVisibleSize();
    return Vec2(visibleOrigin.x, visibleOrigin.y + visibleSize.height);
}

inline Vec2 getLeftDownCorner()
{
    Vec2 visibleOrigin = Director::getInstance()->getVisibleOrigin();
    return Vec2(visibleOrigin.x, visibleOrigin.y);
}

inline Vec2 getRightUpCorner()
{
    Vec2 visibleOrigin = Director::getInstance()->getVisibleOrigin();
    Size visibleSize = Director::getInstance()->getVisibleSize();
    return Vec2(visibleOrigin.x + visibleSize.width, visibleOrigin.y + visibleSize.height);
}


inline Vec2 getRightDownCorner()
{
    Vec2 visibleOrigin = Director::getInstance()->getVisibleOrigin();
    Size visibleSize = Director::getInstance()->getVisibleSize();
    return Vec2(visibleOrigin.x + visibleSize.width, visibleOrigin.y);
}


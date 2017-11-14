#include "BackGroundController.h"
#include "BackGround.h"

BackGroundController::BackGroundController(Node &backgroundParent): startPoint{backgroundParent}
{
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    Size visibleSize = Director::getInstance()->getVisibleSize();
    
    BackGround *backOne = new BackGround(1);

    Size backSize = backOne->getSize();

    backOne->setAnchorPoint(Vec2(0, 0.5));

    Point positionOne(origin.x,
                      origin.y + visibleSize.height / 2);

    backOne->setPosition(positionOne);
    startPoint.addChild(backOne,-1);

    BackGround *backTwo = new BackGround(2);
    backTwo->setAnchorPoint(Vec2(0, 0.5));
    
    const int overlap = -10;

    Point positionTwo(origin.x + backSize.width + overlap,
                      origin.y + visibleSize.height / 2);

    backTwo->setPosition(positionTwo);
    startPoint.addChild(backTwo,-1);
}

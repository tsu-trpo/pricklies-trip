#include "BackGroundController.h"
#include "BackGround.h"

BackGroundController::BackGroundController(Node &creatureParent): spawnPoint{creatureParent}
{
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    Size visibleSize = Director::getInstance()->getVisibleSize();
    
    BackGround *backOne = new BackGround(1);

    Size backSize = backOne->getSize();

    backOne->setAnchorPoint(Vec2(0, 0.5));

    Point positionOne(origin.x,
                      origin.y + visibleSize.height / 2);

    backOne->setPosition(positionOne);
    spawnPoint.addChild(backOne,-1);

    BackGround *backTwo = new BackGround(2);

    backTwo->setAnchorPoint(Vec2(0, 0.5));

    Point positionTwo(origin.x + backSize.width - 10,
                      origin.y + visibleSize.height / 2);

    backTwo->setPosition(positionTwo);
    spawnPoint.addChild(backTwo,-1);
}
//объединить повторяющийся код



#include "BackGroundController.h"
#include "BackGround.h"

BackGroundController::BackGroundController(Node &backgroundParent): startPoint{backgroundParent}
{
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    Size visibleSize = Director::getInstance()->getVisibleSize();
    
    for (int i=0; i<2; i++) {
        BackGround *back = new BackGround(i+1);
        Size backSize = back->getSize();
        back->setAnchorPoint(Vec2(0, 0.5));
        Point position(origin.x + backSize.width * i + overlap * i,
                       origin.y + visibleSize.height / 2);
        back->setPosition(position);
        startPoint.addChild(back,-1);
    }
}

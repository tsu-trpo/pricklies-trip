#include "BackgroundController.h"
#include "Background.h"

BackgroundController::BackgroundController(Node &backgroundParent): startPoint{backgroundParent}
{
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    Size visibleSize = Director::getInstance()->getVisibleSize();
    
    for (int i = 0; i < 2; i++) {
        Background *background = new Background(i + 1);
        Size backgroundSize = background->getSize();
        background->setAnchorPoint(Vec2(0, 0.5));
        Point position(origin.x + backgroundSize.width * i + overlap * i,
                       origin.y + visibleSize.height / 2);
        background->setPosition(position);
        startPoint.addChild(background, -1);
    }
}

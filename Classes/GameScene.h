#pragma once

#include "cocos2d.h"

USING_NS_CC;

class GameScene : public cocos2d::Scene {
public:
    static cocos2d::Scene* createScene();

    virtual bool init() override;
    void addEventListener();
    
    CREATE_FUNC(GameScene);
};

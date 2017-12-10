#pragma once

#include "cocos2d.h"
#include "Hero.h"
#include "enum.h"
USING_NS_CC;

class GameScene : public cocos2d::Scene {
public:
    static cocos2d::Scene* createScene();

    virtual bool init() override;

    CREATE_FUNC(GameScene);
    
    void initKeyboard();
    void onKeyPressed(EventKeyboard::KeyCode key, Event* event);

private:
    Hero* hedgehog;
};

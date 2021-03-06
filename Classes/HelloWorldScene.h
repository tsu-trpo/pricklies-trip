#pragma once

#include "cocos2d.h"

class HelloWorld : public cocos2d::Scene {
public:
    static cocos2d::Scene * createScene();
    
    virtual bool init();
    void menuCloseCallback(cocos2d::Ref *pSender);
    CREATE_FUNC(HelloWorld);

private:
    void goToGameScene(cocos2d::Ref *sender);
};

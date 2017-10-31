#pragma once

#include "Respawner.h"
#include "cocos2d.h"

class GameScene : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init() override;

    void displayScore(unsigned int score);
    
    void update(float delta);
    CREATE_FUNC(GameScene);
private:
    unsigned int score = 0;
    cocos2d::Label *scoreLabel = nullptr;
};

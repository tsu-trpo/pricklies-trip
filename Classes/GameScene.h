#pragma once

#include "cocos2d.h"

class GameScene : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    void displayScore(unsigned int);
    // implement the "static create()" method manually
    CREATE_FUNC(GameScene);
private:
  unsigned int score;
  cocos2d::Label *scoreLabel;
};

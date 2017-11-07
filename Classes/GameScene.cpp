#include <string>
#include "GameScene.h"
#include "ScreenConsts.h"
#include "CreatureRespawner.h"
#include "BackGroundController.h"

USING_NS_CC;

Scene* GameScene::createScene()
{
    return GameScene::create();
}

void GameScene::displayScore(unsigned int score)
{
    auto scoreTextLabel = Label::createWithTTF("Score: ", "fonts/8458.ttf", 30);
    scoreTextLabel->setColor(Color3B::BLACK);
   
    Size contentSize = scoreTextLabel->getContentSize();
    Vec2 offset(contentSize.width / 1.8, -contentSize.height / 2.0);
   
    scoreTextLabel->setPosition(getLeftUpCorner() + offset);
    this->addChild(scoreTextLabel, 0);

    scoreLabel = Label::createWithTTF(std::to_string(score), "fonts/8458.ttf", 30);
    scoreLabel->setColor(Color3B::BLACK);
    
    Size scoreSize = scoreLabel->getContentSize();
    Vec2 offsetScore(scoreSize.width / 2.0 + contentSize.width , -scoreSize.height / 2.0);

    scoreLabel->setPosition(getLeftUpCorner() + offsetScore); 
    this->addChild(scoreLabel, 0);
}

bool GameScene::init()
{
    if (!Scene::init()) {
        return false;
    }
    
    score = 0;
    displayScore(score);
    
    
    BackGroundController *backGround = new BackGroundController(*this);
    addChild(backGround, -1);
    
    CreatureRespawner *respawner = new CreatureRespawner(*this);
    addChild(respawner, 0);
    
    return true;
}


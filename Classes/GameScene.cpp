#include <string>
#include "GameScene.h"
#include "ScreenConsts.h"

USING_NS_CC;

Scene* GameScene::createScene()
{
    return GameScene::create();
}

void GameScene::displayScore(unsigned int score)
{
    auto scoreTextLabel = Label::createWithTTF("Score: ", "fonts/8458.ttf", 30);
    scoreTextLabel->setColor(Color3B::WHITE);
   
    Size contentSize = scoreTextLabel->getContentSize();
    Vec2 offset(contentSize.width / 1.8, -contentSize.height / 2.0);
   
    scoreTextLabel->setPosition(getLeftUpCorner() + offset);
    this->addChild(scoreTextLabel, -1);

    scoreLabel = Label::createWithTTF(std::to_string(score), "fonts/8458.ttf", 30);
    scoreLabel->setColor(Color3B::WHITE);
    
    Size scoreSize = scoreLabel->getContentSize();
    Vec2 offsetScore(scoreSize.width / 2.0 + contentSize.width , -scoreSize.height / 2.0);

    scoreLabel->setPosition(getLeftUpCorner() + offsetScore); 
    this->addChild(scoreLabel, -1);
}

void GameScene::update(float delta)
{
    auto children = this->getChildren();
    
    for (auto &child: children) {
        child->update(delta);
    }

    return;
}

bool GameScene::init()
{
    if (!Scene::init()) {
        return false;
    }
    
    score = 0;
    displayScore(score);
    
    Respawner *respawner = new Respawner(this);
    this->addChild(respawner);
    this->scheduleUpdate();
    return true;
}

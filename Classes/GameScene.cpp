#include "GameScene.h"
#include "ScreenConsts.h"

USING_NS_CC;

Scene* GameScene::createScene()
{
    return GameScene::create();
}


void GameScene::displayScore(unsigned int score)
{
    __String *tempScore = __String::createWithFormat( "%i", score );

    auto scoreTextLabel = Label::createWithTTF("Score: ", "fonts/8458.ttf", 30);
    scoreTextLabel->setColor(Color3B::WHITE);
   
    Size contentSize = scoreTextLabel->getContentSize();
    Vec2 indent(contentSize.width / 1.8, -contentSize.height / 2.0);
   
    scoreTextLabel->setPosition(getLeftUpCorner() + indent);
    this->addChild(scoreTextLabel, -1);

    scoreLabel = Label::createWithTTF(tempScore->getCString(), "fonts/8458.ttf", 30);
    scoreLabel->setColor(Color3B::WHITE);
    
    Size scoreSize = scoreLabel->getContentSize();
    Vec2 indentScore(scoreSize.width / 2.0 + contentSize.width , -scoreSize.height / 2.0);

    scoreLabel->setPosition(getLeftUpCorner() + indentScore); 
    this->addChild(scoreLabel, -1);
}


bool GameScene::init()
{
    if (!Scene::init())
    {
        return false;
    }
    score=0;
    displayScore(score);

    return true;
}

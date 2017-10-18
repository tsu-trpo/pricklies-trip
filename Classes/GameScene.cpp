#include "GameScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* GameScene::createScene()
{
    return GameScene::create();
}


void GameScene::displayScore(unsigned int score)
{
  auto visibleSize = Director::getInstance()->getVisibleSize();
  Vec2 origin = Director::getInstance()->getVisibleOrigin();

  __String *tempScore = __String::createWithFormat( "%i", score );

  auto scoreTextLabel = Label::createWithTTF("Score: ", "fonts/8458.ttf", 30);
  scoreTextLabel->setColor(Color3B::WHITE);
  scoreTextLabel->setPosition(Vec2(origin.x + scoreTextLabel->getContentSize().width / 1.8  ,
                                   origin.y + visibleSize.height - scoreTextLabel->getContentSize().height / 2));
  this->addChild(scoreTextLabel, -1);

  scoreLabel = Label::createWithTTF(tempScore->getCString( ), "fonts/8458.ttf", 30);
  scoreLabel->setColor( Color3B::WHITE );
  scoreLabel->setPosition( Vec2(origin.x + scoreLabel->getContentSize().width / 2 + scoreTextLabel->getContentSize().width ,
                           origin.y + visibleSize.height - scoreLabel->getContentSize().height / 2));

  this->addChild(scoreLabel, -1);
}


bool GameScene::init()
{
  if ( !Scene::init() )
  {
      return false;
  }

  auto visibleSize = Director::getInstance()->getVisibleSize();
  Vec2 origin = Director::getInstance()->getVisibleOrigin();

  auto mysprite = Sprite::create("HelloWorld.png");
  mysprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y - 70));
  this->addChild(mysprite, 0);

  score = 0;

  //this->scheduleUpdate();
  displayScore(score);
  return true;
}

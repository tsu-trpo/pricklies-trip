#include "GameScene.h"
#include "Score.h"
#include "CreatureRespawner.h"
#include "BackgroundController.h"
#include "Hero.h"
#include "Events.h"
#include "HelloWorldScene.h"

USING_NS_CC;

Scene* GameScene::createScene()
{
    auto layer = GameScene::create();
    
    auto scene = Scene::createWithPhysics();
    scene->getPhysicsWorld()->setDebugDrawMask(0xffff);
    scene->addChild(layer);

    return scene;
}

bool GameScene::init()
{
    if (!Scene::init()) {
        return false;
    }

    Score *score = Score::create();
    addChild(score, 0);

    BackgroundController *backgroundController = BackgroundController::create(*this);
    addChild(backgroundController, -1);

    CreatureRespawner *respawner = CreatureRespawner::create(*this);
    addChild(respawner, 0);
   
    Hero* hedgehog = Hero::create();
    addChild(hedgehog, 1);

    addEventListener();

    return true;
}

void GameScene::addEventListener()
{
    getEventDispatcher()->addCustomEventListener(dieEvent, [&](EventCustom *event) {
        const float transitionTime = 0.1;
        auto scene = HelloWorld::create();
        Director::getInstance()->replaceScene(TransitionFade::create(transitionTime, scene));
    });
}

GameScene::~GameScene()
{
    getEventDispatcher()->removeCustomEventListeners(dieEvent);
}

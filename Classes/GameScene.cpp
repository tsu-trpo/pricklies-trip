#include <string>
#include "GameScene.h"
#include "Score.h"
#include "CreatureRespawner.h"
#include "BackgroundController.h"
#include "Hero.h"
#include "enum.h"

USING_NS_CC;

Scene* GameScene::createScene()
{
    return GameScene::create();
}

bool GameScene::init()
{
    if (!Scene::init()) {
        return false;
    }

    initKeyboard();

    Score *score = new Score();
    addChild(score, 0);
    
    BackgroundController *backgroundController = new BackgroundController(*this);
    addChild(backgroundController, -1);
    
    CreatureRespawner *respawner = new CreatureRespawner(*this);
    addChild(respawner, 0);
   
    hedgehog = Hero::create();
    addChild(hedgehog, 1);

    return true;
}

void GameScene::initKeyboard()
{
    auto keyListener = EventListenerKeyboard::create();
    keyListener->onKeyPressed = CC_CALLBACK_2(GameScene::onKeyPressed, this);
 
    _eventDispatcher->addEventListenerWithSceneGraphPriority(keyListener, this);
}
 
void GameScene::onKeyPressed(EventKeyboard::KeyCode key, Event* event)
{
    if (key == EventKeyboard::KeyCode::KEY_UP_ARROW)     
        hedgehog->input(Input::JUMP_PRESS);
}
 

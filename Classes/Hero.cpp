#include "Hero.h"
#include "Input.h"
#include "Events.h"
#include "Creature.h"
#include "Tag.h"

USING_NS_CC;

Hero::Hero()
{
    initWithFile("Creatures/Hedgehog/hedge_c_1.png");
    auto visibleSize = Director::getInstance()->getVisibleSize();
    setPosition(Vec2(visibleSize.width / 4.0, visibleSize.height / 2.6));
    setScale(0.8);
    
    setPhysicsBody(getBody());
    _physicsBody->setDynamic(false);
    _physicsBody->setContactTestBitmask(0xFFFFFFFF);
    _physicsBody->setName(heroTag);

    contactListener = EventListenerPhysicsContact::create();
    contactListener->onContactBegin = CC_CALLBACK_1(Hero::onContact, this); 
    getEventDispatcher()->addEventListenerWithSceneGraphPriority(contactListener, this);    

    RunState* running = new RunState(*this);
    setState(running);
}

Hero* Hero::create()
{
    Hero* hero = new Hero();
    hero->autorelease();

    return hero;
}

void Hero::setState(HeroState* state)
{
    heroState.reset(state);
    heroState->setAnimation();
}

void Hero::onEnter()
{
    Sprite::onEnter();
    auto keyListener = EventListenerKeyboard::create();
    keyListener->onKeyPressed = CC_CALLBACK_2(Hero::onKeyPressed, this);
 
    _eventDispatcher->addEventListenerWithSceneGraphPriority(keyListener, this);
}

void Hero::onKeyPressed(EventKeyboard::KeyCode key, Event* event)
{
    if (key == EventKeyboard::KeyCode::KEY_UP_ARROW) {    
        heroState->handleInput(Input::JUMP_PRESS);
    }
}

bool Hero::onContact(PhysicsContact &contact)
{
    auto shapeABody = contact.getShapeA()->getBody();
    auto shapeBBody = contact.getShapeB()->getBody();
    Creature *creature;

    if (shapeABody->getName() == heroTag) {
        if (shapeBBody->getName() == creatureTag) {
            creature = dynamic_cast<Creature *>(shapeBBody->getNode());
            creature->onContact();
        }
    } else if (shapeBBody->getName() == heroTag) {
        if (shapeABody->getName() == creatureTag) {
            creature = dynamic_cast<Creature *>(shapeABody->getNode());
            creature->onContact();
        }
    }

    return true;
}

PhysicsBody * Hero::getBody()
{
    Size size = getContentSize(); // fix after Hero class inheritance fix
    float heightHalf = size.height * 0.5;
    float widthHalf = size.width * 0.5;
    int pointsNumber = 8;

    Point absPoints[pointsNumber / 2] = { Point(0, heightHalf * 0.8),
                                          Point(widthHalf * 0.6, - heightHalf * 0.6),
                                          Point(widthHalf * 0.8, 0),
                                          Point(widthHalf * 0.6, heightHalf * 0.6) };

    Point points[pointsNumber] = { absPoints[0],
                                   absPoints[1],
                                   absPoints[2],
                                   absPoints[3],
                                   -absPoints[0],
                                   -absPoints[1],
                                   -absPoints[3],
                                   -absPoints[2] };

    return PhysicsBody::createPolygon(points, pointsNumber);
}

#include <string>
#include "Score.h"
#include "ScreenConsts.h"
#include "Events.h"

Score::Score()
{
    scheduleUpdate();

    const int fontSize = 40;
    std::string scoreText = "Score: " + std::to_string((size_t)score);
    scoreLabel = Label::createWithTTF(scoreText , "fonts/Stripe.ttf", fontSize);
    scoreLabel->setColor(Color3B::WHITE);

    Size scoreLabelSize = scoreLabel->getContentSize();
    Vec2 offset(scoreLabelSize.width / 20.0, -scoreLabelSize.height / 2.0);
    scoreLabel->setAnchorPoint(Vec2(0, 0.5));
    scoreLabel->setPosition(getLeftUpCorner() + offset);
    addChild(scoreLabel, -1);

    addEventsListener();
}

void Score::addEventsListener()
{
    getEventDispatcher()->addCustomEventListener(eatGoodiesEvent, [&](EventCustom* event){
        unsigned int goodieReward = 200;
        score += goodieReward;
    });
}

Score::~Score()
{
    getEventDispatcher()->removeCustomEventListeners(eatGoodiesEvent);
}

double Score::getScorePoints()
{
   return score;
}

void Score::update(float delta)
{
    score += delta * scoreMultiplier;
    scoreLabel->setString("Score: " + std::to_string((size_t)score));
}

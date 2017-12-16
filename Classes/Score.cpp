#include <string>
#include "Score.h"
#include "ScreenConsts.h"

Score::Score()
{
    scheduleUpdate();

    const int fontSize = 40;
    std::string scoreText = "Score: " + std::to_string((size_t)score);
    scoreLabel = Label::createWithTTF(scoreText , "Fonts/Stripe.ttf", fontSize);
    scoreLabel->setColor(Color3B::BLACK);

    Size scoreLabelSize = scoreLabel->getContentSize();
    Vec2 offset(scoreLabelSize.width / 20.0, -scoreLabelSize.height / 2.0);
    scoreLabel->setAnchorPoint(Vec2(0, 0.5));
    scoreLabel->setPosition(getLeftUpCorner() + offset);
    addChild(scoreLabel, -1);
}

void Score::update(float delta)
{
    score += delta * scoreMultiplier;
    scoreLabel->setString("Score: " + std::to_string((size_t)score));
}

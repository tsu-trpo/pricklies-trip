#include <gtest/gtest.h>
#include "AppDelegate.h"
#include "Score.h"
#include "Events.h"

USING_NS_CC;

TEST(Score, EventDispatcher)
{
  AppDelegate app;
  app.initializeGlview();

  Score *score = new Score();
  score->getEventDispatcher()->setEnabled(true);
  score->getEventDispatcher()->dispatchCustomEvent(eatGoodiesEvent);

  ASSERT_EQ(score->getScorePoints(), 200);
}

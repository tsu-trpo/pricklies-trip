#pragma once

#include <string>
#include "cocos2d.h"

namespace image {

namespace button {

const std::string exit = "Button/exit.png";
const std::string play = "Button/play.png";

}

namespace creature {

inline std::string getGoodie()
{
    const int numberOfGoodies = 4;
    const int goodieNumber = cocos2d::random(0, numberOfGoodies - 1);

    return "Creature/Goodie/" + std::to_string(goodieNumber) + ".png";
}

inline std::string getEnemy()
{
    const int numberOfEnemies = 2;
    const int enemyNumber = cocos2d::random(0, numberOfEnemies - 1);

    return "Creature/Enemy/" + std::to_string(enemyNumber) + ".png";
}

} // creature

namespace hero {

const std::string die = "Hero/die.png";
const std::string pic0 = "Hero/0.png";
const std::string pic1 = "Hero/1.png";

}

namespace background {

const std::string menu = "Background/menu.png";

inline std::string get(int number)
{
    return "Background/0" + std::to_string(number) + ".png";
}

} // background

namespace font {

const std::string stripe = "Font/Stripe.ttf";

}

} // image


#pragma once

#include <string>
#include "cocos2d.h"

namespace button {
    const std::string exit = "Button/exitButton.png";
    const std::string play = "Button/playButton.png";
}

namespace creature {
    inline std::string getGoodie()
    {
        const int numberOfGoodies = 4;
        const int goodieNumber = cocos2d::random(0, numberOfGoodies - 1);

        return "Creatures/Goodies/" + std::to_string(goodieNumber) + ".png";
    }

    inline std::string getEnemy()
    {
        const int numberOfEnemies = 2;
        const int enemyNumber = cocos2d::random(0, numberOfEnemies - 1);

        return "Creatures/Enemies/" + std::to_string(enemyNumber) + ".png";
    }
}

namespace hero {
    const std::string die = "Creatures/Hedgehog/died.png";
    const std::string pic0 = "Creatures/Hedgehog/hedge_c.png";
    const std::string pic1 = "Creatures/Hedgehog/hedge_c_1.png";
}

namespace background {
    const std::string menu = "Background/background.png"; 

    inline std::string get(int number)
    {
        return "Background/background-0" + std::to_string(number) + ".png";
    }
}

namespace font {
    const std::string stripe = "Fonts/Stripe.ttf";
}

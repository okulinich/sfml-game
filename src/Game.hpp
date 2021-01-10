#pragma once

/*
 *  There are three distinct areas in the code:
    initialization, event processing, and rendering
 */
#include <SFML/Graphics.hpp>

namespace gameSample {

// TODO: move game setting to .csv file
constexpr float PlayerSpeed = 50.f;

const sf::Time TimePerFrame = sf::seconds(1.f / 60.f);

class Game
{
    public:
        Game();
        int run();
    private:
        int processEvents();
        int update(sf::Time deltaTime);
        int render();

        void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);

        sf::RenderWindow m_Window;
        // TODO: move player to the separate class
        sf::Texture m_Texture;
        sf::Sprite m_Player;

        float m_PlayerSpeed;    // units per second

        bool m_IsMovingUp;
        bool m_IsMovingDown;
        bool m_IsMovingLeft;
        bool m_IsMovingRight;
};

} // namespace gameSample
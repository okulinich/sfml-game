#include <iostream>

#include "Game.hpp"

using namespace gameSample;

Game::Game()
    : m_Window(sf::VideoMode(640, 480), "My app")
    , m_Texture()
    , m_Player()
    , m_PlayerSpeed(PlayerSpeed)
{
    if (!m_Texture.loadFromFile("resources/textures/player.png"))
    {
        std::cerr << "Failed to load a texture for the player" << std::endl;
        throw std::exception();
    }
    m_Player.setTexture(m_Texture);
    m_Player.setPosition(100.f,100.f);
}

/*
 * we have two while loops. The outer one is the game loop as we know
it, and calls the render() method. The inner one collects user input, and computes
the game logic; this loop is executed at a constant rate. If rendering is slow, it may
happen that processEvents() and update() are called multiple times before one
render() call.
 */
int Game::run()
{
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;

    while (m_Window.isOpen())
    {
        processEvents();                          // process events from the windows
        timeSinceLastUpdate += clock.restart();   // time elapsed from the previous restart
        while (timeSinceLastUpdate > TimePerFrame)
        {
            timeSinceLastUpdate -= TimePerFrame;
            processEvents();
            update(TimePerFrame);                        // update the game
        }
        render();                                 // render results on the screen
    }
    return 0;
}

// FPS - amount of time the game loop iterates per second
int Game::processEvents()
{
    sf::Event event;
    while (m_Window.pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::KeyPressed:
            handlePlayerInput(event.key.code, true);
            break;
        case sf::Event::KeyReleased:
            handlePlayerInput(event.key.code, false);
            break;
        case sf::Event::Closed:
            m_Window.close();
            break;
        }
    }
    return 0;
}

int Game::update(sf::Time deltaTime)
{
    sf::Vector2f movement(0.f, 0.f);
    
    if (m_IsMovingUp)
        movement.y -= m_PlayerSpeed;
    if (m_IsMovingDown)
        movement.y += m_PlayerSpeed;
    if (m_IsMovingLeft)
        movement.x -= m_PlayerSpeed;
    if (m_IsMovingRight)
        movement.x += m_PlayerSpeed;

    // distance =   speed  *    time
    m_Player.move(movement * deltaTime.asSeconds());
    return 0;
}

int Game::render()
{
    m_Window.clear();           // clear the window with a color, usually black
    m_Window.draw(m_Player);    // draw all the objects of the current frame
    m_Window.display();         // display everything on the screen
    return 0;
}


void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed)
{
    switch (key)
    {
    case sf::Keyboard::Up:
        m_IsMovingUp = isPressed;
        break;
    case sf::Keyboard::Down:
        m_IsMovingDown = isPressed;
        break;
    case sf::Keyboard::Left:
        m_IsMovingLeft = isPressed;
        break;
    case sf::Keyboard::Right:
        m_IsMovingRight = isPressed;
        break;
    }
}

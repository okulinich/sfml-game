#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}

/*
 * a graphocal image stored in video memory (or RAM)
 * as an array of pixels.
 * Textures can be drawn on the screen with the sf::Sprite class
*/
sf::Texture m_Texture;
/*
 * A sprite is a
lightweight object that refers to a texture or a rectangular part of it. It stores
attributes such as the position, rotation, scale, or color to affect the way the texture
is represented on the screen. Multiple sprites can refer to the same texture and have
different attributes, while the texture itself is not affected.
*/
sf::Sprite m_Player;

/*
 *The sf::Image class is a container for pixel values. It behaves similarly to
sf::Texture ; however it stores its pixels on the RAM instead of the video
memory, which makes it possible to manipulate single pixels
*/
sf::Image image;

/*
 *To display text on the screen, we use the class sf::Text . Analogous to sprites, texts
are lightweight objects that refer to fonts.
*/
sf::Text text;
sf::Font font;

/*
 * can be created from a std::string containing the GLSL code of a
vertex or a fragment shader. It can also hold both shaders at once; in this case it can
be loaded from two strings. It is also possible to initialize a sf::Shader instance by
passing the filename of a GLSL source file to its constructor.
 */
sf::Shader shader;

/*
 * The sf::SoundBuffer class is used to store a sound effect. It holds an array of 16 bit
audio samples
 */
/* sf::Sound is the class that plays audio from a sound buffer. Like a sprite refers
to a texture containing the pixels, a sound refers to a sound buffer containing the
audio samples.
*/
/*
While sf::SoundBuffer is appropriate for
short sound effects (explosions, button clicks, and so on.), sf::Music is designed
to handle music themes.
sf::Music does not load all data at once.
Instead, it streams the music, meaning that it continuously loads small chunks of
samples.
*/
sf::SoundBuffer sf;
sf::Sound su;
sf::Music mu;

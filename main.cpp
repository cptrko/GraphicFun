#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

int main()
{
    RenderWindow window(VideoMode(640, 480), "SFML works!");
    Texture tapeta;
    tapeta.loadFromFile( "tlo.jpg" );

    sf::Sprite obrazek;
    obrazek.setTexture( tapeta );
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {

            if( event.type == Event::KeyPressed && event.key.code == Keyboard::F )
                {
                window.close();
                window.create(VideoMode(640, 480), "SFML works!l", Style::Fullscreen );

                window.clear();
                window.draw(obrazek);
                window.display();
                }
                if( event.type == Event::KeyPressed && event.key.code == Keyboard::O)
                {
                window.close();
                window.create(VideoMode(640, 480), "SFML works!l");

                window.clear();
                window.draw(obrazek);
                window.display();
                }
        if( event.type == Event::KeyPressed && event.key.code == Keyboard::Escape )
                 window.close();

            if (event.type == Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(obrazek);
        window.display();
    }

    return 0;
}

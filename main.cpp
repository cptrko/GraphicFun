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
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(obrazek);
        window.display();
    }

    return 0;
}

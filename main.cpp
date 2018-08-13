#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

int main()
{
    RenderWindow window(VideoMode(640, 480), "SFML works!");
    Texture tapeta;
    tapeta.loadFromFile( "icon/tlo.jpg" );


    Texture start, menu, wyjscie;
    start.loadFromFile("icon/start.png");
    menu.loadFromFile("icon/menu.png");
    wyjscie.loadFromFile("icon/exit.png");


    Sprite s_start,s_menu, s_wyjscie;
    s_start.setTexture(start);
    s_menu.setTexture(menu);
    s_wyjscie.setTexture(wyjscie);

    Sprite obrazek;
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
        s_start.setPosition(100,180);
        s_start.setScale(0.17,0.17);
        s_menu.setPosition(280,180);
        s_menu.setScale(0.2,0.2);
        s_wyjscie.setPosition(460,180);
        s_wyjscie.setScale(0.2,0.2);
        window.draw(obrazek);
        window.draw(s_start);
        window.draw(s_menu);
        window.draw(s_wyjscie);
        window.display();
    }

    return 0;
}

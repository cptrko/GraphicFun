#include <iostream>
#include <SFML/Graphics.hpp>
#include "menu.h"

using namespace std;
using namespace sf;

int main()
{

    int szerokosc = 640, wysokosc = 480;
    int zaznaczenie=1;
    RenderWindow window(VideoMode(szerokosc, wysokosc), "I NEED A HERO");

    Texture tapeta,start, menu, wyjscie,z_start,z_menu,z_wyjscie;
    tapeta.loadFromFile( "icon/tlo.jpg" );
    start.loadFromFile("icon/start.png");
    menu.loadFromFile("icon/menu.png");
    wyjscie.loadFromFile("icon/exit.png");
    z_start.loadFromFile("icon/start_zaznaczone.png");
    z_menu.loadFromFile("icon/menu_zaznaczone.png");
    z_wyjscie.loadFromFile("icon/exit_zaznaczone.png");

    Sprite s_start,s_menu, s_wyjscie,obrazek,zs_start,zs_menu,zs_wyjscie;
    s_start.setTexture(start);
    s_menu.setTexture(menu);
    s_wyjscie.setTexture(wyjscie);
    zs_start.setTexture(z_start);
    zs_menu.setTexture(z_menu);
    zs_wyjscie.setTexture(z_wyjscie);
    obrazek.setTexture( tapeta );

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();

            if( event.type == Event::KeyPressed && event.key.code == Keyboard::Return && zaznaczenie==2)
                EndOfGame(window);

            if( event.type == Event::KeyPressed && event.key.code == Keyboard::Return && zaznaczenie==1)
                settings(window,szerokosc,wysokosc);

            if( event.type == Event::KeyPressed && event.key.code == Keyboard::Right )
                { zaznaczenie++;
                    if(zaznaczenie>2) zaznaczenie = 0;
                }
            if( event.type == Event::KeyPressed && event.key.code == Keyboard::Left )
                { zaznaczenie--;
                    if(zaznaczenie<0) zaznaczenie = 2;
                }
        }
        window.clear();
        window.draw(obrazek);
        if(zaznaczenie==0)
        {
        zs_start.setPosition(95,173);
        zs_start.setScale(0.2,0.2);
        s_menu.setPosition(280,180);
        s_menu.setScale(0.2,0.2);
        s_wyjscie.setPosition(460,180);
        s_wyjscie.setScale(0.2,0.2);
        window.draw(zs_start);
        window.draw(s_menu);
        window.draw(s_wyjscie);
        }
        else if(zaznaczenie==1)
        {
        s_start.setPosition(100,180);
        s_start.setScale(0.17,0.17);
        zs_menu.setPosition(275,175);
        zs_menu.setScale(0.22,0.22);
        s_wyjscie.setPosition(460,180);
        s_wyjscie.setScale(0.2,0.2);
        window.draw(s_start);
        window.draw(zs_menu);
        window.draw(s_wyjscie);
        }
        else
        {
        s_start.setPosition(100,180);
        s_start.setScale(0.17,0.17);
        s_menu.setPosition(280,180);
        s_menu.setScale(0.2,0.2);
        zs_wyjscie.setPosition(455,175);
        zs_wyjscie.setScale(0.23,0.23);
        window.draw(s_start);
        window.draw(s_menu);
        window.draw(zs_wyjscie);
        }
        window.display();
    }

    return 0;
}

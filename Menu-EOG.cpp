#include "menu.h"

using namespace std;
using namespace sf;

void EndOfGame(RenderWindow  &okno)
{
 Texture logo;
 logo.loadFromFile("icon/tworcy.png");

 Sprite tworcy;
 tworcy.setTexture(logo);

 okno.clear();
 tworcy.setPosition(0,0);
 tworcy.setScale(0.8,0.9);
 okno.draw(tworcy);
 okno.display();
 sleep(milliseconds(2500));
 okno.close();
}

void settings(RenderWindow  &okno, int &szerokosc, int &wysokosc)
{
 int skala[4] = {160,200,256,350};
 int znacznik_skali =0;
 bool wyjscie=false, fullscreensensor=false;
 Texture tapeta;
 tapeta.loadFromFile( "icon/tlo.jpg" );

 Sprite s_tapeta;
 s_tapeta.setTexture( tapeta );

 while (okno.isOpen())
    {
        Event zdarzenie;
        while (okno.pollEvent(zdarzenie))
        {
            if( zdarzenie.type == Event::KeyPressed && zdarzenie.key.code == Keyboard::W )
                wyjscie=true;

            if( zdarzenie.type == Event::KeyPressed && zdarzenie.key.code == Keyboard::F )
                {
                fullscreensensor=true;
                okno.close();
                okno.create(VideoMode(szerokosc, wysokosc), "SFML works!l", Style::Fullscreen );
                okno.clear();
                okno.draw(s_tapeta);
                okno.display();
                }

            if( zdarzenie.type == Event::KeyPressed && zdarzenie.key.code == Keyboard::O)
                {
                fullscreensensor=false;
                okno.close();
                okno.create(VideoMode(szerokosc, wysokosc), "SFML works!l");
                okno.clear();
                okno.draw(s_tapeta);
                okno.display();
                }

            if( zdarzenie.type == Event::KeyPressed && zdarzenie.key.code == Keyboard::Add )
                {
                    znacznik_skali++;
                    if(znacznik_skali>4) znacznik_skali=0;
                    wysokosc=3*skala[znacznik_skali];
                    szerokosc=4*skala[znacznik_skali];
                }
            if( zdarzenie.type == Event::KeyPressed && zdarzenie.key.code == Keyboard::Subtract )
                {
                    znacznik_skali--;
                    if(znacznik_skali<0) znacznik_skali=4;
                    wysokosc=3*skala[znacznik_skali];
                    szerokosc=4*skala[znacznik_skali];
                }

            if( zdarzenie.type == Event::KeyPressed && zdarzenie.key.code == Keyboard::S )
                {
                    if(fullscreensensor)
                    {
                        okno.close();
                        okno.create(VideoMode(szerokosc, wysokosc), "SFML works!l", Style::Fullscreen );
                        okno.clear();
                        okno.draw(s_tapeta);
                        okno.display();
                    }
                    else
                    {
                        okno.close();
                        okno.create(VideoMode(szerokosc, wysokosc), "SFML works!l");
                        okno.clear();
                        okno.draw(s_tapeta);
                        okno.display();
                    }
                }

        }
        if(wyjscie) {break;}
        okno.clear();
        okno.draw( s_tapeta);
        okno.display();
    }
}

#include <iostream>
#include <SFML/System/Sleep.hpp>
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

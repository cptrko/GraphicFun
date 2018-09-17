#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define PROP_W 4
#define PROP_H 3
using namespace std;

int main()
{
	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "SFML works!");
	sf::RectangleShape shape;
	shape.setSize(sf::Vector2f(PROP_W * 10, PROP_H * 10));
	shape.setFillColor(sf::Color::Green);	
	shape.setPosition(0, 0);

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
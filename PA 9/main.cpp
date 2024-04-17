// This example will use SFML libraries to implement
// the game of Pong

// History: 4/12 - Designed limited movements for the paddle and ball objects. Currently,
//                 if the ball intersects with the p2Paddle the ball will change direction. You'll 
//                 need to modify the code further to get more collision detection, etc.
// 
//          4/10 - Designed Paddle and Ball class. Instantiated two Paddle objects and one
//                 Ball object. Displayed these to the screen. We'll work on movements 
//                 in class on Friday, 4/12.
//          
//          4/ 5 - Started from the SFML tutorial code that draws
//                 a circle in the window.

#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(3060, 1920), "Pong!");
	
	int direction = 1, ballDirection = 1;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
	{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();
		window.display();
	}

	return 0;
}
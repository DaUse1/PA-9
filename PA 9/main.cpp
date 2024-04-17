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

#include "Ball.hpp"
#include "Paddle.hpp"
//yeyeye

int main()
{
	sf::RenderWindow window(sf::VideoMode(3060, 1920), "Pong!");
	//sf::CircleShape shape(100.f);

	Ball gameBall(50, sf::Vector2f(200, 200), sf::Color::Red);
	Paddle p1Paddle(sf::Vector2f(20, 200), sf::Vector2f(0, 0), sf::Color::Green),
		p2Paddle(sf::Vector2f(20, 200), sf::Vector2f(980, 0), sf::Color::Green);

	//shape.setFillColor(sf::Color::Green);
	int direction = 1, ballDirection = 1;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		// the ball should be moving every iteration of the loop
		gameBall.move(0.4 * ballDirection, 0);

		// does the ball collide with the p2Paddle?
		if (p2Paddle.getGlobalBounds().intersects(gameBall.getGlobalBounds()))
		{
			// yes, a collision was detected. let's move the ball the opposite direction
			ballDirection *= -1;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			direction = 1; // do we need direction? Consider...
			p1Paddle.move(0, 0.3 * direction);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			direction = -1; // do we need direction? Consider...
			p1Paddle.move(0, 0.3 * direction); // maybe -direction?
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			direction = 1; // do we need direction? Consider...
			p2Paddle.move(0, 0.3 * direction); // maybe -direction?
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			direction = -1; // do we need direction? Consider...
			p2Paddle.move(0, 0.3 * direction);
		}

		window.clear();
		//	window.draw(shape);
		window.draw(gameBall);
		window.draw(p1Paddle);
		window.draw(p2Paddle);
		window.display();
	}

	return 0;
}
#include <SFML/Graphics.hpp>

int main()
{
    //open window
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Driving Simulator 2025");
    //texture declarations
    sf::Texture img, car;
    img.loadFromFile("./road.png");
    car.loadFromFile("./car.png");
    //Sprite initalization
    sf::Sprite background(img);
    sf::Sprite player(car);
    background.setScale(2.5, 1);
    player.setScale(0.1, 0.1);
    //variable for road loop
    float x = 0.0;
    float acceleration = 0.0;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        //road loop
        background.setPosition(x, 0.0);
        x -= 0.8;
        if (x < -405)
        {
            x = 0;
        }
        //move car
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            player.move(0, -0.6);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            player.move(0, 0.6);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            acceleration -= 0.001;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            acceleration += 0.001;
        }
        player.move(acceleration, 0);
        window.clear();
        window.draw(background);
        window.draw(player);
        window.display();
    }

    return 0;
}
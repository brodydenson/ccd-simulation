#include <SFML/Graphics.hpp>

int main()
{
    auto window = sf::RenderWindow(sf::VideoMode({1920u, 1080u}), "CCD Simulation");
    window.setFramerateLimit(144);

    // Define a circle shape
    sf::CircleShape circle(50); // Radius of 50 pixels
    circle.setFillColor(sf::Color::Green);
    circle.setPosition({ 1920u/2, 1080u/2 }); // Initial position (centered in the window)

    // Velocity for movement
    sf::Vector2f velocity(5.0f, 3.0f); // Change in position per frame

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
            if (event->is<sf::Event::Closed>()) window.close();

        // Update circle's position
        sf::Vector2f position = circle.getPosition();

        // Bounce off window edges
        if (position.x <= 0 || position.x + circle.getRadius() * 2 >= window.getSize().x)
            velocity.x = -velocity.x;
        if (position.y <= 0 || position.y + circle.getRadius() * 2 >= window.getSize().y)
            velocity.y = -velocity.y;

        circle.move(velocity); // Move circle by velocity

        // Clear the window with a black color
        window.clear();

        // Draw the circle
        window.draw(circle);

        // Display the current frame
        window.display();
    }
}

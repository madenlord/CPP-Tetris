#include <SFML/Graphics.hpp>

int main()
{
    // Creates a window for 2D games
    sf::RenderWindow window(sf::VideoMode(800,1000), "Tetris");
    window.setFramerateLimit(60);

    // Run the program as long as the window is open
    while(window.isOpen())
    {
        // Check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while(window.pollEvent(event))
        {
            // "Close requested" event: we close the window
            if(event.type == sf::Event::Closed)
                window.close();
        }

        // Clear the window with black color
        window.clear();

        // Draw everything here...
        // window.draw(...);

        // End the current frame
        window.display();
    }

    return 0;
}
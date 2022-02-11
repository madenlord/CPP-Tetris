#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include "TetrisWindow.hpp"

int main()
{
    // Creates a window for 2D games
    sf::RenderWindow window;
    tw::windowInit(&window, WINDOW_WIDTH, WINDOW_HEIGHT, 40, 6, sf::Vector2u(150, 300));

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
        tw::drawGrid();

        // End the current frame
        window.display();
    }

    return 0;
}
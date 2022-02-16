#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include "Game.hpp"

int main()
{
    // Creates a window for 2D games
    sf::RenderWindow window;
    iniGame(&window);

    // Run the program as long as the window is open
    while(window.isOpen())
    {
        // Check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while(window.pollEvent(event))
        {
            // Keyboard events handling
            if(event.type == sf::Event::KeyPressed)
            {
                processKey(event.key.code);
            }

            // "Close requested" event: we close the window
            if(event.type == sf::Event::Closed)
                window.close();
        }

        // Checks if a second has already ellapsed. If it has, the current Tetromino
        // moves down.
        checkTetrominoDrop();

        // Clear the window with black color
        window.clear();

        // Draw everything here...
        drawGameState();

        // End the current frame
        window.display();
    }

    return 0;
}
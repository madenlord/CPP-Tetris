#ifndef TETRIS_WINDOW_H_
#define TETRIS_WINDOW_H_

#define WINDOW_WIDTH    800
#define WINDOW_HEIGHT   1000

#include <SFML/Graphics.hpp>

namespace tw
{
    void windowInit(sf::RenderWindow* window, uint16_t width, uint16_t height, 
                    uint8_t blkSize, uint8_t blkSeparation);
}

#endif
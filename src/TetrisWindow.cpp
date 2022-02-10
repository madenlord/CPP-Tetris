#include <SFML/System/Vector2.hpp>
#include "Grid.hpp"
#include "TetrisWindow.hpp"

static sf::RenderWindow* pwindow;
static Grid tetrisGrid;
static uint8_t blockSize;
static uint8_t blockSeparation;
static sf::Vector2u gridPosition;
static sf::Color blockColor[] = {
    sf::Color(119,119,119), sf::Color::Red, sf::Color::Green, sf::Color::Green,
    sf::Color::Magenta, sf::Color::Cyan, sf::Color::Yellow, sf::Color(180, 0, 255)
};

namespace tw
{
    void windowInit(sf::RenderWindow* window, uint16_t width, uint16_t height, 
                    uint8_t blkSize, uint8_t blkSeparation)
    {
        uint8_t gridC, gridR, gridW, gridH;

        pwindow = window;
        window->create(sf::VideoMode(width, height), "Tetris");
        window->setFramerateLimit(60);

        blockSize        = blkSize;
        blockSeparation  = blkSeparation;

        gridC = tetrisGrid.getCols();
        gridR = tetrisGrid.getRows();
        gridW = blockSize * gridC + blockSeparation * (gridC - 1);
        gridH = blockSize * gridR + blockSeparation * (gridR - 1); 

        gridPosition.x = (width - gridW) / 2; 
        gridPosition.y = (height - gridH) / 2;
    }
}

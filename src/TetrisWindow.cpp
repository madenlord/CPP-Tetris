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
                    uint8_t blkSize, uint8_t blkSeparation, sf::Vector2u gridPos)
    {
        pwindow = window;
        window->create(sf::VideoMode(width, height), "Tetris");
        window->setFramerateLimit(60);

        blockSize        = blkSize;
        blockSeparation  = blkSeparation;

        gridPosition.x = gridPos.x;
        gridPosition.y = gridPos.y;
    }



    void drawGrid()
    {
        uint8_t i, j, rows, cols, blockIndex;
        sf::Vector2f actualPos(gridPosition.x, gridPosition.y);
        sf::RectangleShape block(sf::Vector2f(blockSize, blockSize));

        rows = tetrisGrid.getRows();
        cols = tetrisGrid.getCols();
        for(i = 0; i < rows; i++)
        {
            for(j = 0; j < cols; j++)
            {   
                blockIndex = tetrisGrid.getBlock(j, i);
                block.setPosition(actualPos);
                block.setFillColor(blockColor[blockIndex]);
                pwindow->draw(block);

                actualPos.x += blockSize + blockSeparation;
            }
            actualPos.x = gridPosition.x;
            actualPos.y += blockSize + blockSeparation;
        }
    }
}
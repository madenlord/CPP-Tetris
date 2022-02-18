#include <SFML/System/Vector2.hpp>
#include "TetrisWindow.hpp"

static sf::RenderWindow* pwindow;
static uint8_t blockSize;
static uint8_t blockSeparation;
static sf::Vector2i gridPosition;
static sf::Color blockColor[] = {
    sf::Color(119,119,119), sf::Color::Red, sf::Color::Green, sf::Color::Green,
    sf::Color::Magenta, sf::Color::Cyan, sf::Color::Yellow, sf::Color(180, 0, 255)
};

namespace tw
{
    void windowInit(sf::RenderWindow* window, uint16_t width, uint16_t height, 
                    uint8_t blkSize, uint8_t blkSeparation, sf::Vector2i gridPos)
    {
        pwindow = window;
        window->create(sf::VideoMode(width, height), "Tetris");
        window->setFramerateLimit(60);

        blockSize        = blkSize;
        blockSeparation  = blkSeparation;

        gridPosition.x = gridPos.x;
        gridPosition.y = gridPos.y;
    }



    void drawGrid(Grid* tetrisGrid)
    {
        uint8_t i, j, rows, cols, blockIndex;
        sf::Vector2f actualPos(gridPosition.x, gridPosition.y);
        sf::RectangleShape block(sf::Vector2f(blockSize, blockSize));

        rows = tetrisGrid->getRows();
        cols = tetrisGrid->getCols();
        for(i = 0; i < rows; i++)
        {
            for(j = 0; j < cols; j++)
            {   
                blockIndex = tetrisGrid->getBlock(j, i);
                block.setPosition(actualPos);
                block.setFillColor(blockColor[blockIndex]);
                pwindow->draw(block);

                actualPos.x += blockSize + blockSeparation;
            }
            actualPos.x = gridPosition.x;
            actualPos.y += blockSize + blockSeparation;
        }
    }



    void drawTetromino(Tetromino* tetromino)
    {
        uint8_t i, j, tetrominoSize, blockIndex;
        sf::Vector2i tetrominoPos = tetromino->getPosition();
        sf::Vector2f actualPos;
        sf::RectangleShape block(sf::Vector2f(blockSize, blockSize));

        actualPos.x = gridPosition.x + (tetrominoPos.y * (blockSize + blockSeparation));
        actualPos.y = gridPosition.y + (tetrominoPos.x * (blockSize + blockSeparation));

        tetrominoSize = tetromino->getSize();
        for(i = 0; i < tetrominoSize; i++)
        {
            for(j = 0; j < tetrominoSize; j++)
            {
                blockIndex = tetromino->getBlock(i, j);
                if(blockIndex != 0)
                {
                    block.setPosition(actualPos);
                    block.setFillColor(blockColor[blockIndex]);
                    pwindow->draw(block);
                }

                actualPos.x += blockSize + blockSeparation;
            }
            actualPos.x = gridPosition.x + (tetrominoPos.y * (blockSize + blockSeparation));
            actualPos.y += blockSize + blockSeparation;
        }
    }
}

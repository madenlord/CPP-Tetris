#include <stdlib.h>
#include <time.h>
#include "Grid.hpp"
#include "Tetromino.hpp"
#include "res/TetrominoesObj.hpp"
#include "TetrisWindow.hpp"
#include "Game.hpp"


Grid* tetrisGrid = NULL;
Tetromino* currentTetromino = NULL;
sf::Clock timer;


void iniGame(sf::RenderWindow* window)
{
    srand(time(NULL));
    tw::windowInit(window, WINDOW_WIDTH, WINDOW_HEIGHT, 40, 6, sf::Vector2i(180, 40));
    
    tetrisGrid = new Grid();
    tetrisGrid->create(GRID_COLS, GRID_ROWS);
    generateTetromino();
}



void generateTetromino()
{
    uint8_t newTetrominoIndex = rand() % 7;

    // TODO: find a way to use 'delete currentTetromino' without it causing a crash.
    currentTetromino = tetrominoes[newTetrominoIndex];
    currentTetromino->respawn();
}



void processKey(sf::Keyboard::Key keyCode)
{
    switch(keyCode)
    {
        case sf::Keyboard::A:
            if(tetrisGrid->canTetrominoMove(currentTetromino, sf::Vector2i(0, -1)))
                currentTetromino->moveLeft();
            break;

        case sf::Keyboard::D:
            if(tetrisGrid->canTetrominoMove(currentTetromino, sf::Vector2i(0, 1)))
                currentTetromino->moveRight();
            break;

        case sf::Keyboard::S:
            if(tetrisGrid->canTetrominoMove(currentTetromino, sf::Vector2i(1, 0)))
                currentTetromino->moveDown();
            else
            {
                tetrisGrid->integrateTetromino(currentTetromino);
                clearRows();
                generateTetromino();
            }
            break;

        case sf::Keyboard::E:
            currentTetromino->rotateCW();
            if(!tetrisGrid->canTetrominoMove(currentTetromino, sf::Vector2i(0,0)))
                currentTetromino->rotateNCW();
            break;

        case sf::Keyboard::Q:
            currentTetromino->rotateNCW();
            if(!tetrisGrid->canTetrominoMove(currentTetromino, sf::Vector2i(0,0)))
                currentTetromino->rotateCW();           
            break;

        default:
            break;
    }
}



void checkTetrominoDrop()
{
    sf::Time elapsedTime = timer.getElapsedTime();
    
    if(elapsedTime.asMilliseconds() >= 1000)
    {
        if(tetrisGrid->canTetrominoMove(currentTetromino, sf::Vector2i(1, 0)))
            currentTetromino->moveDown();
        else
        {
            tetrisGrid->integrateTetromino(currentTetromino);
            clearRows();
            generateTetromino();
        }
        timer.restart();
    }
}



void clearRows()
{
    int8_t cleared, row;

    row = currentTetromino->getPosition().x + currentTetromino->getSize();
    if(row > tetrisGrid->getRows())
        row = tetrisGrid->getRows();

    cleared = 0;
    while(row >= 0 && !tetrisGrid->isRowEmpty(row))
    {
        if(tetrisGrid->isRowComplete(row))
        {
            tetrisGrid->clearRow(row);
            cleared++;
        }
        else
        {
            if(cleared > 0)
                tetrisGrid->dropRow(row, cleared);
        }

        row--;
    }
}



void drawGameState()
{
    tw::drawGrid(tetrisGrid);
    tw::drawTetromino(currentTetromino);
}
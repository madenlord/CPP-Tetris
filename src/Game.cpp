#include <stdlib.h>
#include <time.h>
#include "Grid.hpp"
#include "Tetromino.hpp"
#include "res/TetrominoesObj.hpp"
#include "TetrisWindow.hpp"
#include "Game.hpp"


Grid* tetrisGrid = NULL;
Tetromino* currentTetromino = NULL;


void iniGame(sf::RenderWindow* window)
{
    srand(time(NULL));
    tw::windowInit(window, WINDOW_WIDTH, WINDOW_HEIGHT, 40, 6, sf::Vector2u(180, 40));
    
    tetrisGrid = new Grid();
    tetrisGrid->create(GRID_COLS, GRID_ROWS);
    generateTetromino();
}



void generateTetromino()
{
    uint8_t newTetrominoIndex = rand() % 7;

    if(currentTetromino != NULL)
        delete currentTetromino;
    currentTetromino = tetrominoes[newTetrominoIndex].clone();
}



void processKey(sf::Keyboard::Key keyCode)
{
    currentTetromino->logTetrominoData();
    switch(keyCode)
    {
        case sf::Keyboard::A:
            currentTetromino->moveLeft();
            break;

        case sf::Keyboard::D:
            currentTetromino->moveRight();
            break;

        case sf::Keyboard::S:
            currentTetromino->moveDown();
            break;

        case sf::Keyboard::E:
            currentTetromino->rotateCW();
            break;

        case sf::Keyboard::Q:
            currentTetromino->rotateNCW();
            break;

        default:
            break;
    }
    currentTetromino->logTetrominoData();
}



void drawGameState()
{
    tw::drawGrid(tetrisGrid);
    tw::drawTetromino(currentTetromino);
}
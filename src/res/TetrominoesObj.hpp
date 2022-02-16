#ifndef TETROMINOS_H_
#define TETROMINOS_H_

#include <stdint.h>
#include "Tetromino.hpp"

static const uint8_t OBlock[] =
{
    1, 1,
    1, 1
};

static const uint8_t IBlock[] =
{
    0, 0, 0, 0,
    2, 2, 2, 2,
    0, 0, 0, 0,
    0, 0, 0, 0
};

static const uint8_t LBlock[] =
{
    0, 0, 3,
    3, 3, 3,
    0, 0, 0
};

static const uint8_t JBlock[] =
{
    4, 0, 0,
    4, 4, 4,
    0, 0, 0
};

static const uint8_t SBlock[] =
{
    0, 5, 5,
    5, 5, 0,
    0, 0, 0
};

static const uint8_t ZBlock[] =
{
    6, 6, 0,
    0, 6, 6,
    0, 0, 0
};

static const uint8_t TBlock[] =
{
    7, 7, 7,
    0, 7, 0,
    0, 0, 0
};

extern Tetromino tetrominoes[] =
{
    Tetromino((uint8_t*)OBlock,2,sf::Vector2u(0,4)),
    Tetromino((uint8_t*)IBlock,4,sf::Vector2u(0,3)),
    Tetromino((uint8_t*)LBlock,3,sf::Vector2u(0,4)),
    Tetromino((uint8_t*)JBlock,3,sf::Vector2u(0,4)),
    Tetromino((uint8_t*)SBlock,3,sf::Vector2u(0,4)),
    Tetromino((uint8_t*)ZBlock,3,sf::Vector2u(0,4)),
    Tetromino((uint8_t*)TBlock,3,sf::Vector2u(0,4)),
};

#endif
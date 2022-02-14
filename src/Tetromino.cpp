#include <algorithm>
#include "Tetromino.hpp"

Tetromino::Tetromino()
{
    
}



Tetromino::Tetromino(uint8_t* blocks, uint8_t size, sf::Vector2u spawnPoint)
{
    _blocks = new uint8_t(sizeof(blocks));
    std::copy(blocks, blocks+size, _blocks);

    _size = size;
    _currentPos.x = spawnPoint.x;
    _currentPos.y = spawnPoint.y;
}



void Tetromino::create(uint8_t* blocks, uint8_t size, sf::Vector2u spawnPoint)
{
    _blocks = new uint8_t(sizeof(blocks));
    std::copy(blocks, blocks+size, _blocks);

    _size = size;
    _currentPos.x = spawnPoint.x;
    _currentPos.y = spawnPoint.y;
}



Tetromino Tetromino::clone()
{
    Tetromino clone(_blocks, _size, _currentPos);

    return clone;
}



Tetromino::~Tetromino()
{
    delete _blocks;
}
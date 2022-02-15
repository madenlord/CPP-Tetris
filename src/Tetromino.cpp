#include <algorithm>
#include <iostream>
#include "Tetromino.hpp"



//------------------------------------------------------------
//------------------     Constructors    ---------------------
//------------------------------------------------------------
Tetromino::Tetromino()
{
    
}



Tetromino::Tetromino(uint8_t* blocks, uint8_t size, sf::Vector2u spawnPoint)
{
    uint8_t blocksArraySize = size*size;

    _blocks = new uint8_t(blocksArraySize);
    std::copy(blocks, blocks+blocksArraySize, _blocks);

    _size = size;
    _currentPos.x = spawnPoint.x;
    _currentPos.y = spawnPoint.y;
}



void Tetromino::create(uint8_t* blocks, uint8_t size, sf::Vector2u spawnPoint)
{
    uint8_t blocksArraySize = size*size;

    _blocks = new uint8_t(blocksArraySize);
    std::copy(blocks, blocks+blocksArraySize, _blocks);

    _size = size;
    _currentPos.x = spawnPoint.x;
    _currentPos.y = spawnPoint.y;
}




//------------------------------------------------------------
//---------------     Getters & Setters    -------------------
//------------------------------------------------------------
uint8_t* Tetromino::getBlocks()
{
    return _blocks;
}



void Tetromino::setBlocks(uint8_t* blocks, uint8_t size)
{
    delete _blocks;

    _blocks = new uint8_t(sizeof(blocks));
    std::copy(blocks, blocks+size, _blocks);
    _size = size;
}



uint8_t Tetromino::getBlock(uint8_t x, uint8_t y)
{
    return _blocks[x * _size + y];
}



void Tetromino::setBlock(uint8_t x, uint8_t y, uint8_t blockIndex)
{
    _blocks[x * _size + y] = blockIndex;
}



uint8_t Tetromino::getSize()
{
    return _size;
}



void Tetromino::setSize(uint8_t size)
{
    _size = size;
}


sf::Vector2u Tetromino::getPosition()
{
    return _currentPos;
}



void Tetromino::setPosition(uint8_t x, uint8_t y)
{
    _currentPos.x = x;
    _currentPos.y = y;
}




//------------------------------------------------------------
//------     Extra functions for object handling    ----------
//------------------------------------------------------------
void Tetromino::moveLeft()
{
    _currentPos.y--;
}



void Tetromino::moveRight()
{
    _currentPos.y++;
}



void Tetromino::moveDown()
{
    _currentPos.x++;
}



void Tetromino::rotateCW()
{
    uint8_t rotatedBlocks[_size*_size]; 
    uint8_t i, j, r, c;

    r = 0;
    c = _size - 1;
    for(i = 0; i < _size; i++)
    {
        for(j = 0; j < _size; j++)
        {
            rotatedBlocks[r * _size + c] = _blocks[i * _size + j];
            r++;
        }
        r = 0;
        c--;
    }

    std::copy(rotatedBlocks, rotatedBlocks+(_size*_size), _blocks);
}




//------------------------------------------------------------
//------     Extra functions for object handling    ----------
//------------------------------------------------------------
void Tetromino::logTetrominoBlocks()
{
    uint8_t i, j;

    for(i = 0; i < _size; i++)
    {
        for(j = 0; j < _size; j++)
        {
            std::cout << unsigned(_blocks[i * _size + j]);
        }
        std::cout << "\n";
    }
}



void Tetromino::logTetrominoData()
{
    std::cout << "\nCurrent grid position: (" << unsigned(_currentPos.x) << ", ";
    std::cout << unsigned(_currentPos.y) << ")";

    std::cout << "\nSize of the block: " << unsigned(_size);
    std::cout << "\nTetromino layout: \n";
    logTetrominoBlocks();
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
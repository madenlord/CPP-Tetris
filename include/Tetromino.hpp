#ifndef TETROMINO_H_
#define TETROMINO_H_

#include <stdint.h>
#include <SFML/System/Vector2.hpp>


class Tetromino 
{
    private:
        sf::Vector2u _currentPos;
        uint8_t* _blocks;
        uint8_t _size;

    public:
        // Constructors
        Tetromino(void);
        Tetromino(uint8_t* blocks, uint8_t size, sf::Vector2u spawnPoint);
        void create(uint8_t* blocks, uint8_t size, sf::Vector2u spawnPoint);
        
        // Getters & Setters
        uint8_t* getBlocks(void);
        void setBlocks(uint8_t *blocks, uint8_t size);
        uint8_t getBlock(uint8_t x, uint8_t y);
        void setBlock(uint8_t x, uint8_t y, uint8_t blockIndex);
        uint8_t getSize(void);
        void setSize(uint8_t size);
        sf::Vector2u getPosition(void);
        void setPosition(uint8_t x, uint8_t y);

        // Tetromino functionality
        void moveLeft(void);
        void moveRight(void);
        void moveDown(void);
        void rotateCW(void);
        void rotateNCW(void);
        void drop(void);

        // Extra functions for object handling
        void logTetrominoBlocks(void);
        void logTetrominoData(void);
        Tetromino* clone(void);
        ~Tetromino(void);
};

#endif

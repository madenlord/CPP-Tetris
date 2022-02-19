#ifndef TETROMINO_H_
#define TETROMINO_H_

#include <stdint.h>
#include <SFML/System/Vector2.hpp>


class Tetromino 
{
    private:
        sf::Vector2i _spawnPoint;
        sf::Vector2i _currentPos;
        uint8_t* _nonRotatedBlocks;
        uint8_t* _blocks;
        uint8_t _size;

    public:
        // Constructors
        Tetromino(void);
        Tetromino(uint8_t* blocks, uint8_t size, sf::Vector2i spawnPoint);
        Tetromino(Tetromino* tetromino);
        void create(uint8_t* blocks, uint8_t size, sf::Vector2i spawnPoint);
        
        // Getters & Setters
        uint8_t* getBlocks(void);
        void setBlocks(uint8_t *blocks, uint8_t size);
        uint8_t getBlock(uint8_t x, uint8_t y);
        void setBlock(uint8_t x, uint8_t y, uint8_t blockIndex);
        uint8_t getSize(void);
        void setSize(uint8_t size);
        sf::Vector2i getSpawnPoint(void);
        void setSpawnPoint(uint8_t x, uint8_t y);
        sf::Vector2i getPosition(void);
        void setPosition(uint8_t x, uint8_t y);

        // Tetromino functionality
        void moveLeft(void);
        void moveRight(void);
        void moveDown(void);
        void rotateCW(void);
        void rotateNCW(void);
        void respawn(void);

        // Extra functions for object handling
        void logTetrominoBlocks(void);
        void logTetrominoData(void);
        Tetromino* clone(void);
        ~Tetromino(void);
};

#endif

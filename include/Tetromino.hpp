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
        Tetromino(void);
        Tetromino(uint8_t* blocks, uint8_t size, sf::Vector2u spawnPoint);
        void create(uint8_t* blocks, uint8_t size, sf::Vector2u spawnPoint);
        void setPosition(uint8_t x, uint8_t y);
        void moveLeft(void);
        void moveRight(void);
        void moveDown(void);
        void rotateCW(void);
        void rotateNCW(void);
        void drop(void);
        Tetromino clone(void);
        ~Tetromino(void);
};

#endif

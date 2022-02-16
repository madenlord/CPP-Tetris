#ifndef GRID_H_
#define GRID_H_

#include <cstdint>
#include <SFML/System/Vector2.hpp>
#include "Tetromino.hpp"

#define GRID_COLS   10
#define GRID_ROWS   20

class Grid
{
    private:
        uint8_t _rows;
        uint8_t _cols;
        uint8_t* _grid;
        
    public:
        Grid(void);
        Grid(uint8_t c, uint8_t r);
        void create(uint8_t c, uint8_t r);
        uint8_t getCols(void);
        uint8_t getRows(void);
        uint8_t getBlock(uint8_t col, uint8_t row);
        uint8_t canTetrominoMove(Tetromino* tetromino, sf::Vector2u movVector);
        void integrateTetromino(Tetromino* tetromino);
        void logGrid(void);
        void logGridData(void);
        ~Grid();
};

#endif
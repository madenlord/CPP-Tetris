#ifndef GRID_H_
#define GRID_H_

#include <cstdint>

#define GRID_COLS   10
#define GRID_ROWS   20

class Grid
{
    private:
        uint8_t rows;
        uint8_t cols;
        uint8_t* grid;
        
    public:
        Grid(void);
        Grid(uint8_t c, uint8_t r);
        void create(uint8_t c, uint8_t r);
        uint8_t getCols(void);
        uint8_t getRows(void);
        uint8_t getBlock(uint8_t col, uint8_t row);
        ~Grid();
};

#endif
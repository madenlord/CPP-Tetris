#include "Grid.hpp"

Grid::Grid()
{
    uint8_t i;

    cols = GRID_COLS;
    rows = GRID_ROWS;
    grid = new uint8_t[cols * rows];

    for(i = 0; i < (cols * rows); i++)
        grid[i] = 0;
}



Grid::Grid(uint8_t c, uint8_t r)
{
    uint8_t i;

    cols = c;
    rows = r;
    grid = new uint8_t[cols * rows];

    for(i = 0; i < (cols * rows); i++)
        grid[i] = 0;
}



uint8_t Grid::getCols()
{
    return cols;
}



uint8_t Grid::getRows()
{
    return rows;
}



uint8_t Grid::getBlock(uint8_t col, uint8_t row)
{
    return grid[(row * cols) + col];
}



Grid::~Grid()
{
    delete grid;
}
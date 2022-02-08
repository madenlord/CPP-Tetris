#include "grid.hpp"

Grid::Grid()
{
    uint8_t i;

    cols = GRID_COLS;
    rows = GRID_ROWS;
    grid = new char[cols * rows];

    for(i = 0; i < (cols * rows); i++)
        grid[i] = '0';
}

Grid::Grid(uint8_t c, uint8_t r)
{
    uint8_t i;

    cols = c;
    rows = r;
    grid = new char[cols * rows];

    for(i = 0; i < (cols * rows); i++)
        grid[i] = '0';
}

uint8_t Grid::getCols()
{
    return cols;
}

uint8_t Grid::getRows()
{
    return rows;
}

Grid::~Grid()
{
    delete grid;
}
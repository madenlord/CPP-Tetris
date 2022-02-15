#include <iostream>
#include "Grid.hpp"

Grid::Grid()
{
    uint8_t i;

    _cols = GRID_COLS;
    _rows = GRID_ROWS;
    _grid = new uint8_t[_cols * _rows];

    for(i = 0; i < (_cols * _rows); i++)
        _grid[i] = 0;
}



Grid::Grid(uint8_t c, uint8_t r)
{
    uint8_t i;

    _cols = c;
    _rows = r;
    _grid = new uint8_t[_cols * _rows];

    for(i = 0; i < (_cols * _rows); i++)
        _grid[i] = 0;
}



void Grid::create(uint8_t c, uint8_t r)
{
    delete _grid;
    uint8_t i;

    _cols = c;
    _rows = r;
    _grid = new uint8_t[_cols * _rows];

    for(i = 0; i < (_cols * _rows); i++)
        _grid[i] = 0;

}



uint8_t Grid::getCols()
{
    return _cols;
}



uint8_t Grid::getRows()
{
    return _rows;
}



uint8_t Grid::getBlock(uint8_t col, uint8_t row)
{
    return _grid[(row * _cols) + col];
}



void Grid::logGrid()
{
    uint8_t i, j, blockIndex;

    for(i = 0; i < _rows; i++)
    {
        std::cout << "\n# ";
        for(j = 0; j < _cols; j++)
        {
            blockIndex = _grid[i * _cols + j];
            if(blockIndex != 0)
                std::cout << unsigned(blockIndex); 
            std::cout << " ";
        }
        std::cout << "#";
    }

    std::cout << "\n";
    for(j = 0; j < _cols; j++)
    {
        std::cout << "#";
    }
}



void Grid::logGridData()
{
    std::cout << "\nGrid rows: " << unsigned(_rows);
    std::cout << "\nGrid colums: " << unsigned(_cols);

    std::cout << "\nGrid status: ";
    logGrid();
}



Grid::~Grid()
{
    delete _grid;
}
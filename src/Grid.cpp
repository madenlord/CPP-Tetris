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



uint8_t Grid::canTetrominoMove(Tetromino* tetromino, sf::Vector2u movVector)
{
    uint8_t tetrominoPosX = tetromino->getPosition().x + movVector.x;
    uint8_t tetrominoPosY = tetromino->getPosition().y + movVector.y;
    uint8_t tetrominoSize = tetromino->getSize();
    uint8_t i, j, x, y;

    x = 0;
    for(i = tetrominoPosX; i < (tetrominoPosX + tetrominoSize); i++)
    {
        y = 0;
        for(j = tetrominoPosY; j < (tetrominoPosY + tetrominoSize); j++)
        {
            if(tetromino->getBlock(x, y) != 0)
            {
                if( (i < 0) || (i >= _rows) )
                    return 0;
                if( (j < 0) || (j >= _cols) )
                    return 0;
                if(_grid[i * _cols + j] != 0)
                    return 0;
            }
            y++;
        }
        x++;
    }

    return 1;
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
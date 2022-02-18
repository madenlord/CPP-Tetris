#include <iostream>
#include "Grid.hpp"



//------------------------------------------------------------
//------------------     Constructors    ---------------------
//------------------------------------------------------------
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




//------------------------------------------------------------
//---------------     Getters & Setters    -------------------
//------------------------------------------------------------
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




//------------------------------------------------------------
//---------------     Grid functionality    ------------------
//------------------------------------------------------------
uint8_t Grid::canTetrominoMove(Tetromino* tetromino, sf::Vector2i movVector)
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



void Grid::integrateTetromino(Tetromino* tetromino)
{
    uint8_t tetrominoPosX = tetromino->getPosition().x;
    uint8_t tetrominoPosY = tetromino->getPosition().y;
    uint8_t tetrominoSize = tetromino->getSize();
    uint8_t i, j, x, y, block;

    x = 0;
    for(i = tetrominoPosX; i < (tetrominoPosX + tetrominoSize); i++)
    {
        y = 0;
        for(j = tetrominoPosY; j < (tetrominoPosY + tetrominoSize); j++)
        {
            block = tetromino->getBlock(x, y);
            if(block != 0)
                _grid[i * _cols + j] = block;

            y++;
        }
        x++;
    }
}



uint8_t Grid::isRowEmpty(uint8_t row)
{
    uint8_t j;

    for(j = 0; j < _cols; j++)
    {
        if(_grid[row * _cols + j] > 0)
            return 0;
    }

    return 1;
}



uint8_t Grid::isRowComplete(uint8_t row)
{
    uint8_t j;

    for(j = 0; j < _cols; j++)
    {
        if(_grid[row * _cols + j] == 0)
            return 0;
    }

    return 1;
}



void Grid::clearRow(uint8_t row)
{
    uint8_t j;

    for(j = 0; j < _cols; j++)
        _grid[row * _cols + j] = 0;
}



void Grid::dropRow(uint8_t row, uint8_t height)
{
    uint8_t j;

    for(j = 0; j < _cols; j++)
    {
        _grid[(row + height) * _cols + j] = _grid[row * _cols + j];
        _grid[row * _cols + j] = 0;
    }
}




//------------------------------------------------------------
//------     Extra functions for object handling    ----------
//------------------------------------------------------------
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
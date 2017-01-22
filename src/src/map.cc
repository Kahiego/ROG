#include "Map.hh"

Matrix &Matrix::operator=(Matrix const &obj)
{
    _width = obj._widht;
    _height = obj._height;
    _valued = obj._values;
}

Map::Map()
{
        
}



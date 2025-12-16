#pragma once

#include "Position.h"

class Piece {
private:
    char _color_and_type;

public:
    Piece(char color_and_type);

    char getColorAndType() const;
    char getColor() const;
    virtual int isMovementValid(Position src, Position dest, Piece* board[8][8]) = 0;
    virtual ~Piece() = default;
};

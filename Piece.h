#pragma once

#include "Position.h"

class Piece {
	char _color;
	Piece(char type_and_color);

	virtual int isMovementValid(Position src, Position dest, Piece* board[8][8]) = 0;
};

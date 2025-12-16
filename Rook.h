#pragma once
#include "Piece.h"

class Rook : public Piece {

public:
	Rook(char color_and_type);
	int isMovementValid(Position src, Position dest, Piece* board[8][8])  override;

};

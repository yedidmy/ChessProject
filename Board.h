#pragma once
#include "Piece.h"
#include "Position.h"
#include <string>

using std::string;

class Board {
private:
	Piece* _board[8][8];

public:
	Board(string pieces);
	~Board();

	Position string_to_position(string posStr);

	int move_piece(Position src, Position dst);

	string print_board();

	Position find_king(char color);
	bool is_in_check(char color);

	Piece& getBlock(Position block);



};



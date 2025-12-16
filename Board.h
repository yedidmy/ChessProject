#pragma once
#include "Piece.h"
#include "Position.h"
#include "Game.h"
#include <string>

using std::string;

class Board : public Game {
private:
	Piece* _board[8][8];

public:
	Board(string pieces);
	~Board();

	Position string_to_position(string posStr) const;

	int move_piece(Position src, Position dst);

	void print_board() const;

	Position find_king(char king_color) const;
	bool is_in_check(char  king_color);
};



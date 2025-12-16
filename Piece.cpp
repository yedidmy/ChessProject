#include "Piece.h"

Piece::Piece(char color_and_type) {
	_color_and_type = color_and_type;
}

char Piece::getColorAndType() const {
	return _color_and_type;
}

char Piece::getColor() const{

	if (_color_and_type >= 'A' && _color_and_type <= 'Z') {
		return 'W';
	}

	if (_color_and_type >= 'a' && _color_and_type <= 'z') {
		return 'B';
	}

	return 'B';

}
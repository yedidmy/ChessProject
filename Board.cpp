#include "Board.h"
#include "Rook.h"
#include <iostream>


Board::Board(string pieces) {
    //example string - rnbqkbnrpppppppp################################PPPPPPPPRNBQKBNR0
    int current_char = ' ';
    int counter = 0;

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            _board[i][j] = nullptr;
        }
    }
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (pieces[counter] == '#') { _board[i][j] = nullptr; }

            if (pieces[counter] == 'r') { _board[i][j] = new Rook('r'); }
            //coninue for the other pieces...


            counter++;
            
        }

    }
}

Board::~Board() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {

            if (_board[i][j] != nullptr) {
                delete _board[i][j];
                _board[i][j] = nullptr;
            }
        }
    }
}

Position Board::string_to_position(string posStr) const{
    //example string - e2

    if(posStr.length() != 2) { 
        Position p = {-1, -1};
        return p;
    }
    

    int col = posStr[0] - 'a';
    int row = posStr[1] - '1';

    if (row < 0 || row > 7 || col < 0 || col > 7) {
        Position p = { -1, -1 };
        return p;
    }

    Position p = { row, col };
    return p;
}

int Board::move_piece(Position src, Position dst) {

    //Check if indices are out of bounds
    if (src.row < 0 || src.col < 0 || src.row > 7 || dst.row < 0 || dst.col < 0 || dst.row > 7 || src.col > 7) {
        return 5;
    }

    //Check if source and destination are the same
    if (src.row == dst.row && src.col == dst.col) {
        return 7;
    }

    Piece* srcP = _board[src.row][src.col];

    //Check if the player is trying to move an invalid piece
    if (srcP == nullptr || srcP->getColor() != _currentColor) {
        return 2;
    }

    Piece* dstP = _board[dst.row][dst.col];

    //Check if the player is trying to capture their own piece
    if (dstP != nullptr && dstP->getColor() == _currentColor) {
        return 3;
    }

    //Check if the move is geometrically valid
    if (srcP->isMovementValid(src, dst, _board) != 0) {
        return 6;
    }


    //Make the move temporarily and check if the player put themselves in check
    _board[dst.row][dst.col] = srcP;
    _board[src.row][src.col] = nullptr;

    if (is_in_check(_currentColor)) {
        //If so, undo the move and return error
        _board[dst.row][dst.col] = dstP;
        _board[src.row][src.col] = srcP;

        return 4;
    }

    //If valid, delete the captured piece
    if (dstP != nullptr) {
        delete dstP;
    }

    //Change turn
    _currentColor = (_currentColor == 'W') ? 'B' : 'W';

    if (is_in_check(_currentColor)) {
        return 1;
    }

    return 0;
}

void Board::print_board() const{
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (_board[i][j] == nullptr) { std::cout << "#"; }
            else { std::cout << _board[i][j]->getColorAndType(); }
        }
        std::cout << ""<< std::endl;
    }

}

Position Board::find_king(char king_color) const {
    char target_char = ' ';
    Position p = { -1,-1 };

    if (king_color == 'W') { target_char = 'K'; }
    if (king_color == 'B') { target_char = 'k'; }

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (_board[i][j] != nullptr && _board[i][j]->getColorAndType() == target_char) {
                p = { i,j };
                return p;

            }
        }
    }

    return p;
}

bool Board::is_in_check(char king_color){
    Position king_pos = find_king(king_color);

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            Piece* p = _board[i][j];

            if (p != nullptr) {
                if (p->getColor() != king_color) {

                    if (p->isMovementValid({ i,j }, king_pos, _board) == 0) {
                        return true;

                    }

                }

            }

        }
    }

    return false;


}


#include "Board.h"


Board::Board(string pieces) {

    //example string - rnbqkbnrpppppppp################################PPPPPPPPRNBQKBNR0
    int counter = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {

            //fills with the picese - do after we finish all of the picies classs
        }

    }
}
Board::~Board() {
    //we will complete this after we done with the constructor
}

Position Board::string_to_position(string posStr) {
    //example string - e2

    if(posStr.length() != 2) { 
        Position p = {-1, -1};
        return p;
    }
    
    int row = posStr[0] - 'a';;
    int col = posStr[1] - '1';

    if (row < 0 || row > 7 || col < 0 || col > 7) {
        Position p = { -1, -1 };
        return p;
    }

    Position p = { row, col };
    return p;
}

int Board::move_piece(Position src, Position dst) {

    Piece* sourcePiece = _board[src.row][src.col];

    if (sourcePiece == nullptr) {
        return 11;
    }

    Piece* destPiece = _board[dst.row][dst.col];

    if (destPiece != nullptr) {
        delete destPiece;
    }


    _board[dst.row][dst.col] = sourcePiece;
    _board[src.row][src.col] = nullptr;

    //change the turn - to do whem we finish Game


    return 8; 
}

string Board::print_board() {
    ////we will complete this after we done with the pieces classs
}

Position Board::find_king(char color) {
    ////we will complete this after we done with the pieces classs

}
bool Board::is_in_check(char color) {
    ////we will complete this after we done with the pieces classs

}


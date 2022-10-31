#include "controller.h"

using namespace std;

Controller::Controller(QObject *parent)
    : QObject{parent}
{

}

/**
 * @brief createBoard Creates board.
 *
 * First version: numbers 1-15 sorted.
 *
 * @param difficulty Can be hard, medium or easy.
 * @return Value of each piece in order.
 */
void Controller::createBoard(string difficulty)
{
    // Clear board variable.
    _board.clear();

    for(int i = 1; i < 16; ++i){
        _board.append(i);
    }

    // Append "empty" item
    _board.append(-1);

    // Update columns, rows and number of pieces (static)
    _nRows = 4;
    _nColumns = 4;
    _nPieces = 15;

    // Notify changes.
    emit nPiecesChanged(_nPieces);
    emit nRowsChanged(_nRows);
    emit nColumnsChanged(_nColumns);
    emit boardChanged(_board);

    // DEBUG - REMOVE LATER
    printf("Updated board. New difficulty is %s.\n", difficulty.c_str());
    fflush(stdout);
}

/**
 * @brief Check and move piece in respective index.
 * @param pieceIndex Position of piece in board list.
 *
 */
int Controller::move(int movingIndex){
    // Check if piece can be moved...
    // In order to be moved, the specific piece has to have
    //  an adjacent empty square.
    //
    // Get empty square index.
    int emptyIndex = _board.indexOf(-1);

    // Check if indexes are adjacent in grid.
    // For that we need the row/column of both the empty piece
    int rowEmptyPiece = emptyIndex / _nRows;
    int colEmptyPiece = emptyIndex % _nColumns;
    //  and the piece we want to move.
    int rowMovingPiece = movingIndex / _nRows;
    int colMovingPiece = movingIndex % _nColumns;

    // Row and column squared distances...
    int rowDistance = (rowEmptyPiece - rowMovingPiece) * (rowEmptyPiece - rowMovingPiece);
    int colDistance = (colEmptyPiece - colMovingPiece) * (colEmptyPiece - colMovingPiece);

    // If both values are <= 1 it means the moving piece is adjacent to the empty one.
    // BUT at least one of the values has to be zero in order to avoid the diagonal.
    if(rowDistance <= 1
            && colDistance <= 1
            && (rowDistance == 0 ||
                colDistance == 0
                ))
    {
        // Swap pieces.
        _board.swapItemsAt(movingIndex, emptyIndex);

        // Changed board...
        emit boardChanged(_board);

        printf("empty_row=%d, empty_col=%d\n", rowEmptyPiece, colEmptyPiece);
        printf("moving_row=%d, moving_col=%d\n\n", rowMovingPiece, colMovingPiece);
        fflush(stdout);
    }
    else
    {
        emptyIndex = -1;
    }

    return emptyIndex;
}

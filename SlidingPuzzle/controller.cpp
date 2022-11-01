#include "controller.h"

Controller::Controller(QObject *parent)
    : QObject{parent}
    , m_board(16)
    , m_initialBoard(16)
    , m_nPieces(16)
    , m_nCols(4)
    , m_nRows(4)
    , m_voidPiece("-1")
{
}

void Controller::createBoard(QString difficulty)
{
    // Create board list...
    QList<QString> newBoard;

    // Set default board
    // First 15 pieces
    for (int i = 1; i < 16; ++i) {
        newBoard.append(QString::number(i));
    }

    // Empty piece
    newBoard.append(voidPiece());

    // Set as the initial board.
    setInitialBoard(newBoard);

    // Set as the current board...
    setBoard(newBoard);
}

bool Controller::pieceClicked(int movingIndex)
{
    // Return win or no win..
    bool win = true;

    // Check if piece can be moved...
    // In order to be moved, the specific piece has to have
    //  an adjacent empty square.
    //
    // Get current board
    QList<QString> newBoard = board();

    // Get empty square index.
    int emptyIndex = newBoard.indexOf(voidPiece());

    // Check if indexes are adjacent in grid.
    // For that we need the row/column of both the empty piece
    int rowEmptyPiece = emptyIndex / nRows();
    int colEmptyPiece = emptyIndex % nCols();
    //  and the piece we want to move.
    int rowMovingPiece = movingIndex / nRows();
    int colMovingPiece = movingIndex % nCols();

    // Row and column squared distances...
    int rowDistance = (rowEmptyPiece - rowMovingPiece) * (rowEmptyPiece - rowMovingPiece);
    int colDistance = (colEmptyPiece - colMovingPiece) * (colEmptyPiece - colMovingPiece);

    // If both values are <= 1 it means the moving piece is adjacent to the empty one.
    // BUT at least one of the values has to be zero in order to avoid the diagonal.
    if(rowDistance <= 1 && colDistance <= 1 && (rowDistance == 0 || colDistance == 0))
    {
        // Swap pieces...
        newBoard.swapItemsAt(emptyIndex, movingIndex);

        // Check win?
        for(int i = 0; win && (i < nPieces() - 2); ++i)
        {
            // Check if current number is smaller than the next
            if(newBoard.at(i).toInt() > newBoard.at(i + 1).toInt())
            {
                win = false;
            }
        }

        // Update board
        setBoard(newBoard);
    }
    else{
        win = false;
    }

    return win;
}

void Controller::resetGame()
{
    // Set the board as the initial board.
    setBoard(initialBoard());
}

const QList<QString> &Controller::initialBoard() const
{
    return m_initialBoard;
}

void Controller::setInitialBoard(const QList<QString> &newInitialBoard)
{
    if (m_initialBoard == newInitialBoard)
        return;
    m_initialBoard = newInitialBoard;
    emit initialBoardChanged();
}

const QList<QString> &Controller::board() const
{
    return m_board;
}

void Controller::setBoard(const QList<QString> &newBoard)
{
    if (m_board == newBoard)
        return;
    m_board = newBoard;
    emit boardChanged();
}

int Controller::nPieces() const
{
    return m_nPieces;
}

int Controller::nRows() const
{
    return m_nRows;
}

int Controller::nCols() const
{
    return m_nCols;
}

const QString &Controller::voidPiece() const
{
    return m_voidPiece;
}
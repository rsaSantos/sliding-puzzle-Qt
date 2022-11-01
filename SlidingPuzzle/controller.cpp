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

/**
 * @brief Controller::createBoard
 * @param difficulty: easy, mediuum, hard, default
 */
void Controller::createBoard(QString difficulty)
{
    qDebug() << "Creating a board with" << difficulty << "difficulty.";

    // Create board list...
    QList<QString> newBoard = QList<QString>();

    if(difficulty == "random")
    {
        // Seed random number generator.
        std::srand(static_cast<unsigned int>(std::time(nullptr)));

        // Set random board
        for (int i = 0; i < 16; ++i) {
            // Prevent infine loop by counting iterations
            int iterations = 0;

            int randomNumber = (std::rand() % 16) + 1;
            while(iterations < MAX_RAND_ITERATIONS && newBoard.contains(QString::number(randomNumber)))
            {
                randomNumber = (std::rand() % 16) + 1;
                iterations++;
            }

            // If number of iterations was exceeded, create default board.
            if(iterations == MAX_RAND_ITERATIONS)
            {
                createBoard("default");
                return;
            }

            newBoard.append(QString::number(randomNumber));
        }

        // Replace number 16 with void piece.
        int sixteenthIndex = newBoard.indexOf("16");
        newBoard.replace(sixteenthIndex, voidPiece());

        // TODO: Check if puzzle is solvable
    }
    else{
        int nMoves = 0;
        if(difficulty == "easy")
        {
            nMoves = 10;
        }
        else if(difficulty == "medium")
        {
            nMoves = 25;
        }
        else if(difficulty == "hard")
        {
            nMoves = 50;
        }

        // Set default board
        // First 15 pieces
        for (int i = 1; i < 16; ++i) {
            newBoard.append(QString::number(i));
        }

        // Empty piece
        newBoard.append(voidPiece());

        // Position of void piece.
        int emptyIndex = newBoard.indexOf(voidPiece());

        // Last random move.
        int lastRandomMove = -1;

        // Simulate random moves.
        for(int i = 0; i < nMoves; ++i)
        {
            // Get possible moves
            //  aka indexes that the voidPiece can be moved.
            QList<int> possibleMoves = QList<int>(0);
            for(int j = 0; j < nPieces() - 1; ++j)
            {
                if(j != lastRandomMove && isMovable(newBoard, j, emptyIndex))
                {
                    possibleMoves.append(j);
                }
            }

            // If there are moves to be made
            if(possibleMoves.size() > 0)
            {
                // Choose random move (and update last one)
                int randomIndex = std::rand() % possibleMoves.size();
                lastRandomMove = emptyIndex;

                // Swap positions in the board
                int randomMove = possibleMoves.at(randomIndex);
                newBoard.swapItemsAt(emptyIndex, randomMove);

                // Update empty index
                emptyIndex = randomMove;
            }
        }
    }


    // Set as the initial board.
    setInitialBoard(newBoard);

    // Set as the current board...
    setBoard(newBoard);
}

// Check if it is possible to move a given piece of the board.
bool Controller::isMovable(QList<QString> board, int movingIndex, int emptyIndex)
{
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
    return rowDistance <= 1 && colDistance <= 1 && (rowDistance == 0 || colDistance == 0);
}

/**
 * @brief Controller::pieceClicked
 * @param movingIndex
 * @return
 */
bool Controller::movePiece(int movingIndex)
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

    // Check if piece is movable.
    if(isMovable(newBoard, movingIndex, emptyIndex))
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

#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QDebug>
#include <QList>

// Random numbers
#include <cstdlib>
#include <ctime>
#define MAX_RAND_ITERATIONS 999

class Controller : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QList<QString> board READ board WRITE setBoard NOTIFY boardChanged)
    Q_PROPERTY(QList<QString> initialBoard READ initialBoard WRITE setInitialBoard NOTIFY initialBoardChanged)
    Q_PROPERTY(int nPieces READ nPieces CONSTANT)
    Q_PROPERTY(int nRows READ nRows CONSTANT)
    Q_PROPERTY(int nCols READ nCols CONSTANT)
    Q_PROPERTY(QString voidPiece READ voidPiece CONSTANT)

public:
    explicit Controller(QObject *parent = nullptr);

    const QList<QString> &board() const;
    const QString &voidPiece() const;
    void setBoard(const QList<QString> &newBoard);
    int nPieces() const;
    int nRows() const;
    int nCols() const;

    Q_INVOKABLE void createBoard(QString difficulty);
    Q_INVOKABLE bool movePiece(int pieceIndex);
    Q_INVOKABLE void resetGame();

    const QList<QString> &initialBoard() const;
    void setInitialBoard(const QList<QString> &newInitialBoard);

signals:
    void boardChanged();
    void initialBoardChanged();

private:
    QList<QString> m_board;
    QList<QString> m_initialBoard;
    int m_nPieces;
    int m_nRows;
    int m_nCols;
    QString m_voidPiece;
    bool isMovable(QList<QString> board, int movingIndex, int emptyIndex);
};

#endif // CONTROLLER_H

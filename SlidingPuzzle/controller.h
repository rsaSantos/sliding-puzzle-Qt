#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QList>

class Controller : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int nPieces MEMBER _nPieces NOTIFY nPiecesChanged)
    Q_PROPERTY(int nRows MEMBER _nRows NOTIFY nRowsChanged)
    Q_PROPERTY(int nColumns MEMBER _nColumns NOTIFY nColumnsChanged)
    Q_PROPERTY(QList<int> board MEMBER _board NOTIFY boardChanged)
public:
    explicit Controller(QObject *parent = nullptr);
    void createBoard(std::string difficulty);
    Q_INVOKABLE int move(int index);

signals:
    void nPiecesChanged(int nPieces);
    void nRowsChanged(int nRows);
    void nColumnsChanged(int nColumns);
    void boardChanged(QList<int> board);

private:
    int _nPieces  = 0;
    int _nRows    = 0;
    int _nColumns = 0;
    QList<int> _board = QList<int>();
};

#endif // CONTROLLER_H

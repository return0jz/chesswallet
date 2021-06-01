#ifndef PIECE_H
#define PIECE_H
#include <QLabel>
#include <QMouseEvent>

#define KING 0
#define QUEEN 1
#define ROOK 2
#define BISHOP 3
#define KNIGHT 4
#define PAWN 5
#define WHITE 1
#define BLACK 0

class Piece : public QLabel
{
    Q_OBJECT
    QPixmap *img;
public:
    Piece(QWidget *parentwindow, int piece, bool iswhite);
    ~Piece();
private:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
};

#endif // PIECE_H

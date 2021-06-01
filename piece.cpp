#include "piece.h"
#include <iostream>
#include <vector>
#include <QtCore>

const char* piecetable[] {
    ":img/kingw.png",
    ":img/queenw.png",
    ":img/rookw.png",
    ":img/bishopw.png",
    ":img/knightw.png",
    ":img/pawnw.png",
    ":img/kingb.png",
    ":img/queenb.png",
    ":img/rookb.png",
    ":img/bishopb.png",
    ":img/knightb.png",
    ":img/pawnb.png"
};
Piece::Piece(QWidget *parentwindow, int piece, bool iswhite) : QLabel(parentwindow)
{
    this->setGeometry(QRect(0, 0, 75, 75));
    img = new QPixmap(piecetable[piece +((int)!iswhite*6)]);
    this->setPixmap(img->scaled(this->width(),this->height(),Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
}

Piece::~Piece() {
    delete img;
}

void Piece::mousePressEvent(QMouseEvent *event) {
    if(event->buttons() & Qt::LeftButton)
    {
            this->move(mapToParent(event->pos()-QPoint(37,37)));
    }
}

void Piece::mouseMoveEvent(QMouseEvent *event) {
    if(event->buttons() & Qt::LeftButton)
    {
            this->move(mapToParent(event->pos()-QPoint(37,37)));
    }
}

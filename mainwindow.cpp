#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QPixmap>
#include <iostream>
#include "piece.h"
#include <QDir>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new  Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap myimg(":/img/board.svg");
    std::cout << (QDir::currentPath()).toStdString() << std::endl;
    ui->label->setPixmap(myimg.scaled(ui->label->width(),ui->label->height()));
    this->setFixedSize(this->size());
    for (int i = 0; i < 8;i++) {
        pieces.push_back(new Piece(this, PAWN, BLACK));
    }
    pieces.push_back(new Piece(this, KNIGHT, BLACK));
    pieces.push_back(new Piece(this, KNIGHT, BLACK));
    pieces.push_back(new Piece(this, BISHOP, BLACK));
    pieces.push_back(new Piece(this, BISHOP, BLACK));
    pieces.push_back(new Piece(this, ROOK, BLACK));
    pieces.push_back(new Piece(this, ROOK, BLACK));
    pieces.push_back(new Piece(this, QUEEN, BLACK));
    pieces.push_back(new Piece(this, KING, BLACK));

    for (int i = 0; i < 8;i++) {
        pieces.push_back(new Piece(this, PAWN, WHITE));
    }
    pieces.push_back(new Piece(this, KNIGHT, WHITE));
    pieces.push_back(new Piece(this, KNIGHT, WHITE));
    pieces.push_back(new Piece(this, BISHOP, WHITE));
    pieces.push_back(new Piece(this, BISHOP, WHITE));
    pieces.push_back(new Piece(this, ROOK, WHITE));
    pieces.push_back(new Piece(this, ROOK, WHITE));
    pieces.push_back(new Piece(this, QUEEN, WHITE));
    pieces.push_back(new Piece(this, KING, WHITE));
}

MainWindow::~MainWindow()
{
    for (int i = 0; i < static_cast<int>(pieces.size()); i++) {
        delete pieces[i];
    }
    delete ui;
}

#include "mainwindow.h"
#include <QApplication>
#include <iostream>
#include <QMainWindow>
#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QGroupBox>
#include <QFrame>
#include <QTextEdit>
#include <QColorDialog>
#include <QToolBar>
#include <QWidgetAction>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QMainWindow window;
    QWidget *widget = new QWidget(&window);

    QVBoxLayout *vertical = new QVBoxLayout(widget);
    QGridLayout *layout = new QGridLayout();
    QColorDialog* colorPicker = new QColorDialog(&window);
    QToolBar* toolBar = new QToolBar(widget);
    colorPicker->setWindowFlags(Qt::Widget);
    colorPicker->setOptions(QColorDialog::NoButtons);

    vertical->addWidget(toolBar);
    vertical->addLayout(layout);
    widget->setLayout(vertical);



    toolBar->addAction("Save");
    toolBar->addAction("Save As");



    window.setCentralWidget(widget);

    int ROW = 10;
    int COL = 10;

    Pixel* temp;
    for(int row = 0; row < ROW; row++){
        for(int col = 0; col < COL; col++) {
            temp = new Pixel(colorPicker);

            temp->setStyleSheet("");
            temp->setStyleSheet("background-color: rgb(255,255,255)");

            layout->addWidget(temp, row, col);
        }

    }
//    widget->setStyleSheet("margin-top:10px");
    layout->addWidget(colorPicker,0,COL+1,ROW,1);

    window.show();

    return a.exec();
}

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
    QColorDialog* colorPicker = new QColorDialog(nullptr);
    colorPicker->setWindowFlags(Qt::Widget);
    colorPicker->setOptions(QColorDialog::NoButtons);
    colorPicker->setCurrentColor(Qt::black);

    MainWindow window(colorPicker);
    //w.show();

    //QMainWindow window;
    QWidget *widget = new QWidget(&window);


    QGridLayout *layout = new QGridLayout();

    layout->setSpacing(0);
    layout->setVerticalSpacing(0);


    widget->setLayout(layout);



    window.setCentralWidget(widget);

    int ROW = window.window()->size().height()/20;
    int COL = window.window()->size().width()/20;

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

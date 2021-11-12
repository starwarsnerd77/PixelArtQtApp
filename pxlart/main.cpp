#include "mainwindow.h"
#include <QApplication>

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

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QMainWindow window;
    QWidget *widget = new QWidget(&window);
    QGridLayout *layout = new QGridLayout(widget);

    widget->setLayout(layout);
    window.setCentralWidget(widget);

    int ROW = 10;
    int COL = 10;

    Pixel* temp;
    for(int row = 0; row < ROW; row++){
        for(int col = 0; col < COL; col++) {
            temp = new Pixel();

            temp->setStyleSheet("");
            temp->setStyleSheet("background-color: rgb(0,0,255)");

            layout->addWidget(temp, row, col);
        }

    }
    QColorDialog* colorPicker = new QColorDialog();
    layout->addWidget(colorPicker);



    window.show();

    return a.exec();
}

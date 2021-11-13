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
    layout->sizeConstraint();


    QApplication::setStyle("windows");
//    window.setStyle("fusion");

    window.setLayout(layout);


    widget->setLayout(layout);



    window.setCentralWidget(widget);

    int ROW = window.window()->size().height()/20;
    int COL = window.window()->size().width()/20;


    window.drawBoxes(colorPicker, ROW,  COL );

//    widget->setStyleSheet("margin-top:10px");
    layout->addWidget(colorPicker,0,COL+1,ROW,1);

    window.show();

    return a.exec();
}

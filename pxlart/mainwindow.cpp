#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Create Layout
    windowWidth = this->window()->size().width();
    windowHeight = this->window()->size().height();

    pxlSize = 20;


     //gridLayout = QGridLayout();
    for(int i = 0; i <windowHeight*windowWidth; i++){
        Pixel temp = Pixel();
        QWidget* bp = dynamic_cast<QWidget*>(&temp);
        pxlVector.push_back(temp);

        gridLayout.addWidget(bp);
    }


}

MainWindow::~MainWindow()
{
    delete ui;
}


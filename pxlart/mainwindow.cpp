#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Create Layout
    QWidget* mainWidget = new QWidget(this);
    windowWidth = this->window()->size().width();
    windowHeight = this->window()->size().height();


    pxlSize = 20;

    Pixel* temp;

    for(int i = 0; i < 200; i++){
        temp = new Pixel();
        pxlVector.push_back(temp);

        gridLayout->addWidget(temp);


    }

    mainWidget->setLayout(gridLayout);
    setCentralWidget(mainWidget);



}

MainWindow::~MainWindow()
{
    delete ui;
}

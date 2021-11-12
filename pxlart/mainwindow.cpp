#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGridLayout>
#include <QApplication>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Create Layout
//    QRect rec = QApplication::desktop()->screenGeometry();
    QGridLayout gridLayout = QGridLayout();

//    for(int i = 0; i < )
}

MainWindow::~MainWindow()
{
    delete ui;
}


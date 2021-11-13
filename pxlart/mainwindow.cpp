#include "mainwindow.h"
#include <QColorDialog>
#include <QColor>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Create Layout



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actioncolor2_triggered()
{

}


void MainWindow::on_pushButton_clicked()
{

}


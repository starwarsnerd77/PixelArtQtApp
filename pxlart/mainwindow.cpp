#include "mainwindow.h"
#include <QColorDialog>
#include <QColor>


MainWindow::MainWindow(QColorDialog* cp, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    colorPicker = cp;
    // Create Layout



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actioncolor2_triggered()
{
    colorPicker->open();
}


void MainWindow::on_pushButton_clicked()
{

}


#include "mainwindow.h"
#include <QColorDialog>
#include <QColor>
#include "pixel.h"
#include <QFile>
#include <QFileDialog>
#include "pxlfile.h"

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

void MainWindow::on_actioncolor2_triggered() //This is the Choose Color selection in the menu. Name didn't change here when renamed menu
{
    colorPicker->open();
}


void MainWindow::on_pushButton_clicked()
{

}


void MainWindow::on_actionSave_triggered()
{
    PxlFile newFile = PxlFile();
    newFile.writeToFile();

}
void MainWindow::pushBack(Pixel* pixel){
 
         pxlVector.push_back(pixel);
 
}

vector<Pixel*> MainWindow::getVector( ) {
	return pxlVector;
}

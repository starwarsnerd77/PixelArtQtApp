#include "mainwindow.h"
#include <QColorDialog>
#include <QColor>
#include "pixel.h"
#include <QResizeEvent>
#include <iostream>
#include <QFile>
#include <QFileDialog>
#include "pxlfile.h"


MainWindow::MainWindow(QColorDialog* cp, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(width(),height());
    colorPicker = cp;
    pxlSize = 20;
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
    PxlFile newFile = PxlFile(pxlVector);
    newFile.setFileHeight(this->window()->size().height());
    newFile.setFileWidth(this->window()->size().width());
    newFile.setPxlSize(pxlSize);
    newFile.writeToFile();

}
void MainWindow::pushBack(Pixel* pixel){
 
    pxlVector.push_back(pixel);
 
}

vector<Pixel*> MainWindow::getVector( ) {
	return pxlVector;
}


void MainWindow::on_actionOpen_triggered()
{
    PxlFile newFile = PxlFile();
    newFile.readFromFile();
}

//void MainWindow::resizeEvent(QResizeEvent *event){
//    (void) event;
//    //std::cout << this->window()->size().height()/20 << " " << this->window()->size().width()/20 << std::endl;
//    int ROW = this->window()->size().height()/20;
//    int COL = this->window()->size().width()/20;
//    drawBoxes(colorPicker,ROW, COL );
//}

void MainWindow::drawBoxes(QColorDialog *colorPicker,int ROW, int COL ){
    Pixel* temp;

    for(int row = 0; row < ROW; row++){
        for(int col = 0; col < COL; col++) {
            temp = new Pixel(colorPicker);

            temp->setStyleSheet("");
            temp->setStyleSheet("background-color: rgb(255,255,255)");

            layout->addWidget(temp, row, col);

        //this->window()->layout()->pushBack(temp);
        }

    }
}

void MainWindow::setLayout(QGridLayout *lay){
 layout =lay;
}
QGridLayout* MainWindow::getLayout(){
    return layout;
}

#include "mainwindow.h"
#include <QColorDialog>
#include <QColor>
#include "pixel.h"
#include <QResizeEvent>
#include <iostream>
#include <QFile>
#include <QFileDialog>
#include "pxlfile.h"
#include <QInputDialog>
#include <QString>

MainWindow::MainWindow(QColorDialog* cp, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->resize(800,600);
    this->setFixedSize(width(),height());
    colorPicker = cp;
    pxlSize = 20;

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actioncolor2_triggered() //This is the Choose Color selection in the menu. Name didn't change here when renamed menu
{
    colorPicker->open();
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
    PxlFile newFile = PxlFile(pxlVector);
    newFile.readFromFile(this);

}

void MainWindow::drawBoxes(QColorDialog *colorPicker,int ROW, int COL ){
    Pixel* temp;

    for(int row = 0; row < ROW; row++){
        for(int col = 0; col < COL; col++) {
            temp = new Pixel(colorPicker);

            temp->setStyleSheet("");
            temp->setStyleSheet("background-color: rgb(255,255,255)");

            layout->addWidget(temp, row, col);
            pxlVector.push_back(temp);
        }
    }
}

void MainWindow::setLayout(QGridLayout *lay){
 layout =lay;
}

QGridLayout* MainWindow::getLayout(){
    return layout;
}

void MainWindow::on_actionReset_triggered()
{
 resetBoxes();
}

void MainWindow::resetBoxes(){
    for(uint i = 0;i < pxlVector.size();i++){
        pxlVector.at(i)->setStyleSheet("");
        QPalette pal = QPalette();

        pal.setColor(QPalette::Window, QColor(255,255,255));
        pxlVector.at(i)->setRed(0);
        pxlVector.at(i)->setGreen(0);
        pxlVector.at(i)->setBlue(0);
        pxlVector.at(i)->setAutoFillBackground(true);
        pxlVector.at(i)->setPalette(pal);
        pxlVector.at(i)->show();
    }
}

void MainWindow::on_actionFill_from_current_color_triggered()
{
    for(uint i = 0;i < pxlVector.size();i++){
        pxlVector.at(i)->setStyleSheet("");
        QPalette pal = QPalette();
        pal.setColor(QPalette::Window, colorPicker->currentColor());
        pxlVector.at(i)->setRed(colorPicker->currentColor().red());
        pxlVector.at(i)->setGreen(colorPicker->currentColor().green());
        pxlVector.at(i)->setBlue(colorPicker->currentColor().blue());
        pxlVector.at(i)->setAutoFillBackground(true);
        pxlVector.at(i)->setPalette(pal);
        pxlVector.at(i)->show();
    }
}

void MainWindow::on_actionResize_triggered()
{
    QString text = QInputDialog::getText(0, "Resize", "Size (Square):", QLineEdit::Normal,"");

    this->setFixedSize(text.toInt(), text.toInt());
    this->resetBoxes();
}

#include "mainwindow.h"
#include <QColorDialog>
#include <QColor>
#include "pixel.h"
#include <QResizeEvent>
#include <iostream>
#include <QFile>
#include <QFileDialog>
#include "pxlfile.h"
#include "lodepng.h"

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


void MainWindow::on_actionExport_as_PNG_triggered()
{
    windowWidth = this->window()->size().width();
    windowHeight = this->window()->size().height();
//    unsigned width = 512, height = 512;
    std::vector<unsigned char> image;
    image.resize(windowWidth * windowHeight * 4);
    int numOfPxlW = windowWidth / pxlSize;
    int numOfPxlH = windowHeight / pxlSize;
    int counterX = 0;
    int counterY = 0;
    for(unsigned int i = 0; i < pxlVector.size(); i++) {
        for(int y = counterY*pxlSize; y < counterY*pxlSize+pxlSize; y++) {
            for(int x = counterX*pxlSize; x < counterX*pxlSize+pxlSize; x++) {
                image[4*windowWidth*y+4*x] = pxlVector.at(i)->getRed();
                image[4*windowWidth*y+4*x+1] = pxlVector.at(i)->getGreen();
                image[4*windowWidth*y+4*x+2] = pxlVector.at(i)->getBlue();
                image[4*windowWidth*y+4*x+3] = 255;
            }
        }
        counterX++;
        if(counterX >= numOfPxlW) {
            counterX = 0;
            counterY++;
        }
    }

//      encodeOneStep(filename, image, width, height);
      unsigned error = lodepng::encode("test.png", image, windowWidth, windowHeight);

      if(error) std::cout << "encoder error " << error << ": "<< lodepng_error_text(error) << std::endl;
}

void MainWindow::on_actionResize_triggered()
{
    QString text = QInputDialog::getText(0, "Resize", "Size (Square):", QLineEdit::Normal,"");

    this->setFixedSize(text.toInt(), text.toInt());
    this->resetBoxes();
}

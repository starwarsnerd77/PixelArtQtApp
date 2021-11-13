#include "pxlfile.h"
#include <fstream>
#include <sstream>
#include <QFileDialog>
#include <QColor>
#include <iostream>

PxlFile::PxlFile()
{

}

string PxlFile::getFileName() {
    return fileName;
}

int PxlFile::getFileHeight() {
    return fileHeight;
}

int PxlFile::getFileWidth() {
    return fileWidth;
}

int PxlFile::getPxlSize() {
    return pxlSize;
}

void PxlFile::setFileHeight(int height) {
    fileHeight = height;
}

void PxlFile::setFileName(string filename) {
    fileName = filename;
}

void PxlFile::setFileWidth(int width) {
    fileWidth = width;
}

void PxlFile::setPxlSize(int size) {
    pxlSize = size;
}

void PxlFile::readFromFile(MainWindow* thing) {
    QString filters("Pixel files (*.pxl);;Music files (*.mp3);;Text files (*.txt);;All files (*.*)");
    QString defaultFilter("Pixel files (*.pxl)");

    QString file = QFileDialog::getOpenFileName(0, "Save file", QDir::currentPath(), filters, &defaultFilter);
    string line;
    string c;
    this->setFileName(file.toStdString());

    ifstream inFile(fileName);
    if(inFile.is_open()) {

        getline(inFile, line, ',');
        fileName = line;
        getline(inFile, line, ',');
        fileHeight = stoi(line);
        getline(inFile, line, ',');
        fileWidth = stoi(line);
        getline(inFile, line, ',');
        pxlSize = stoi(line);
        getline(inFile, line, '\n');
        numOfPxls = stoi(line);
        QPalette pal = QPalette();
        thing->setFixedSize(fileWidth, fileHeight);

        for(int i = 0; i < numOfPxls; i++) {
            getline(inFile, line, ' ');
            stringstream ss(line);
            getline(ss,c,',');
            pxlVector.at(i)->setRed(stoi(c));
            getline(ss,c,',');
            pxlVector.at(i)->setGreen(stoi(c));
            getline(ss,c,',');
            pxlVector.at(i)->setBlue(stoi(c));
            pxlVector.at(i)->setStyleSheet("");
            pal.setColor(QPalette::Window, QColor(pxlVector.at(i)->getRed(), pxlVector.at(i)->getGreen(), pxlVector.at(i)->getBlue()));
            pxlVector.at(i)->setAutoFillBackground(true);
            pxlVector.at(i)->setPalette(pal);
        }
        inFile.close();
    }

}

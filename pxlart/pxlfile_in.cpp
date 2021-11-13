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

void PxlFile::readFromFile() {
    QString filters("Music files (*.mp3);;Text files (*.txt);;All files (*.*)");
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
        cout << numOfPxls << endl;
        QPalette pal = QPalette();

//        Pixel* temp;
//        int counter;

//        getline(inFile, line, ' ');
//        while(line != "EOF") {

//            cout << line << endl;

//            temp = new Pixel();
//            stringstream ss(line);

//            getline(ss,c,',');
//            temp->setRed(stoi(c));
//            getline(ss,c,',');
//            temp->setGreen(stoi(c));
//            getline(ss,c,',');
//            temp->setBlue(stoi(c));

//            QPalette pal = QPalette();
//            pal.setColor(QPalette::Window, QColor::fromRgb(temp->getRed(), temp->getGreen(), temp->getBlue()));
//            temp->setPalette(pal);
//            temp->show();

//            pxlVector->push_back(temp);
//            getline(inFile, line, ' ');
//            counter++;
//        }

        for(int i = 0; i < numOfPxls; i++) {
            getline(inFile, line, ' ');
//            cout << line << endl;
            stringstream ss(line);
            getline(ss,c,',');
            pxlVector.at(i)->setRed(stoi(c));
            getline(ss,c,',');
            pxlVector.at(i)->setGreen(stoi(c));
            getline(ss,c,',');
            pxlVector.at(i)->setBlue(stoi(c));
            // QColor::fromRgb(pxlVector.at(i)->getRed(), pxlVector.at(i)->getGreen(), pxlVector.at(i)->getBlue())
            pal.setColor(QPalette::Window, QColor(0,0,0));
            pxlVector.at(i)->setAutoFillBackground(true);
            pxlVector.at(i)->setPalette(pal);
            pxlVector.at(i)->show();
        }
        inFile.close();
    }
}

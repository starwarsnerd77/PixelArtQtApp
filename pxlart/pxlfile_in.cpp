#include "pxlfile.h"
#include <fstream>
#include <sstream>
#include <QFileDialog>
#include <QColor>

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

vector<Pixel*> PxlFile::readFromFile() {
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

        Pixel* temp;

        while(line != "") {
            getline(inFile, line, ' ');

            temp = new Pixel();
            stringstream ss(line);

            getline(ss,c,',');
            temp->setRed(stoi(c));
            getline(ss,c,',');
            temp->setGreen(stoi(c));
            getline(ss,c,',');
            temp->setBlue(stoi(c));

            QPalette pal = QPalette();
            pal.setColor(QPalette::Window, QColor::fromRgb(temp->getRed(), temp->getGreen(), temp->getBlue()));
            temp->setPalette(pal);
            temp->show();

            pxlVector.push_back(temp);
        }
        inFile.close();
        return pxlVector;
    }
    return vector<Pixel*>();
}

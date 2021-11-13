#include "pxlfile.h"
#include <fstream>
#include <sstream>

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

vector<Pixel*> PxlFile::readFromFile(string filename) {
    string line;
    string c;
    ifstream inFile(filename);
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

        while(getline(inFile, line, ' ')) {
            temp = new Pixel();
            stringstream ss(line);

            getline(ss,c,',');
            temp->setRed(stoi(c));
            getline(ss,c,',');
            temp->setGreen(stoi(c));
            getline(ss,c,',');
            temp->setBlue(stoi(c));

            pxlVector.push_back(temp);
        }
        inFile.close();
        return pxlVector;
    }
    return vector<Pixel*>();
}

#ifndef PXLFILE_H
#define PXLFILE_H

#include <string>
#include <vector>
#include "pixel.h"
#include "mainwindow.h"
using namespace std;


class PxlFile
{
public:
    PxlFile();
    PxlFile(vector<Pixel*> pxlv);
    string getFileName();
    int getFileHeight();
    int getFileWidth();
    int getPxlSize();
    void setFileName(string filename);
    void setFileHeight(int height);
    void setFileWidth(int width);
    void setPxlSize(int size);
    bool writeToFile();
    void readFromFile(MainWindow* window);

private:
    string fileName;
    int fileHeight;
    int fileWidth;
    int pxlSize;
    int numOfPxls;
    vector<Pixel*> pxlVector;
};

#endif // PXLFILE_H

#include "pxlfile.h"
#include <iostream>
#include <fstream>
#include <QFileDialog>
#include <QChar>
PxlFile::PxlFile(vector<Pixel*> pxlv) {
	pxlVector = pxlv;
}

bool PxlFile::writeToFile() {

	QString filters("Music files (*.mp3);;Text files (*.txt);;All files (*.*)");
    QString defaultFilter("Text files (*.txt)");

    /* Static method approach */
    QString file = QFileDialog::getSaveFileName(0, "Save file", QDir::currentPath(),
        filters, &defaultFilter);

    string fileName = file.toStdString();

	ofstream myfile;
    myfile.open (fileName + ".pxl");
    
    //Header portion of the file
	myfile << fileName + "," +  to_string(getFileHeight()) + "," + to_string(getFileWidth()) + "," + to_string(getPxlSize()) + "\n";
	for(size_t i = 0; i < pxlVector.size(); i++){
		myfile << pxlVector.at(i)->getRGB() + " ";
	}

	myfile.close();
	return true;
}


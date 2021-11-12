#include "pixel.h"

Pixel::Pixel(QWidget *parent) : QWidget(parent), pxlRed(0), pxlGreen(0), pxlBlue(0), pxlSize(20){

//    this->setPalette(pal);
//    this->show();
}
int Pixel::getRed() const{

	return pxlRed;

}

int Pixel::getGreen() const{

	return pxlGreen;

}

int Pixel::getBlue() const{

	return pxlBlue;

}

void Pixel::setRed( const int& red ){

	if(red >= 0 && red <= 255){
		pxlRed = red;
	}
}

void Pixel::setGreen( const int& green ){

	if(green >= 0 && green <= 255){
		pxlGreen = green;
	}
}

void Pixel::setBlue( const int& blue ){

	if(blue >= 0 && blue <= 255){
		pxlBlue = blue;
	}
}

void Pixel::setSize( const int& size ){

	if(size >= 0 && size <= 80){ //Does this need to be changed?
		pxlSize = size;
        this->resize(pxlSize, pxlSize);
	}
}

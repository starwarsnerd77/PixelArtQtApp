#include "pixel.h"

pixel::pixel(QWidget *parent) : QWidget(parent), pxlRed(0), pxlGreen(0), pxlBlue(0), pxlSize(20){

}
int pixel::getRed(){

	return pxlRed;

}

int pixel::getGreen(){

	return pxlGreen;

}

int pixel::getBlue(){

	return pxlBlue;

}

void pixel::setRed( const int& red ){

	if(red >= 0 && red <= 255){
		pxlRed = red;
	}
}

void pixel::setGreen( const int& green ){

	if(green >= 0 && green <= 255){
		pxlGreen = green;
	}
}

void pixel::setBlue( const int& blue ){

	if(blue >= 0 && blue <= 255){
		pxlBlue = blue;
	}
}

void pixel::setSize( const int& size ){

	if(size >= 0 && size <= 80){ //Does this need to be changed?
		pxlSize = size;
	}
}

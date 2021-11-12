#ifndef PIXEL_H
#define PIXEL_H

#include <QWidget>

class Pixel : public QWidget {
    Q_OBJECT
	public:
        explicit Pixel(QWidget *parent = nullptr);
	
	    int getRed( ) const;
	    int getGreen( ) const;
	    int getBlue( ) const;
	    int getSize( ) const;


	    void setRed( const int& red );
	    void setGreen( const int& green );
	    void setBlue( const int& blue );
	    void setSize( const int& green );
	    

	protected:
	    int pxlRed;
	    int pxlGreen;
	    int pxlBlue;
	    int pxlSize;

	signals:

};

#endif // PIXEL_H

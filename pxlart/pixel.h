#ifndef PIXEL_H
#define PIXEL_H

#include <QWidget>

class pixel : public QWidget {
    Q_OBJECT
	public:
	    explicit pixel(QWidget *parent = nullptr);
	
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

#ifndef PIXEL_H
#define PIXEL_H

#include <QGroupBox>
#include <QColorDialog>

class Pixel : public QGroupBox {
    Q_OBJECT
	public:
        explicit Pixel(QGroupBox *parent = nullptr);
        Pixel(QColorDialog *colorPicker);
	
	    int getRed( ) const;
	    int getGreen( ) const;
	    int getBlue( ) const;
	    int getSize( ) const;


	    void setRed( const int& red );
	    void setGreen( const int& green );
	    void setBlue( const int& blue );
	    void setSize( const int& green );

        void mousePressEvent(QMouseEvent *event);
	    

	protected:
	    int pxlRed;
	    int pxlGreen;
	    int pxlBlue;
	    int pxlSize;
	QColorDialog* colorPicker;

	signals:

};

#endif // PIXEL_H

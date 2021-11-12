#include "mainwindow.h"
#include <QApplication>

#include <QMainWindow>
#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QGroupBox>
#include <QFrame>
#include <QTextEdit>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QMainWindow window;
    QWidget *widget = new QWidget(&window);
    QGridLayout *layout = new QGridLayout(widget);

    widget->setLayout(layout);
    window.setCentralWidget(widget);

//    int windowWidth = this->window()->size().width();
//    int windowHeight = this->window()->size().height();


    //int pxlSize = 20;

    Pixel* temp;
    QFrame* frame;
    for(int row = 0; row < 10; row++){
        for(int col = 0; col < 10; col++) {
            //temp = new Pixel();

	    //frame = new QFrame(temp);

            //layout->addWidget(frame , row, col);

//	    QGroupBox *box = new QGroupBox("", widget);
        temp = new Pixel();

        temp->setStyleSheet("");
        temp->setStyleSheet("background-color: rgb(0,0,255)");

        layout->addWidget(temp, row, col);
        }

    }
    //layout->addWidget(new QPushButton("Validate", widget), 1, 0);
    //layout->addWidget(new QPushButton("Reset", widget), 1, 1);
    //layout->addWidget(new QPushButton("Cancel", widget), 1, 2);

    //QGroupBox *box = new QGroupBox("", widget);
    //layout->addWidget(box, 0, 0);

//    QVBoxLayout *boxLayout = new QVBoxLayout(box);

//    QWidget* nameWidget = new QWidget(box);
//    QWidget* ageWidget = new QWidget(box);
//    QWidget* addressWidget = new QWidget(box);

//    boxLayout->addWidget(nameWidget);
//    boxLayout->addWidget(ageWidget);
//    boxLayout->addWidget(addressWidget);

//    QHBoxLayout *nameLayout = new QHBoxLayout(nameWidget);
//    nameLayout->addWidget(new QLabel("Name:"));
//    nameLayout->addWidget(new QLineEdit(nameWidget));


//    QHBoxLayout *ageLayout = new QHBoxLayout(ageWidget);
//    ageLayout->addWidget(new QLabel("Age:"));
//    ageLayout->addWidget(new QLineEdit(ageWidget));

//    QHBoxLayout *addressLayout = new QHBoxLayout(addressWidget);
//    addressLayout->addWidget(new QLabel("Address:"));
//    addressLayout->addWidget(new QLineEdit(addressWidget));





    window.show();

    return a.exec();
}

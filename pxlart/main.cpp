#include "mainwindow.h"
#include <QApplication>

#include <QMainWindow>
#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QGroupBox>

#include <QTextEdit>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QMainWindow window;
    QWidget *widget = new QWidget(&window);
    QGridLayout *layout = new QGridLayout(widget);

    window.setCentralWidget(widget);
    widget->setLayout(layout);

//    int windowWidth = this->window()->size().width();
//    int windowHeight = this->window()->size().height();


    int pxlSize = 20;

    Pixel* temp;
    for(int row = 0; row < 100; row++){
        for(int col = 0; col < 100; col++) {
            QPalette pal = QPalette();
            QColor qc = QColor(0,0,0);
//            pal.setColor(QPalette::Window, qc);
            temp = new Pixel();
//            temp->setPalette(pal);
            temp->setStyleSheet("background-color: black");
            layout->addWidget(temp, row, col);
        }

    }

//    QGroupBox *box = new QGroupBox("", widget);
//    layout->addWidget(box, 0, 0);

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



//    layout->addWidget(new QPushButton("Validate", widget), 1, 0);
//    layout->addWidget(new QPushButton("Reset", widget), 1, 1);
//    layout->addWidget(new QPushButton("Cancel", widget), 1, 2);


    window.show();

    return a.exec();
}

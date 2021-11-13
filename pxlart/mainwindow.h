#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "pixel.h"
#include <vector>

#include <QMainWindow>

#include "ui_mainwindow.h"
#include <QGridLayout>
#include <QApplication>

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QColorDialog* cp, QWidget *parent = nullptr);
    ~MainWindow();
    void pushBack( Pixel* pixel);
    vector<Pixel*> getVector();
    void drawBoxes(QColorDialog *colorPicker,int ROW, int COL );
    void setLayout(QGridLayout *layout);
    QGridLayout* getLayout();
    void resetBoxes();


private slots:
    void on_actioncolor2_triggered();

    void on_pushButton_clicked();

    void on_actionSave_triggered();

    //void resizeEvent(QResizeEvent *event);


    void on_actionOpen_triggered();

    void on_actionReset_triggered();

    void on_actionFill_from_current_color_triggered();

    void on_actionResize_triggered();

private:
    Ui::MainWindow *ui;
    vector<Pixel*> pxlVector;
//    QGridLayout* gridLayout;
    QGridLayout *layout;
    int pxlSize;
    int curPxlR;
    int curPxlG;
    int curPxlB;
    int windowHeight;
    int windowWidth;
    QColorDialog* colorPicker;



};
#endif // MAINWINDOW_H

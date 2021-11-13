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
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actioncolor2_triggered();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    vector<Pixel*> pxlVector;
//    QGridLayout* gridLayout;
    int pxlSize;
    int curPxlR;
    int curPxlG;
    int curPxlB;
    int windowHeight;
    int windowWidth;

};
#endif // MAINWINDOW_H

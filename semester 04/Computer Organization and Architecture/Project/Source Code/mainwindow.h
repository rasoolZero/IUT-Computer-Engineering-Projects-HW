#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <string>
#include "help.h"
#include <QSignalMapper>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void onTick();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_horizontalSlider_valueChanged(int value);

    void on_actionHelp_2_triggered();

    void on_inputToggle_clicked();

    void on_outputToggle_clicked();

    void on_pushButton_4_clicked();

    void on_actionAbout_triggered();

private:
    Ui::MainWindow *ui;
    QTimer timer;
    QTimer scrollTimer;
    int PC,AC,INPR,OUTR,E;
    bool FGI,FGO,IEN,R;
    QString INS2RTL(std::string ins);
    void step(std::string);
    void setLogColor(int);
    void scrollTable();
};
#endif // MAINWINDOW_H

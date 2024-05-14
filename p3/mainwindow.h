#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    QVector<double> x = {1,2,3,4,5,6,7,8,9, 10};
    QVector<double> temper = {32, 34, 30, 34, 29 ,28, 31, 33, 30, 28};
    QVector<double> vlazhn = {98, 95 ,92, 99, 94 ,96, 95, 91, 93, 99};
    QVector<double> prives = {32, 32.25 ,32.6, 33, 33.29 ,33.7, 34.1, 34.24, 34.5, 35};
    bool f = false;
    double t = temper[9];
    double v = vlazhn[9];
    double p = prives[9];
    double p1 = prives[8];


public slots:
    void ontimeout();

private slots:
    void on_pushButton_clicked();
};
#endif // MAINWINDOW_H

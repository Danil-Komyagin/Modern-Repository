#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"
#include "QWidget"
#include "QLabel"
#include "QPixmap"
#include "QTimer"
#include "QTime"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QTimer* timer = new QTimer(this);
    timer->start(1000);
    connect(timer, SIGNAL(timeout()), this, SLOT(ontimeout()));

    ui->widget->xAxis->setRange(1, 10);
    ui->widget->yAxis->setRange(20, 40);
    ui->widget->addGraph();
    ui->widget->graph(0)->addData(x, temper);
    ui->widget->replot();

    ui->widget_2->xAxis->setRange(1,10);
    ui->widget_2->yAxis->setRange(50, 100);
    ui->widget_2->addGraph();
    ui->widget_2->graph(0)->addData(x, vlazhn);
    ui->widget_2->replot();

    ui->widget_3->xAxis->setRange(1,10);
    ui->widget_3->yAxis->setRange(30, 42);
    ui->widget_3->addGraph();
    ui->widget_3->graph(0)->addData(x, prives);
    ui->widget_3->replot();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::ontimeout()
{
    ui->label->setText(QTime::currentTime().toString());
}

void MainWindow::on_pushButton_clicked()
{

    if (t > 37) {f = true; QMessageBox::critical(this, "Температура > 37°C", "Высок шанс гибели расплода. Необходимо убрать утепление.");}
    if (t < 8)  {f = true; QMessageBox::critical(this, "Температура < 8°C", "Высок шанс гибели пчёл. Необходимо установить утепление.");}

    if (v < 70) {f = true; QMessageBox::critical(this, "Влажность в улье <70%", "Слишком сухо: это мешает развитию расплода! Обеспечьте пчёл источником воды.");}
    if (v < 98 && v >= 70 ) {f = true; QMessageBox::warning(this, "Влажность в улье <98%", "Высок риск возникновения плесени. Необходимо проветривание: уберите утепление.");}

    if (p > 47) {f = true; QMessageBox::warning(this, "Улей переполнен", "Необходимо поменять рамки, убрать мёд");}
    if (prives[9] < prives[8]) {f = true; QMessageBox::warning(this, "Вес улья уменьшился", "Необходимо проверить состояние улья.");}
    if (!f) {QMessageBox::information(this, "Information", "Нарушений нет");}
}


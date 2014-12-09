#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QGraphicsItem>
#include<QDebug>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QObject::connect(ui->draw, SIGNAL(clicked()), this, SLOT(start()));



    scene = new QGraphicsScene(this);
    ui->canvas->setScene(scene);
    //ui->canvas->setSceneRect(ui->canvas->geometry());
    scene->setSceneRect(ui->canvas->sceneRect());
    defaultPen.setWidth(1);

}

MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::start()
{
    QString text = ui->source->document()->toPlainText();
    qDebug() << text;

    int x1 = qrand() % 300;
    int y1 = qrand() % 300;
    int x2 = qrand() % 300;
    int y2 = qrand() % 300;

    scene->addLine(x1,y1, x2, y2, defaultPen);
}

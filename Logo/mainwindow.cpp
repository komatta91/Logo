#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QGraphicsItem>
#include<QDebug>
#include<Scan.h>
#include<Parser.h>
#include<iostream>
#include<Turtle.h>
#include <QPen>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    QObject::connect(ui->draw, SIGNAL(clicked()), this, SLOT(start()));
    ui->tabWidget->setCurrentWidget(ui->programTab);


    scene = new QGraphicsScene(this);
    ui->canvas->setScene(scene);
    //ui->canvas->setSceneRect(ui->canvas->geometry());
    scene->setSceneRect(ui->canvas->sceneRect());

    Turtle::GetInstance().SetScene(scene);

}

MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::start()
{
    Turtle::GetInstance().Restart();
    QString text = ui->source->document()->toPlainText();
    Scan s(text.toStdString());
    try
    {
        Parser p(&s);
        if (p.Parse())
        {
            p.GetProgram()->Execute();
        } else
        {
            QString errors;
            for each (std::string err in p.GetErrors())
            {
                errors.append(err.c_str());

            }
            ui->errors->document()->setPlainText(errors);
            ui->tabWidget->setCurrentWidget(ui->errorsTab);
        }
    }
    catch (std::exception e)
    {
        std::cout << e.what() << std::endl;
    }
}

#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <iostream>
#include <QDebug>
using namespace std;

long long result = 0 ;
long long first = 0  , second = 0 ;
bool operatorChecked = false;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton_0 , SIGNAL(clicked()) , this , SLOT(setNumber()));
    connect(ui->pushButton_1 , SIGNAL(clicked()) , this , SLOT(setNumber()));
    connect(ui->pushButton_2 , SIGNAL(clicked()) , this , SLOT(setNumber()));
    connect(ui->pushButton_3 , SIGNAL(clicked()) , this , SLOT(setNumber()));
    connect(ui->pushButton_4 , SIGNAL(clicked()) , this , SLOT(setNumber()));
    connect(ui->pushButton_5 , SIGNAL(clicked()) , this , SLOT(setNumber()));
    connect(ui->pushButton_6 , SIGNAL(clicked()) , this , SLOT(setNumber()));
    connect(ui->pushButton_7 , SIGNAL(clicked()) , this , SLOT(setNumber()));
    connect(ui->pushButton_8 , SIGNAL(clicked()) , this , SLOT(setNumber()));
    connect(ui->pushButton_9 , SIGNAL(clicked()) , this , SLOT(setNumber()));

}

void MainWindow::setNumber()
{
    QPushButton* buttonSender = qobject_cast<QPushButton*>(sender());
    int num = buttonSender->text().right(1).toInt();
    result*=10;
    result+=num;
    ui->result_screen->setText(QString::number(result));
}
MainWindow::~MainWindow()
{
    delete ui;
}

#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <iostream>
#include <QDebug>
using namespace std;

double result = 0 ;
long long first = 0  , second = 0 ;
QString operationChecked ;
bool minus = false ;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //number buttons

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

    //operations

    connect(ui->pushButton_add , SIGNAL(clicked()) , this , SLOT(setOperation()));
    connect(ui->pushButton_sub , SIGNAL(clicked()) , this , SLOT(setOperation()));
    connect(ui->pushButton_div , SIGNAL(clicked()) , this , SLOT(setOperation()));
    connect(ui->pushButton_mul , SIGNAL(clicked()) , this , SLOT(setOperation()));

    //equal

    connect(ui->pushButton_equal , SIGNAL(clicked()) , this , SLOT(findResult()));

    //clear

    connect(ui->pushButton_clear , SIGNAL(clicked()) , this , SLOT(clearScreen()));
    connect(ui->pushButton_clear2 , SIGNAL(clicked()) , this , SLOT(clearScreen()));

    //negative / positive sign

    connect(ui->pushButton_negORpos , SIGNAL(clicked()) , this , SLOT(changeSign()));

    // 1/x

    connect(ui->pushButton_1overX , SIGNAL(clicked()) , this , SLOT(oneOverX()));

    // x*x

    connect(ui->pushButton_square , SIGNAL(clicked()) , this , SLOT(squareX()));
}

void MainWindow::setNumber()
{
    QPushButton* buttonSender = qobject_cast<QPushButton*>(sender());
    int num = buttonSender->text().right(1).toInt();
    result*=10;
    result+=num;
    ui->result_screen->setText(QString::number(result));
}

void MainWindow::setOperation()
{
    first = result ;
    QPushButton* buttonSender = qobject_cast<QPushButton*>(sender());
    operationChecked = buttonSender->text();
    result = 0;
    ui->result_screen->setText("");
}

void MainWindow::findResult()
{
    double finalAnswer;

    second = result ;
    if(operationChecked=="+")
        finalAnswer = first + second;
    else if (operationChecked == "-")
        finalAnswer = first - second ;
    else if (operationChecked == "X")
        finalAnswer = first * second ;
    else
        finalAnswer = first * 1.00 / second ;
    ui->result_screen->setText(QString::number(finalAnswer));
}

void MainWindow::clearScreen()
{
    ui->result_screen->setText("0.0");
    first = second = result = 0 ;
    operationChecked = "";
}

void MainWindow::changeSign()
{
    result*=-1;
    ui->result_screen->setText(QString::number(result));
}

void MainWindow::oneOverX()
{
    result = 1.0000/result;
    ui->result_screen->setText(QString::number(result));
}

void MainWindow::squareX()
{
    result *= result ;
    ui->result_screen->setText(QString::number(result));
}
MainWindow::~MainWindow()
{
    delete ui;
}

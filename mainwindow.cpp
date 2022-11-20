#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <iostream>
#include <QDebug>
using namespace std;

double first = 0  , second = 0 ;
QString operationChecked ;
bool boolDot = false ;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->pushButton_history->setIcon(QIcon(":/images/icons8-history-48.png"));
    ui->pushButton_history->setIconSize(QSize(40,40));
    ui->pushButton_delete->setIcon(QIcon(":/images/icons8-clear-symbol-96.png"));
    ui->pushButton_squareRoot->setIcon(QIcon(":/images/icons8-square-root-64.png"));
    ui->pushButton_squareRoot->setIconSize(QSize(30,30));
    ui->pushButton_square->setIcon(QIcon(":/images/icons8-square-number-96 (1).png"));
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

    //square root

    connect(ui->pushButton_squareRoot , SIGNAL(clicked()) , this , SLOT(squareRoot()));

    // delete

    connect(ui->pushButton_delete , SIGNAL(clicked()) , this , SLOT(deleteDigit()));

    //dot

    connect(ui->pushButton_dot , SIGNAL(clicked()) , this , SLOT(addDot()));

    //binary

    connect(ui->pushButton_binary , SIGNAL(clicked()) , this , SLOT(binaryRep()));
}

void MainWindow::setNumber()
{
    QPushButton* buttonSender = qobject_cast<QPushButton*>(sender());
    QString num = buttonSender->text().right(1);
    QString finalNumber = ui->result_screen->text()+num;
    if(ui->result_screen->text() == '0' || ui->result_screen->text()=="0.0")
            ui->result_screen->setText(num);
    else
        ui->result_screen->setText(finalNumber);
}

void MainWindow::setOperation()
{
    first = ui->result_screen->text().toDouble();
    QPushButton* buttonSender = qobject_cast<QPushButton*>(sender());
    operationChecked = buttonSender->text();
    ui->result_screen->setText("");
}

void MainWindow::findResult()
{
    double finalAnswer;

    second = ui->result_screen->text().toDouble() ;
    if(operationChecked=="+")
        finalAnswer = first + second;
    else if (operationChecked == "-")
        finalAnswer = first - second ;
    else if (operationChecked == "X")
        finalAnswer = first * second ;
    else
        finalAnswer = first * 1.00 / second ;
    cout<<first<<" "<<second<<endl;
    ui->result_screen->setText(QString::number(finalAnswer));

//    ui->treeView->setHidden(b);
//    b=!b;
}

void MainWindow::clearScreen()
{
    ui->result_screen->setText("0.0");
    first = second = 0 ;
    operationChecked = "";
}

void MainWindow::changeSign()
{
    double number = ui->result_screen->text().toDouble();
    number*=-1;
    ui->result_screen->setText(QString::number(number));
}

void MainWindow::oneOverX()
{
    double result = 1.0000/ui->result_screen->text().toDouble();
    ui->result_screen->setText(QString::number(result));
}

void MainWindow::squareX()
{
    double result = ui->result_screen->text().toDouble();
    result*=result ;
    ui->result_screen->setText(QString::number(result));
}

void MainWindow::squareRoot()
{
    double result = pow( ui->result_screen->text().toDouble() , 0.5);
    ui->result_screen->setText(QString::number(result));
}

void MainWindow::deleteDigit()
{
    QString result = ui->result_screen->text();
    result.chop(1);
    QString isDot = result.right(1);
    if(isDot==".")
    {
        result.chop(1);
        boolDot = false ;
    }
    if(result == "")
           result = "0.0";
    ui->result_screen->setText(result);
}

void MainWindow::addDot()
{
    if(!ui->result_screen->text().contains("."))
    {
        ui->result_screen->setText(ui->result_screen->text()+".");
    }
}

void MainWindow::binaryRep()
{
    ui->label_3->setText(QString::number(ui->result_screen->text().toInt(),2));
}
MainWindow::~MainWindow()
{
    delete ui;
}

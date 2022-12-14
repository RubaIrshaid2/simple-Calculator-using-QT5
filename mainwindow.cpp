#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "calculatorwithhistory.h"
#include <iostream>
#include <QDebug>
#include <QSizePolicy>
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
      ui->setupUi(this);
//      cout<<"hello from the other side"<<endl;
//      CalculatorWithHistory * calc = new CalculatorWithHistory;
//      ui->gridLayout->addWidget(calc , 0 , 2);
}


MainWindow::~MainWindow()
{
    delete ui;
}

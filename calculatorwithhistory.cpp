#include "calculatorwithhistory.h"
#include "TreeWidgetItem.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <mainwindow.h>


CalculatorWithHistory::CalculatorWithHistory(QWidget *parent)
    : QWidget{parent}
{
    ui->setupUi(new MainWindow);
//    cout<<"hello"<<endl;

//    ui->pushButton_history->setIcon(QIcon(":/images/icons8-history-48.png"));
//    ui->pushButton_history->setIconSize(QSize(35,35));
//    ui->pushButton_delete->setIcon(QIcon(":/images/icons8-clear-symbol-96.png"));
//    ui->pushButton_squareRoot->setIcon(QIcon(":/images/icons8-square-root-64.png"));
//    ui->pushButton_squareRoot->setIconSize(QSize(30,30));
//    ui->pushButton_square->setIcon(QIcon(":/images/icons8-square-number-96 (1).png"));
//    ui->pushButton_clearHistory->setIcon(QIcon(":/images/icons8-trash-can-64.png"));
//    ui->pushButton_clearHistory->setIconSize(QSize(40,40));
//    //number buttons

//    connect(ui->pushButton_0 , SIGNAL(clicked()) , this , SLOT(setNumber()));
//    connect(ui->pushButton_1 , SIGNAL(clicked()) , this , SLOT(setNumber()));
//    connect(ui->pushButton_2 , SIGNAL(clicked()) , this , SLOT(setNumber()));
//    connect(ui->pushButton_3 , SIGNAL(clicked()) , this , SLOT(setNumber()));
//    connect(ui->pushButton_4 , SIGNAL(clicked()) , this , SLOT(setNumber()));
//    connect(ui->pushButton_5 , SIGNAL(clicked()) , this , SLOT(setNumber()));
//    connect(ui->pushButton_6 , SIGNAL(clicked()) , this , SLOT(setNumber()));
//    connect(ui->pushButton_7 , SIGNAL(clicked()) , this , SLOT(setNumber()));
//    connect(ui->pushButton_8 , SIGNAL(clicked()) , this , SLOT(setNumber()));
//    connect(ui->pushButton_9 , SIGNAL(clicked()) , this , SLOT(setNumber()));

//    //operations

//    connect(ui->pushButton_add , SIGNAL(clicked()) , this , SLOT(setOperation()));
//    connect(ui->pushButton_sub , SIGNAL(clicked()) , this , SLOT(setOperation()));
//    connect(ui->pushButton_div , SIGNAL(clicked()) , this , SLOT(setOperation()));
//    connect(ui->pushButton_mul , SIGNAL(clicked()) , this , SLOT(setOperation()));

//    //equal

//    connect(ui->pushButton_equal , SIGNAL(clicked()) , this , SLOT(equal()));

//    //clear

//    connect(ui->pushButton_clear , SIGNAL(clicked()) , this , SLOT(clearScreen()));
//    connect(ui->pushButton_clear2 , SIGNAL(clicked()) , this , SLOT(clearScreen()));

//    //negative / positive sign

//    connect(ui->pushButton_negORpos , SIGNAL(clicked()) , this , SLOT(changeSign()));

//    // 1/x

//    connect(ui->pushButton_1overX , SIGNAL(clicked()) , this , SLOT(oneOverX()));

//    // x*x

//    connect(ui->pushButton_square , SIGNAL(clicked()) , this , SLOT(squareX()));

//    //square root

//    connect(ui->pushButton_squareRoot , SIGNAL(clicked()) , this , SLOT(squareRoot()));

//    // delete

//    connect(ui->pushButton_delete , SIGNAL(clicked()) , this , SLOT(deleteDigit()));

//    //dot

//    connect(ui->pushButton_dot , SIGNAL(clicked()) , this , SLOT(addDot()));

//    //binary

//    connect(ui->pushButton_binary , SIGNAL(clicked()) , this , SLOT(binaryRep()));

//    //percentage

//    connect(ui->pushButton_per , SIGNAL(clicked()) , this , SLOT(percentage()));

//    //History

//    connect(ui->pushButton_history , SIGNAL(clicked()) , this , SLOT(HideShowHistory()));

//    //clear History]

//    connect(ui->pushButton_clearHistory , SIGNAL(clicked()) , this , SLOT(ClearOperationsHistory()));

//    //tree History widget

//    ui->treeWidget->setColumnCount(4);

//    QStringList labels = {
//        "1'st Number","opertion" , "2'nd Number" , "Result"
//    };

//    ui->treeWidget->setHeaderLabels(labels);

//    root  = new QTreeWidgetItem(ui->treeWidget);
//    root->setText(0,"History");
//    root->setExpanded(true);

//    ui->treeWidget->addTopLevelItem(root);

//    ui->treeWidget->setSortingEnabled(true);
//}

//void CalculatorWithHistory::setNumber()
//{
//    if(this->m_newNum)
//    {
//        ui->result_screen->setText("");
//        this->m_newNum = false ;
//    }
//    if(ui->result_screen->text().size() <= 15)
//    {
//        QPushButton* buttonSender = qobject_cast<QPushButton*>(sender());
//        QString num = buttonSender->text().right(1);
//        QString finalNumber = ui->result_screen->text()+num;
//        if(ui->result_screen->text() == '0')
//                ui->result_screen->setText(num);
//        else
//            ui->result_screen->setText(finalNumber);
//    }
//}


//void CalculatorWithHistory::setOperation()
//{
//    m_newNum = true;
//    findResult();
//    first = ui->result_screen->text().toDouble();
//    QPushButton* buttonSender = qobject_cast<QPushButton*>(sender());
//    operationChecked = buttonSender->text();
//    cout<<first<<" st "<<second<<endl;
//}

//void CalculatorWithHistory::findResult()
//{
//    double finalAnswer;

//    second = ui->result_screen->text().toDouble() ;
//    if(operationChecked=="+")
//        finalAnswer = first + second;
//    else if (operationChecked == "-")
//        finalAnswer = first - second ;
//    else if (operationChecked == "X")
//        finalAnswer = first * second ;
//    else
//        finalAnswer = first * 1.00 / second ;
//    cout<<first<<" "<<second<<" "<<finalAnswer<<endl;
//    qDebug() << operationChecked;
//    ui->result_screen->setText(QString::number(finalAnswer));

//    if(!m_FirstOperation)
//        addToHistory(first , second , operationChecked , finalAnswer);

//    m_FirstOperation = false;
//}

//void CalculatorWithHistory::equal()
//{
//    findResult();
//    first = 0 ;
//    operationChecked = "+";
//    m_FirstOperation = true;
//    cout<<first<<" eq "<<second<<endl;
//}

//void CalculatorWithHistory::clearScreen()
//{
//    ui->result_screen->setText("0");
//    first = second = 0 ;
//    operationChecked = "+";
//    m_FirstOperation = true;
//}

//void CalculatorWithHistory::changeSign()
//{
//    double number = ui->result_screen->text().toDouble();
//    number*=-1;
//    ui->result_screen->setText(QString::number(number));
//}

//void CalculatorWithHistory::oneOverX()
//{
//    double result = 1.0000/ui->result_screen->text().toDouble();
//    ui->result_screen->setText(QString::number(result));
//}

//void CalculatorWithHistory::squareX()
//{
//    int DotIndex = ui->result_screen->text().indexOf(".");
//    if(ui->result_screen->text().size()<=6 || (DotIndex<=6 && DotIndex>=0))
//    {
//        double result = ui->result_screen->text().toDouble();
//        result*=result ;
//        ui->result_screen->setText(QString::number(result));
//    }
//}

//void CalculatorWithHistory::squareRoot()
//{
//    double result = pow( ui->result_screen->text().toDouble() , 0.5);
//    ui->result_screen->setText(QString::number(result));
//}

//void CalculatorWithHistory::deleteDigit()
//{
//    QString result = ui->result_screen->text();
//    result.chop(1);
//    QString isDot = result.right(1);

//    if(isDot=="." || isDot=="-")
//        result.chop(1);

//    if(result == "")
//           result = "0";
//    ui->result_screen->setText(result);
//}

//void CalculatorWithHistory::addDot()
//{
//    if(!ui->result_screen->text().contains("."))
//    {
//        ui->result_screen->setText(ui->result_screen->text()+".");
//    }
//}

//void CalculatorWithHistory::binaryRep()
//{
//    ui->label_3->setText(QString::number(ui->result_screen->text().toInt(),2));
//}

//void CalculatorWithHistory::percentage()
//{
//    double result = ui->result_screen->text().toDouble()*1.000/100;
//    ui->result_screen->setText(QString::number(result));
//}

//void CalculatorWithHistory::addToHistory(double first , double second , QString operation , double result)
//{

//    TreeWidgetItem * child1  = new TreeWidgetItem();
//    child1->setText(0,QString::number(first));
//    child1->setText(1,operation);
//    child1->setText(2,QString::number(second));
//    child1->setText(3,QString::number(result));
//    root->addChild(child1);
//}

//void CalculatorWithHistory::HideShowHistory()
//{
//    if(HistoryVisible)
//        MainWindow::resize(1100,720);
//    else
//        MainWindow::resize(410 , 720);
//    HistoryVisible = !HistoryVisible;
//}

//void CalculatorWithHistory::ClearOperationsHistory()
//{
//    for( int i = root->childCount() ; i>=0 ; i--)
//        root->removeChild(root->child(i));
//}


//void CalculatorWithHistory::onTreeWidgetItemClicked(QTreeWidgetItem *item, int column)
//{
//    QString prevOperation = item->text(0) + " " + item->text(1) + " " + item->text(2)+ " = " +
//                            item->text(3);
//    ui->previousOperation->setText(prevOperation);
//    ui->result_screen->setText(item->text(3));
//    first = 0 ;
//    operationChecked = "+";
//    m_FirstOperation = true;
}

CalculatorWithHistory::~CalculatorWithHistory()
{
    delete ui;
}


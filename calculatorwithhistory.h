#ifndef CALCULATORWITHHISTORY_H
#define CALCULATORWITHHISTORY_H

#include <QWidget>
#include <mainwindow.h>

QT_BEGIN_NAMESPACE
namespace Ui { class CalculatorWithHistory; }
QT_END_NAMESPACE


class CalculatorWithHistory : public QWidget
{
    Q_OBJECT
public:
    explicit CalculatorWithHistory(QWidget *parent = nullptr);
    ~CalculatorWithHistory();

    double first = 0 , second = 0 ;
    QString operationChecked = "+";
    bool m_FirstOperation = true , m_newNum = true , HistoryVisible = true;
    QTreeWidgetItem * root ;

private slots:

//    void setNumber();
//    void setOperation();
//    void findResult();
//    void clearScreen();
//    void changeSign();
//    void oneOverX();
//    void squareX();
//    void squareRoot();
//    void deleteDigit();
//    void addDot();
//    void binaryRep();
//    void equal();
//    void percentage();
//    void addToHistory(double first , double second , QString operation , double result);
//    void HideShowHistory();
//    void ClearOperationsHistory();
//    void onTreeWidgetItemClicked(QTreeWidgetItem *item, int column);

signals:

private:
    Ui::MainWindow *ui;

};

#endif // CALCULATORWITHHISTORY_H

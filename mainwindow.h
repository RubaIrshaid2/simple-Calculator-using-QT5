#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTreeWidget>
#include <iostream>
using namespace std ;
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void setNumber();
    void setOperation();
    void findResult();
    void clearScreen();
    void changeSign();
    void oneOverX();
    void squareX();
    void squareRoot();
    void deleteDigit();
    void addDot();
    void binaryRep();
    void equal();
    void percentage();
    void addToHistory(double first , double second , QString operation , double result);
    void HideShowHistory();
    void ClearOperationsHistory();

    void on_treeWidget_itemClicked(QTreeWidgetItem *item, int column);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

class TreeWidgetItem : public QTreeWidgetItem
{
public:
    TreeWidgetItem(): QTreeWidgetItem(){};
    TreeWidgetItem(QTreeWidget *tree) : QTreeWidgetItem(tree)  {}
    TreeWidgetItem(QTreeWidget * parent, const QStringList & strings)
                   : QTreeWidgetItem (parent,strings)  {}
    bool operator< (const QTreeWidgetItem &other) const
    {

        int sortCol = treeWidget()->sortColumn();// the index of pressed column
        if(text(sortCol)=="+" || text(sortCol)=="-" || text(sortCol)=="X" || text(sortCol)=="/")
            return text(sortCol) < other.text(sortCol);
        int myNumber = text(sortCol).toInt();
        int otherNumber = other.text(sortCol).toInt();
        return myNumber < otherNumber;
    }
};

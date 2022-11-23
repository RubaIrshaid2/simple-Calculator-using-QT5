#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

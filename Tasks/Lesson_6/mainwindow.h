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
    void digitPressed();
    void on_pb_decimal_released();
    void unaryOperationPressed();
    void on_pb_clear_released();
    void on_pb_equals_released();
    void binaryOperationPressed();


private:
    Ui::MainWindow *ui;

    double firstNumber;
    bool userIsTypingSecondNumber;
};
#endif // MAINWINDOW_H

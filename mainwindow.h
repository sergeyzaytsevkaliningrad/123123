#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <iostream>
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:
       void digit_pressed ();
       void on_pushButton_10_released();
       void unary_operation_presed();
       void binary_operation_pressed();
       void on_pushButton_equl_released();
      // void on_label_2_linkActivated(const QString &link);
      // void on_lcdNumber_overflow();
};

#endif // MAINWINDOW_H

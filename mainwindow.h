#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"submittingdata.h"
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    //void calculate (int number ,QString algorithm , submittingdata & input);
    ~MainWindow();

private slots:   
    void on_submitdata_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

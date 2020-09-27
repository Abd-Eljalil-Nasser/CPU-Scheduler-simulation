#ifndef SUBMITTINGDATA_H
#define SUBMITTINGDATA_H
#include<QtCore>
#include<QDialog>
#include<QtGui>
#include <QDialog>
#include<delegate.h>
#include <QKeyEvent>
namespace Ui {
class submittingdata;
}

class submittingdata : public QDialog
{
    Q_OBJECT

public:
    explicit submittingdata(QWidget *parent = nullptr);
    //void setdata(int number , QString algorthim);
    ~submittingdata();
    //void keyPressEvent(QKeyEvent * e);


private slots:
    void on_submittable_clicked();


private:
    Ui::submittingdata *ui;
    QStandardItemModel *model;
    Delegate * mydatalate;
};

#endif // SUBMITTINGDATA_H

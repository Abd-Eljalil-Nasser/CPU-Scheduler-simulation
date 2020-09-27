#ifndef RESULT_H
#define RESULT_H
#include <QDialog>
#include<QtCore>
#include<QtGui>
#include <QGraphicsScene>
#include<queue>
#include<QGraphicsItem>
#include<QTableWidget>
using namespace  std;
namespace Ui {
class result;
}

class result : public QDialog
{
    Q_OBJECT

public:
    explicit result(QWidget *parent = nullptr);
    ~result();

private:
    Ui::result *ui;
    QGraphicsScene * scene ;
   QGraphicsRectItem *rect;
   queue<QTableWidgetItem *> x;
   queue<QGraphicsTextItem *> y;
};

#endif // RESULT_H

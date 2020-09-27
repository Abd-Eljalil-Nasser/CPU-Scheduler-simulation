#include "result.h"
#include "ui_result.h"
#include<process.h>
#include<node.h>
#include<list>
#include <QGraphicsScene>
#include <QGraphicsView>
#include<QGraphicsItem>
#include<QTableWidget>
#include<queue>
#include<algorithm>
using namespace std;
extern int number;
extern QString algorithm;
extern process * proc;
extern list<Node> output;
extern int TimeSclice;
result::result(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::result)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->draw->setScene(scene);
    QBrush greenBrush (Qt::green);
    QBrush redBrush (Qt::red);
    QPen blackpen (Qt::black);
    blackpen.setWidth(2);
    ui->tab->setRowCount(number);
    if (algorithm == "Preemptivepriority" ||algorithm=="priority")
    {
        ui->tab->setColumnCount(8);
    }
    else {
         ui->tab->setColumnCount(7);
         }
    ui->tab->setColumnWidth(0,150);
    ui->tab->setColumnWidth(1,150);
    ui->tab->setColumnWidth(2,150);
    ui->tab->setColumnWidth(3,150);
    ui->tab->setColumnWidth(4,150);
    ui->tab->setColumnWidth(5,150);
    ui->tab->setColumnWidth(6,150);
    if(algorithm == "Preemptivepriority" ||algorithm=="priority")
     {
         ui->tab->setColumnWidth(7,150);
     }
    int counter=0;
    ui->tab->setHorizontalHeaderItem(counter++,new QTableWidgetItem ("Process ID"));
    ui->tab->setHorizontalHeaderItem(counter++,new QTableWidgetItem ("Arrival time"));
    ui->tab->setHorizontalHeaderItem(counter++,new QTableWidgetItem ("Burst time"));
    if (algorithm == "Preemptivepriority" ||algorithm=="priority")
    {
     ui->tab->setHorizontalHeaderItem(counter++,new QTableWidgetItem ("priority"));
    }
    ui->tab->setHorizontalHeaderItem(counter++,new QTableWidgetItem ("Start Time"));
    ui->tab->setHorizontalHeaderItem(counter++,new QTableWidgetItem ("End Time"));
    ui->tab->setHorizontalHeaderItem(counter++,new QTableWidgetItem ("Turn Around Time"));
    ui->tab->setHorizontalHeaderItem(counter++,new QTableWidgetItem ("Wating Time"));
    for (int K=0;K<number;K++)
    {
        int counter =0;
         int temp1 = proc[K].get_id();
         QTableWidgetItem *item1  = new QTableWidgetItem;
         x.push(item1);
         item1->setText(QString::number(temp1));
         ui->tab->setItem(K,counter++, item1);

         temp1 = proc[K].get_arrivaltime();
         QTableWidgetItem *item2  = new QTableWidgetItem;
         x.push(item2);
         item2->setText(QString::number(temp1));
         ui->tab->setItem(K,counter++, item2);

         temp1 = proc[K].get_bursttime();
         QTableWidgetItem *item3  = new QTableWidgetItem;
         x.push(item3);
         item3->setText(QString::number(temp1));
         ui->tab->setItem(K,counter++, item3);

         if (algorithm == "Preemptivepriority" ||algorithm=="priority")
         {
             temp1 = proc[K].get_priority();
             QTableWidgetItem *item4  = new QTableWidgetItem;
             x.push(item4);
             item4->setText(QString::number(temp1));
             ui->tab->setItem(K,counter++, item4);
         }

         temp1 = proc[K].get_StartTime();
         QTableWidgetItem *item5  = new QTableWidgetItem;
         item5->setText(QString::number(temp1));
         x.push(item5);
         ui->tab->setItem(K,counter++, item5);

         temp1 = proc[K].get_EndTime();
         QTableWidgetItem *item6  = new QTableWidgetItem;
         item6->setText(QString::number(temp1));
         x.push(item6);
         ui->tab->setItem(K,counter++, item6);

         temp1 = proc[K].get_EndTime()-proc[K].get_arrivaltime();
         QTableWidgetItem *item7 = new QTableWidgetItem;
         item7->setText(QString::number(temp1));
         x.push(item7);
         ui->tab->setItem(K,counter++, item7);

         temp1 = proc[K].get_EndTime()-proc[K].get_arrivaltime()-proc[K].get_bursttime();
         QTableWidgetItem *item8  = new QTableWidgetItem;
         x.push(item8);
         item8->setText(QString::number(temp1));
         ui->tab->setItem(K,counter++, item8);


    }
    int startpoint=0;
    int endtime =0;
    int size = output.size();
    for (list<Node> ::iterator it = output.begin();it != output.end();it++)
        {
        int temp = it->get_start();
        int temp2 = it->get_end();
        if (endtime !=temp)
        {
           rect=scene->addRect(0+startpoint,0,(it->get_start()-endtime)*50,80,blackpen,greenBrush);
           QString temp_str="gap";
           QGraphicsTextItem *txtitem1 = new QGraphicsTextItem(temp_str);
           txtitem1->setPos(QPointF(((startpoint)+(startpoint-40+(it->get_start()-endtime)*50))/2,30));
           QFont Times ("Times",10,QFont::Bold);
           txtitem1->setFont(Times);
           scene->addItem(txtitem1);
           y.push(txtitem1);
           temp_str=QString::number(endtime);
           QGraphicsTextItem *txtitem2= new QGraphicsTextItem(temp_str);
           txtitem2->setPos(QPointF(startpoint-10,80));
           txtitem2->setFont(Times);
           scene->addItem(txtitem2);
           y.push(txtitem2);
           startpoint = startpoint + (it->get_start()-endtime)*50;
           endtime= endtime+it->get_start()-endtime;

        }
        rect=scene->addRect((0+startpoint),0,(it->get_end()-it->get_start())*50,80,blackpen,redBrush);
        QString temp_str="P"+QString::number(it->get_ProcessId());
        QGraphicsTextItem *txtitem3 = new QGraphicsTextItem(temp_str);
        y.push(txtitem3);
        int tem = (startpoint+startpoint+(it->get_end()-it->get_start())*50)/2 -15;
        txtitem3->setPos(QPointF(tem,30));
        QFont Times ("Times",10,QFont::Bold);
        txtitem3->setFont(Times);
        scene->addItem(txtitem3);
        temp_str=QString::number(endtime);
        QGraphicsTextItem *txtitem4= new QGraphicsTextItem(temp_str);
        txtitem4->setPos(QPointF(startpoint-10,80));
        y.push(txtitem4);
        scene->addItem(txtitem4);
        txtitem4->setFont(Times);
        startpoint = (it->get_end()-it->get_start())*50+startpoint;
        endtime = endtime+ it->get_end()-it->get_start();
        if (size==1){
            temp_str=QString::number(endtime);
            QGraphicsTextItem *txtitem5= new QGraphicsTextItem(temp_str);
            txtitem5->setPos(QPointF(startpoint-10,80));
            txtitem5->setFont(Times);
            scene->addItem(txtitem5);
            y.push(txtitem5);
        }
        size--;
        }



}

result::~result()
{
    while (x.empty()== false)
    {
        QTableWidgetItem *item= x.front();
        x.pop();
        delete item;
    }
    while (y.empty()==false){
        QGraphicsTextItem * item = y.front();
        y.pop();
        delete item;
    }
    scene->clear();
    scene->update();
    output.clear();
    delete ui;
}

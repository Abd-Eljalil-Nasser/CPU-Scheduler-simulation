#include "submittingdata.h"
#include "ui_submittingdata.h"
#include<QtCore>
#include<QDialog>
#include<QtGui>
#include<QMessageBox>
#include<QTableWidget>
#include<QTableView>
#include <QKeyEvent>
#include<QCloseEvent>
extern int number;
extern QString algorithm;
extern process * proc;
extern int TimeSclice;
submittingdata::submittingdata(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::submittingdata)
{
    this->setWindowFlags((
    (windowFlags() | Qt::CustomizeWindowHint)
    & ~Qt::WindowCloseButtonHint));
    ui->setupUi(this);
    mydatalate = new Delegate(this);
    if (algorithm=="SJF" || algorithm == "FCFS" ||algorithm == "PreemptiveSJF")
    {
       model = new QStandardItemModel(number,2,this);
       model->setHorizontalHeaderItem(0,new QStandardItem ("arrrival time"));
       model->setHorizontalHeaderItem(1,new QStandardItem("Busrt time"));
       ui->timeslice->hide();
       ui->label->hide();


    }
    if (algorithm == "Roundrobin")
    {
       model = new QStandardItemModel(number,2,this);
       model->setHorizontalHeaderItem(0,new QStandardItem ("arrrival time"));
       model->setHorizontalHeaderItem(1,new QStandardItem("Busrt time"));

    }

    else if (algorithm == "priority" ||algorithm == "Preemptivepriority")
    {
         model = new QStandardItemModel(number,3,this);
         model->setHorizontalHeaderItem(0,new QStandardItem ("arrrival time"));
         model->setHorizontalHeaderItem(1,new QStandardItem("Busrt time"));
         model->setHorizontalHeaderItem(2,new QStandardItem("priority"));
         ui->timeslice->hide();
         ui->label->hide();
    }
    ui->table->setModel(model);
    ui->table->setItemDelegate(mydatalate);

}

/*void submittingdata::setdata(int number , QString algorithm){

  ui->table->setRowCount(number);
  if (algorithm=="SJF")
  {
      ui->table->setColumnCount(2);
      ui->table->setColumnWidth(0,200);
      ui->table->setColumnWidth(1,200);
      ui->table->setHorizontalHeaderItem(0,new QTableWidgetItem ("arrrival time"));
      ui->table->setHorizontalHeaderItem(1,new QTableWidgetItem ("Busrt time"));
      ui->timeslice->hide();
      ui->label->hide();
  }
 else if (algorithm=="FCFS")
 {
      ui->table->setColumnCount(2);
      ui->table->setHorizontalHeaderItem(0,new QTableWidgetItem ("arrrival time"));
      ui->table->setHorizontalHeaderItem(1,new QTableWidgetItem ("Busrt time"));
      ui->timeslice->hide();
      ui->label->hide();

 }
  else if (algorithm == "priority")
  {

      ui->table->setColumnCount(3);
      ui->table->setHorizontalHeaderItem(0,new QTableWidgetItem ("arrrival time"));
      ui->table->setHorizontalHeaderItem(1,new QTableWidgetItem ("Busrt time"));
      ui->table->setHorizontalHeaderItem(2,new QTableWidgetItem ("priority"));
      ui->timeslice->hide();
      ui->label->hide();

  }
  else if (algorithm == "Roundrobin")
  {
      ui->table->setColumnCount(2);
      ui->table->setHorizontalHeaderItem(0,new QTableWidgetItem ("arrrival time"));
      ui->table->setHorizontalHeaderItem(1,new QTableWidgetItem ("Busrt time"));

  }
}*/
submittingdata::~submittingdata()
{
    delete ui;
}
/*void submittingdata::keyPressEvent(QKeyEvent * e){
    if(e->key() == Qt::Key_Exit)
    {
        e->ignore();
    }
}
*/
void submittingdata::on_submittable_clicked()
{
    if (algorithm=="SJF" || algorithm=="FCFS" || algorithm=="PreemptiveSJF" ||algorithm == "Roundrobin" )
    {
       int i;
        for ( i=0;i<number;i++)
        {

            QModelIndex index = model->index(i,0,QModelIndex());
            QString value = ui->table->model()->data(index).toString();
            if (value == "")
            {
                QMessageBox  message;
                message.setMinimumSize(1000,1000);
                message.setWindowTitle("ERROR");
                message.setText("something wrong happened");
                message.setInformativeText(" please , fill in the required data");
                message.setIcon(QMessageBox::Critical);
                message.setStandardButtons(QMessageBox::Ok);
                message.setDefaultButton(QMessageBox::Ok);
                message.exec();
                break;
            }
            else {
                int tempint = value.toInt();
                 proc[i].set_arrivaltime(tempint);
            }
            index = model->index(i,1,QModelIndex());
           value = ui->table->model()->data(index).toString();
           if (value == "")
           {
               QMessageBox  message;
               message.setMinimumSize(1000,1000);
               message.setWindowTitle("ERROR");
               message.setText("something wrong happened");
               message.setInformativeText(" please , fill in the required data");
               message.setIcon(QMessageBox::Critical);
               message.setStandardButtons(QMessageBox::Ok);
               message.setDefaultButton(QMessageBox::Ok);
               message.exec();
               break;
           }
           else {
               int tempint = value.toInt();
                proc[i].set_bursttime(tempint);
                proc[i].set_RemainingTime(tempint);
           }
           proc[i].set_id(i+1);
           proc[i].set_StartTime(-1);
           proc[i].set_EndTime(-1);
        }
        if (algorithm=="Roundrobin")
        {
            QString x = ui->timeslice->text();
            int y = x.toInt();
            TimeSclice = y;
            if (y==0)
            {
                QMessageBox  message;
                message.setMinimumSize(1000,1000);
                message.setWindowTitle("Error");
                message.setText("something happened");
                message.setInformativeText("enter a postive number for time slice");
                message.setIcon(QMessageBox::Critical);
                message.setStandardButtons(QMessageBox::Ok);
                message.setDefaultButton(QMessageBox::Ok);
                int a=message.exec();
                i=0;
            }
        }
        if (i == number)
        {

            this->close();
        }
    }
    if (algorithm == "priority" || algorithm=="Preemptivepriority" )
    {
       int i;
        for ( i=0;i<number;i++)
        {

            QModelIndex index = model->index(i,0,QModelIndex());
            QString value = ui->table->model()->data(index).toString();
            if (value == "")
            {
                QMessageBox  message;
                message.setMinimumSize(1000,1000);
                message.setWindowTitle("ERROR");
                message.setText("something wrong happened");
                message.setInformativeText(" please , fill in the required data");
                message.setIcon(QMessageBox::Critical);
                message.setStandardButtons(QMessageBox::Ok);
                message.setDefaultButton(QMessageBox::Ok);
                message.exec();
                break;
            }
            else {
                int tempint = value.toInt();
                 proc[i].set_arrivaltime(tempint);

            }
            index = model->index(i,1,QModelIndex());
           value = ui->table->model()->data(index).toString();
           if (value == "")
           {
               QMessageBox  message;
               message.setMinimumSize(1000,1000);
               message.setWindowTitle("ERROR");
               message.setText("something wrong happened");
               message.setInformativeText(" please , fill in the required data");
               message.setIcon(QMessageBox::Critical);
               message.setStandardButtons(QMessageBox::Ok);
               message.setDefaultButton(QMessageBox::Ok);
               message.exec();
               break;
           }
           else {
               int tempint = value.toInt();
                proc[i].set_bursttime(tempint);
                proc[i].set_RemainingTime(tempint);
           }
            index = model->index(i,2,QModelIndex());
            value = ui->table->model()->data(index).toString();
           if (value == "")
           {
               QMessageBox  message;
               message.setMinimumSize(1000,1000);
               message.setWindowTitle("ERROR");
               message.setText("something wrong happened");
               message.setInformativeText(" please , fill in the required data");
               message.setIcon(QMessageBox::Critical);
               message.setStandardButtons(QMessageBox::Ok);
               message.setDefaultButton(QMessageBox::Ok);
               message.exec();
               break;
           }
           else {
               int tempint = value.toInt();
                proc[i].set_priority(tempint);
           }
            proc[i].set_id(i+1);
            proc[i].set_StartTime(-1);
            proc[i].set_EndTime(-1);
        }
        if (i == number)
        {

            this->close();

        }
    }


    //ui->table->item()
}


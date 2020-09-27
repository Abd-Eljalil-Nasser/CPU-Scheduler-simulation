#include "mainwindow.h"
#include"process.h"
#include"node.h"
#include<result.h>
#include "ui_mainwindow.h"
#include"QPixmap"
#include<submittingdata.h>
#include<QMessageBox>
#include<QDebug>
#include<list>
#include<algorithm>
#include<result.h>
using namespace std;
extern int number;
extern QString algorithm;
extern process * proc;
extern list<Node> output;
extern int TimeSclice;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    QFont Times ("Times",20,QFont::Bold);
    ui->setupUi(this);
    this->setFixedSize(this->geometry().width(),this->geometry().height());

    QPixmap pix(":/resources/image/arm-processor.jpg");
   // int w = ui->label->width();
    // int h = ui->label->height();
    ui->label->setScaledContents(true);
    ui->label->setPixmap(pix);
    //ui->label->setPixmap(pix.scaled(w,h,Qt::AspectRatioMode));
    ui->SJF->setFont(Times);
    ui->SJF->setStyleSheet("color:rgb(255, 255, 255)");
    ui->PreemptiveSJF->setFont(Times);
    ui->PreemptiveSJF->setStyleSheet("color:rgb(255, 255, 255)");
    ui->FCFS->setFont(Times);
    ui->FCFS->setStyleSheet("color:rgb(255, 255, 255)");
    ui->RoundRobin->setFont(Times);
    ui->RoundRobin->setStyleSheet("color:rgb(255, 255, 255)");
    ui->priority->setFont(Times);
    ui->priority->setStyleSheet("color:rgb(255, 255, 255)");
    ui->Preemptivepriority->setFont(Times);
    ui->Preemptivepriority->setStyleSheet("color:rgb(255, 255, 255)");
    ui->lab->setFont(Times);
    ui->lab->setStyleSheet("color:rgb(255, 255, 255)");
    ui->label_3->setFont(Times);
    ui->label_3->setStyleSheet("color:rgb(255, 255, 255)");

}

MainWindow::~MainWindow()
{
    delete ui;
}

/*void MainWindow::calculate (int number ,QString algorithm , submittingdata & input ){
   input.setdata(number,algorithm);
}
*/
bool arvtime(process p1, process p2){
    if (p1.arrivaltime != p2.arrivaltime)
    {
     return (p1.arrivaltime < p2.arrivaltime);
    }
    return (p1.id) < (p2.id);
}
bool rearrange(process p1 , process p2)
{
    return p1.get_id()<p2.get_id();
}
 void SJFpreemtpive_Sort(process * input, int &index, int size, int start, int end) {
     if (index == size - 1)
     {
         return;
     }
     int itirator = index+1;
     int tem = 1000000000;

     int miniarrtime = 1000000000;
     int miniindex = -20;
     while (itirator < size)
     {
         if ( input[itirator].arrivaltime  > start && input[itirator].arrivaltime < end)
         {
             {
                 if (input[itirator].RemainingTime < (start +input[index].RemainingTime - (input[itirator].arrivaltime)))
                  {
                     if (input[itirator].RemainingTime < tem  && input[itirator].arrivaltime < miniarrtime)
                      {
                         tem = input[itirator].RemainingTime;
                         miniarrtime = input[itirator].arrivaltime;
                         miniindex = itirator;
                         itirator++;
                         continue;
                      }
                  }
             }
         }
         itirator++;
     }
     if (miniindex != -20)
     {
         input[index].set_RemainingTime(start+input[index].RemainingTime - input[miniindex].arrivaltime);
         if (input[index].get_StartTime()!= -1)
         {
             input[index].set_StartTime(start);
         }
         process temp = input[index];
         input[index ] = input[miniindex];
         input[miniindex] = temp;
         return;
     }
     else {
         if (input[index].StartTime == -1)
         {

             input[index].StartTime = start;
         }
         input[index].EndTime = start + input[index].RemainingTime;
         index++;
     }

 }
 void SJFNon_Sort(process * input, int index, int size, int time) {
     if (index == size - 1)
     {
         return;
     }
     int itirator = index;
     int tem = 1000000000;
     int miniindex = -20;
     while (itirator < size)
     {
         if (input[itirator].arrivaltime <= time)
         {
             if (input[itirator].bursttime < tem)
             {
                 tem = input[itirator].bursttime;
                 miniindex = itirator;
                 itirator++;
                 continue;
             }
             itirator++;
             continue;
         }
         itirator++;
         continue;
     }
     if (miniindex != -20)
     {
         process temp = input[index];
         input[index] = input[miniindex];
         input[miniindex] = temp;
     }

 }
 bool arvtime2(process p1, process p2) {
     if (p1.arrivaltime != p2.arrivaltime)
     {
         return p1.arrivaltime < p2.arrivaltime;
     }
     else
     {
         if (p1.bursttime == p2.bursttime)
         {
             return p1.id < p2.id;
         }
         return p1.bursttime < p2.bursttime;
     }
 }
 bool arvtime3(process p1, process p2) {
     if (p1.arrivaltime != p2.arrivaltime)
     {
         return p1.arrivaltime < p2.arrivaltime;
     }
     else
     {
         if (p1.priority == p2.priority)
         {
             return p1.id < p2.id;
         }
         return p1.priority < p2.priority;
     }
 }

 void SJF_Sort(process * input, int index, int size, int time) {
     if (index == size - 1)
     {
         return;
     }
     int itirator = index;
     int tem = 1000000000;
     int miniindex = -20;
     while (itirator < size)
     {
         if (input[itirator].arrivaltime <= time)
         {
             if (input[itirator].RemainingTime < tem)
             {
                 tem = input[itirator].RemainingTime;
                 miniindex = itirator;
                 itirator++;
                 continue;
             }
             itirator++;
             continue;
         }
         itirator++;
         continue;
     }
     if (miniindex != -20)
     {
         process temp = input[index];
         input[index] = input[miniindex];
         input[miniindex] = temp;
     }

 }
 void priorityNon_Sort(process * input, int index, int size, int time) {
     if (index == size - 1)
     {
         return;
     }
     int itirator = index;
     int prior = 1000000000;
     int miniindex = -20;
     while (itirator < size)
     {
         if (input[itirator].arrivaltime <= time)
         {
             if (input[itirator].priority < prior)
             {
                 prior = input[itirator].priority;
                 miniindex = itirator;
                 itirator++;
                 continue;
             }
             itirator++;
             continue;
         }
         itirator++;
         continue;
     }
     if (miniindex != -20)
     {
         process temp = input[index];
         input[index] = input[miniindex];
         input[miniindex] = temp;
     }

 }
 void prioritypreemtpive_Sort(process * input, int &index, int size, int start, int end) {
      if (index == size - 1)
      {
          return;
      }
      int itirator = index;
      int pri = 1000000000;

      int miniarrtime = 1000000000;
      int miniindex = -20;
      while (itirator < size)
      {
          if (input[itirator].arrivaltime > start && input[itirator].arrivaltime < end)
          {

                  if (input[itirator].priority < input[index].priority && input[itirator].priority < pri && input[itirator].arrivaltime<miniarrtime)
                  {
                      pri = input[itirator].priority;
                      miniarrtime = input[itirator].get_arrivaltime();
                      miniindex = itirator;
                      itirator++;
                      continue;
                  }
          }
          itirator++;

      }
      if (miniindex != -20)
      {
          input[index].set_RemainingTime(start + input[index].RemainingTime - input[miniindex].arrivaltime);
          process temp = input[index];
          input[index] = input[miniindex];
          input[miniindex] = temp;
          return;
      }
      else
      {
          if (input[index].StartTime == -1)
           {

              input[index].StartTime = start;
           }
          input[index].EndTime = start + input[index].RemainingTime;
          index++;
      }
 }
 void priority_Sort(process * input, int index, int size, int time) {
     if (index == size - 1)
     {
         return;
     }
     int itirator = index;
     int pri = 1000000000;
     int miniindex = -20;
     while (itirator < size)
     {
         if (input[itirator].arrivaltime <= time)
         {
             if (input[itirator].priority < pri)
             {
                 pri = input[itirator].priority;
                 miniindex = itirator;
                 itirator++;
                 continue;
             }
             itirator++;
             continue;
         }
         itirator++;
         continue;
     }
     if (miniindex != -20)
     {
         process temp = input[index];
         input[index] = input[miniindex];
         input[miniindex] = temp;
     }

 }
void SJF_Nonpreemptive(int size, process* array, list<Node> & output){
    sort(array, array + size, arvtime2);
    array[0].set_StartTime(array[0].get_arrivaltime());
    array[0].set_EndTime(array[0].get_StartTime() + array[0].get_bursttime());
    Node x;
    x.set_ProcessId(array[0].get_id());
    x.set_start(array[0].get_StartTime());
    x.set_end(array[0].get_EndTime());
    output.push_back(x);
    int starttime = array[0].get_EndTime();
    int index = 1;
    while (index < size)
    {
        SJFNon_Sort(array, index, size, starttime);
        if (array[index].get_arrivaltime() <= starttime)
        {
        //starttime = starttime + array[index].get_bursttime();
        x.set_ProcessId(array[index].get_id());
        x.set_start(starttime);
        x.set_end(starttime + array[index].get_bursttime());
        array[index].set_StartTime(starttime);
        array[index].set_EndTime(starttime + array[index].get_bursttime());
        output.push_back(x);
        starttime = array[index].get_EndTime();
        index++;
        }
        else
        {
            starttime = array[index].get_arrivaltime();
            x.set_ProcessId(array[index].get_id());
            x.set_start(starttime);
            x.set_end(starttime + array[index].get_bursttime());
            array[index].set_StartTime(starttime);
            array[index].set_EndTime(starttime + array[index].get_bursttime());
            output.push_back(x);
            starttime = array[index].get_EndTime();
            index++;
        }
    }
    sort(proc,proc+number,rearrange);
}
void SJF_preemptive(int size, process* array, list<Node> & output){
    sort(array, array + size, arvtime2);
    array[0].set_StartTime(array[0].get_arrivaltime());
    int completed = 0;
    int start = array[0].get_StartTime();
    int index = 0;
    int prvinde = index;
    //Node x;
    while (index < size-1)
    {
        int temp1 = array[index].get_id();
        //int temp2 = array[index].get
        //int temp3

        SJFpreemtpive_Sort(array, index, size, start, (array[index].get_RemainingTime() + start));
        if (prvinde == index)
        {
            Node X;
            X.set_ProcessId(temp1);
            X.set_start(start);
            X.set_end(array[index].get_arrivaltime());
            output.push_back(X);
            start = array[index].get_arrivaltime();
            if (array[index].get_StartTime() == -1)
            {
                array[index].set_StartTime(start);
            }

        }
        else {
            Node X;
            X.set_ProcessId(temp1);
            X.set_start(start);
            X.set_end(start + array[prvinde].get_RemainingTime());
            start = start + array[prvinde].get_RemainingTime();
            array[prvinde].set_RemainingTime (0);
            output.push_back(X);
            completed++;
            prvinde = index;
            SJF_Sort(array, index,size,start);
            if (array[index].get_arrivaltime() > start)
            {
                start = array[index].get_arrivaltime();
            }
        }
    }
    if (array[size - 1].get_StartTime() == -1)
    {
        array[size - 1].set_StartTime(array[size - 1].get_arrivaltime());
    }
    array[size - 1].set_EndTime(start + array[size - 1].get_RemainingTime());
    array[size - 1].set_RemainingTime(0);
    Node X;
    X.set_ProcessId(array[size - 1].get_id());
    X.set_start(start);
    X.set_end(array[size - 1].get_EndTime());
    output.push_back(X);
    sort(proc,proc+number,rearrange);
}
void prioirty_non(int size, process* array, list<Node> & output)
{
    sort(array, array + size, arvtime3);
    array[0].set_StartTime(array[0].get_arrivaltime());
    array[0].set_EndTime(array[0].get_StartTime() + array[0].get_bursttime());
    Node x;
    x.set_ProcessId(array[0].get_id());
    x.set_start(array[0].get_StartTime());
    x.set_end(array[0].get_EndTime());
    output.push_back(x);
    int starttime = array[0].get_EndTime();
    int index = 1;
    while (index < size)
    {
        priorityNon_Sort(array, index, size, starttime);
        if (array[index].get_arrivaltime() <= starttime)
        {
            //starttime = starttime + array[index].get_bursttime();
            x.set_ProcessId(array[index].get_id());
            x.set_start(starttime);
            x.set_end(starttime + array[index].get_bursttime());
            array[index].set_StartTime(starttime);
            array[index].set_EndTime(starttime + array[index].get_bursttime());
            output.push_back(x);
            starttime = array[index].get_EndTime();
            index++;
        }
        else
        {
            starttime = array[index].get_arrivaltime();
            x.set_ProcessId(array[index].get_id());
            x.set_start(starttime);
            x.set_end(starttime + array[index].get_bursttime());
            array[index].set_StartTime(starttime);
            array[index].set_EndTime(starttime + array[index].get_bursttime());
            output.push_back(x);
            starttime = array[index].get_EndTime();
            index++;
        }
    }
    sort(proc,proc+number,rearrange);
}
void priority_preemptive(int size, process* array, list<Node> & output) {
    sort(array, array + size, arvtime3);
    array[0].set_StartTime(array[0].get_arrivaltime());
    int completed = 0;
    int start = array[0].get_StartTime();
    int index = 0;
    int prvinde = index;
    while (index < size - 1)
    {
        int temp1 = array[index].get_id();
        prioritypreemtpive_Sort(array, index, size, start, (array[index].get_RemainingTime() + start));
        if (prvinde == index)
        {
            Node X;
            X.set_ProcessId(temp1);
            X.set_start(start);
            X.set_end(array[index].get_arrivaltime());
            output.push_back(X);
            start = array[index].get_arrivaltime();
            if (array[index].get_StartTime() == -1)
            {
                array[index].set_StartTime(start);
            }

        }
        else {
            Node X;
            X.set_ProcessId(temp1);
            X.set_start(start);
            X.set_end(start + array[prvinde].get_RemainingTime());
            start = start + array[prvinde].get_RemainingTime();
            array[prvinde].set_RemainingTime(0);
            output.push_back(X);
            completed++;
            prvinde = index;
            priority_Sort(array, index, size, start);
            if (array[index].get_arrivaltime() > start)
            {
                start = array[index].get_arrivaltime();
            }
        }
    }
    if (array[size - 1].get_StartTime() == -1)
    {
        array[size - 1].set_StartTime(array[size - 1].get_arrivaltime());
    }
    array[size - 1].set_EndTime(start + array[size - 1].get_RemainingTime());
    array[size - 1].set_RemainingTime(0);
    Node X;
    X.set_ProcessId(array[size - 1].get_id());
    X.set_start(start);
    X.set_end(array[size - 1].get_EndTime());
    output.push_back(X);
    sort(proc,proc+number,rearrange);
}
void FCFS(int size, process* arr, list<Node> & output)
{
    //sort the array of processes according to arrival time
    sort(arr, arr + size, arvtime);


    //first node
    Node x1;
    x1.set_ProcessId(arr[0].get_id());
    x1.set_start(arr[0].get_arrivaltime() );
    x1.set_end(arr[0].get_arrivaltime() + arr[0].get_bursttime());
    arr[0].set_EndTime(arr[0].get_arrivaltime() + arr[0].get_bursttime());
    arr[0].set_StartTime(arr[0].get_arrivaltime());
    arr[0].set_RemainingTime(0);

    //indicate to finish time to first node
    int end = x1.get_end();
    output.push_back(x1);
    for (int i = 1; i < size; i++)
    {
        Node x;
        x.set_ProcessId ( arr[i].get_id() );
        //if there is a gap between end of process and arrival of next
        if (end < arr[i].get_arrivaltime() )
        {
            x.set_start(arr[i].get_arrivaltime());
            x.set_end(arr[i].get_arrivaltime() + arr[i].get_bursttime());
            arr[i].set_StartTime(arr[i].get_arrivaltime());
            arr[i].set_EndTime(arr[i].get_arrivaltime() + arr[i].get_bursttime());
            arr[i].set_RemainingTime(0);
        }
        else
        {
            x.set_start(end);
            x.set_end(end + arr[i].get_bursttime());
            arr[i].set_StartTime(end);
            arr[i].set_EndTime(end+ arr[i].get_bursttime());
            arr[i].set_RemainingTime(0);
        }


        output.push_back(x);
        end = x.get_end();
    }
    sort(proc,proc+number,rearrange);
}
void Round_Robin(int timeslice, int size, process* arr, list<Node> & output) {

    for (int i = 0; i < size; i++)
    {
        arr[i].set_RemainingTime(arr[i].get_bursttime());
    }
    //sort the array by arrival time
    sort(arr, arr + size, arvtime);

    //set the starting time = the arrival time of the firts process
    int running = arr[0].get_arrivaltime();

    bool still = true;
    int last_arrivale_time = arr[size - 1].get_arrivaltime();
    while (still) {

        still = false;
        for (int i = 0; i < size; i++)
        {

            if (arr[i].get_RemainingTime() > 0) {
                // if there is some remaining time left in the process

                if (arr[i].get_arrivaltime() <= running) {
                    if(arr[i].get_bursttime() == arr[i].get_RemainingTime()){
                        arr[i].set_StartTime(running);
                    }
                    Node x;
                    x.set_ProcessId(arr[i].get_id());
                    x.set_start(running);

                    //if the remaining time is bigger or smaller then remainingtime
                    if (arr[i].get_RemainingTime() >= timeslice) {
                        running = running + timeslice;
                        arr[i].set_RemainingTime(arr[i].get_RemainingTime() - timeslice);
                    }
                    else
                    {
                        running = running + arr[i].get_RemainingTime();
                        arr[i].set_RemainingTime(0);
                    }


                    x.set_end(running);
                    output.push_back(x);
                    //law laf 3ala loop kolha w md5lsh hena eb2a mfesh remaining time in any process
                    still = true;
                    if (arr[i].get_RemainingTime() <= 0)
                    {
                        arr[i].set_EndTime(running);
                    }


                }
            }

        }
        if (running < last_arrivale_time && !still)
        {
            still = true;
            running++;
        }
    }
sort(proc,proc+number,rearrange);
}
void MainWindow::on_submitdata_clicked()
{
    int a;
    algorithm= ui->processes->text();
    number  = algorithm.toInt();
        if (number == 0)
        {
        QMessageBox  message;
        message.setMinimumSize(1000,1000);
        message.setWindowTitle("Error");
        message.setText("something happened");
        message.setInformativeText("enter a postive number of processes");
        message.setIcon(QMessageBox::Critical);
        message.setStandardButtons(QMessageBox::Ok);
        message.setDefaultButton(QMessageBox::Ok);
        ui->processes->clear();
        a =message.exec();
        }
    else
        {

             if (ui->SJF->isChecked())
             {
             algorithm = "SJF";
             }
             else if (ui->FCFS->isChecked())
             {
                 algorithm="FCFS";
             }
             else if (ui->priority->isChecked())
             {
                 algorithm="priority";
             }
             else if (ui->RoundRobin->isChecked())
             {
                 algorithm= "Roundrobin";
             }
             else if (ui->PreemptiveSJF->isChecked())
             {
                 algorithm = "PreemptiveSJF";
             }
             else if (ui->Preemptivepriority->isChecked())
             {
                 algorithm="Preemptivepriority";
             }
             else {
                 algorithm="";
             }
             if (algorithm =="")
             {
                 QMessageBox  message;
                 message.setMinimumSize(1000,1000);
                 message.setWindowTitle("Error");
                 message.setText("something happened");
                 message.setInformativeText("choose the required algorithm");
                 message.setIcon(QMessageBox::Critical);
                 message.setStandardButtons(QMessageBox::Ok);
                 message.setDefaultButton(QMessageBox::Ok);
                 a =message.exec();
             }
             else {
                 proc = new process[number];
                 submittingdata x(this);
                  int r =x.exec();
                  int temp=1;
                 if (temp ==1)
                 {
                     if (algorithm=="SJF")
                     {
                      SJF_Nonpreemptive(number,proc,output);
                     }
                     else if(algorithm=="FCFS")
                     {
                     FCFS(number,proc,output);
                     }
                     else if (algorithm=="priority")
                     {
                         prioirty_non(number,proc,output);
                     }
                     else if (algorithm=="Roundrobin")
                     {
                      Round_Robin(TimeSclice,number,proc,output);
                     }
                     else if (algorithm == "PreemptiveSJF")
                     {
                         SJF_preemptive(number,proc,output);
                     }
                     else if (algorithm=="Preemptivepriority")
                     {
                         priority_preemptive(number,proc,output);
                     }
                     result y(this);
                     y.exec();
                 }

             }
            // proc = new process[number];
            // submittingdata x(this);
            // x.exec();
        }
        /*proc = new process[number];
        submittingdata x(this);
        x.exec();*/





}

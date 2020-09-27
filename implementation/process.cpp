#include "process.h"
#include"Node.h"
process::process()
{
priority =0;
id = 0;
bursttime = 0;
arrivaltime = 0;
RemainingTime = 0;
StartTime = 0;
EndTime = 0;

}
process::process(int id_, int arvtime, int bsttime, int pri){
   id = id_;
   bursttime =  bsttime;
   arrivaltime = arvtime;
   priority = pri;
   RemainingTime = bsttime;
   StartTime = 0;
   EndTime = 0;
}
void process::set_id(int id_)
{
    id = id_;
}
int process::get_id(){
    return id;
}
void process::set_priority(int pri)
{
    priority = pri;
}
int process::get_priority(){
    return priority;
}
void process::set_bursttime(int bsttime)
{
    bursttime = bsttime;
}
int process::get_bursttime()
{
    return bursttime;
}
void process::set_arrivaltime(int arvtime){
    arrivaltime=arvtime;
}
int process::get_arrivaltime(){
    return arrivaltime;
}
void process::set_RemainingTime(int input)
{
    RemainingTime = input;
}
int process::get_RemainingTime() {
    return RemainingTime;
}
void process::set_StartTime(int input) {
    StartTime = input;
}
int process::get_StartTime() {
    return StartTime;
}
void process::set_EndTime(int input) {
    EndTime = input;
}
int process::get_EndTime() {
    return EndTime;
}
/*
 bool arvtime(process p1, process p2){
     return (p1.arrivaltime < p2.arrivaltime);
}
*/
/*
 void SJFpreemtpive_Sort(process * input, int &index, int size, int start, int end) {
     if (index == size - 1)
     {
         return;
     }
     int itirator = index;
     int tem = 1000000000;

     int miniarrtime = 1000000000;
     int miniindex = 0;
     while (itirator < size)
     {
         if ( input[itirator].arrivaltime < end)
         {
             if (input[itirator].StartTime !=-1)
             {
                 if (input[itirator].RemainingTime < input[index].RemainingTime && input[itirator].RemainingTime < tem) {
                     tem = input[itirator].RemainingTime;
                    // miniarrtime = input[itirator].arrivaltime;
                     miniarrtime = 1000000000;
                     miniindex = itirator;
                     itirator++;
                     continue;
                 }

             }
             else
             {
                 if (input[itirator].RemainingTime < (start +input[index].RemainingTime - input[itirator].arrivaltime))
                 {
                     if (input[itirator].RemainingTime < tem  && input[itirator].arrivaltime < miniarrtime)
                     {
                         tem = input[itirator].RemainingTime;
                         miniarrtime = input[itirator].arrivaltime;
                         miniindex = itirator;
                         itirator++;
                         continue;
                     }
                     // tem = input[itirator].RemainingTime;
                      //miniindex = itirator;
                     itirator++;
                     continue;
                 }
                 itirator++;
                 continue;
             }
             itirator++;
             continue;
         }
         itirator++;
         continue;
     }
     if (miniindex != 0)
     {

         input[index].set_RemainingTime(start+input[index].RemainingTime - input[miniindex].arrivaltime);
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
     int miniindex = 0;
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
     if (miniindex != 0)
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
     int miniindex = 0;
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
     if (miniindex != 0)
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
     int miniindex = 0;
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
     if (miniindex != 0)
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
      int miniindex = 0;
      while (itirator < size)
      {
          if ( input[itirator].arrivaltime < end)
          {
              if (input[itirator].StartTime != -1)
              {
                  if (input[itirator].priority < input[index].priority && input[itirator].priority < pri) {
                      pri = input[itirator].priority;
                      // miniarrtime = input[itirator].arrivaltime;
                      miniarrtime = 1000000000;
                      miniindex = itirator;
                      itirator++;
                      continue;
                  }

              }
              else
              {
                  if (input[itirator].priority <  input[index].priority )
                  {
                      if (input[itirator].priority < pri  && input[itirator].arrivaltime < miniarrtime)
                      {
                          pri = input[itirator].priority;
                          miniarrtime = input[itirator].arrivaltime;
                          miniindex = itirator;
                          itirator++;
                          continue;
                      }
                      // tem = input[itirator].RemainingTime;
                      //miniindex = itirator;
                      itirator++;
                      continue;
                  }
                  itirator++;
                  continue;
              }
              itirator++;
              continue;
          }
          itirator++;
          continue;
      }
      if (miniindex != 0)
      {

          input[index].set_RemainingTime(start + input[index].RemainingTime - input[miniindex].arrivaltime);
          process temp = input[index];
          input[index] = input[miniindex];
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
 void priority_Sort(process * input, int index, int size, int time) {
     if (index == size - 1)
     {
         return;
     }
     int itirator = index;
     int pri = 1000000000;
     int miniindex = 0;
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
     if (miniindex != 0)
     {
         process temp = input[index];
         input[index] = input[miniindex];
         input[miniindex] = temp;
     }

 }
 */

    /* if (p1.arrivaltime <= input && p2.arrivaltime <= input)
     {
         if (p1.bursttime < p2.bursttime)
         {
             return true;
         }
         return false;
     }
     else if (p1.arrivaltime <=  input &&  p2.arrivaltime>input)
     {
         return true;
     }
     else if(p1.arrivaltime > input &&  p2.arrivaltime <= input) {
         return false;
     }
     return true;
 }*/

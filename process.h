#ifndef PROCESS_H
#define PROCESS_H
class process
{
private:
    int id ;
    int arrivaltime;
    int bursttime;
    int priority;
    int StartTime;
    int EndTime;
    int RemainingTime;

public:
    process(int id_,int arvtime, int bsttime, int pri);
    process();
    void set_id(int id_);
    int get_id();
    void set_arrivaltime(int arvtime);
    int get_arrivaltime();
    void set_bursttime(int bsttime);
    int get_bursttime();
    void set_priority(int pri);
    int get_priority();
    void set_RemainingTime(int input);
    int get_RemainingTime();
    void set_StartTime(int input);
    int get_StartTime();
    void set_EndTime(int input);
    int get_EndTime();
    friend bool arvtime(process p1, process p2);
    friend bool arvtime2(process p1, process p2);
    friend bool arvtime3(process p1, process p2);
    //friend bool prioirtyNon_Sort(process p1, process p2);
    friend void SJFNon_Sort(process * input, int index, int size, int time);
    friend void SJFpreemtpive_Sort(process * input,int &index, int size, int start , int end);
    friend void SJF_Sort(process * input, int index, int size, int time);
    friend void priorityNon_Sort(process * input, int index, int size, int time);
    friend void prioritypreemtpive_Sort(process * input, int &index, int size, int start, int end);
    friend void priority_Sort(process * input, int index, int size, int time);


};

#endif // PROCESS_H

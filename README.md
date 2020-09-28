# CPU Scheduler simualtion

## Requirements 
1.C++ 

2.Qt creator 

## Describtion 
CPU scheduling is a process which allows one process to use the CPU while the execution of another process is on hold(in waiting state) due to unavailability of any resource like I/O etc, thereby making full use of CPU. The aim of CPU scheduling is to make the system efficient, fast and fair.  Whenever the CPU becomes idle, the operating system must select one of the processes in the ready queue to be executed. The selection process is carried out by the short-term scheduler (or CPU scheduler). The scheduler selects from among the processes in memory that are ready to execute, and allocates the CPU to one of them. This project make a simulation for CPU scheduler using different scheduling algorithms using c++ and QT . 

### scheduling algorithms 
1. First come First serve (FCFS)
2. Shortest job first (SJF) (Preemptive and Non Preemptive)
3. Priority (Preemptive and Non Preemptive) .The smaller the priority number the
higher the priority .
4. Round Robin

## input 
Type of the scheduler , number of Processes and required information about each process
according to the scheduler type.

## output 
Gantt Char and a table contain The process Id (number of the process), Arrival time ,  Burst time ,priority(in Priority scheduling algorithm ),Start time , End time , Turn Arround time , Waiting time .

## test 

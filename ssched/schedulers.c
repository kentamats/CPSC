#include "schedulers.h"
#include "list.h"
#include "cpu.h"
#include "task.h"

//Helper function to sort tasks based on burst time using bubble sort
struct node* sort_tasks_by_burst(struct node* start) {
    int swapped;
    struct node *ptr1;
    struct node *lptr = NULL;

    if (start == NULL)
        return NULL;

    do {
        swapped = 0;
        ptr1 = start;

        while (ptr1->next != lptr) {
            if (ptr1->task->burst > ptr1->next->task->burst) {
                //Swap tasks in nodes
                Task *temp = ptr1->task;
                ptr1->task = ptr1->next->task;
                ptr1->next->task = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);

    return start;
}

//Helper function to sort tasks based on priority using bubble sort
struct node* sort_tasks_by_priority(struct node* start) {
    int swapped;
    struct node *ptr1;
    struct node *lptr = NULL;

    if (start == NULL)
        return NULL;

    do {
        swapped = 0;
        ptr1 = start;

        while (ptr1->next != lptr) {
            if (ptr1->task->priority > ptr1->next->task->priority) {
                //Swap tasks in nodes
                Task *temp = ptr1->task;
                ptr1->task = ptr1->next->task;
                ptr1->next->task = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);

    return start;
}

void schedule_fcfs() {
    struct node *temp = taskList;

    while (temp != NULL) {
        Task *task = temp->task;
        run(task, task->burst);
        temp = temp->next;
    }
}

void schedule_sjf() {
    taskList = sort_tasks_by_burst(taskList);
    schedule_fcfs();
}

void schedule_priority() {
    taskList = sort_tasks_by_priority(taskList);
    schedule_fcfs();
}

void schedule_rr() {
    int quantum = 10;
    struct node *temp;

    while (taskList) {
        temp = taskList;
        while (temp != NULL) {
            Task *task = temp->task;
            if (task->burst <= quantum) {
                run(task, task->burst);
                //Remove the task from taskList
                delete(&taskList, task);
            } else {
                run(task, quantum);
                task->burst -= quantum;
            }
            temp = temp->next;
        }
    }
}

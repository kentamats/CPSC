#define MIN_PRIORITY 1
#define MAX_PRIORITY 10

// add a task to the list 
void add(char *name, int priority, int burst);

// invoke the scheduler
void schedule();

void schedule_fcfs();
void schedule_sjf();
void schedule_priority();
void schedule_rr();

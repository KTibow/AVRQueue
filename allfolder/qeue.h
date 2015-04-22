#ifndef QUEUE_H
#define QUEUE_H

// Settings
#define QUEUE_DEPTH 10
#define NAME_LIMIT 8
typedef uint32_t queue_time_t;

typedef int (*queuedFunction)(queue_time_t);

typedef struct _queue_item
{
    queuedFunction fPtr;
    queue_time_t recur;
    queue_time_t next;
    char itemName[NAME_LIMIT];
} queueItem;

//Functions
int scheduleFunction(queuedFunction, const char *, queue_time_t, queue_time_t);
int scheduleRemoveFunction(const char *);
int scheduleChangeFunction(const char *, queue_time_t, queue_time_t);

int scheduleRun(queue_time_t);

#endif

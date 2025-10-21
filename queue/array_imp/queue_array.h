#ifndef QUEUEA_H
#define QUEUEA_H

struct QueueRecord;
typedef struct QueueRecord *Queue;

int isEmpty(Queue q);
int isFull(Queue q);
Queue createQueue(int maxElements);
void disposeQueue(Queue q);
void makeEmpty(Queue q);
void enqueue(int element, Queue q);
void dequeue(Queue q);
int frontAndDequeue(Queue q);

#endif

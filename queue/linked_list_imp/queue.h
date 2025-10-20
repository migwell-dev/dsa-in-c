#ifndef _QUEUE_H
#define _QUEUE_H

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
} QueueRecord;

typedef QueueRecord* ptrToQueue;
typedef ptrToQueue Queue;

Queue createQueue();
int isEmpty(Queue q);
void enqueue(Queue q, int data);
int dequeue(Queue q);
int front(Queue q);
void displayQueue(Queue q);
void clearQueue(Queue q);
void freeQueue(Queue q);

#endif

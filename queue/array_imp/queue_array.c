#include "queue_array.h"
#define MIN_QUEUE_SIZE 5

struct QueueRecord {
  int capacity;
  int front;
  int rear;
  int size;
  int *array;
};

int isEmpty(Queue q) {
  return q->size == 0;
}

void makeEmpty(Queue q) {
  q->size = 0;
  q->front = 1;
  q->rear = 0;
}

static int succ(int value, Queue q) {
  if (++value == q->capacity)
    value = 0;
  return value;
}

/*
 * checks if q->rear + 1 == limit of queue_array
 * if it is, 
 * */

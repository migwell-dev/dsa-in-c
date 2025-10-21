#include "queue_array.h"
#include <stdio.h>
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

void enqueue(int element, Queue q) {
  if (isFull(q)) {
    printf("Queue is full\n");
    return;
  } else {
    q->size++;
    q->rear = succ(q->rear, q);
    q->array[q->rear] = element;
  }
}

void dequeue(Queue q) {
  if (isEmpty(q)) {
    printf("Queue is empty\n");
    return;
  } else {
    q->size--;
    q->front = succ(q->front, q);
  }
}

int frontAndDequeue(Queue q) {
  if (isEmpty(q)) {
    printf("Queue is empty\n");
    return -1;
  } else {
    int frontElement = q->array[q->front];
    q->size--;
    q->front = succ(q->front, q);
    return frontElement;
  }
}

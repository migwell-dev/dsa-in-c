#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

Queue createQueue() {
  Queue q = malloc(sizeof(QueueRecord));
  if (q == NULL) {
    printf("Memory allocation failed.\n");
    return NULL;
  }
  q->front = NULL;
  q->rear = NULL;
  return q;
}

int isEmpty(Queue q) {
  return q->front == NULL;
}

void enqueue(Queue q, int data) {
  Node *item = malloc(sizeof(Node));
  if (item == NULL) {
    printf("Memory allocation failed.\n");
    return;
  }

  item->data = data;
  item->next = NULL;

  if (isEmpty(q)) {
    q->front = q->rear = item;
  } else {
    q->rear->next = item;
    q->rear = item;
  }
}

int dequeue(Queue q) {
  if (isEmpty(q)) {
    printf("Queue is empty.\n");
    return 0;
  }

  Node *tmp = q->front;
  int value = tmp->data;
  q->front = tmp->next;

  if (q->front == NULL)
    q->rear = NULL;

  free(tmp);
  return value;
}

int front(Queue q) {
  if (isEmpty(q)) {
    printf("Queue is empty.\n");
    return 0;
  }
  return q->front->data;
}

void displayQueue(Queue q) {
  if (isEmpty(q)) {
    printf("Empty queue\n");
    return;
  }

  Node *p = q->front;
  printf("Queue (front → rear): ");
  while (p != NULL) {
    printf("%d ", p->data);
    p = p->next;
  }
  printf("\n");
}

void clearQueue(Queue q) {
  while (!isEmpty(q))
    dequeue(q);
}

void freeQueue(Queue q) {
  clearQueue(q);
  free(q);
}

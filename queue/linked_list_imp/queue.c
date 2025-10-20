#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

Queue createQueue() {
  Queue q;
  q = malloc(sizeof(Node));
  if (q == NULL)
    printf("Memory allocation failed.\n");
  else
    clearQueue(q);
  return q;
}

int isEmpty(Queue q) { return q->front == NULL; }

void enqueue(Queue q, int data) {
  Node *item;
  item = malloc(sizeof(Node));
  if (item == NULL) {
    printf("Memory allocation failed.\n");
  } else {
    item->data = data;
    item->next = NULL;
  }

  if (isEmpty(q)) {
    q->front = item;
    q->rear = item;
  } else {
    q->rear->next = item;
    q->rear = item;
  }
}

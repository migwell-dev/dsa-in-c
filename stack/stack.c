#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

int isEmpty(Stack s) { return s->next == NULL; }

Stack createStack() {
  Stack s;
  s = malloc(sizeof(struct Node));
  if (s == NULL)
    printf("Memory error: out of space\n");
  else {
    makeEmpty(s);
  }
  return s;
}

void disposeStack(Stack s) {
  makeEmpty(s);
  free(s);
}

void makeEmpty(Stack s) {
  if (s == NULL)
    printf("Stack must be initialized\n");
  else
    while (!isEmpty(s))
      pop(s);
}

void push(Stack s, int x) {
  ptrToNode newItem;
  newItem = malloc(sizeof(struct Node));
  if (newItem == NULL)
    printf("Memory error: out of space\n");
  else {
    newItem->element = x;
    newItem->next = s->next;
    s->next = newItem;
  }
}

int top(Stack s) {
  if (!isEmpty(s))
    return s->next->element;
  printf("Empty stack\n");
  return 0;
}

void pop(Stack s) {
  ptrToNode tmpCell;
  if (isEmpty(s))
    printf("Empty stack\n");
  else {
    tmpCell = s->next;
    s->next = s->next->next;
    free(tmpCell);
  }
}

void displayStack(Stack s) {
  if (s == NULL) {
    printf("Stack not initialized\n");
    return;
  }
  if (isEmpty(s)) {
    printf("Stack is empty\n");
    return;
  }

  ptrToNode p = s->next;
  printf("Stack (top → bottom): ");
  while (p != NULL) {
    printf("%d ", p->element);
    p = p->next;
  }
  printf("\n");
}

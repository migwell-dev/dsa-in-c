#ifndef _STACK_H
#define _STACK_H

typedef struct Node* ptrToNode;
typedef ptrToNode Stack;

struct Node {
  int element;
  ptrToNode next;
};

int isEmpty(Stack s);
Stack createStack(void);
void disposeStack(Stack s);
void makeEmpty(Stack s);
void push(Stack s, int x);
int top(Stack s);
void pop(Stack s);
void displayStack(Stack s);
#endif

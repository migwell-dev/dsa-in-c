#include "list.h"
#include <stdio.h>

// creates int node
struct Node {
  ElementType element;
  Position next;
};

int isEmpty(List l) { return l->next == NULL; }

int isLast(Position p, List l) { return p->next == NULL; }

Position find(ElementType x, List l) {
  Position p;

  p = l->next;
  while (p != NULL && p->element != x) {
    p = p->next;
  }

  return p;
}

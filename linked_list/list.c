#include "list.h"
#include <stdio.h>
#include <stdlib.h>


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

void deleteElement(ElementType x, List l) {
  Position p, tmp_cell;

  p = findPrevious(x, l);

  if (p->next != NULL) {
    tmp_cell = p->next;
    p->next = tmp_cell->next;
    free(tmp_cell);
  }
}

Position findPrevious(ElementType x, List l) {
  Position p;

  p = l;
  while (p->next != NULL && p->next->element != x) {
    p = p->next;
  }

  return p;
}

void insert(ElementType x, List l, Position p) {
  Position tmp_cell;
  tmp_cell = (Position) malloc(sizeof(struct Node));

  if (tmp_cell == NULL) {
    printf("Out of space");
  } else {
    tmp_cell->element = x;
    tmp_cell->next = p->next;
    p->next = tmp_cell;
  }
}

void deleteList(List l) {
  Position p, tmp_cell;

  p = l->next;
  l->next = NULL;
  while (p != NULL) {
    tmp_cell = p;
    p = p->next;
    free(tmp_cell);
  }
}

Position header(List l) {
  return l;
}

Position first(List l) {
  return l->next;
}

Position advance(Position p) {
  return p->next;
}

ElementType retrieve(Position p) {
  return p->element;
}

#ifndef _LIST_H

struct Node;
typedef struct Node *ptrToNode;
typedef ptrToNode List;
typedef ptrToNode Position;
typedef int ElementType;

List makeEmpty(List l);
int isEmpty(List l);
int isLast(Position p, List l);
Position find(ElementType x, List l);
void deleteElement(ElementType x, List l);
Position findPrevious(ElementType x, List l);
void insert(ElementType x, List l, Position p);
void deleteList(List l);
Position header(List l);
Position first(List l);
Position advance(Position p);
ElementType retrieve(Position p);

#endif


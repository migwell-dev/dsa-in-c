#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main(void) {
    List myList;
    Position p;
    ElementType x;

    myList = malloc(sizeof(struct Node));
    if (myList == NULL) {
        printf("Out of memory\n");
        return 1;
    }
    myList->next = NULL;

    insert(10, myList, header(myList));
    insert(20, myList, header(myList));
    insert(30, myList, header(myList));

    printf("List contents:\n");
    for (p = first(myList); p != NULL; p = advance(p)) {
        printf("%d ", retrieve(p));
    }
    printf("\n");

    deleteElement(20, myList);

    printf("After deleting 20:\n");
    for (p = first(myList); p != NULL; p = advance(p)) {
        printf("%d ", retrieve(p));
    }
    printf("\n");

    x = 10;
    p = find(x, myList);
    if (p != NULL)
        printf("Found %d in list\n", x);
    else
        printf("%d not found\n", x);

    if (isEmpty(myList))
        printf("List is empty\n");
    else
        printf("List is not empty\n");

    deleteList(myList);
    free(myList);

    return 0;
}

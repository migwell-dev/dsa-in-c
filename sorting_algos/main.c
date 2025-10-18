#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

void print_list(List list) {
    for (int i = 0; i < list.length; i++) {
        printf("%d ", list.items[i]);
    }
    printf("\n");
}

int main() {
    int data[] = {12, 5, 7, 3, 9, 1, 8, 6};
    int n = sizeof(data) / sizeof(data[0]);

    List myList;
    myList.length = n;
    myList.items = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        myList.items[i] = data[i];

    printf("Original list:\n");
    print_list(myList);

    List sorted1 = bubble_sort(myList);
    printf("\nBubble sort:\n");
    print_list(sorted1);

    List sorted2 = selection_sort(myList);
    printf("\nSelection sort:\n");
    print_list(sorted2);

    List sorted3 = insertion_sort(myList);
    printf("\nInsertion sort:\n");
    print_list(sorted3);

    // free dynamic allocations
    free(myList.items);

    return 0;
}

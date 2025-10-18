#ifndef _SORT_H
#define _SORT_H

typedef struct List {
  int* items;
  int length;
} List;

/*bubble sort, worst case O(n^2), returns copy of list*/
List bubble_sort(List list);

/*selection sort, worst case O(n^2), returns copy of list*/
List selection_sort(List list);

/*insertion sort, worst case O(n^2), returns copy of list*/
List insertion_sort(List list);
#endif

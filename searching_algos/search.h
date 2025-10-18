#ifndef _SEARCH_H
#define _SEARCH_H

typedef struct List {
  int length;
  int* items;
} List;

/*linear search: searches iteratively, worst case: O(n)*/
int linear_search(List* list, int target);

/*binary search: divide and conquer search, worst case: O(log n)*/
int bin_search(List* list, int target);

#endif

#include "search.h"

int linear_search(List* list, int target) {
  int length = list->length;
  for (int i = 0; i < length; i++)
    if (list->items[i] == target)
      return i;
  return -1;
}

int bin_search(List *list, int target) {
  int l = 0, r = list->length-1, mid;

  while (l <= r) {
    mid = (l + r) / 2;
    if (list->items[mid] > target)
      r = mid - 1;
    else if (list->items[mid] < target) 
      l = mid + 1;
    else
     return mid;
  }
  return -1;
}

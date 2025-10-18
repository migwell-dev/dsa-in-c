#include "search.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  List myList;
  myList.length = 8;
  myList.items = malloc(myList.length * sizeof(int));
  for (int i = 0; i < myList.length; i++)
    myList.items[i] = i;

  printf("%d\n", linear_search(&myList, 5));
  printf("%d\n", bin_search(&myList, 5));
  return 0;
}

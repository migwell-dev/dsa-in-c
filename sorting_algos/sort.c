#include "sort.h"

List bubble_sort(List list) {
  int temp;
  for (int i = 0; i < list.length - 1; i++) {
    for (int j = 0; j < list.length - i - 1; j++) {
      if (list.items[j] > list.items[j + 1]) {
        temp = list.items[j];
        list.items[j] = list.items[j + 1];
        list.items[j + 1] = temp;
      }
    }
  }
  return list;
}

List selection_sort(List list) {
  int min_idx, temp;
  for (int i = 0; i < list.length - 1; i++) {
    min_idx = i;
    for (int j = i + 1; j < list.length; j++) {
      if (list.items[j] < list.items[min_idx]) {
        min_idx = j;
      }
    }
    temp = list.items[i];
    list.items[i] = list.items[min_idx];
    list.items[min_idx] = temp;
  }
  return list;
}

List insertion_sort(List list) {
  for (int i = 1; i < list.length; ++i) {
    int key = list.items[i];
    int j = i - 1;

    while (j >= 0 && list.items[j] > key) {
      list.items[j + 1] = list.items[j];
      j = j - 1;
    }
    list.items[j + 1] = key;
  }

  return list;
}

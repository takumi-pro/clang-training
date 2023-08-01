#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "vector.h"
#include "linked_list.h"

#define rep(n) for(int i = 0; i < n; i++)

int main() {
  // 動的配列
  printf("========== array ==========\n");
  Vec* vec = vector_new(4);
  int a = 23;
  int num1 = 100;
  int num2 = 2222;
  char* s = "hello";
  int num3 = 99999;
  
  printf("capacity: %d\n", vec->capacity);
  printf("size: %d\n", vec->size);

  vector_insert(vec, 0, &a);
  printf("capacity: %d\n", vec->capacity);
  printf("size: %d\n", vec->size);

  vector_insert(vec, 1, &a);
  printf("capacity: %d\n", vec->capacity);
  printf("size: %d\n", vec->size);

  vector_insert(vec, 2, &num1);
  printf("capacity: %d\n", vec->capacity);
  printf("size: %d\n", vec->size);

  vector_insert(vec, 2, &num1);
  printf("capacity: %d\n", vec->capacity);
  printf("size: %d\n", vec->size);

  vector_push(vec, &num1);
  vector_push(vec, &num2);
  vector_push(vec, &num2);
  vector_push(vec, &num3);
  vector_delete(vec, 5);

  for (int i = 0; i < vec->size; ++i) {
    printf("arr[%d]: %d\n", i, *(int*)(vec->values[i]));
  };
  int num4 = 45;
  printf("find 100: %d\n", vector_find(vec, &(num4)));

  free(vec->values);
  free(vec);

  // 連結リスト
  printf("\n");
  printf("========== list ==========\n");
  List* list = make_list();
  printf("list top: %p\n", list->top);
  push(list, 100);
  push(list, 200);
  push(list, 300);
  push(list, 400);
  push_back(list, 50);
  print_list(list);

  free(list);
  free(list->top);
  return 0;
}
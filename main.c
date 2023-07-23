#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

#define rep(n) for(int i = 0; i < n; i++)

int addressIndirection() {
  printf("===== AddressOperator =====\n");
  int n = 100;
  printf("n: %d\n", n);
  printf("n address operator: %p\n", &n);
  printf("indirection operator: %d", *(&n));
  printf("\n\n");
  return 0;
};

int pointerVariable() {
  printf("===== PointerVariable =====\n");
  int n = 100;
  int *p = &n;
  printf("n address: %p\n", p);
  printf("n: %d", *p);
  printf("\n\n");
  return 0;
}

int doubleArrayElements(int *array, int n) {
  printf("===== DoubleArrayElements =====\n");
  printf("Array Element: ");
  rep(n) printf("%d, ", array[i]);
  printf("\n");
  rep(n) array[i] *= 2;
  printf("Double Array Element: ");
  rep(n) printf("%d, ", array[i]);
  printf("\n\n");
  return 0;
}

int main() {
  addressIndirection();
  pointerVariable();

  int array[5] = {1,2,3,4,5};
  doubleArrayElements(array, 5);

// 動的配列
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
  return 0;
}
#include <stdio.h>

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
  return 0;
}
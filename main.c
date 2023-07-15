#include <stdio.h>

int address() {
  int n = 100;
  printf("n: %d\n", n);
  printf("n address: %p", &n);
  return 0;
};

int main() {

  address();
  return 0;
  // // 構造体のポインタ
  // struct Test {
  //   char name[10];
  //   int num;
  //   int num2;
  // };

  // struct Test *testPointer;

  // printf("struct T: %p\n", testPointer);
  // int *testPointerNum = &testPointer->num;
  // int *testPointerNum2 = &testPointer->num2;
  // char *testPointerName = testPointer->name;
  // printf("struct name: %p\n", testPointerName);
  // printf("struct num: %p\n", testPointerNum);
  // printf("struct num2: %p\n", testPointerNum2);

  // // 配列のポインタ
  // // int array[10];
  // // int *p, *t, *r;
  // // p = array;
  // // t = &array[0];
  // // r = &array[1];
  // // array[0] = 0;
  // // int e = array[0];

  // // printf("p: %p\n", p);
  // // printf("t: %p\n", t);
  // // printf("r: %p\n", r);
  // // printf("e: %d", e);

  // int array[10];
  // int n;
  // scanf("%d", &n);
  // int arr[n];
  // for (int i=0; i<n; i++) {
  //   arr[i] = i;
  // };
  // for (int i=0; i<n; i++) {
  //   printf("arr %d: %d", i, arr[i]);
  // }
  // for (int i=0; i < 10; i++) array[i] = i + 1;
  // int *topPtr;
  // topPtr = &array[0];

  // printf("topPtr: %p\n", topPtr);
  // printf("array pointer: %p", array);
  // printf("array pointer: %d", topPtr[2]);
  // return 0;
}
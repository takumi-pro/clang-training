#include <stdio.h>
#include <stdlib.h>

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

// 動的配列の実装
struct Vector {
  void** values;
  int32_t size;     // 項目数
  int32_t capacity; // 保持しているメモリサイズ
};

typedef struct Vector Vec;

/*
* @function vector_new
* @description capacity分のメモリ領域を確保する関数
* @param capacity 確保するメモリ領域
* @return Vec構造体のポインタ
*/
Vec* vector_new(int32_t capacity) {
  Vec* arr = malloc(sizeof(Vec));
  arr->capacity = capacity;
  arr->size = 0;
  arr->values = malloc(capacity * sizeof(void*));
  if (arr->values == NULL) {
    printf("Memory allocation failed\n");
    exit(1);
  }
  return arr;
};

/*
* @function insert
* @description 任意のindexに任意の値を挿入する関数
* @param arr Vec型のポインタ
* @param index 値を挿入するインデックス
* @param value 挿入したい値
*/
void vector_insert(Vec* arr, int index, void* value) {
  if (index < 0 || index > arr->size) {
    printf("Invalid index\n");
    exit(1);
  }

  // メモリ領域がいっぱいになったら再割り当て
  arr->size++;
  if (arr->size == arr->capacity) {
    // メモリ領域を2倍確保
    arr->capacity += arr->capacity;

    // メモリを capasicy × (void*のサイズ)分 再割り当て
    void** tmp = (void**)realloc(arr->values, arr->capacity * sizeof(void*));
    if (tmp == NULL) {
      printf("Memory allocation failed\n");
      exit(1);
    }
    arr->values = tmp;
  }

  // 指定されたindex以降の要素を1つずらす
  for (int i = arr->size-1; i > index; --i) {
    arr->values[i] = arr->values[i-1];
  }

  arr->values[index] = value;
}

/*
* @function push
* @description 末尾に指定した値を追加する関数
* @param value 末尾に追加する値
*/
void vector_push(void* value) {
  
}

int main() {
  addressIndirection();
  pointerVariable();

  int array[5] = {1,2,3,4,5};
  doubleArrayElements(array, 5);

  Vec* vec = vector_new(10);
  int a = 23;
  int num1 = 100;
  int num2 = 2222;
  char* s = "hello";
  vector_insert(vec, 0, &a);
  vector_insert(vec, 1, s);
  vector_insert(vec, 2, &num1);
  printf("capacity: %d\n",vec->capacity);
  printf("size: %d\n",vec->size);
  printf("arr: %p\n", vec->values);
  printf("arr: %p\n", vec->values);
  printf("arr[0]: %d\n", *(int*)(vec->values[0]));
  printf("arr[1]: %s\n", (char*)(vec->values[1]));
  printf("arr[2]: %d\n", *(int*)(vec->values[2]));
  vector_insert(vec, 2, &num2);
  printf("arr[2]: %d\n", *(int*)(vec->values[2]));
  printf("arr[3]: %d\n", *(int*)(vec->values[3]));
  free(vec->values);
  free(vec);
  return 0;
}
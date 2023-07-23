#include <stdio.h>
#include <stdlib.h>

struct Vector {
  void** values;
  int32_t size;     // 項目数
  int32_t capacity; // 保持しているメモリサイズ
};

typedef struct Vector Vec;

Vec* vector_new(int32_t capacity);
void vector_insert(Vec* arr, int index, void* value);
void vector_delete(Vec* arr, int index);
int vector_find(Vec* arr, int* value);
void vector_push(Vec* arr, void* value);
void* vector_at(Vec* arr, int index);
void* vector_pop(Vec* arr);
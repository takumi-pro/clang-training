#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

Stack* stack_init() {
  Stack* stack = malloc(sizeof(Stack));
  stack->size = 0;
  return stack;
}

/*
* @function stack_push
* @description スタックに要素を挿入する
* @params stack
* @params data
*/
void stack_push(Stack* stack, int data) {
  if (stack->size >= STACK_SIZE) {
    printf("over stack size");
    exit(1);
  }
  stack->data[stack->size] = data;
  stack->size++;
}

/*
* @function stack_pop
* @description スタックから要素を削除する
* @params stack
*/
void stack_pop(Stack* stack) {
  if (stack->size == 0) {
    printf("stack is empty");
    exit(1);
  }
  stack->size--;
}

/*
* @function stack_top
*/
int stack_top(Stack* stack) {
  if (stack->size == 0) {
    printf("stack is empty");
    exit(1);
  }
  return stack->data[stack->size - 1];
}
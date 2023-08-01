/*
* 用意するメソッド
* @function push
* @function top
* @function pop
* @function empty
* @function size
*/

#include <stdbool.h>

#define STACK_SIZE 100

typedef struct stack {
  int data[STACK_SIZE];
  int size;
} Stack;

Stack* stack_init();
void stack_push(Stack* stack, int data);
void stack_pop(Stack* stack);
int stack_top(Stack* stack);
bool stack_empty(Stack* stack);
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "linked_list.h"

/*
* @function make_cell
* @description セルを生成する関数
* @params data セルに格納する値
* @params *next 次のセルへのポインタ
*/
Cell *make_cell(int data, Cell *cell) {
  Cell *newcell = malloc(sizeof(Cell));
  if (newcell == NULL) {
    printf("memory allocation failed");
    exit(1);
  }
  newcell->data = data;
  newcell->next = cell;
  return newcell;
}

/*
* @description リストを生成する関数
* @return List構造体のポインタ
*/
List* make_list() {
  List *list = malloc(sizeof(List));
  if (list == NULL) {
    printf("memory allocation failed");
    exit(1);
  }
  // セルをセットする
  list->top = make_cell(0, NULL);
  return list;
}

/*
* @description n番目のセルを返す
* @params cell
* @params n
* @return cell
*/
Cell* nth_cell(Cell* cell, int n) {
  for (int i = -1; cell != NULL; i++, cell = cell->next) {
    if (n == i) break;
  }
  return cell;
}

/*
* @description n番目にセルを挿入する関数
* @params cell Cell構造対のポインタ
* @params n 挿入する位置
* @params data 挿入するせるの値
* @return bool
*/
bool insert_cell(List* list, int n, int data) {
  Cell* previousCell = nth_cell(list->top, n - 1);
  if (previousCell == NULL) {
    return false;
  }
  previousCell->next = make_cell(data, previousCell->next);
  return true;
}

/*
* @description 先頭にデータを追加する
* @params list List構造体のポインタ
* @params data 格納する値
*/
bool push(List* list, int data) {
  return insert_cell(list, 0, data);
}

/*
* @description 先頭の値を返却する関数
* @params list
* @return data 先頭の要素
*/
int top(List* list) {
  Cell* cell = nth_cell(list->top, 0);
  if (cell == NULL) {
    printf("no item\n");
    exit(1);
  }
  return cell->data;
}

/*
* @function delete_nth
* @description n番目の要素を削除する
* @params list List構造体のポインタ
* @params n 削除する要素番号
*/
void delete_nth(List* list, int n) {
  Cell* cell = nth_cell(list->top, n - 1);
  if (cell == NULL || cell->next == NULL) {
    printf("no item");
    exit(1);
  }
  Cell* cell_to_be_deleted = cell->next;
  cell->next = cell->next->next;
  free(cell_to_be_deleted);
}

/*
* @function push_back
* @description 最後に要素を追加する
* @params list
* @params data
*/
void push_back(List* list, int data) {
  int i = 0;
  for (
    Cell* cell = list->top->next;
    cell != NULL;
    cell = cell->next, i++
  ) {
    if (cell->next == NULL) {
      cell->next = make_cell(data, NULL);
      break;
    }
  }
}

/*
* @function print_list
* @description リストを表示する
* @params list List構造体のポインタ
*/
void print_list(List* list) {
  int i = 0;
  for (
    Cell* cell = list->top->next;
    cell != NULL;
    cell = cell->next, i++
  ) {
    printf("index %d, data: %d\n", i, cell->data);
  }
}
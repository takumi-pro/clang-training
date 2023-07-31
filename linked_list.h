// 連結リストの実装
typedef struct cell {
  int data;
  struct cell *next;
} Cell;

typedef struct {
  Cell *top;
} List;

Cell* make_cell(int data, Cell* cell);
List* make_list();
Cell* nth_cell(Cell* cell, int n);
bool insert_cell(List* list, int n, int data);
bool push(List* list, int data);
int top(List* list);
void delete_nth(List* list, int n);
void push_back(List* list, int data);
void print_list(List* list);
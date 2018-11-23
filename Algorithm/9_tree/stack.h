/* stack.h */

typedef void* STACK;
typedef void* T;

STACK stack_construct();
void stack_free(STACK stack);
void stack_print(STACK stack);

T stack_top(STACK stack);
T stack_pop(STACK stack);
void stack_push(STACK stack, T value);
int stack_empty(STACK stack);

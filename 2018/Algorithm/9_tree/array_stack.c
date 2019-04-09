/* array_stack.c */

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

#define STACK_SIZE 100

typedef struct array_stack {
    T elements[STACK_SIZE];
    int top;
} array_stack;

STACK stack_construct() {
    array_stack* a_stack = (array_stack*)malloc(sizeof(array_stack));
    a_stack->top = 0;

    return (STACK)a_stack;
}

void stack_free(STACK stack) {
    array_stack* a_stack = (array_stack*)stack;
    if(a_stack == NULL) {
        return;
    }
    free(a_stack);
}
/*
void stack_print(STACK stack) {
    array_stack* a_stack = (array_stack*)stack;
    if(a_stack == NULL) {
        return;
    }
    for(int i = 0; i < a_stack->top; i++) {
        if(i != a_stack->top - 1) {
            printf("%d -> ", a_stack->elements[i]);
        } else {
            printf("%d\n", a_stack->elements[i]);
        }
    }
}
*/

T stack_top(STACK stack) {
    array_stack* a_stack = (array_stack*)stack;
    if((a_stack == NULL) || (a_stack->top == 0)) {
        return 0;
    }
    return a_stack->elements[a_stack->top - 1];
}

T stack_pop(STACK stack) {
    array_stack* a_stack = (array_stack*)stack;
    if((a_stack == NULL) || (a_stack->top == 0)) {
        return 0;
    }
    a_stack->top--;
    return a_stack->elements[a_stack->top];
}

void stack_push(STACK stack, T value) {
    array_stack* a_stack = (array_stack*)stack;
    if((a_stack == NULL) || (a_stack->top == STACK_SIZE)){
        return;
    }
    a_stack->elements[a_stack->top] = value;
    a_stack->top++;
}

int stack_empty(STACK stack) {
    array_stack* a_stack = (array_stack*)stack;
    return (a_stack == NULL) || (a_stack->top == 0);
}

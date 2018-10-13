/* dlinked_list.c */

#include <stdlib.h>
#include <stdio.h>
#include "list.h"

typedef struct list_node {
    int value;
    struct list_node* next;
    struct list_node* previous;
} list_node;

typedef struct dlinked_list {
    list_node* top;
    list_node* tail;
} dlinked_list;

LIST list_construct() {
    dlinked_list* d_lst = (dlinked_list*)malloc(sizeof(dlinked_list));
    list_node* node = (list_node*)malloc(sizeof(list_node));
    node->next = NULL;
    node->previous = NULL;
    d_lst->top = node;
    d_lst->tail = node;

    return (LIST)d_lst;
}

void list_free(LIST lst) {
    dlinked_list* d_lst = (dlinked_list*)lst;
    list_node* node = d_lst->top;
    while(node != NULL) {
        list_node* next = node->next;
        free(node);
        node = next;
    }
    free(lst);
}

void list_print(LIST lst) {
    dlinked_list* d_lst = (dlinked_list*)lst;
    if((d_lst == NULL) || (d_lst->top == NULL) || (d_lst->top->next == NULL)) {
        return;
    }

    list_node* node = d_lst->top->next;
    while(node->next != NULL) {
        printf("%d -> ", node->value);
        node = node->next;
    }
    printf("%d\n", node->value);
}

void list_insert(LIST lst, POSITION pos, int value) {
    dlinked_list* d_lst = (dlinked_list*)lst;
    list_node* node = (list_node*)pos;

    if((d_lst == NULL) || (node == NULL)){
        return;
    }
    list_node* new_node = (list_node*)malloc(sizeof(list_node));
    new_node->value = value;
    
    new_node->next = node->next;
    if(new_node->next != NULL) {
        new_node->next->previous = new_node;
    } else {
        d_lst->tail = new_node;
    }
    new_node->previous = node;
    node->next = new_node;
}

void list_delete(LIST lst, POSITION pos) {
    dlinked_list* d_lst = (dlinked_list*)lst;
    list_node* node = (list_node*)pos;

    if((d_lst == NULL) || (node == NULL)) {
        return;
    }

    list_node* next = node->next;
    if(next == NULL) {
        return;
    }

    node->next = next->next;
    if(node->next != NULL) {
        node->next->previous = node;
    } else {
        d_lst->tail = node;
    }
    free(next);
}

int list_retrieve(LIST lst, POSITION pos) {
    list_node* node = (list_node*)pos;
    if((lst == NULL) || (node == NULL) || (node->next == NULL)) {
        return 0;
    }
    return node->next->value;
}

POSITION list_first(LIST lst) {
    dlinked_list* d_lst = (dlinked_list*)lst;
    return (POSITION)d_lst->top;
}

POSITION list_last(LIST lst) {
    dlinked_list* d_lst = (dlinked_list*)lst;
    return (POSITION)d_lst->tail;
}

POSITION list_next(LIST lst, POSITION pos) {
    list_node* node = (list_node*)pos;
    if((lst == NULL) || (node == NULL)) {
        return NULL;
    }
    return node->next;
}

POSITION list_previous(LIST lst, POSITION pos) {
    list_node* node = (list_node*)pos;
    if((lst == NULL) || (node == NULL)) {
        return NULL;
    }
    return node->previous;
}

POSITION list_get(LIST lst, long n) {
    list_node* node = (list_node*)lst;
    if(node == NULL) {
        return NULL;
    }
    for(int i = 0; i < n; i++) {
        if(node->next == NULL) {
            return NULL;
        }
        node = node->next;
    }
    return node;
}
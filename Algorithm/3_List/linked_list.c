/* linked_list.c */

#include <stdlib.h>
#include <stdio.h>
#include "list.h"

typedef struct list_node {
    int value;
    struct list_node* next;
} list_node;

LIST list_construct() {
    list_node* node = (list_node*)malloc(sizeof(list_node));
    node->next = NULL;

    return (LIST)node;
}

void list_free(LIST lst) {
    list_node* node = (list_node*)lst;
    while(node != NULL) {
        list_node* next = node->next;
        free(node);
        node = next;
    }
}

void list_print(LIST lst) {
    list_node* node = (list_node*)lst;
    if((node == NULL) || (node->next == NULL)){
        return;
    }
    node = node->next;

    while(node->next != NULL) {
        printf("%d -> ", node->value);
        node = node->next;
    }
    printf("%d\n", node->value);
}

void list_insert(LIST lst, POSITION pos, int value) {
    list_node* node = (list_node*)pos;

    if((lst == NULL) || (node == NULL)){
        return;
    }
    list_node* new_node = (list_node*)malloc(sizeof(list_node));
    new_node->value = value;
    new_node->next = node->next;
    node->next = new_node;
}

void list_delete(LIST lst, POSITION pos) {
    list_node* node = (list_node*)pos;
    if((lst == NULL) || (node == NULL)) {
        return;
    }

    list_node* next = node->next;
    if(next == NULL) {
        return;
    }

    node->next = next->next;
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
    list_node* node = (list_node*)lst;
    return (POSITION)node;
}

POSITION list_last(LIST lst) {
    list_node* node = (list_node*)lst;
    if(node == NULL) {
        return NULL;
    }

    while(node->next != NULL) {
        node = node->next;
    }
    return node;
}

POSITION list_next(LIST lst, POSITION pos) {
    list_node* node = (list_node*)pos;
    if((lst == NULL) || (node == NULL)) {
        return NULL;
    }
    return node->next;
}

POSITION list_previous(LIST lst, POSITION pos) {
    list_node* node = (list_node*)lst;
    if((node == NULL) || (node->next == NULL)){
        return NULL;
    }

    while(node->next != pos) {
        node = node->next;
    }
    return node;
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
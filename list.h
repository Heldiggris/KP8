#ifndef _LIST_H_
#define _LIST_H_

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define STR_SIZE 64

typedef struct _node{
    char value[STR_SIZE];
    struct _node *next;
    struct _node *prev;
}Node;

typedef struct _list{
    size_t len;
    Node *border;
}List;


size_t list_size(List *l);

Node *node_create();

List *list_create();

void list_destroy(List *l);

void list_insert(int index, char *str, List *l);

void list_print(List *l);

char *list_get(int index, List *l);

void list_append(char *str, List *l);

void list_delete(int index, List *l);

void list_remove(char *str, List *l);

void list_assign(int index, char *str, List *l);

size_t list_size(List *l);

int list_check_sort(List *l);

#endif



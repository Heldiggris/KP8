#include "list.h"


Node *node_create()
{
    Node *n = (Node*)malloc(sizeof(Node));
    n->next = n;
    n->prev = n;
    strcpy(n->value, " ");
    return n;
}


List *list_create()
{
    List *l = (List*)malloc(sizeof(List));
    l->len = 0;
    l->border = node_create();
    return l;
}

void list_destroy(List *l)
{
    Node *n = l->border;
    for (int i = 0; i <= l->len; ++i) {
        Node *n1 = n->next;
        free(n);
        n = n1;
    }
    free(l);
}

void list_insert(int index, char *str, List *l)
{
    Node *n = l->border;
    Node *n1 = node_create();
    strcpy(n1->value, str);
    if (index <= l->len / 2) {
        for (int i = 0; i < index; i++) {
            n = n->next;
        }
        n1->next = n->next;
        n1->prev = n;
        n->next->prev = n1;
        n->next = n1;
        l->len++;
    } else if (index < l->len) {
        for (int i = 0; i < l->len - index; i++) {
            n = n->prev;
        }
        n1->next = n->next;
        n1->prev = n;
        n->next->prev = n1;
        n->next = n1;
        l->len++;
    } else {
        n1->prev = n->prev;
        n1->next = n;
        n->prev->next = n1;
        n->prev = n1;
        l->len++;
    }
}

void list_print(List *l)
{
    Node *n = l->border;
    for (int i = 0; i < l->len; ++i)
    {
        printf("%s ", n->next->value);
        n = n->next;
    }
    printf("\n");
}

size_t list_size(List *l)
{
    return l->len;
}

void list_remove(char *str, List *l)
{
    Node *n = l->border;
    for (int i = 0; i < l->len; ++i)
    {
        if(!strcmp(n->next->value, str)) {
            Node *n1 = n->next;
            n->next = n->next->next;
            n->next->prev = n;
            free(n1);
            l->len--;
            return;
        }
        n = n->next;
    }
}


void list_delete(int index, List *l)
{
    Node *n = l->border;
    if (index > l->len - 1) {
        return;
    }
    if (index <= l->len / 2) {
        for (int i = 0; i < index; i++) {
            n = n->next;
        }
        Node *n1 = n->next;
        n->next->next->prev = n;
        n->next = n->next->next;
        l->len--;
        free(n1);
    } else if (index < l->len) {
        for (int i = 0; i < l->len - index; i++) {
            n = n->prev;
        }
        Node *n1 = n->next;
        n->next->next->prev = n;
        n->next = n->next->next;
        l->len--;
        free(n1);
    }
}

void list_append(char *str, List *l)
{
    Node *n = l->border;
    Node *n1 = node_create();
    strcpy(n1->value, str);
    n1->prev = n->prev;
    n1->next = n;
    n->prev->next = n1;
    n->prev = n1;
    l->len++;
}

char *list_get(int index, List *l)
{
    Node *n = l->border;
    if (index > (l->len - 1)) {
        return " ";
    }
    for (int i = 0; i < index; ++i) {
        n = n->next;
    }
    return n->next->value;
}

void list_assign(int index, char *str, List *l)
{
    Node *n = l->border;
    if (index > (l->len - 1)) {
        printf("Неверный индекс");
        printf("\n");
        return;
    }
    for (int i = 0; i < index; ++i) {
        n = n->next;
    }
    strcpy(n->next->value, str);
}

int list_check_sort(List *l)
{
    Node *n = l->border;
    n = n->next;
    for (int i = 0; i < l->len - 1; i++) {
        if (strcmp(n->value, n->next->value) > 0) {
            return 0;
        }
        n = n->next;
    }
    return 1;
}
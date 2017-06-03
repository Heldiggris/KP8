#include <stdio.h>
#include <string.h>
#include "list.h"

int main(void)
{
    char what_do[STR_SIZE] = " ";
    List *l = list_create();
    do {
        if (!strcmp(what_do, "help")) {
            printf("\thelp - список команд\n");
            printf("\tprint - распечатать список\n");
            printf("\tremove - удалить элемент\n");
            printf("\tdelete - удалить по индексу\n");
            printf("\tget - получить значение по индексу\n");
            printf("\tinsert [индекс][значение] - вставить по индексу\n");
            printf("\tappend [значение] - добавить в конец\n");
            printf("\tassign [индекс][значение] - присвоить значение по индексу\n");
            printf("\tsize - размер списка\n");
            printf("\tcheck - проверить на упорядоченность\n");
            printf("\texit - выйти\n");
        } else if (!strcmp(what_do, "insert")) {
            char value[STR_SIZE];
            int a;
            scanf("%d%s", &a, value);
            list_insert(a, value, l);
        } else if (!strcmp(what_do, "remove")) {
            char value[STR_SIZE];
            scanf("%s", value);
            list_remove(value, l);
        } else if (!strcmp(what_do, "delete")) {
            int a;
            scanf("%d", &a);
            scanf("%d", &a);
            list_delete(a, l);
        } else if (!strcmp(what_do, "get")) {
            int a;
            scanf("%d", &a);
            printf("%s\n", list_get(a, l));
        } else if (!strcmp(what_do, "print")) {
            list_print(l);
        } else if (!strcmp(what_do, "exit")) {
            break;
        } else if (!strcmp(what_do, "append")) {
            char value[STR_SIZE];
            scanf("%s", value);
            list_append(value, l);
        } else if (!strcmp(what_do, "assign")) {
            char value[STR_SIZE];
            int a;
            scanf("%d%s", &a, value);
            list_assign(a, value, l);
        } else if(!strcmp(what_do, "size")) {
            printf("%d\n", list_size(l));
        } else if(!strcmp(what_do, "check")) {
            printf("%d\n", list_check_sort(l));
        }
        scanf("%s", what_do);
    } while (!feof(stdin));
    list_destroy(l);
    return 0;
}
// as df vq ba pp ds gb
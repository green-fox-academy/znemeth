#include <stdio.h>
#include <malloc.h>

typedef struct node
{
    int data;
    struct node *next;
} node_t;

node_t *insert_first(node_t *list, int data)
{
    node_t *first_node = (node_t *) malloc(sizeof(node_t));
    first_node->data = data;
    first_node->next = list;

    return first_node;
}

node_t *create()
{
    node_t *list = (node_t *) malloc(sizeof(node_t));
    list->data = 2;
    list->next = NULL;
    return list;
}

void list_print(node_t *list)
{
    node_t *it = list;
    while (it != NULL) {
        printf("%p: %d\n", it, it->data);
        it = it->next;
    }
}

void list_dealloc(node_t *list)
{
    node_t *node_free = list;
    while (node_free != NULL) {
        node_t *next_node = node_free->next;
        free(node_free);
        node_free = next_node;
    }
}

int main()
{
    node_t *list = create();
    list = insert_first(list, 999);
    
    list_print(list);

    list_dealloc(list);
    return 0;
}
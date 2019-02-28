#include <stdio.h>
#include <malloc.h>

typedef struct node
{
    int data;
    struct node *next;
} node_t;

node_t *create()
{
    node_t *list = (node_t *) malloc(sizeof(node_t));
    list->data = 2;
    list->next = NULL;
    return list;
}

void size(node_t *list)
{
    node_t *it = list;
    int count = 0;

    if (it->next == NULL) {
        count = 1;
        printf("Number of nodes: 1");
    };

    while (it->next != NULL) {
        it = it->next;
        count++;
    }
    printf("Number of nodes: %d\n", count + 1);
}

void list_pushback(node_t *list, int data)
{
    //allocate
    node_t *new_node = (node_t *) malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = NULL;

    //iterate through to the last element
    node_t *it = list;
    while (it->next != NULL) {
        it = it->next;
    }

    it->next = new_node;

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

int list_empty(node_t *list)
{
    if (list == NULL) {
        return 0;
    } else {
        return 1;
    }
}

int main()
{
    node_t *list = create();

    list_pushback(list, 10);
    list_pushback(list, 20);
    list_pushback(list, 100);
    list_pushback(list, 200);
    list_pushback(list, 1000);

    list_print(list);

    size(list);

    printf("Is the list empty: %d\n", list_empty(list));

    list_dealloc(list);
    return 0;
}
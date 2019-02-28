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
    list->data = 50;
    list->next = NULL;
    return list;
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
    while(it != NULL) {
        printf("%p: %d\n", it, it->data);
        it = it->next;
    }
}

int main()
{
    node_t *list = create();
    list_pushback(list, 10);

    list_print(list);
    return 0;
}
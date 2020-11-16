#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

/* Search specific value insie the list and return index */
int search_val(struct ListNode *obj, int value)
{
    int index = 1;
    struct ListNode *current = NULL;

    current = obj;
    while (current->next != NULL) {
        if(current->val == value)
            return index;
        current = current->next;
        index++;
    } 

    return -1;
}

/* Insert node after node m */
void insert_node(struct ListNode *obj, int m, int value)
{
    struct ListNode *current = NULL;
    struct ListNode *new_node = malloc(sizeof(new_node));
    struct ListNode *tmp = NULL;
    int index = 1;

    new_node->val = value;
    current = obj;
    while (index < m){
        index++;
        current = current->next;
    }

    tmp = current->next;
    current->next = new_node;
    new_node->next = tmp;
}

/* remove m node */
void remove_node(struct ListNode *obj, int m)
{
    struct ListNode *current = NULL;
    struct ListNode *left_node = NULL;
    struct ListNode *tmp = NULL;

    int index = 1;

    current = obj;
    while(index < m) {
        index++;
        left_node = current;
        current = current->next;
    }

    tmp = current->next;
    left_node->next = tmp;
    free(current);
}

void print_list(struct ListNode *obj)
{
    struct ListNode *current = obj;

    while(current->next != NULL) {
        printf("%d ", current->val);
        current = current->next;
    }
    printf("\n");
}

int main(int argv, char *argc[])
{
    struct ListNode *head = malloc(sizeof(head));
    struct ListNode *current;
    int i = 0;
    int N = strtol(argc[1], NULL, 0);
    int target = 5;
    int index = 0;

    /* initial head node */
    head->val = 1;
    head->next = NULL;
    
    /* initial linked list */
    current = head;
    for (i = 2; i <= N; i++) {
        current->next = malloc(sizeof(current->next));
        current = current->next;
        current->next = NULL;
        current->val = i;
    }

    /* list all val in each node */
    print_list(head);

    index = search_val(head,target);
    printf("target: %d, index: %d\n", target, index);

    target = 8;
    printf("delete node: %d\n", target);
    remove_node(head, target);
    print_list(head);

    target = 10;
    printf("insert node: %d\n", target);
    insert_node(head, target, 111);
    print_list(head);

    return 0;
}
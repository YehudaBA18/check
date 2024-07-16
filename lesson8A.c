#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} *ptr;
void sortList(ptr *head) {
    if (*head == NULL || (*head)->next == NULL) {
        /*The list is empty or has only one element, so it's already sorted.*/
        return;
    }

    ptr current, index;
    int temp;

    /*Traverse the list*/
    for (current = *head; current != NULL; current = current->next) {
        /*Traverse the list again for each element*/
        for (index = current->next; index != NULL; index = index->next) {
            if (current->data > index->data) {
                /*Swap the data of the two nodes*/
                temp = current->data;
                current->data = index->data;
                index->data = temp;
            }
        }
    }
}
void add2list(ptr *head, int num) {
    ptr new_node = malloc(sizeof(struct node));
    if (new_node == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }
    new_node->data = num;
    new_node->next = *head;
    *head = new_node;
}

void freelist(ptr *head) {
    while (*head != NULL) {
        ptr temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

void printList(ptr head) {
    ptr current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    ptr head = NULL;
    int num;

    while (scanf("%d", &num) == 1)
        add2list(&head, num);
sortList(&head); /*Call to sort the list*/

    printf("\nSorted List: ");
    printList(head);

    printf("\nList: ");
    printList(head);

    printf("\nHead address before free: %p\n", (void *)head);

    freelist(&head);
    printf("\nHead address after free: %p\n", (void *)head);

    return 0;
}


#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
};
struct node *start = NULL;
struct node *insert_at_beg(struct node *start, int data) 
{
    struct node *new_node;
    if (new_node=NULL)
    {
    	printf("No memoery Space");
	}
	else
	{
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = start;
    start = new_node;
    return start;
}
}
struct node *insert_at_end(struct node *start, int data) {
    struct node *new_node, *ptr;
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;

    if (start == NULL) {
        start = new_node;
    } else {
        ptr = start;
        while (ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = new_node;
    }
    return start;
}
struct node *insert_at_pos(struct node *start, int data, int pos) {
    struct node *new_node, *ptr;
    int i;
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    if (pos == 1) {
        new_node->next = start;
        start = new_node;
    } else {
        ptr = start;
        for (i = 1; i < pos - 1 && ptr != NULL; i++)
            ptr = ptr->next;
        if (ptr != NULL) {
            new_node->next = ptr->next;
            ptr->next = new_node;
        } else {
            printf("Position out of range\n");
        }
    }
    return start;
}
struct node *del_from_beg(struct node *start) {
    struct node *ptr;
    if (start == NULL) {
        printf("List is empty\n");
    } else {
        ptr = start;
        start = start->next;
        free(ptr);
    }
    return start;
}
struct node *del_from_end(struct node *start) {
    struct node *ptr, *preptr;
    if (start == NULL) {
        printf("List is empty\n");
    } else if (start->next == NULL) {
        free(start);
        start = NULL;
    } else {
        ptr = start;
        while (ptr->next != NULL) {
            preptr = ptr;
            ptr = ptr->next;
        }
        preptr->next = NULL;
        free(ptr);
    }
    return start;
}
struct node *del_at_pos(struct node *start, int pos) {
    struct node *ptr, *preptr;
    int i;
    if (start == NULL) {
        printf("List is empty\n");
    } else if (pos == 1) {
        ptr = start;
        start = start->next;
        free(ptr);
    } else {
        ptr = start;
        for (i = 1; i < pos && ptr != NULL; i++) {
            preptr = ptr;
            ptr = ptr->next;
        }
        if (ptr != NULL) {
            preptr->next = ptr->next;
            free(ptr);
        } else {
            printf("Position out of range\n");
        }
    }
    return start;
}
void traverse(struct node *start) {
    struct node *ptr;
    if (start == NULL) {
        printf("List is empty\n");
    } else {
        ptr = start;
        while (ptr != NULL) {
            printf("%d -> ", ptr->data);
            ptr = ptr->next;
        }
        printf("NULL\n");
    }
}

int main() {
    int choice, data, pos;
    do {
        printf("\nMenu:\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert at position\n");
        printf("4. Delete from beginning\n");
        printf("5. Delete from end\n");
        printf("6. Delete from position\n");
        printf("7. Traverse\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                start = insert_at_beg(start, data);
                break;
            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                start = insert_at_end(start, data);
                break;
            case 3:
                printf("Enter data and position: ");
                scanf("%d%d", &data, &pos);
                start = insert_at_pos(start, data, pos);
                break;
            case 4:
                start = del_from_beg(start);
                break;
            case 5:
                start = del_from_end(start);
                break;
            case 6:
                printf("Enter position: ");
                scanf("%d", &pos);
                start = del_at_pos(start, pos);
                break;
            case 7:
                traverse(start);
                break;
            case 8:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 8);

    return 0;
}

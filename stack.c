 #include <stdio.h>
#include <stdlib.h>

#define MAX 100

int stack[MAX], top = -1, n;

void push() {
    int element;
    if (top >= n - 1) {
        printf("Stack Overflow\n");
    } else {
        printf("Enter the element to push: ");
        scanf("%d", &element);
        stack[++top] = element;
        printf("Pushed %d to the stack\n", element);
    }
}

void pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
    } else {
        printf("Popped %d from the stack\n", stack[top--]);
    }
}

void display() {
    if (top < 0) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements: ");
        for (int i = 0; i <= top; i++) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, element;

    printf("Enter the size of STACK (MAX=100): ");
    scanf("%d", &n);

    while (1) {
        printf("\nMenu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
            	printf("Exit Point");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

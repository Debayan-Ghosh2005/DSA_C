#include <stdio.h>
#define MAX_SIZE 100

void insertElement();
void deleteElement();
void replaceElement();
void searchElement();
void displayArray();
int isFull();
int isEmpty();

int arr[MAX_SIZE];  
int size = 0; 

int main() {
    int choice, n, i;  
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    size = n; 
    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++) {  
        scanf("%d", &arr[i]);
    }
    
    printf("You entered:\n");
    for (i = 0; i < n; i++) {  
        printf("%d ", arr[i]);
    }
    printf("\n"); 
    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert element\n");
        printf("2. Delete element\n");
        printf("3. Replace element\n");
        printf("4. Search element\n");
        printf("5. Display array\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                insertElement();
                break;
            case 2:
                deleteElement();
                break;
            case 3:
                replaceElement();
                break;
            case 4:
                searchElement();
                break;
            case 5:
                displayArray();
                break;
            case 6:
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

int isFull() {
    return size >= MAX_SIZE;
}

int isEmpty() {
    return size == 0;
}

void insertElement() {
    if (isFull()) {
        printf("Array is full. Cannot insert element.\n");
        return;
    }  
    
    int choice, element, position, i;  
    printf("\nInsert Menu:\n");
    printf("1. Insert at beginning\n");
    printf("2. Insert at end\n");
    printf("3. Insert at any position\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    printf("Enter element to insert: ");
    scanf("%d", &element);
    
    switch (choice) {
        case 1:
            position = 0;
            break;
        case 2:
            position = size;
            break;
        case 3:
            printf("Enter position to insert at (0 to %d): ", size);
            scanf("%d", &position);
            if (position < 0 || position > size) {
                printf("Invalid position.\n");
                return;
            }
            break;
        default:
            printf("Invalid choice.\n");
            return;
    }
    
    for (i = size; i > position; i--) {  
        arr[i] = arr[i - 1];
    }
    arr[position] = element;
    size++;
    printf("Element inserted.\n");
}

void deleteElement() {
    if (isEmpty()) {
        printf("Array is empty. Cannot delete element.\n");
        return;
    }    
    
    int choice, position, i;  
    printf("\nDelete Menu:\n");
    printf("1. Delete from beginning\n");
    printf("2. Delete from end\n");
    printf("3. Delete from any position\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    switch (choice) {
        case 1:
            position = 0;
            break;
        case 2:
            position = size - 1;
            break;
        case 3:
            printf("Enter position to delete from (0 to %d): ", size - 1);
            scanf("%d", &position);
            if (position < 0 || position >= size) {
                printf("Invalid position.\n");
                return;
            }
            break;
        default:
            printf("Invalid choice.\n");
            return;
    }
    
    for (i = position; i < size - 1; i++) {  
        arr[i] = arr[i + 1];
    }
    size--;
    printf("Element deleted.\n");
}

void replaceElement() {
    if (isEmpty()) {
        printf("Array is empty. Cannot replace element.\n");
        return;
    }   
    
    int position, newElement;
    printf("Enter position to replace element (0 to %d): ", size - 1);
    scanf("%d", &position);
    if (position < 0 || position >= size) {
        printf("Invalid position.\n");
        return;
    }
    printf("Enter new element: ");
    scanf("%d", &newElement);
    arr[position] = newElement;
    printf("Element at position %d replaced with %d.\n", position, newElement);
}

void searchElement() {
    if (isEmpty()) {
        printf("Array is empty. Cannot search for an element.\n");
        return;
    }
    
    int element, i;  
    printf("Enter element to search: ");
    scanf("%d", &element);

    for (i = 0; i < size; i++) {  
        if (arr[i] == element) {
            printf("Element found at position: %d\n", i+1);
            return;
        }
    }
    printf("Element not found\n");
}

void displayArray() {
    if (isEmpty()) {
        printf("Array is empty.\n");
        return;
    }
    
    int i;  
    printf("Array elements: ");
    for (i = 0; i < size; i++) 
	{ 
        printf("%d ", arr[i]);
    }
    printf("\n");
}

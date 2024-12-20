#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coefficient;
    int exponent;
    struct Node* next;
};
struct Node* createNode(int coeff, int exp) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coefficient = coeff;
    newNode->exponent = exp;
    newNode->next = NULL;
    return newNode;
}
void sortedInsertNode(struct Node** poly, int coeff, int exp) {
    if (coeff == 0) return;  
    
    struct Node* newNode = createNode(coeff, exp);
    struct Node* current = *poly;
    struct Node* previous = NULL;
    while (current != NULL && current->exponent > exp) {
        previous = current;
        current = current->next;
    }

    if (current != NULL && current->exponent == exp) {
        current->coefficient += coeff;
        free(newNode);  
        if (current->coefficient == 0) {  
            if (previous != NULL) {
                previous->next = current->next;
            } else {
                *poly = current->next;
            }
            free(current);
        }
    } else {
        newNode->next = current;
        if (previous == NULL) {
            *poly = newNode;
        } else {
            previous->next = newNode;
        }
    }
}

void displayPoly(struct Node* poly) {
    int first = 1;
    while (poly != NULL) {
        if (poly->coefficient != 0) {
            if (!first) printf(" + ");
            if (poly->exponent == 0) {
                printf("%d", poly->coefficient);
            } else if (poly->exponent == 1) {
                printf("%dx", poly->coefficient);
            } else {
                printf("%dx^%d", poly->coefficient, poly->exponent);
            }
            first = 0;
        }
        poly = poly->next;
    }
    printf("\n");
}
struct Node* addPolynomials(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;
    while (poly1 != NULL) {
        sortedInsertNode(&result, poly1->coefficient, poly1->exponent);
        poly1 = poly1->next;
    }
    while (poly2 != NULL) {
        sortedInsertNode(&result, poly2->coefficient, poly2->exponent);
        poly2 = poly2->next;
    }

    return result;
}
void inputPolynomial(struct Node** poly) {
    int n, coeff, exp;
    printf("Enter the number of terms in the polynomial: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter coefficient and exponent for term %d: ", i + 1);
        scanf("%d%d", &coeff, &exp);
        sortedInsertNode(poly, coeff, exp);
    }
}

int main() {
    struct Node* poly1 = NULL;
    struct Node* poly2 = NULL;
    struct Node* sum = NULL;
    
    printf("Input the first polynomial:\n");
    inputPolynomial(&poly1);
    
    printf("Input the second polynomial:\n");
    inputPolynomial(&poly2);
    
    printf("First Polynomial: ");
    displayPoly(poly1);
    
    printf("Second Polynomial: ");
    displayPoly(poly2);
    
    sum = addPolynomials(poly1, poly2);
    
    printf("Sum of the Polynomials: ");
    displayPoly(sum);
    
    return 0;
}

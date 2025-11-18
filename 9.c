#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int coeff;
    int exp;
    struct Node* next;
} Node;

// Function to create a new polynomial node
Node* createNode(int coeff, int exp) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

// Insert node in descending order of exponents
void insertTerm(Node** poly, int coeff, int exp) {
    if (coeff == 0) return; // ignore zero coefficients

    Node* newNode = createNode(coeff, exp);

    // Insert at beginning if list is empty or exponent is larger
    if (*poly == NULL || (*poly)->exp < exp) {
        newNode->next = *poly;
        *poly = newNode;
        return;
    }

    Node* curr = *poly;
    // Traverse to find correct position
    while (curr->next != NULL && curr->next->exp > exp)
        curr = curr->next;

    // If exponent already exists → add coefficients
    if (curr->next != NULL && curr->next->exp == exp) {
        curr->next->coeff += coeff;
        free(newNode);
        // If coefficient becomes zero → delete node
        if (curr->next->coeff == 0) {
            Node* temp = curr->next;
            curr->next = temp->next;
            free(temp);
        }
    } else {
        newNode->next = curr->next;
        curr->next = newNode;
    }
}

// Function to add two polynomials
Node* addPolynomials(Node* p1, Node* p2) {
    Node* result = NULL;

    while (p1 != NULL && p2 != NULL) {
        if (p1->exp == p2->exp) {
            insertTerm(&result, p1->coeff + p2->coeff, p1->exp);
            p1 = p1->next;
            p2 = p2->next;
        } else if (p1->exp > p2->exp) {
            insertTerm(&result, p1->coeff, p1->exp);
            p1 = p1->next;
        } else {
            insertTerm(&result, p2->coeff, p2->exp);
            p2 = p2->next;
        }
    }

    // Add remaining terms
    while (p1 != NULL) {
        insertTerm(&result, p1->coeff, p1->exp);
        p1 = p1->next;
    }

    while (p2 != NULL) {
        insertTerm(&result, p2->coeff, p2->exp);
        p2 = p2->next;
    }

    return result;
}

// Print polynomial in readable format
void printPolynomial(Node* poly) {
    if (poly == NULL) {
        printf("0\n");
        return;
    }
    while (poly != NULL) {
        printf("%dx^%d", poly->coeff, poly->exp);
        poly = poly->next;
        if (poly != NULL) printf(" + ");
    }
    printf("\n");
}

int main() {
    Node *p1 = NULL, *p2 = NULL, *result = NULL;

    int n, coeff, exp;

    printf("Enter number of terms in Polynomial 1: ");
    scanf("%d", &n);
    printf("Enter each term as: <coefficient exponent>\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &coeff, &exp);
        insertTerm(&p1, coeff, exp);
    }

    printf("Enter number of terms in Polynomial 2: ");
    scanf("%d", &n);
    printf("Enter each term as: <coefficient exponent>\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &coeff, &exp);
        insertTerm(&p2, coeff, exp);
    }

    printf("\nPolynomial 1: ");
    printPolynomial(p1);
    printf("Polynomial 2: ");
    printPolynomial(p2);

    result = addPolynomials(p1, p2);

    printf("\nResultant Polynomial (P1 + P2): ");
    printPolynomial(result);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int coeff;
    int exp;
    struct Node* next;
} Node;

// Create new term node
Node* createNode(int coeff, int exp) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->coeff = coeff;
    n->exp = exp;
    n->next = NULL;
    return n;
}

// Insert term in descending order of exponent
void insertTerm(Node** poly, int coeff, int exp) {
    if (coeff == 0) return;  // ignore zeros

    Node* newNode = createNode(coeff, exp);

    // Insert at head if empty or exponent is larger
    if (*poly == NULL || (*poly)->exp < exp) {
        newNode->next = *poly;
        *poly = newNode;
        return;
    }

    Node* curr = *poly;

    while (curr->next != NULL && curr->next->exp > exp)
        curr = curr->next;

    // If exponent exists → add coefficients
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

// Multiply two polynomials
Node* multiplyPolynomials(Node* p1, Node* p2) {
    Node* result = NULL;

    for (Node* a = p1; a != NULL; a = a->next) {
        for (Node* b = p2; b != NULL; b = b->next) {
            int coeff = a->coeff * b->coeff;
            int exp   = a->exp + b->exp;
            insertTerm(&result, coeff, exp);
        }
    }

    return result;
}

// Print polynomial
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

// Build polynomial from user input
void buildPolynomial(Node** poly) {
    int n, coeff, exp;
    printf("Enter number of terms: ");
    scanf("%d", &n);

    printf("Enter each term as <coefficient exponent>:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &coeff, &exp);
        insertTerm(poly, coeff, exp);
    }
}

int main() {
    Node *p1 = NULL, *p2 = NULL, *result = NULL;

    printf("Polynomial 1:\n");
    buildPolynomial(&p1);

    printf("\nPolynomial 2:\n");
    buildPolynomial(&p2);

    printf("\nPolynomial 1: ");
    printPolynomial(p1);

    printf("Polynomial 2: ");
    printPolynomial(p2);

    result = multiplyPolynomials(p1, p2);

    printf("\nResultant Polynomial (P1 × P2): ");
    printPolynomial(result);

    return 0;
}

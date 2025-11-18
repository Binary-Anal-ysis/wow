#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int x) {
    stack[++top] = x;
}

int pop() {
    return stack[top--];
}

int evaluatePostfix(char exp[]) {
    int i = 0, a, b;

    while (exp[i] != '\0') {

        // Operand (single digit)
        if (exp[i] >= '0' && exp[i] <= '9') {
            push(exp[i] - '0');   // convert char → int
        }
        else {
            b = pop();
            a = pop();

            switch (exp[i]) {
                case '+': push(a + b); break;
                case '-': push(a - b); break;
                case '*': push(a * b); break;
                case '/': push(a / b); break;
            }
        }
        i++;
    }

    return pop();
}

int main() {
    char exp[MAX];

    printf("Enter postfix expression: ");
    scanf("%s", exp);

    printf("Result: %d\n", evaluatePostfix(exp));

    return 0;
}

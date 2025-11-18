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

int evaluatePrefix(char exp[]) {
    int i = 0;

    // find length
    while (exp[i] != '\0') i++;
    i--;  // start from last index

    while (i >= 0) {

        // If operand (single digit)
        if (exp[i] >= '0' && exp[i] <= '9') {
            push(exp[i] - '0');
        }               
        else {  
            int a = pop();
            int b = pop();
            
            switch (exp[i]) {
                case '+': push(a + b); break;
                case '-': push(a - b); break;
                case '*': push(a * b); break;
                case '/': push(a / b); break;
            }
        }
        i--;
    }

    return pop();
}

int main() {
    char exp[MAX];

    printf("Enter prefix expression: ");
    scanf("%s", exp);

    printf("Result: %d\n", evaluatePrefix(exp));

    return 0;
}

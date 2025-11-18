#include <stdio.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c)
{
    stack[++top] = c;
}

char pop()
{
    return (top == -1) ? '\0' : stack[top--];
}

char peek()
{
    return (top == -1) ? '\0' : stack[top];
}

int precedence(char c)
{
    if (c == '^')
        return 3;
    if (c == '*' || c == '/')
        return 2;
    if (c == '+' || c == '-')
        return 1;
    return 0;
}

// Reverse using WHILE loop only
void reverse(char s[])
{
    int i = 0;
    int j = 0;
    char temp;

    // find length
    while (s[j] != '\0')
        j++;
    j--;    

    // swap using while-loop
    while (i < j)
    {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        i++;
        j--;
    }
}

void infixToPostfix(char infix[], char postfix[])
{
    int i = 0, j = 0;
    char c;

    while ((c = infix[i++]) != '\0')
    {

        if (isalnum(c))
        {
            postfix[j++] = c;
        }
        else if (c == '(')
        {
            push(c);
        }
        else if (c == ')')
        {
            while (peek() != '(')
                postfix[j++] = pop();
            pop();
        }
        else
        {
            while (precedence(peek()) >= precedence(c))
                postfix[j++] = pop();
            push(c);
        }
    }

    while (top != -1)
        postfix[j++] = pop();

    postfix[j] = '\0';
}

void infixToPrefix(char infix[], char prefix[])
{
    char temp[MAX];
    int i = 0;

    reverse(infix);

    // swap '(' and ')'
    while (infix[i] != '\0')
    {
        if (infix[i] == '(')
            infix[i] = ')';
        else if (infix[i] == ')')
            infix[i] = '(';
        i++;
    }

    infixToPostfix(infix, temp);

    reverse(temp);

    i = 0;
 
}

int main()
{
    char infix[MAX], prefix[MAX];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPrefix(infix, prefix);

    printf("Prefix expression: %s\n", prefix);

    return 0;
}

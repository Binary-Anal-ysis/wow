#include <stdio.h>
#include <ctype.h>

char stack[100];
int top = -1;

void push(char c)
{
    stack[++top] = c;
}

char pop()
{
    return stack[top--];
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

int isOperator(char c)
{
    return (c == '+' || c == '/' || c == '-' || c == '*' || c == '^');
}

void ToPostfix(char exp[])
{
    int i = 0;

    while (exp[i] != '\0')
    {
        if (isalnum(exp[i]))
        {
            printf("%c", exp[i]);
        }
        else if (exp[i] == '(')
        {
            push(exp[i]);
        }
        else if (exp[i] == ')')
        {
            while (top != -1 && stack[top] != '(')
            {
                printf("%c", pop());
            }
            pop(); // remove '('
        }
        else if (isOperator(exp[i]))
        {
            while (top != -1 && precedence(stack[top]) >= precedence(exp[i]))
            {
                printf("%c", pop());
            }
            push(exp[i]);
        }

        i++;
    }

    while (top != -1)
    {
        printf("%c", pop());
    }
}
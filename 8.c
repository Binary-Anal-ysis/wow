#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node
{
    int data;
    struct Node *next;
};

// Insert node at end
void insert(struct Node **head, int x)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    struct Node *temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

// Reverse a linked list
struct Node *reverse(struct Node *head)
{
    struct Node *prev = NULL;
    struct Node *curr = head;
    struct Node *next;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

// Check if palindrome
int isPalindrome(struct Node *head)
{
    if (head == NULL || head->next == NULL)
        return 1;

    // 1. Find middle using slow/fast pointers
    struct Node *slow = head;
    struct Node *fast = head;

    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    // 2. Reverse second half
    struct Node *second = reverse(slow->next);

    // 3. Compare both halves
    struct Node *first = head;
    struct Node *temp = second;

    int result = 1;
    while (temp != NULL)
    {
        if (first->data != temp->data)
        {
            result = 0;
            break;
        }
        first = first->next;
        temp = temp->next;
    }

    return result; // 1 = palindrome, 0 = not
}

int main()
{
    struct Node *head = NULL;
    int n, x;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        insert(&head, x);
    }

    printf("%d\n", isPalindrome(head));

    return 0;
}
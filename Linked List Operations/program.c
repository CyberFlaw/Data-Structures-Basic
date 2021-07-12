#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *link;
};

struct Node* addElement(struct Node *ptr)
{
    int ele;
    printf("Enter data: ");
    scanf("%d", &ele);

    struct Node *temp;
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = ele;
    temp->link = NULL;

    ptr->link = temp;
    return temp;
}

void deleteElement(struct Node **head)
{
    int pos;
    printf("Enter position: ");
    scanf("%d", &pos);

    struct Node *current = *head;
    struct Node *prev = *head;

    if (*head == NULL)
        printf("Empty list\n");
    else if (pos == 1)
    {
        *head = current->link;
        free(current);
        current = NULL;
    }
    else
    {
        while (pos != 1)
        {
            prev = current;
            current = current->link;
            pos--;
        }
        prev->link = current->link;
        free(current);
        current = NULL;
    }
}

struct Node* reverseLinkedList(struct Node *head)
{
    struct Node *prev = NULL;
    struct Node *next = NULL;

    while (head != NULL)
    {
        next = head->link;
        head->link = prev;
        prev = head;
        head = next;
    }
    head = prev;
    return head;
}

void display(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }
}

void main()
{
    int n;
    printf("Enter the length of linked list: ");
    scanf("%d", &n);

    struct Node *head;
    head = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter data: ");
    scanf("%d", &head->data);
    head->link = NULL;

    struct Node *ptr;
    ptr = head;
    for (int i = 0; i < n - 1; i++)
        ptr = addElement(ptr);

    ptr = head;

    printf("\nThe linked list is: \n");
    display(ptr);

    head = reverseLinkedList(head);
    ptr = head;
    printf("\n\nThe reverse of linked list is: \n");
    display(ptr);

    printf("\nDeletion:\n");
    deleteElement(&head);
    display(ptr);
}
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int data;
    struct node *link;
};

struct Node *top = 0;

void push()
{
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter element to be pushed: ");
    int ele;
    scanf("%d", &ele);

    newNode->data = ele;
    newNode->link = top;
    top = newNode;
}

void display()
{
    struct Node *traverse;
    traverse = top;

    if (top == 0)
        printf("\nSTACK UNDERFLOW");
    else
    {
        while (traverse != 0)
        {
            printf("%d\t", traverse->data);
            traverse = traverse->link;
        }
    }
    printf("\n");
}

void pop()
{
    struct Node *temp;
    temp = top;

    if (top == 0)
        printf("\nSTACK UNDERFLOW\n");
    else
    {
        top = top->link;
        free(temp);
        printf("Element popped!\n");
    }
}

void main()
{
    int ch;
    bool run = true;
    while (run)
    {
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            run = false;
            break;
        default:
            printf("Wrong option\n");
            break;
        }
    }
}
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int data;
    struct Node *link;
};

struct Node *front = 0;
struct Node *rear = 0;

void enqueue()
{
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));

    int ele;
    printf("Enter the element: ");
    scanf("%d", &ele);
    newNode->data = ele;
    newNode->link = 0;

    if (front == 0 && rear == 0)
        front = rear = newNode;
    else
    {
        rear->link = newNode;
        rear = newNode;
    }
}

void dequeue()
{
    struct Node *temp;
    if (front == 0 && rear == 0)
        printf("List Empty!\n");
    else
    {
        temp = front;
        front = front->link;
        free(temp);
    }
}

void display()
{
    struct Node *temp;
    if (front == 0 && rear == 0)
        printf("Empty List!\n");
    else
    {
        temp = front;
        while (temp != 0)
        {
            printf("%d\t", temp->data);
            temp = temp->link;
        }
        printf("\n");
    }
}

void main()
{
    bool run = true;
    int ch;
    while (run)
    {
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            run = false;
            break;

        default:
            printf("Wrong Option!\n");
            break;
        }
    }
}
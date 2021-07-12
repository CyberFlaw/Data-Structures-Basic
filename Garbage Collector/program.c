#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int insert = 0;
int delete = 0;

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
} * availHead, *availTemp;

struct Node *createList()
{
    int ele;
    struct Node *temp;
    temp = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter Initial Element: ");
    scanf("%d", &ele);
    temp->data = ele;
    temp->next = temp->prev = NULL;

    return temp;
}

void display(struct Node *head)
{
    struct Node *temp = head;
    int i = 1;

    printf("The List Items: \n");
    while (temp != NULL)
    {
        printf("%d : %d\n", i++, temp->data);
        temp = temp->next;
    }
    printf("\n");
}

struct Node *sweep()
{
    struct Node *ptr = availHead;

    availHead = availHead->next;
    ptr->next = NULL;
    delete --;

    return ptr;
}

struct Node *insertElement(struct Node *head)
{
    int ele;
    struct Node *ptr = head, *temp = NULL, *garbage = NULL;

    insert++;

    while (ptr->next != NULL)
        ptr = ptr->next;

    if (insert > 5)
    {
        printf("Insufficient Memory... Cleaning up...\n");
        insert = insert - delete;
        garbage = sweep();

        printf("Enter elemet: ");
        scanf("%d", &ele);
        garbage->data = ele;
        ptr->next = garbage;
        garbage->prev = ptr;
    }
    else
    {
        temp = createList();
        temp->prev = ptr;
        ptr->next = temp;
    }

    display(head);
    return head;
}

struct Node *deleteElement(struct Node *head)
{
    struct Node *ptr = head;
    head = head->next;
    ptr->next = NULL;
    head->prev = NULL;
    delete ++;

    printf("Sweeping Unmarked Nodes...\n");

    if (delete == 1)
    {
        availHead = ptr;
        availTemp = availHead;
    }
    else
    {
        availHead->next = ptr;
        ptr->prev = availTemp;
        availTemp = availTemp->next;
    }

    display(head);
    return head;
}

void main()
{
    int ch;
    bool run = true;
    struct Node *head, *temp;
    head = (struct Node *)malloc(sizeof(struct Node));
    temp = (struct Node *)malloc(sizeof(struct Node));
    head->next = head->prev = NULL;

    while (run)
    {
        printf("1. Create\n2. Insert\n3. Delete\n4. Exit \n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            temp = createList();
            head = temp;
            break;
        case 2:
            head = insertElement(head);
            break;
        case 3:
            head = deleteElement(head);
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
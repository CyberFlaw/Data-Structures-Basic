#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

void displayList(struct Node *head)
{
    struct Node *temp = head;
    int i = 0;
    printf("List:\n");
    while (temp != NULL)
    {
        printf("%d : %d\n", i++, temp->data);
        temp = temp->next;
    }
    printf("\n");
}

struct Node *createList()
{
    int ele;
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter the element: ");
    scanf("%d", &ele);

    temp->next = temp->prev = NULL;
    temp->data = ele;

    return temp;
}

struct Node *insertStart(struct Node *head)
{
    int ele;
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter the element: ");
    scanf("%d", &ele);

    temp->data = ele;
    temp->prev = NULL;
    temp->next = head;
    head->prev = temp;
    head = temp;

    return head;
}

struct Node *insertEnd(struct Node *head)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    struct Node *ptr = head;

    while (ptr->next != NULL)
        ptr = ptr->next;

    temp = createList();
    temp->next = NULL;
    temp->prev = ptr;
    ptr->next = temp;

    return head;
}

struct Node *insertKey(struct Node *head)
{
    int key, i = 0;
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    struct Node *ptr = head;

    printf("Enter the key: ");
    scanf("%d", &key);

    while (i++ < key)
        ptr = ptr->next;

    temp = createList();
    temp->next = ptr->next;
    temp->prev = ptr;
    ptr->next = temp->next->prev = temp;

    return head;
}

struct Node *deleteStart(struct Node *head)
{
    struct Node *ptr = head;

    head = head->next;
    ptr->next = head->prev = NULL;
    free(ptr);

    return head;
}

struct Node *deleteEnd(struct Node *head)
{
    struct Node *ptr1 = head;
    struct Node *ptr2 = head;

    while (ptr1->next != NULL)
    {
        ptr1 = ptr1->next;
        ptr2 = ptr1->next;
    }

    ptr2 = ptr2->prev;
    ptr1->prev = ptr2->next = NULL;
    free(ptr1);

    return head;
}

struct Node *deleteKey(struct Node *head)
{
    int key, i = 0;
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    struct Node *ptr1 = head;
    struct Node *ptr2 = head;

    printf("Enter the key: ");
    scanf("%d", &key);

    while (i++ < key)
    {
        ptr1 = ptr1->next;
        ptr2 = ptr1->next;
    }

    temp = ptr1;
    ptr1 = ptr1->prev;
    ptr2 = ptr2->next;
    ptr1->next = ptr2;
    ptr2->prev = ptr1;
    free(temp);

    return head;
}

void main()
{
    int ch;
    bool run = true;

    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    head->prev = NULL;
    head->next = NULL;

    head = createList();

    while (run)
    {
        printf("Insert\n1. Start \t2. Given Key\t3. End\nDelete\n4. Start\t5. Given key\t6. End\n7. Display\n8. Exit\t: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            head = insertStart(head);
            break;
        case 2:
            insertKey(head);
            break;
        case 3:
            head = insertEnd(head);
            break;

        case 4:
            head = deleteStart(head);
            break;
        case 5:
            head = deleteKey(head);
            break;
        case 6:
            head = deleteEnd(head);
            break;

        case 7:
            displayList(head);
            break;
        case 8:
            run = false;
            break;

        default:
            printf("Wrong Option!\n");
            break;
        }
    }
}
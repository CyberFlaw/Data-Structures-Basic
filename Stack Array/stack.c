#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int size;
    int top;
    int *s;
};

void push(struct Stack *s)
{
    int ele;

    if (s->top == s->size - 1)
        printf("Stack Overflow!! ");
    else
    {
        printf("Enter number to be pushed: ");
        scanf("%d", &ele);
        s->top++;
        s->s[s->top] = ele;
    }
}

void pop(struct Stack *s)
{
    if (s->top == -1)
        printf("Stack underflow!! ");
    else
    {
        printf("The element popped is: %d", s->s[s->top]);
        s->top--;
    }
}

void viewTopElement(struct Stack *s)
{
    if (s->top == -1)
        printf("Empty Stack!");
    else
        printf("Top element in the stack is: %d", s->s[s->top]);
}

void checkStackSpaceStatus(struct Stack *s)
{
    if (s->top == -1)
        printf("Stack is empty!");
    else if (s->top == s->size - 1)
        printf("Stack is full!");
    else
        printf("The stack has %d free spaces", (s->size - s->top));
}

void displayStack(struct Stack *s)
{
    printf("The stack is: \n");
    for (int i = s->top; i > 0; i--)
        printf("%d \t", s->s[i]);
}

void main()
{
    int ch, run = 1;
    struct Stack s;

    printf("Enter the length of stack: ");
    scanf("%d", &s.size);
    s.s = (int *)malloc(s.size * sizeof(int));
    s.top = -1;

    while (run)
    {
        printf("\n1. Check state of stack\n2. Push\n3. Pop\n4. View top element\n5. Display\n6. Exit\n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            checkStackSpaceStatus(&s);
            break;
        case 2:
            push(&s);
            break;
        case 3:
            pop(&s);
            break;
        case 4:
            viewTopElement(&s);
            break;
        case 5:
            displayStack(&s);
            break;
        case 6:
            run = 0;
            break;
        default:
            printf("Wrong option!");
            break;
        }
    }
}
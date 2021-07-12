#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int size;
    int front;
    int rear;
    int *q;
};

void enqueue(struct Queue *q)
{
    int ele;

    if (q->rear == q->size - 1)
        printf("Queue is full! ");
    else
    {
        printf("Input element to be pushed: ");
        scanf("%d", &ele);
        q->rear++;
        q->q[q->rear] = ele;
    }
}

void dequeue(struct Queue *q)
{
    if (q->rear == q->front)
        printf("Empty Queue!");
    else
    {
        printf("Element popped!");
        q->front++;
    }
}

void display(struct Queue q)
{
    printf("The current state of the queue is: \n");
    for (int i = q.front + 1; i <= q.rear; i++)
        printf("%d\t", q.q[i]);
}

void main()
{
    int ch, run = 1;
    struct Queue q;

    printf("Enter size of the queue: ");
    scanf("%d", &q.size);

    q.q = (int *)malloc(q.size * sizeof(int));
    q.front = q.rear = -1;

    while (run)
    {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            enqueue(&q);
            break;
        case 2:
            dequeue(&q);
            break;
        case 3:
            display(q);
            break;
        case 4:
            run = 0;
            break;
        default:
            printf("Wrong option!");
            break;
        }
    }
}
#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int front;
    int rear;
    int size;
    int *q;
};

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void sort(struct Queue *q)
{
    for (int i = 0; i < q->size - 1; i++)
        for (int j = 0; j < q->size - i - 1; j++)
        {
            if (q->q[j] < q->q[j + 1])
                swap(&q->q[j], &q->q[j + 1]);
        }
}

void enQueue(struct Queue *q)
{
    int ele;

    if (q->rear == q->size - 1)
        printf("Queue is full!");
    else if (q->front == -1 && q->rear == -1)
    {
        printf("Input element: ");
        scanf("%d", &ele);
        q->front = q->rear = 0;
        q->q[q->rear] = ele;
        q->rear++;
    }
    else
    {
        printf("Input element: ");
        scanf("%d", &ele);
        q->rear++;
        q->q[q->rear] = ele;
    }
}

void deQueue(struct Queue *q)
{
    if (q->rear == q->front)
        printf("Empty Queue!");
    else if (q->front == q->rear - 1)
    {
        printf("Element popped!");
        q->front = q->rear = -1;
    }
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

    printf("Enter the size of queue: ");
    scanf("%d", &q.size);
    q.front = q.rear = -1;
    q.q = (int *)malloc(q.size * sizeof(int));

    while (run)
    {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            enQueue(&q);
            sort(&q);
            break;
        case 2:
            deQueue(&q);
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
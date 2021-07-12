#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int front;
    int rear;
    int size;
    int *q;
};

void enqueue(struct Queue *q)
{
    int ele;
    printf("Input the element: ");
    scanf("%d", &ele);

    if ((q->front == 0 && q->rear == q->size - 1) || (q->front == q->rear + 1))
        printf("The queue is full!");
    else if (q->front == -1 && q->rear == -1)
    {
        q->front = q->rear = 0;
        q->q[q->rear] = ele;
    }
    else if (q->rear == q->size - 1)
    {
        q->rear = 0;
        q->q[q->rear] = ele;
    }
    else
    {
        q->rear++;
        q->q[q->rear] = ele;
    }
}

void dequeue(struct Queue *q)
{
    if (q->front == -1 && q->rear == -1)
        printf("The queue is empty! ");
    else if (q->front == q->rear)
    {
        printf("Element popped!");
        q->front = q->rear = -1;
    }
        else if (q->front == q->size - 1)
        {
            printf("Element popped!");
            q->front = 0;
        }
    else
    {
        printf("Element popped!");
        q->front++;
    }
}

void display(struct Queue q)
{
    int i = q.front;
    printf("The queue is: \n");
    while (i != q.rear)
    {
        printf("%d\t", q.q[i]);
        i = (i + 1) % q.size;
    }
    printf("%d", q.q[q.rear]);
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
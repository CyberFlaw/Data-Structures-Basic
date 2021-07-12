#include <stdio.h>
#include <stdlib.h>

struct DEQueue
{
    int front;
    int rear;
    int size;
    int *q;
};

int elementInput()
{
    int ele;
    printf("Input the element: ");
    scanf("%d", &ele);
    return ele;
}

void frontEnqueue(struct DEQueue *q)
{
    int ele = elementInput();

    if ((q->front == 0 && q->rear == q->size - 1) || (q->front == q->rear + 1))
        printf("The queue is full!");
    else if (q->front == -1 && q->rear == -1)
    {
        q->front = q->rear = 0;
        q->q[q->front] = ele;
    }
    else if (q->front == 0)
    {
        q->front = q->size - 1;
        q->q[q->front] = ele;
    }
    else
    {
        q->front--;
        q->q[q->front] = ele;
    }
}

void rearEnqueue(struct DEQueue *q)
{
    int ele = elementInput();

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

void frontDequeue(struct DEQueue *q)
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

void rearDequeue(struct DEQueue *q)
{
    if (q->front == -1 && q->rear == -1)
        printf("The queue is empty! ");
    else if (q->front == q->rear)
    {
        printf("Element popped!");
        q->front = q->rear = -1;
    }
    else if (q->rear == 0)
    {
        printf("Element popped!");
        q->rear = q->size - 1;
    }
    else
    {
        printf("Element popped!");
        q->rear--;
    }
}

void display(struct DEQueue q)
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
    struct DEQueue q;
    q.front = q.rear = -1;

    printf("Enter size: ");
    scanf("%d", &q.size);
    q.q = (int *)malloc(q.size * sizeof(int));

    while (run)
    {
        printf("\n1. Front Enqueue\n2. Rear Enqueve\n3. Front Dequeue\n4. Rear Dequeue\n5. Display\n6. Exit\n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            frontEnqueue(&q);
            break;
        case 2:
            rearEnqueue(&q);
            break;
        case 3:
            frontDequeue(&q);
            break;
        case 4:
            rearDequeue(&q);
            break;
        case 5:
            display(q);
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
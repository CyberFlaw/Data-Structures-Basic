#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int coeff;
    int pow;
    struct Node *next;
};

void createNode(int coeff, int pow, struct Node **temp)
{
    struct Node *r, *z;
    z = *temp;
    if (z == NULL)
    {
        r = (struct Node *)malloc(sizeof(struct Node));
        r->coeff = coeff;
        r->pow = pow;
        *temp = r;
        r->next = (struct Node *)malloc(sizeof(struct Node));
        r = r->next;
        r->next = NULL;
    }
    else
    {
        r->coeff = coeff;
        r->pow = pow;
        r->next = (struct Node *)malloc(sizeof(struct Node));
        r = r->next;
        r->next = NULL;
    }
}

void addPolinomial(struct Node *poly1, struct Node *poly2, struct Node *poly)
{
    while (poly1->next && poly2->next)
    {
        if (poly1->pow > poly2->pow)
        {
            poly->pow = poly1->pow;
            poly->coeff = poly1->coeff;
            poly1 = poly1->next;
        }
        else if (poly1->pow < poly2->pow)
        {
            poly->pow = poly2->pow;
            poly->coeff = poly2->coeff;
            poly2 = poly2->next;
        }
        else
        {
            poly->pow = poly1->pow;
            poly->coeff = poly1->coeff + poly2->coeff;
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
        poly->next = (struct Node *)malloc(sizeof(struct Node));
        poly = poly->next;
        poly->next = NULL;
    }
    while (poly1->next || poly2->next)
    {
        if (poly1->next)
        {
            poly->pow = poly1->pow;
            poly->coeff = poly1->coeff;
            poly1 = poly1->next;
        }
        if (poly2->next)
        {
            poly->pow = poly2->pow;
            poly->coeff = poly2->coeff;
            poly2 = poly2->next;
        }
        poly->next = (struct Node *)malloc(sizeof(struct Node));
        poly = poly->next;
        poly->next = NULL;
    }
}

void multiplyPolinomial(struct Node *poly1, struct Node *poly2, struct Node *poly)
{
    struct Node *ptr1 = poly1, *ptr2 = poly2;
    int coeff, pow;
    while (ptr1 != NULL)
    {
        while (ptr2 != NULL)
        {
            coeff = ptr1->coeff * ptr2->coeff;
            pow = ptr1->pow + ptr2->pow;
            createNode(coeff, pow, &poly);
            ptr2 = ptr2->next;
        }
        ptr2 = poly2;
        ptr1 = ptr1->next;
    }
}

void show(struct Node *node)
{
    while (node->next != NULL)
    {
        printf("%dx^%d", node->coeff, node->pow);
        node = node->next;
        if (node->coeff >= 0)
        {
            if (node->next != NULL)
                printf("+");
        } else {
            if (node->next != NULL)
                printf("-");
        }
    }
    printf("\n");
}

void main()
{
    int ch;
    bool run = true;
    struct Node *poly1 = NULL, *poly2 = NULL, *polyAdd = NULL, *polyMultiply = NULL;
    int coeff, pow, i = 1;

    printf("--First Polynomial Declaration--\n");
    while (i == 1)
    {
        printf("Enter Power: ");
        scanf("%d", &pow);
        printf("Enter coeficient: ");
        scanf("%d", &coeff);
        printf("Press 1 to add next element...\n");
        scanf("%d", &i);
        createNode(coeff, pow, &poly1);
    }

    printf("--Second Polynomial Declaration--\n");
    i = 1;
    while (i == 1)
    {
        printf("Enter Power: ");
        scanf("%d", &pow);
        printf("Enter coeficient: ");
        scanf("%d", &coeff);
        printf("Press 1 to add next element...\n");
        scanf("%d", &i);
        createNode(coeff, pow, &poly2);
    }

    polyAdd = (struct Node *)malloc(sizeof(struct Node));
    polyMultiply = (struct Node *)malloc(sizeof(struct Node));

    show(poly1);
    show(poly2);

    addPolinomial(poly1, poly2, polyAdd);
    printf("Addision Results: \n");
    show(polyAdd);

    multiplyPolinomial(poly1, poly2, polyMultiply);
    printf("Multiplication Results: \n");
    show(polyMultiply);
}
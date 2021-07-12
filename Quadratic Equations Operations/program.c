#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Term
{
    int coeff;
    int pow;
};

struct Poly
{
    int n;
    struct Term *t;
};

void create(struct Poly *p)
{
    int i;

    printf("Enter number of terms: ");
    scanf("%d", &p->n);

    // Dynamic Array declaration

    p->t = (struct Term *)malloc(p->n * sizeof(struct Term));

    // Input terms
    printf("Enter the coefficient and its power:\n");

    for (i = 0; i < p->n; i++)
    {
        scanf("%d %d", &p->t[i].coeff, &p->t[i].pow);
        if(i != p->n-1)
            printf("Enter next element: \n");
    }
}

void display(struct Poly p)
{
    int i;

    for (i = 0; i < p.n; i++)
        if (i == p.n - 1)
            printf("%d x^%d ", p.t[i].coeff, p.t[i].pow);
        else
            printf("%d x^%d + ", p.t[i].coeff, p.t[i].pow);

    printf("\n");
}

struct Poly *add(struct Poly *p1, struct Poly *p2)
{
    int i, j, k;

    struct Poly *sum;

    // Dynamically allocating sum structure
    sum = (struct Poly *)malloc(sizeof(struct Poly));
    sum->t = (struct Term *)malloc((p1->n + p2->n) * sizeof(struct Term));

    i = j = k = 0;

    // Addision algorithm

    while (i < p1->n && j < p2->n)
    {
        if (p1->t[i].pow > p2->t[j].pow)
            sum->t[k++] = p1->t[i++];
        else if (p1->t[i].pow < p2->t[j].pow)
            sum->t[k++] = p2->t[j++];
        else
        {
            sum->t[k].pow = p1->t[i].pow;
            sum->t[k++].coeff = p1->t[i++].coeff + p2->t[j++].coeff;
        }
    }
    // Copying the remaining elements

    for (; i < p1->n; i++)
        sum->t[k++] = p1->t[i++];
    for (; j < p2->n; j++)
        sum->t[k++] = p2->t[j++];

    // Giving the correct length value
    sum->n = k;

    return sum;
}

struct Poly *subtract(struct Poly *p1, struct Poly *p2)
{
    struct Poly *difference;
    int i, j, k;

    difference = (struct Poly *)malloc(sizeof(struct Poly));
    difference->t = (struct Term *)malloc((p1->n + p2->n) * sizeof(struct Term));

    i = j = k = 0;

    while (i < p1->n && j < p2->n)
    {
        if (p1->t[i].pow > p2->t[j].pow)
            difference->t[k++] = p1->t[i++];
        else if (p2->t[i].pow > p1->t[j].pow)
        {
            difference->t[k++].coeff = p2->t[j].coeff * -1;
            difference->t[k++].pow = p2->t[j].pow;
        }
        else
        {
            difference->t[k].pow = p1->t[i].pow;
            difference->t[k++].coeff = p1->t[i++].coeff - p2->t[j++].coeff;
        }
    }

    for (; i < p1->n; i++)
        difference->t[k++] = p1->t[i];
    for (; j < p2->n; j++)
    {
        difference->t[k].pow = p2->t[j].pow;
        difference->t[k++].coeff = p2->t[j].coeff * -1;
    }

    difference->n = k;

    return difference;
}

struct Poly *multiply(struct Poly *p1, struct Poly *p2)
{
    struct Poly *product;
    int i, j, k;

    product = (struct Poly *)malloc(sizeof(struct Poly));
    product->t = (struct Term *)malloc((p1->n * p2->n) * sizeof(struct Term));

    i = j = k = 0;

    while (i < p1->n)
    {
        while (j < p2->n)
        {
            product->t[k].coeff = p1->t[i].coeff * p2->t[j].coeff;
            product->t[k++].pow = p1->t[i].pow + p2->t[j++].pow;
        }
        i++;
        j = 0;
    }

    product->n = k;

    return product;
}

int main()
{
    struct Poly p1, p2, *p3;
    int ch;

    create(&p1);
    create(&p2);

    printf("Enter \n1. Addition\n2. Subtraction\n3. Multiplication \n");
    scanf("%d", &ch);

    switch (ch)
    {
    case 1:
        p3 = add(&p1, &p2);
        printf("The polynomials are: \n");
        display(p1);
        printf("\n");
        display(p2);
        printf("The modified polynomial is: \n");
        display(*p3);
        break;

    case 2:
        p3 = subtract(&p1, &p2);
        printf("The polynomials are: \n");
        display(p1);
        printf("\n");
        display(p2);
        printf("The modified polynomial is: \n");
        display(*p3);
        break;

    case 3:
        p3 = multiply(&p1, &p2);
        printf("The polynomials are: \n");
        display(p1);
        printf("\n");
        display(p2);
        printf("The modified polynomial is: \n");
        display(*p3);
        break;

    default:
        printf("Invalid option!");
        break;
    }

    return 0;
}
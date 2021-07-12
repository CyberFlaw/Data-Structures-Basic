#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack
{
    int size;
    int top;
    char *s;
};

void push(struct Stack *s, char ele)
{
    if (s->top == s->size - 1)
        printf("Stack Overflow!! ");
    else
    {
        s->top++;
        s->s[s->top] = ele;
    }
}

int pop(struct Stack *s)
{
    if (s->top == -1)
        return 0;
    else
        return s->s[s->top--];
}

char stackTop(struct Stack s)
{
    if (s.top == -1)
        return;
    else
        return (s.s[s.top]);
}

int isOperant(char ele)
{
    if (ele == '+' || ele == '-' || ele == '*' || ele == '/')
        return 0;
    else
        return 1;
}

int precedence(char ele)
{
    if (ele == "+" || ele == "-")
        return 1;
    else if (ele == "*" || ele == "/")
        return 2;
    else
        return 0;
}

int isEmpty(struct Stack s)
{
    if (s.top == -1)
        return 1;
    else
        return 0;
}

char *postfixConvertion(char *infix)
{
    struct Stack s;
    s.top = -1;
    s.size = strlen(infix) + 1;
    char *postfix = malloc(s.size * sizeof(char));
    int i = 0, j = 0;

    while (infix[i] != '\0')
    {
        if (isOperant(infix[i]))
            postfix[j++] = infix[i++];
        else
        {
            if (precedence(infix[i]) > precedence(stackTop(s)))
                push(&s, infix[i++]);
            else
            {
                if (precedence(infix[i]) < precedence(stackTop(s)))
                    push(&s, infix[i++]);
                else
                    postfix[j++] = pop(&s);
            }
        }
    }

    while (!isEmpty(s))
    {
        postfix[j++] = pop(&s);
    }

    postfix[j] = '\0';

    return postfix;
}

void main()
{
    char *infix;
    int size;

    infix = (char *)malloc(20 * sizeof(char));

    printf("Enter the infix notation: ");
    scanf("%255s", infix);
    printf("Infix notatin is: %s", infix);

    char *postfix = postfixConvertion(infix);
    printf("The corresponding postfix notation is: %s", postfix);
}
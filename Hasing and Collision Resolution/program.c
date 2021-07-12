#include <stdio.h>
#include <stdbool.h>

int Table_Size = 10;
int Hash_Table[10];

// Division Methord
int hash(int x)
{
    return (x % 10) - 1;
}

int doubleHash(int ele)
{
    return (7 - (hash(ele) % 7));
}

void elementInput(int ele)
{
    int flag = 0;
    for (int i = 0; i < Table_Size; i++)
        if (ele == Hash_Table[i])
            flag++;

    if (flag == 0)
    {
        if (Hash_Table[hash(ele)] == 0)
            Hash_Table[hash(ele)] = ele;
        else
        {
            // Collition Resolution - Double Hashing
            if (Hash_Table[doubleHash(ele)] != 0)
                printf("No space left in the hash table!\n");
            else
                Hash_Table[doubleHash(ele)] = ele;
        }
    }
    else
    {
        printf("Element already exist!\n");
    }
}

void removeElement(int ele)
{
    if (Hash_Table[hash(ele)] == 0 && Hash_Table[doubleHash(ele)] == 0)
        printf("Slot already empty! \n");
    else
        Hash_Table[hash(ele)] = 0;
}

void display()
{
    for (int i = 0; i < Table_Size; i++)
        printf("%d -> %d\n", i, Hash_Table[i]);
}

void main()
{
    bool run = true;
    printf("--- The size of the hash table is %d ---\n", Table_Size);

    for (int i = 0; i < Table_Size; i++)
        Hash_Table[i] = 0;

    while (run)
    {
        printf("1. Enter\n2. Remove\n3. Display\n4. Exit\n");
        int ch;
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter element: ");
            int ele;
            scanf("%d", &ele);
            elementInput(ele);
            break;

        case 2:
            printf("Enter element: ");
            int eleRem;
            scanf("%d", &eleRem);
            removeElement(eleRem);
            break;

        case 3:
            display();
            break;

        case 4:
            run = false;
            break;

        default:
            printf("Wromg Entry");
            break;
        }
    }
}
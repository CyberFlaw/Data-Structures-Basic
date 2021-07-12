#include <stdio.h>
#include <stdlib.h>

void main()
{
    int size, ele, flag = 0;
    int *ar;

    printf("Enter size of array: ");
    scanf("%d", &size);
    ar = (int *)malloc(size * sizeof(int));

    printf("Enter elements into the array: ");
    for (int i = 0; i < size; i++)
        scanf("%d", &ar[i]);

    printf("Enter element to be searched: ");
    scanf("%d", &ele);

    for (int i = 0; i < size; i++)
        if (ele == ar[i])
        {
            printf("Element found at %d", (i + 1));
            flag++;
        }

    if (flag == 0)
        printf("No elements found! ");
}

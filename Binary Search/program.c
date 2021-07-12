#include <stdio.h>
#include <stdlib.h>

void binarySearch(int ar[], int l, int r, int ele)
{
    while (l <= r)
    {
        int m = l + (r - l) / 2;

        if (ar[m] == ele)
            printf("Element found at: %d", m);

        if (ar[m] < ele)
            l = m + 1;

        else
            r = m - 1;
    }
}

void main()
{
    int size, ele, *ar;

    printf("Enter the size of array: ");
    scanf("%d", &size);
    ar = (int *)malloc(size * sizeof(int));

    printf("Enter elements in the accending order: ");
    for (int i = 0; i < size; i++)
        scanf("%d", &ar[i]);

    printf("Enter element to be searched: ");
    scanf("%d", &ele);

    binarySearch(ar, 0, size - 1, ele);
}

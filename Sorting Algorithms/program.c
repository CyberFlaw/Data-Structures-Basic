#include <stdio.h>

int size = 5;

void display(int ar[size]);

void swap(int *xp, int *yp);

int splitArray(int arr[], int low, int high);

void merge(int arr[], int l, int m, int r);

void bubbleSort(int ar[5])
{
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size - 1; j++)
            if (ar[j] > ar[j + 1])
                swap(&ar[j], &ar[j + 1]);
} 

void insertionSort(int ar[])
{

    for (int i = 1; i < size; i++)
    {
        int key = ar[i];
        int j = i - 1;

        while (key < ar[j] && j >= 0)
        {
            ar[j + 1] = ar[j];
            --j;
        }
        ar[j + 1] = key;
    }
}

void selectionSort(int ar[])
{
    int i, j, min;

    for (i = 0; i < size - 1; i++)
    {
        min = i;
        for (j = i + 1; j < size; j++)
            if (ar[j] < ar[min])
                min = j;

        swap(&ar[min], &ar[i]);
    }
}

void quickSort(int ar[], int low, int high)
{
    if (low < high)
    {
        int pi = splitArray(ar, low, high);

        quickSort(ar, low, pi - 1);
        quickSort(ar, pi + 1, high);
    }
}

void mergeSort(int ar[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;

        mergeSort(ar, l, m);
        mergeSort(ar, m + 1, r);

        merge(ar, l, m, r);
    }
}

void main()
{
    int ch, i = 0, ar[size];

    printf("Enter the elements to be sorterd: \n");
    while (i++ < size)
        scanf("%d", &ar[i - 1]);

    printf("1. Bubble Sort\n2. Insertion Sort\n3. Selection Sort\n4. Quick Sort\n5. Merge Sort\n");
    scanf("%d", &ch);

    switch (ch)
    {
    case 1:
        bubbleSort(ar);
        display(ar);
        break;

    case 2:
        insertionSort(ar);
        display(ar);
        break;

    case 3:
        selectionSort(ar);
        display(ar);
        break;

    case 4:
        quickSort(ar, 0, size - 1);
        display(ar);
        break;

    case 5:
        mergeSort(ar, 0, size - 1);
        display(ar);
        break;

    default:
        ("Wrong Option! \n");
        break;
    }
}

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void display(int ar[size])
{
    int i = 0;
    printf("Array:\n");
    while (i++ < size)
        printf("%d\t", ar[i - 1]);
}

int splitArray(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
        if (arr[j] < pivot)
            swap(&arr[i++], &arr[j]);

    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        
        else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];

}
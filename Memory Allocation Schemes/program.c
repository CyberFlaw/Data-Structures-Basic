#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void firstFit(int blockSize[], int processSize[], int processCount, int blockCount)
{
    int allocation[processCount];
    memset(allocation, -1, processCount);

    for (int i = 0; i < processCount; i++)
    {
        for (int j = 0; j < blockCount; j++)
        {
            if (blockSize[j] >= processSize[i])
            {
                allocation[i] = j;
                blockSize[j] -= processSize[i];
                break;
            }
        }
    }

    printf("\nProcess No.\tProcess Size\tBlock no.\n");
    for (int i = 0; i < processCount; i++)
    {
        printf(" %d \t\t %d \t\t", i + 1, processSize[i]);
        if (allocation[i] != -1)
            printf("%d", allocation[i]);
        else
            printf("Not Allocated!");
        printf("\n");
    }
}

void bestFit(int blockSize[], int processSize[], int processCount, int blockCount)
{
    int allocation[processCount];
    memset(allocation, -1, processCount);

    for (int i = 0; i < processCount; i++)
    {
        int bestIndex = -1;
        for (int j = 0; j < blockCount; j++)
        {
            if (blockSize[j] >= processSize[i])
            {
                if (bestIndex == -1)
                    bestIndex = j;
                else if (blockSize[bestIndex] > blockSize[j])
                    bestIndex = j;
            }
        }

        if (bestIndex != -1)
        {
            allocation[i] = bestIndex;
            blockSize[bestIndex] -= processSize[i];
        }
    }

    printf("\n\nProcess No.\tProcess Size\tBlock no.\n");
    for (int i = 0; i < processCount; i++)
    {
        printf(" %d \t\t %d \t\t", i + 1, processSize[i]);
        if (allocation[i] != -1)
            printf("%d", allocation[i]);
        else
            printf("Not Allocated!");
        printf("\n");
    }
}

void worstFit(int blockSize[], int processSize[], int processCount, int blockCount)
{
    int allocation[processCount];
    memset(allocation, -1, processCount);

    for (int i = 0; i < processCount; i++)
    {
        int worstIndex = -1;
        for (int j = 0; j < blockCount; j++)
        {
            if (blockSize[j] >= processSize[i])
            {
                if (worstIndex == -1)
                    worstIndex = j;
                else if (blockSize[worstIndex] < blockSize[j])
                    worstIndex = j;
            }
        }

        if (worstIndex != -1)
        {
            allocation[i] = worstIndex;
            blockSize[worstIndex] -= processSize[i];
        }
    }

    printf("\nProcess No.\tProcess Size\tBlock no.\n");
    for (int i = 0; i < processCount; i++)
    {
        printf(" %d \t\t %d \t\t", i + 1, processSize[i]);
        if (allocation[i] != -1)
            printf("%d", allocation[i]);
        else
            printf("Not Allocated!");
        printf("\n");
    }
}

void main()
{
    int ch;
    bool run = true;

    int blockSize[] = {100, 200, 300, 400, 500};
    int blockCount = 5;
    int processSize[10];
    int processCount;

    printf("Enter the number of process: ");
    scanf("%d", &processCount);

    printf("Enter the processes: ");
    for (int i = 0; i < processCount; i++)
        scanf("%d", &processSize[i]);

    while (run)
    {
        printf("1. First Fit\n2. Best Fit\n3. Worst Fit\n4. Exit\n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            firstFit(blockSize, processSize, processCount, blockCount);
            break;
        case 2:
            bestFit(blockSize, processSize, processCount, blockCount);
            break;
        case 3:
            worstFit(blockSize, processSize, processCount, blockCount);
            break;
        case 4:
            run = false;
            break;

        default:
            break;
        }
    }
}
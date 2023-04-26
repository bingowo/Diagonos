#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int data[51];
    int len;
} row;

int cmp(const void *a, const void *b)
//
{
    row *p1 = (row *)a, *p2 = (row *)b;
    /*int i = 0;
    while (p1->data[i] != 0 && p2->data[i] != 0 && p1->data[i] == p2->data[i])
    {
        i++;
    }
    return (p2->data[i] - p1->data[i]);*/
    for (int i = 0; i < p1->len && i < p2->len; i++)
    {
        if (p1->data[i] > p2->data[i])
            return 1;
        else if (p1->data[i] < p2->data[i])
            return -1;
    }
    return (p1->len > p2->len);
}

void func()
{
    /*int **arr;
        arr = (int **)malloc(n * sizeof(int *));
        int *ak = (int *)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++)
        {
            int k = 0, temp[51] = {0};
            while (scanf("%d", &temp[k]) && temp[k] != -1)
            {
                k++;
            }
            ak[i] = k;
            arr[i] = (int *)malloc(sizeof(int) * k);
            for (int j = 0; j < k; j++)
            {
                arr[i][j] = temp[j];
            }
        }
        qsort(*arr[0], n, sizeof(int), cmp);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < ak[i]; j++)
            {
                printf("%d ", arr[i][j]);
            }
            printf("\n");
        }
        free(arr);*/
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int z = 0; z < T; z++)
    {
        int n;
        scanf("%d", &n);
        row array[n];
        /*for (int j = 0; j < 51; j++)
        {
            for (int i = 0; i < 51; i++)
            {
                array[j].data[i] = -1;
            }
        }*/
        for (int i = 0; i < n; i++)
        {
            int k = 0;
            int temp;
            scanf("%d", &temp);
            while (temp != -1)
            {
                array[i].data[k++] = temp;
                scanf("%d", &temp);
            }
            array[i].len = k;
        }
        qsort(array, n, sizeof(int), cmp);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < array[i].len; j++)
                printf("%d ", array[i].data[j]);
            printf("\n");
        }
    }
    return 0;
}
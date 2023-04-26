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
    for (int i = 0; i < p1->len && i < p2->len; i++)
    {
        if (p1->data[i] != p2->data[i])
            return p1->data[i] < p2->data[i];
    }
    return (p1->len > p2->len);
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int z = 0; z < T; z++)
    {
        int n;
        scanf("%d", &n);
        // row *array = (row *)malloc(sizeof(row) * n);
        row array[n];
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
        qsort(array, n, sizeof(array[0]), cmp);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < array[i].len; j++)
                printf("%d ", array[i].data[j]);
            printf("\n");
        }
        //free(array);
    }
    return 0;
}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int cmpA(const void *a, const void *b)
{
    return (*(int*)a - *(int*)b);
}

int cmpD(const void *a, const void *b)
{
    return (*(int*)b - *(int*)a);
}


int main()
{
    char order;
    int number = 0;
    int array[101];

    scanf("%c", &order);


    if (order == 'A')
    {
        for (int k = 0; ; k++)
        {
            scanf("%d", &array[k]);
            number++;
            if (getchar() == '\n')
                break;
        }

        qsort (array, number, sizeof(int), cmpA);
    }

    if (order == 'D')
    {
        for (int k = 0; ; k++)
        {
            scanf("%d", &array[k]);
            number++;
            if (getchar() == '\n')
                break;
        }

        qsort (array, number, sizeof(int), cmpD);
    }

    printf("%d", array[0]);
    for(int i = 0; i < number - 1; i++)
    {
        if (array[i] != array[i + 1])
        {
            printf(" %d", array[i + 1]);
        }
    }

    return 0;
}

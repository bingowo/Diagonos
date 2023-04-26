#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sort(int arr[], int len, char c)
{
    int *brr = (int*)calloc(1000, sizeof(int));
    int *crr = (int*)calloc(len, sizeof(int));

    for(int i = 0; i < len; i++)
    {
        brr[arr[i]] += 1;
    }

    if(c == 'A')
    {
        for(int i = 0; i < 1000; i++)
        {
            if(brr[i])
                printf("%d ", i);
        }
    }
    else
    {
        for(int i = 1000; i >= 0; i--)
        {
            if(brr[i])
                printf("%d ", i);
        }
    }

    free(brr);
    free(crr);
}

int main()
{
    char c;
    scanf("%c", &c);

    int a[10000] = {0};
    int len = 0;
    int b;
    while(scanf("%d", &b) != EOF)
    {
        a[len++] = b;
    }

    sort(a, len, c);

    return 0;
}

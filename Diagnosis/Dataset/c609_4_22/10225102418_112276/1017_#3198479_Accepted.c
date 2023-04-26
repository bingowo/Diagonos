#include <stdio.h>
#include <stdlib.h>

int main()
{
    char sort;
    int nums[1001];
    int i = 0;
    for (i = 0; i <= 1000; ++i)
        nums[i] = 0;
    while ((scanf("%c", &sort)) != EOF)
    {
        while ((scanf("%d", &i)) != EOF)
        {
            nums[i]++;
        }
    }
    if (sort == 'A')
    {
        for (i = 0; i <= 1000; ++i)
            if (nums[i] > 0)
                printf("%d ", i);
    }
    else
    {
        for (i = 1000; i > 0; --i)
            if (nums[i] > 0)
                printf("%d ", i);
    }
    printf("\n");
}

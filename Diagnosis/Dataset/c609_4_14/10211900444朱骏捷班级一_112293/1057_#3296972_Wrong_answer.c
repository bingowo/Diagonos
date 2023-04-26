#include <stdio.h>

int main()
{
    int t;
    scanf("%d", &t);
    for (int z = 0; z != t; z++)
    {
        int n;
        scanf("%d", &n);
        printf("case #%d:", z);
        int count = 0;
        for (int i = 1; i <= n; i++)
        {
            int temp = i;
            while(temp % 5 == 0)
            {
                temp /= 5;
                count++;
            }
        }
        printf("%d", count);
    }
    return 0;
}
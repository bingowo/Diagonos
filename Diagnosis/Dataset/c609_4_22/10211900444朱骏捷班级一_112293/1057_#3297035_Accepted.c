#include <stdio.h>

int main()
{
    int t;
    scanf("%d", &t);
    for (int z = 0; z != t; z++)
    {
        int n;
        scanf("%d", &n);
        printf("case #%d:\n", z);
        int count = 0;
        for (int i = 1; i <= n; i++)
        {
            int temp = i;
            while(!(temp % 5))
            {
                temp /= 5;
                count++;
            }
        }
        printf("%d\n", count);
    }
    return 0;
}
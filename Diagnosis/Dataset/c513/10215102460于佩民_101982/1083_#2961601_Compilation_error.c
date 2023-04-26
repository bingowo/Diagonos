#include <stdio.h>

int main()
{
    int t;
    scanf("%d",&t);
    for(int i = 0; i < t; i++)
    {
        int n;
        scanf("%d",&n)
        printf("case #%d:\n",i);
        int count = 0;
        for(int i = 1; i <= n; i++)
        {
            int temp = i;
            while(temp % 5 == 0)
            {
                temp /= 5;
                count++;
            }
        }
        printf("%d\n",count);
    }

    return 0;
}

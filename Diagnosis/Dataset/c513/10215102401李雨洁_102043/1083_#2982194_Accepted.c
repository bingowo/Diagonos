#include<stdio.h>

int main()
{
    int t;
    scanf("%d",&t);
    for(int z = 0; z < t; z++)
    {
        int n;
        scanf("%d",&n);
        int end = 0;
        for(int i = 1; i <= n; i++)
        {
            int t = i;
            while(t % 5 == 0)
            {
                t /= 5;
                end++;
            }
        }
        printf("case #%d:\n",z);
        printf("%d\n",end);
    }
    return 0;
}





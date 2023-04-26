#include<stdio.h>

int main()
{
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++)
    {
        int n;
        scanf("%d",&n);
        int count=0;
        for(;n>0;n--)
        {
            if(n%5==0) count++;
        }
        printf("case #%d:\n",t);
        printf("%d\n",count);
    }
    return 0;
}


#include <stdio.h>

void trans(long long int n)
{
    if(n>0)
    {
        trans(n/2333);
        printf("%d ",n%2333);
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        long long int n;
        scanf("%d",&n);
        if(n==0)
            printf("0");
        else trans(n);
        printf("\n");
    }
    return 0;
}

#include <stdio.h>

void trans(int n)
{
    if(N>0)
    {
        trans(n/2233);
        printf("%d'space'",n%2233);
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        int n;
        scanf("%d",&n);
        if(n==0)
            printf("0");
        else trans(n);
        printf("\n");
    }
    return 0;
}
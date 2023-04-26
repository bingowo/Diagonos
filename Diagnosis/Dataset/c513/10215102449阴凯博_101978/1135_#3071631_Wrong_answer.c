#include <stdio.h>
#include <stdlib.h>


int F[1000000]={0};

int domino(int n)
{
    if (n<=4)
        return F[n];
    else
    {
        return F[n-1]+F[n-2]+F[n-4];
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    F[0]=0; F[1]=1; F[2]=2; F[3]=3; F[4]=6;
    printf("%d",domino(n));

    return 0;
}

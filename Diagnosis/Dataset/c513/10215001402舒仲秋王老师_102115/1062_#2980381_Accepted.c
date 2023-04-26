#include <stdio.h>
#include <stdlib.h>

long long int putout(int a)
{
    long long int base[50];
    base[0]=1;base[1]=2;
    base[2]=4;base[3]=8;
    for(int i=4;i<50;i++)
        base[i]=base[i-4]+base[i-3]+base[i-2]+base[i-1];
    return base[a-1];
}

int main()
{
    int N,i;
    scanf("%d",&N);
    for(i=0;i<N;i++)
    {
        int c;
        printf("case #%d:\n",i);
        scanf("%d",&c);
        printf("%lld\n",putout(c));
    }
    return 0;
}

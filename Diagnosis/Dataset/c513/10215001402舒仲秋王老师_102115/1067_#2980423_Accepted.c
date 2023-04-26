#include <stdio.h>
#include <stdlib.h>

long long int put(int a)
{
    long long int base[75];
    base[0]=0;base[1]=1;
    base[2]=1;
    for(int i=3;i<=74;i++)
        base[i]=base[i-1]+base[i-2]+base[i-3];
    return base[a];
}

int main()
{
    int N,i;
    scanf("%d",&N);
    for(i=0;i<N;i++)
    {
        printf("case #%d:\n",i);
        int a;
        scanf("%d",&a);
        printf("%lld\n",put(a));
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int T;
    scanf("%d",&T);
    int i;
    for(i=0;i<T;i++)
    {
        int N;
        scanf("%d",&N);
        long long int n;
        n=pow(2,N);
        printf("case #%d:\n",i);
        printf("%lld\n",n);
    }
}

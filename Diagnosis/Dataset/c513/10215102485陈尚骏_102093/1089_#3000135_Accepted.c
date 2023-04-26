#include <stdio.h>
#include <stdlib.h>
#include<string.h>


int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        long long A,B,N;
        scanf("%lld %lld %lld",&A,&B,&N);
        long long cnt=1;
        long long a=A;
        for(int j=0;j<N;j++) cnt*=10;
        for(int j=0;j<B-1;j++)
        {
            A%=cnt;
            A*=a;
        }
        A%=cnt;
        printf("case #%d:\n",i);
        printf("%0*lld\n",(int)N,A);
    }
    return 0;
}

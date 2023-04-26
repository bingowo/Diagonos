#include<stdio.h> 
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
    int T;scanf("%d",&T);int A,B,N;
    for(int t=0;t<T;t++)
    {
        scanf("%d %d %d",&A,&B,&N);
        int d=0;
        long long sum=A,k;
        while(B-1)
        {
            sum=sum*A%(pow(10,N));
            B--;
        }
        for(k=sum;;k>0;k/10)d++;
        printf("case #%d:\n",t);
        for(int i=0;i<t;i++)printf("0");
        printf("%lld\n",sum);
    }
}
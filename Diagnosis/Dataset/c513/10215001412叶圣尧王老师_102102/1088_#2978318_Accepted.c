#include<stdio.h> 
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
    int T;scanf("%d",&T);int m,n;
    for(int t=0;t<T;t++)
    {
        long long sum=1;
        printf("case #%d:\n",t);
        scanf("%d %d",&m,&n);
        for(int i=m,j=1;i>=m-n+1;i--,j++)sum=sum*i/j;
        printf("%lld\n",sum);
    }
}
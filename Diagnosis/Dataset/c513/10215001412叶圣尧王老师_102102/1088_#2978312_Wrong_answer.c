#include<stdio.h> 
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
    int T;scanf("%d",&T);int m,n;long long sum=1;
    for(int t=0;t<T;t++)
    {
        printf("case #%d:\n",t);
        scanf("%d %d",&m,&n);
        for(int i=m;i>=m-n+1;i--)sum=sum*i;
        for(int i=n;i>=1;i--)sum=sum/i;
        printf("%lld\n",sum);
    }
}
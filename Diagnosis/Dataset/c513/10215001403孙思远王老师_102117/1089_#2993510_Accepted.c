#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t,T;
    scanf("%d\n",&T);
    for(t=0;t<T;t++)
    {
        printf("case #%d:\n",t);
        int b,n,i;
        long long int a,x=1,X,N=1;
        scanf("%lld%d%d",&a,&b,&n);
        for(i=0;i<n;i++)
            N*=10;
        for(i=0;i<b;i++)
        {
            x=x*a;
            x%=N;
        }
        i=0;
        X=x;
        while(X>0)
        {
            X/=10;
            i++;
        }
        for(int j=0;j<n-i;j++)
            printf("0");
        if(x!=0)
            printf("%lld\n",x);
        else
            printf("\n");
    }
    return 0;
}

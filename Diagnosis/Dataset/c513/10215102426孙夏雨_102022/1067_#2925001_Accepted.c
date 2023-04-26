#include <stdio.h>
#include <stdlib.h>

long long int f(int n)
{
    if(n==0) return 0;
    else if(n<=2) return 1;
    else {
        long long int a1=0,a2=1,a3=1,sum=0;
        for(int i=0;i<=n-3;i++){
            sum=a1+a2+a3;
            a1=a2;
            a2=a3;
            a3=sum;
        }
        return sum;
    }
}

int main()
{
    int T=0;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        int n=0;
        long long int ans=0;
        scanf("%d",&n);
        ans=f(n);
        printf("case #%d:\n",t);
        printf("%lld\n",ans);
    }
    return 0;
}

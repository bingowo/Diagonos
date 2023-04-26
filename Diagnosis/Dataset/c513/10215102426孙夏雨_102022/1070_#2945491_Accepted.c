#include <stdio.h>
#include <stdlib.h>

long long int f(int n)
{
    if(n==1) return 2;
    else if(n==2) return 4;
    else if(n==3) return 7;
    else if(n==4) return 12;
    else return 2*f(n-1)-f(n-2)+f(n-3);
}

int main()
{
    int n=0;
    while(1){
        scanf("%d",&n);
        if(n==-1) break;
        long long int ans=0;
        ans=f(n);
        printf("%lld\n",ans);
    }
    return 0;
}

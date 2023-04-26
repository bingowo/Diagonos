#include <stdio.h>
#include <stdlib.h>

long long re(int n,int m)
{
    long long ans = 0;
    if(n<m){
        ans=0;
    }
    else if(n==m){
        ans=1;
    }
    else{
        ans=2*re(n-1,m)+(1<<(n-m-1))-re(n-m-1,m);
    }
    return ans;
}

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    while(!(n==-1&&m==-1)){
        long long ans = 0;
        ans = re(n,m);
        printf("%lld\n",ans);
        scanf("%d%d",&n,&m);
    }
    return 0;
}

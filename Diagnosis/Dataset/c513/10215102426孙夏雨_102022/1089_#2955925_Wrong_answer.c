#include <stdio.h>
#include <stdlib.h>

long long int po(int n)
{
    long long int ans=1;
    for(int i=0;i<n;i++) ans*=10;
    return ans;
}

int main()
{
    long long int A=0;
    int B=0,N=0,T=0;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        scanf("%lld %d %d",&A,&B,&N);
        long long int w=po(N);
        unsigned long long int ans=1;
        for(int j=0;j<N;j++){
            ans=ans*A%w;
        }
        int weishu= ans==0?1:0;
        unsigned long long int a=ans;
        while(a>0){
            weishu++;
            a/=10;
        }printf("case #%d:\n",i);
        if(weishu<N){
            for(int k=0;k<N-weishu;k++) printf("0");
        }
        printf("%llu\n",ans);
    }
    return 0;
}

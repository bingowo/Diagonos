#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T=0;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        int N=0;
        scanf("%d",&N);
        int ans=0,x=5,y=0;
        while(x<=N){
            y=x*8;
            while(y%10==0){
                ans++;
                y/=10;
            }
            x+=5;
        }
        ans= ans>100 ?ans+1:ans;
        printf("case #%d:\n%d\n",t,ans);
    }
    return 0;
}

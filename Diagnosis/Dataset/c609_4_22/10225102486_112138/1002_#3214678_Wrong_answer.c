#include<stdio.h>
int main()
{
    int T,n,i,x=1;
    scanf("%d",&T);
    int S=T;
    while(S--){
        scanf("%d",&n);
        i=0,x=0;
        int ans[1000];
        while(n!=0){
            ans[i++]=n%2;
            n/=2;
        }
        for(int j=i-1;j>=0;j--){
            if(ans[j]!=ans[j+1])
                x+=1;
            else
                break;
        }
        printf("case #%d:\n",T-S-1);
        printf("%d",x);
    }
    return 0;
}
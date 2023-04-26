#include <stdio.h>
#include <stdlib.h>
int j=1;
void dp(int* ans,int i)
{
    if(i==0) return;
    else
    {
        int l=j;j*=2;i-=1;
        for(int k=l,p=0;k<2*l&&p<l;k++,p++) ans[k]=ans[p]^1;
        dp(ans,i);
        return;
    }
}
int main()
{
    int i=0;
    scanf("%d",&i);
    int ans[100000]={0};
    dp(ans,i);//printf("%d\n",j);
    for(int l=0;l<j;l++) printf("%d",ans[l]);
    return 0;
}
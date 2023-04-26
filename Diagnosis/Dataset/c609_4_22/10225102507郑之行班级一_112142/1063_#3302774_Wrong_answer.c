#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;scanf("%d",&n);
    long long ans[51]={0,1,2,6,8};
    for(int i=5;i<51;i++){
        ans[i]=ans[i-1]+ans[i-2]+ans[i-3]+ans[i-4];
    }
    for (int i=0;i<n;i++){
        int in;scanf("%d",&in);
        printf("case #%d:\n%lld\n",i,ans[in]);
    }
    return 0;
}

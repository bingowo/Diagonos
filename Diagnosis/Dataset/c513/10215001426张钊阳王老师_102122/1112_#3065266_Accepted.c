#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T;
    scanf("%d",&T);

    int ans[1200]={0};

    ans[0]=1;

    for(int i=1;i<=4;i++)
        for(int j=i;j<1200;j++)
    {
        ans[j]=ans[j]+ans[j-i];
    }

    for(int z=0;z<T;z++)
    {
        int n;
        scanf("%d",&n);
        printf("%d\n",ans[n]);
    }
    return 0;
}

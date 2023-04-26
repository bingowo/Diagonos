#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T,cnt;
    scanf("%d",&T);
    long long N[T];
    int j[T];
    int ans[T][100];
    for(int i=0;i<T;i++)
    {
        scanf("%d",&N[i]);
        int r;
        j[i]=0;
        if(N[i]==0)
                ans[i][j[i]]=0;
            while(N[i]>0)
            {
                r=N[i]%2333;
                ans[i][j[i]]=r;
                j[i]=j[i]+1;
                N[i]=N[i]/2333;
            }
    }
    for(int k=0;k<T;k++)
    {
        for(int l=j[k]-1;l>=0;l--)
        {
            printf("%d ",ans[k][l]);
        }
        printf("\n");
    }
    return 0;
}

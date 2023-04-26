#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int main()
{
    int T;scanf("%d",&T);
    for(int t=0;t<T;t++) 
    {
        printf("case #%d:\n",t);
        int r,c,n,k,i,j;
        scanf("%d %d %d %d",r,c,n,k);
        int a[r][c]={0},x[n],y[n];
        for(i=0;i<n;i++)
        {
            scanf("%d %d",x[i],y[i]);
            x[i]--;y[i]--;
            a[x[i]][y[i]]=1;
        }
        for(i=k;i<=n;i++)
        {
            
        }
        
    }
}
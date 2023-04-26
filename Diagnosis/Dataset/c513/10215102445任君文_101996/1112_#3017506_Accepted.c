#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
int main()
{
    int T,n;
    int i,j,k;
    int res=0;
    scanf("%d",&T);
    int v[4]={4,3,2,1};
    
    for(i=0;i<T;i++)
    {
        int d[1100]={0};
        d[0]=1;
        scanf("%d",&n);
        if(n==0)
            printf("1\n");
        else
        {
            for(j=0;j<4;j++)
            {
                for(k=v[j];k<=n;k++)
                {
                    d[k]+=d[k-v[j]];
                }
            }
            printf("%d\n",d[n]);
        }
    }
}
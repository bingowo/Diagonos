#include<stdio.h>
#include<stdlib.h>

int main()
{
    int T;
    int i,j,k;
    int x,y,f;
    int r,c,n,m;
    int res=0;
    int s[10][10]={0};
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        res=0;
        f=0;
        scanf("%d%d%d%d",&r,&c,&n,&m);
        for(j=0;j<r;j++)
        {
            for(k=0;k<c;k++)
            {
                s[j][k]=0;
            }
        }
        for(j=0;j<n;j++)
        {
            scanf("%d%d",&x,&y);
            for(j=x;j<=r;j++)
            {
                for(k=y;k<=c;k++)
                {
                    res++;
                }
            }
        }

        printf("case #%d:\n",i);
        printf("%d\n",res);
    }
    return 0;
}
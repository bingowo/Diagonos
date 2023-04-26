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
            s[x-1][y-1]=1;
        }
        for(j=0;j<r;j++)
        {
            for(k=0;k<c;k++)
            {
                if(s[j][k]==1)
                {
                    f++;
                }
                if(f==m)
                {
                    res++;
                }
                else if(f>m)
                {
                    f=1;
                }
            }
        }
        printf("case #%d:\n",i);
        printf("%d\n",res);
    }
    return 0;
}
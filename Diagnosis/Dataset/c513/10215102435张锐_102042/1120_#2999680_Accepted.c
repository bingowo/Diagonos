#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t;
    scanf("%d",&t);
    for(int f=0;f<t;f++)
    {
        int r,c,n,k;
        scanf("%d%d%d%d",&r,&c,&n,&k);
        int **p=(int **)malloc(sizeof(int*)*r);
        for(int i=0;i<r;i++)
        {
            p[i]=(int*)malloc(sizeof(int)*c);
            for(int j=0;j<c;j++) p[i][j]=0;
        }
        for(int k=0;k<n;k++)
        {
            int i,j;
            scanf("%d%d",&i,&j);
            p[i-1][j-1]=1;
        }
        int num=0;
        for(int x=0;x<r;x++)
        {
            for(int y=0;y<c;y++)
            {
                //行
                for(int rr=0;x+rr<r;rr++)
                {
                    for(int cc=0;y+cc<c;cc++)
                    {
                        int sum=0;
                        for(int i=x;i-x<=rr;i++)
                        {
                            for(int j=y;j-y<=cc;j++) sum+=p[i][j];
                        }
                        if(sum>=k) num++;
                    }
                }
            }
        }
        printf("case #%d:\n",f);
        printf("%d\n",num);
    }
    return 0;
}

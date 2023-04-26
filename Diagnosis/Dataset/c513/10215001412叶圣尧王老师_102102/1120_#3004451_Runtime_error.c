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
        scanf("%d %d %d %d",&r,&c,&n,&k);
        int a[10][10]={0},x[n],y[n];
        for(i=0;i<n;i++)
        {
            scanf("%d %d",x[i],y[i]);
            x[i]--;y[i]--;
            a[x[i]][y[i]]=1;
        }
        int sum=0;
        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
            {
                int d=0;
                for(int k1=i;k1<r;k1++)
                {
                    for(int k2=j;k2<c;k2++)
                        if(a[k1][k2]==1){d++;if(d>=k)sum++;}
                }
            }
        }
        printf("%d\n",sum);
    }
}
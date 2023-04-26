#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n,m,k,i,j;
    int cnt=0;
    int num[200][200];
    scanf("%d %d %d",&n,&m,&k);
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            scanf("%d",&num[i][j]);
        }
    }//input
    //左上角
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            int max=((n-i)>(m-j))?(m-j-1):(n-i-1);
            int sum[200];//存储和
            //printf("max=%d",max);
            int t,q;
            if(max>=1)
            {
                sum[0]=num[i][j];
                for(t=1;t<=max;t++)
                {
                    sum[t]=sum[t-1];
                    for(q=0;q<=t;q++){sum[t]+=num[i+q][j+t-q];}
                    if(sum[t]>=k)cnt++;
                }
            }
        }
    }
    //printf("\n");
    //左下角
    for(i=n-1;i>=0;i--)
    {
         for(j=0;j<m;j++)
         {
            int max=(i>(n-j))?(n-j-1):i;
            int sum[200];//存储和
            int t,q;
            if(max>=1)
            {
                sum[0]=num[i][j];
                for(t=1;t<=max;t++)
                {
                    sum[t]=sum[t-1];
                    for(q=0;q<=t;q++){sum[t]+=num[i-q][j+t-q];}
                    //printf("%d ",sum[t]);
                    if(sum[t]>=k)cnt++;
                }
            }
         }
    }
    //右上角
    for(i=0;i<n;i++)
    {
         for(j=m-1;j>=0;j--)
         {
            int max=((n-i)>j)?(j):(n-i-1);
            int sum[200];//存储和
            int t,q;
            if(max>=1)
            {
                sum[0]=num[i][j];
                for(t=1;t<=max;t++)
                {
                    sum[t]=sum[t-1];
                    for(q=0;q<=t;q++){sum[t]+=num[i+q][j-t+q];}
                    //printf("%d ",sum[t]);
                    if(sum[t]>=k)cnt++;
                }
            }
         }
    }
    //右下角
    for(i=n-1;i>=0;i--)
    {
         for(j=m-1;j>=0;j--)
         {
            int max=(i>j)?(j):(i);
            int sum[200];//存储和
            int t,q;
            if(max>=1)
            {
                sum[0]=num[i][j];
                for(t=1;t<=max;t++)
                {
                    sum[t]=sum[t-1];
                    for(q=0;q<=t;q++){sum[t]+=num[i-q][j-t+q];}
                    //printf("%d ",sum[t]);
                    if(sum[t]>=k)cnt++;
                }
            }
         }
    }
    printf("%d",cnt);
    return 0;
}

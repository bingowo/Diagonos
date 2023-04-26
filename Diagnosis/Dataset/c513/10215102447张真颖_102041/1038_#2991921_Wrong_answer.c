#include <stdio.h>
#include <stdlib.h>
int count(int cnt,int table[][200],int m,int n,int k)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<m-1;j++)
        {
            int sum[200]={table[i][j]};
            int t1=1;
            for(;t1<m&&t1<n;t1++)
            {
                sum[t1]=sum[t1-1];
                if(sum[t1]>=k)
                {
                    if(m<n) cnt+=m-t1;
                    else cnt+=n-t1;
                }
                else
                {
                    for(int t2=0;t2<=t1;t2++)
                        sum[t1]+=table[i+t2][t1-t2];
                }
            }
            if(sum[t1-2]<k&&sum[t1-1]>=k) cnt+=1;
        }
    }
    return cnt;
}

int table[200][200]={0};
int table1[200][200]={0};
int main()
{
    int n=0,m=0,k=0;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            scanf("%d",&table[i][j]);
    int cnt=0;
    cnt=count(cnt,table,m,n,k);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            table1[i][j]=table[i][m-j-1];
    cnt=count(cnt,table1,m,n,k);
    for(int j=0;j<m;j++)
        for(int i=0;i<n;i++)
            table1[i][j]=table[n-i-1][j];
    cnt=count(cnt,table1,m,n,k);
    for(int i=0;i<n;i++)
        for(int j=0;j<m/2;j++)
        {
            int t=table1[i][j];
            table1[i][j]=table1[i][m-j-1];
            table1[i][m-j-1]=t;
        }
    cnt=count(cnt,table1,m,n,k);
    printf("%d",cnt);
    return 0;
}

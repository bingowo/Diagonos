#include <stdio.h>
#include <stdlib.h>
int count(int cnt,int table[][200],int m,int n,int k)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<m-1;j++)
        {
            int sum[200]={table[i][j]};
            for(int t1=1;t1<m-j&&t1<n-i;t1++)
            {
                sum[t1]=sum[t1-1];
                for(int t2=0;t2<=t1;t2++)
                    sum[t1]+=table[i+t2][j-t2+t1];
                if(sum[t1]>=k)
                {
                    if(m-j-t1<n-i-t1)
                        cnt+=m-j-t1;
                    else
                        cnt+=n-i-t1;
                    break;
                }
            }
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

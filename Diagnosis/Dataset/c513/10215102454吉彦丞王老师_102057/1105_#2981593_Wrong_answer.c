#include<stdio.h>
#include<stdlib.h>
int zhishu(int n)
{
    int t=1;
    for(int i=0;i<n;i++)
    {
        t=t*2;
    }
    return t;
}
int min(int a[8])
{
    for(int i=7;i>=0;i--)
    {
        if(a[i]==0)
        {
            for(int j=7;j>=1;j--)
            {
                a[j]=a[j-1];
            }
            a[0]=0;
        }
        else
        {
            break;
        }
    }
    int result=0;
    for(int i=7;i>=0;i--)
    {
        result=result+a[i]*zhishu(7-i);
    }
    return result;
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int a[n][m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    for(int i=1;i<n-1;i++)
    {
        for(int j=1;j<m-1;j++)
        {
            int b[8];
    		b[0]=a[i-1][j-1]>=a[i][j]?1:0;
    		b[1]=a[i-1][j]>=a[i][j]?1:0;
    		b[2]=a[i-1][j+1]>=a[i][j]?1:0;
    		b[3]=a[i][j+1]>=a[i][j]?1:0;
    		b[4]=a[i+1][j+1]>=a[i][j]?1:0;
    		b[5]=a[i+1][j]>=a[i][j]?1:0;
    		b[6]=a[i+1][j-1]>=a[i][j]?1:0;
    		b[7]=a[i][j-1]>=a[i][j]?1:0;
    		printf("%d ",min(b));
        }
        printf("\n");
    }
    return 0;
}
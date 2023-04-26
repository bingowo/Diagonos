#include <stdio.h>
#include <stdlib.h>
#include<string.h>
typedef long long int lli;
int S[11][11];
int a[11][11];
int matrix(int (*a)[11],int k,int r,int c)
{
    int ans=0;
    for(int i=1;i<=r;i++)
    {
        for(int j=1;j<=c;j++)
        {
            S[i][j]=S[i-1][j]+S[i][j-1]-S[i-1][j-1]+a[i][j];
        }
    }

    for(int i=1;i<=r;i++)
    {
        for(int j=1;j<=c;j++)
        {
            for(int x=i;x<=r;x++)
            {
                for(int y=j;y<=c;y++)
                {
                    if((S[x][y]-S[x][j-1]-S[i-1][y]+S[i-1][j-1])>=k)
                        ans++;
                }
            }
        }
    }
    return ans;
}

int main()
{
    int t,r,c,n,k;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        scanf("%d%d%d%d",&r,&c,&n,&k);
        memset(a,0,sizeof(a));
        int x,y;

        for(int j=0;j<n;j++)
        {
            scanf("%d%d",&x,&y);
            a[x][y]=1;
        }
        int result=matrix(a,k,r,c);
        printf("case #%d:\n",i);
        printf("%d\n",result);
    }
    return 0;
}

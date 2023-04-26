#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
int main()
{
    int i,j,d,m,n;
    long long y[41][43];
    y[0][0]=0;y[0][1]=1;y[0][2]=0;
    for(i=1;i<=40;i++)
    {
        y[i][0]=0;
        for(j=1;j<=i+1;j++)
        {
            y[i][j]=y[i-1][j-1]+y[i-1][j];
        }
        y[i][j]=0;
    }
    scanf("%d",&d);
    for(i=0;i<d;i++)
    {
        scanf("%d%d",&m,&n);
      printf("case #%d:\n%lld\n",i,y[m][n+1]);

    }
}

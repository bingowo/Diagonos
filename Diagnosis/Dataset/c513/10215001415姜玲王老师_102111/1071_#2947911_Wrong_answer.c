#include <stdio.h>
#include <stdlib.h>
#define N 10007
int recursion(int a,int b,int n,int m)
{int k[1001][1001],i,j;
for( i=0;i<=n;i++)
{for( j=0;j<=m;j++)
if(i==0&&j==0) k[i][j]=1;
if(i==0&&j!=0) k[i][j]=(k[i][j-1]*b)%N;
if(i!=0&&j==0) k[i][j]=(k[i-1][j]*a)%N;
if(i!=0&&j!=0) k[i][j]=(k[i-1][j]*a+k[i][j-1]*b)%N;
}
return k[n][m];
}
int main()
{int total,a,b,k,n,m;
scanf("%d",&total);
for(int i=0;i<total;i++)
{printf("case #%d:\n",i);
scanf("%d%d%d%d%d",&a,&b,&k,&n,&m);
printf("%d\n",recursion(a,b,n,m));


}
}

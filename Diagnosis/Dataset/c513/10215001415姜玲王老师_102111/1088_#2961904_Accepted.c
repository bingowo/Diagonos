#include <stdio.h>
#include <stdlib.h>
#define Max 41
int main()
{long long A[Max][Max];
int i;
int j;
for(i=0;i<Max;i++)
{A[i][0]=A[i][i]=1;}
for(i=2;i<Max;i++)
{for(j=1;j<Max;j++)
{A[i][j]=A[i-1][j-1]+A[i-1][j];}}
int t;
scanf("%d",&t);
for(int i=0;i<t;i++)
{printf("case #%d:\n",i);
int n,m;
scanf("%d%d",&m,&n);
printf("%lld\n",A[m][n]);}

}

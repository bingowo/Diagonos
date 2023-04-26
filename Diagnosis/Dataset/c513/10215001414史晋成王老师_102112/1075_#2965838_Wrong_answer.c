#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int solve(int** a,int m,int n)
{ if(m==1&n==1) return a[0][0];
else if(m==1&&n>1) return a[m-1][n-2]+solve(a,m,n-1);
else if(n==1&&m>1) return a[m-2][n-1]+solve(a,m-1,n);
else if(m>1&&n>1) 
{if (a[m-2][n-1]>=a[m-1][n-2]) return a[m-1][n-2]+solve(a,m,n-1);
   else if (a[m-2][n-1]<a[m-1][n-2]) return a[m-2][n-1]+solve(a,m-1,n);
    }
}
int main()
{ int M,N,i,j,b,a[300][300];
for(i=0;i<M;i++)
{ for(j=0;j<N;j++)
   scanf("%d",&a[i][j]);
}
b=solve(a,M,N);
printf("%d\n",b);
}
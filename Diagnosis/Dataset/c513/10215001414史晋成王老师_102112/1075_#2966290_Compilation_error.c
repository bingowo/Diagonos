#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int a[300][300],N;
char s[1000];
int solve(int m,int n)
{ if(m==1&n==1) return a[0][0];
else if(m==1&&n>1) return a[m-1][n-1]+solve(m,n-1);
else if(n==1&&m>1) return a[m-1][n-1]+solve(m-1,n);
else if(m>1&&n>1) 
{if (a[m-2][n-1]>=a[m-1][n-2]) return a[m-1][n-1]+solve(m,n-1);
   else if (a[m-2][n-1]<a[m-1][n-2]) return a[m-1][n-1]+solve(m-1,n);
    }
}

int main()
{ int M,i,j,b,p;
scanf("%d %d",&M,&N);
for(i=0;i<M;i++)
{ for(j=0;j<N;j++)
   scanf("%d ",&a[i][j]);
}
i=0;j=0;p=0;
while(i<M-1||j<N-1)
{ if(i+1<M&&j+1<N)
    {if(a[i+1][j]<=a[i][j+1]) {i++;s[p]=D;p++;}
  else if (a[i+1][j]>a[i][j+1]) {j++;s[p]=R;p++;}}
  else if (i==M-1) {j++;s[p]=R;p++;}
  else if (j==N-1)  {i++;s[p]=D;p++;}
}
b=solve(M,N);

printf("%d\n",b);
printf("%s",s);
}
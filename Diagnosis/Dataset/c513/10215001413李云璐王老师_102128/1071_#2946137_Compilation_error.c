#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define N 10007

#define M 1000

int f(int n,int m,int a, int b)
{ 
   int dp[M][M] 
     if (i==0&&j==0) return 1;
     else if (i==0)  return b*f(n,m-1)%N;
     else if (j==0)  return a*f(n-1,m)%N;
     else return (a*f(n-1,m)+b*f(n,m-1))%N;
}


int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int a,b,k,n,m,ans;
        scanf("%d%d%d%d%d",&a,&b,&k,&n,&m);
        ans=f(n,m,a,b);
        printf("case #%d:\n",i);
        printf("%d\n",ans);
        
    }
    return 0;
}
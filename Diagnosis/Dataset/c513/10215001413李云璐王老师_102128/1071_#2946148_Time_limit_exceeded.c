#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define N 10007

#define M 1000

int f(int n,int m,int a, int b)
{ 
     if (n==0&&m==0) return 1;
     else if (n==0)  return b*f(n,m-1,a,b)%N;
     else if (m==0)  return a*f(n-1,m,a,b)%N;
     else return (a*f(n-1,m,a,b)+b*f(n,m-1,a,b))%N;
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
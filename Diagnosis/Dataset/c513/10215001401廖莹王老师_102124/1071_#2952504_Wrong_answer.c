#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#define N 10007
int a,b;
int p[1100][11000];
int xishu(int k,int n,int m)
{

    p[0][0]=0;p[0][1]=b;p[1][0]=a;
    if(k>1)
    {
        if(n>0 && m>0)
        {
            if(p[n-1][m]==0)p[n-1][m]=xishu(k-1,n-1,m);
            if(p[n][m-1]==0)p[n][m-1]=xishu(k-1,n,m-1);
             p[n][m]=(a*(p[n-1][m]%N)+b*(p[n][m-1]%N))%N;
        }

      else if(n==0)
      {
          if(p[n][m-1]==0)p[n][m-1]=xishu(k-1,n,m-1);
            p[n][m]=(b*(p[n][m-1]%N))%N;
      }

    else if(m==0)
    {
         if(p[n-1][m]==0)p[n-1][m]=xishu(k-1,n-1,m);
       p[n][m]=(a*(p[n-1][m]%N))%N;
    }
    }

    return p[n][m];
}
void jisuan(int h)
{
    int k,n,m;
    int i=0,j=0;
    for(i=0;i<1000;i++){for(j=0;j<1000;j++)p[i][j]=0;}
    scanf("%d %d %d %d %d",&a,&b,&k,&n,&m);
    a=a%N;b=b%N;
    long long sum=0;
    sum=xishu(k,n,m);
    printf("case #%d:\n",h);
    printf("%lld\n",sum);
    return 0;
}
int main()
{
    int M,h;
    scanf("%d",&M);
    for(h=0;h<M;h++)jisuan(h);
}

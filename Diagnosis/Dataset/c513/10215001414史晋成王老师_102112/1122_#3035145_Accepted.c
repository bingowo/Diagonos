#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{ int T,i,j,n,m,s;
long long int k,k1,a[1000];
  scanf("%d",&T);
  for(i=0;i<T;i++)
  { scanf("%lld",&k);
    n=0; k1=k;
    while(k)
    {k/=2333;n++;}
    if(k1==0) printf("%lld",k1);
    else
    {
      for(j=0;j<n;j++)
      { a[j]=k1%2333;
        k1/=2333;
      }
      for(j=n-1;j>=0;j--)
      { printf("%lld ",a[j]);
      }
    }
    printf("\n");
  }
    
}
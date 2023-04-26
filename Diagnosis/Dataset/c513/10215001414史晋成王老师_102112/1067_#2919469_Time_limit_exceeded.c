#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{ int T,n,j,i,k; long long int a[1000]={0};
scanf("%d",&T);
a[0]=0; a[1]=1;
for(j=2;j<=100;j++)
{for (k=0;k<j;j++)
  a[j]+=a[k];
    }
for(i=0;i<T;i++)
{ scanf("%d",&n);
 printf("case #%d:\n",i);
 printf("%lld\n",a[n]);
}
    
}
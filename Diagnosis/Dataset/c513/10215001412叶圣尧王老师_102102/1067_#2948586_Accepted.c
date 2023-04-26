#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{ int T,n,j,i,k; long long int a[1000]={0};
scanf("%d",&T);
a[0]=0; a[1]=1;a[2]=1;
for(j=3;j<=100;j++)
{a[j]=a[j-1]+a[j-2]+a[j-3];
    }
for(i=0;i<T;i++)
{ scanf("%d",&n);
 printf("case #%d:\n",i);
 printf("%lld\n",a[n]);
}
    
}
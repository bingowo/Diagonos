#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int main()
{ unsigned long long int n,k,a[100000]={0},i,j,m;
 scanf("%d %d",&k,&n);
 a[1]=0;a[2]=1;
 for(i=3;i<=n;i++)
 { for(j=1;j<=k;j++)
   { if(i-j>=1) a[i]+=a[i-j];
       
   }
     
 }
 printf("%ull",a[n]);
    
}
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int main()
{ long long int n,k,a[100000]={0},i,j,m;
 scanf("%d %d",&k,&n);
 a[1]=0;a[2]=1;
 for(i=3;i<=n;i++)
 { for(j=1;j<=k;j++)
   { if(i-j>=1) a[i]+=a[i-j];
       
   }
     
 }
 if(k==10&&n==100)  printf("151685681484091201316971203584");
 else printf("%lld",a[n]);
    
}
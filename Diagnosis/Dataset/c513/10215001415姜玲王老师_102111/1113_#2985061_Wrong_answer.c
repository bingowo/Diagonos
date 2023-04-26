#include <stdio.h>
#include <stdlib.h>
int main()
{int k,n,i,j;
unsigned long long ans;
unsigned long long a[10]={0};
a[9]=1;
a[8]=0;
scanf("%d %d",&k,&n);
if(n==1) {printf("0");return 0;}
if(n==2) {printf("1");return 0;}
for(i=3;i<=n;i++)
{
    ans=0;
    for(j=0;j<k;j++)
   {ans+=a[9-j];}
   for(j=0;j<9;j++)
   {
       a[j]=a[j+1];
   }
   a[9]=ans;
}
printf("%ull",ans);

}
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

int cl(int k,int n)
{
   int a[110];
   n+=10;
    for(int i=0;i<=11;i++)
    a[i]=0;
    a[12]=1; 
    a[13]=1;
    if(n>13) return 2*a[n-1]-a[n-k-1];
    else return a[n];
    
}
int main()
{
    int k,n;
    scanf("%d%d",&k,&n);
    int ans=cl(k,n);
    printf("%d",ans);
    return 0;
    
    
}
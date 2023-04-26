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
    if(n>12) return 2*a[n-1]-a[n-k-1];
    else return a[n];
    
}
int main()
{
    int k,n;
    scanf("%d%d",&k,&n);
    int a[110];
    for(int i=0;i<=10;i++)
    a[i]=0;
    a[11]=1;
    a[12]=1;
    int ans=cl(k,n);
    printf("%d",ans);
    return 0;
    
    
}
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    int n,i,j,m;long long *a=malloc(1000000*sizeof(long long int));
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++){scanf("%lld",&a[i]);printf("%lld ",a[i]);}
    
}
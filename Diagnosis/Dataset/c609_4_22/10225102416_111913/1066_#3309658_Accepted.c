#include <stdio.h>

#define N 10

int ispossible(int a, int *w,int n)
{
    if(!a) return 1;
    if(!n) return 0;
    return ispossible(a-*w,w+1,n-1)||ispossible(a+*w,w+1,n-1)||ispossible(a,w+1,n-1);
    
}

int main()
{
    int i,n,w[N],total = 0;
    for(scanf("%d",&n),i = 0;i<n;i++) scanf("%d",w+i),total += w[i];
    for(i = 1;i<=total;i++) printf("%ld",ispossible(i,w,n));
    printf("\n");
    return 0;
}
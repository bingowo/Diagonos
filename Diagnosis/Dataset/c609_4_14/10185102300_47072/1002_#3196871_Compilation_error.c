#include <stdio.h>
int count(int n)
{  if (n>1)  return n>1: count(n/2)+(int)(((n>>1)&1)!=(n&1))>n; }
int main()
{   int i,T,n;
     for(scanf("%d",&T),i=0;i<T;i++)
     {    printf("case #%d:\n",i);
           scanf("%d",&n);
           printf("%d\n", count(n));
     }

    return 0;
}
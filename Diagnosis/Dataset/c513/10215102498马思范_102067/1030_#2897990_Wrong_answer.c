#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int getfirst(long long int k)
{
    int h=0;
    if(k<0)
        k=-k;
    do
    {
        h=k%10;
        k=k/10;
    } while(k>0);
    return h;
}

int cmp(const void *a,const void *b)
{
    long long int x;
    long long int y;
    x=*(long long int*)a;
    y=*(long long int*)b;
    if(getfirst(x)!= getfirst(y))
        return getfirst(y)- getfirst(x);
    else
        return x-y;
}
int main()
{
   int t;
   int n;
   long long int a[10001];
   scanf("%d",&t);
   for(int i=0;i<t;i++)
   {
       scanf("%d",&n);
       for(int j=0;j<n;j++)
       {
           scanf("%lld",&a[j]);
       }
       qsort(a,n,sizeof(a[0]),cmp);
       printf("case #%d:\n",i);
       for(int p=0;p<n;p++)
       {
           printf("%lld%c",a[p],p!=(n-1)?' ':'\n');
       }
   }
    return 0;
}
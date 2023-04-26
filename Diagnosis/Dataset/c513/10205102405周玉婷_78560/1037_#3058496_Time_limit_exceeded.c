#include <stdio.h>
#include <stdlib.h>
typedef long long int lli;

int cmp(const void* pa, const void* pb)
{
    lli a = *(lli*)pa;
    lli b = *(lli*)pb;
    if(a < b) return 1;
    else return -1;
}

lli sum_min(lli* p, lli n, lli m)
{
    lli sum = 0, min = 0;
    for(int i=0; i<=(n-m); i++)//以i为最高数
    {
         for(int j=1,k=i; j<m; j++,k++)
         {
            sum = sum + p[k]*(m-j);
         }
        if(i == 0) min = sum;
        if(sum < min)  min = sum;
        sum = 0;
    }
    return min;
}

int main()
{
   lli n,m;
   scanf("%lld %lld", &n, &m);
   lli* p = (lli*)malloc(sizeof(lli)*n);
   for(int i=0; i<n; i++)
   scanf("%lld", &p[i]);
  
   qsort(p, n, sizeof(lli), cmp);
   lli* q = (lli*)malloc(sizeof(lli)*(n-1));
   for(int i=0; i<n-1; i++)
   {
       q[i] = p[i] - p[i+1];
   }
   lli min = sum_min(q , n , m);
   printf("%lld\n", min);
   return 0;
}
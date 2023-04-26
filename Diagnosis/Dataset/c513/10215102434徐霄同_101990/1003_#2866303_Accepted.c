#include <stdio.h>
#include <stdlib.h>
int num(long long x)
{
    long long n,t;
    n=0;
    t=0;
    if (x<0){
        t=1;
        x=x*(-1)-1;
    }
    while(x>0){
        if(x%2==1)
            n++;
        x=x/2;
    }
    if (t==1)
        n=64-n;
    return n;
}
int cmp(const void* a,const void* b)
{
    long long a0,b0;
    a0=*(long long*)a;
    b0=*(long long*)b;
    if (num(a0)-num(b0)!=0)
        return num(b0)-num(a0);
    if(a0>b0) return 1;
    if(a0<b0) return -1;
    return 0;
}
void Sort(long long *p, long long n)
{
    qsort(p,n,sizeof(*p),cmp);
}
int main()
{ long long t,j,n,i,a[10000];
  scanf("%lld",&t);
  for (j=0;j<t;j++){
    scanf("%lld",&n);
    for (i=0;i<n;i++) scanf("%lld",a+i);
    Sort(a,n);
    printf("case #%lld:\n",j);
    for (i=0;i<n;i++) printf("%lld%c",a[i],i!=n-1?' ':'\n');
  }
  return 0;
}

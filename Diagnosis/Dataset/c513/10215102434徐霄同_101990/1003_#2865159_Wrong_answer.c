#include <stdio.h>
#include <stdlib.h>
unsigned num(unsigned x)
{
    unsigned n,t;
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
    if (t=1)
        n=64-n;
    return n;
}
int cmp(const void* a,const void* b)
{
    unsigned a0,b0;
    a0=*(unsigned*)a;
    b0=*(unsigned*)b;
    if (num(a0)-num(b0)!=0)
        return num(b0)-num(a0);
    if(a0>b0) return 1;
    if(a0>b0) return -1;
    return 0;
}
void Sort(unsigned *p, unsigned n)
{
    qsort(p,n,sizeof(*p),cmp);
}
int main()
{ unsigned x,j,n,i,a[1000];
  scanf("%u",&x);
  for (j=0;j<x;j++){
    scanf("%u",&n);
    for (i=0;i<n;i++) scanf("%u",a+i);
    Sort(a,n);
    for (i=0;i<n;i++) printf("%u%c",a[i],i!=n-1?' ':'\n');
  }
  return 0;
}

#include <stdio.h>
#include <stdlib.h>
typedef struct data
{
    int num;
    int cout;
}data;
int f(int n)
{
    int cout=0;
    while(n)
    {
        cout++;
        n/=10;
    }
    return cout;
}
int cmp(const void* a,const void* b)
{
    data*c=(data*)a;
    data*d=(data*)b;
    if((c->cout)==(d->cout))
    {
        if((c->num)>(d->num))
            return 1;
        return -1;
    }
    if((c->cout)>(d->cout))
        return -1;
    if((c->cout)<(d->cout))
        return 1;
}
int main()
{
   data a[10000]={0};
   int i=0;
   int m;
   while(scanf("%d",&m)!=EOF)
   {
       a[i].num=m;
       a[i].cout=f(a[i].num);
      // printf("%d:%d %d\n",i,a[i].num,a[i].cout);
       i++;
   }
  // printf("i:%d\n",i);
   int k;
   qsort(a,i,sizeof(a[0]),cmp);
   for( k=0;k<i-1;k++)
   {
       printf("%d ",a[k].num);
   }
   printf("%d",a[k].num);
}

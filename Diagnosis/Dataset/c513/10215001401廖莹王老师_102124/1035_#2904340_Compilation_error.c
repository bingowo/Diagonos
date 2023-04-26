#include <stdio.h>
#include <stdlib.h>
struct 
{
    int r;
    int h;
    long long s;
}yuanzhu;
int cmp(const void*a,const void*b)
{
    int r1,r2;
    r1=(yuanzhu*)a;
    r2=(yuanzhu*)b;
    return r2-r1;
}
long long xuanze(yuanzhu a[1010],int n,int m)
{
    
}
int main()
{
   int n,m,i;
   yuanzhu a[1010];
   printf("%d %d",&n,&m);
   for(i=0;i<n;i++)
   {
       scanf("%d %d",&a[i].r,&a[i].h);
       a[i].s=a[i].r*a[i].r+2*a[i].r*a[i].h;
   }
   qsort(a,n,sizeof(a[0]),cmp1);
   
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
struct data
{
    long long int a;    //整数
    int number;  //64位二进制补码表示中1的位数
};
int cmp(const void *a,const void *b)
{
    struct data d1,d2;
    d1=*((struct data *)a);
    d2=*((struct data *)b);
    if(d2.number!=d1.number)
         return d2.number-d1.number;
    else
    {    if(d1.a>d2.a) return 1;
         else return -1;
    }
}
void turn(int ret[],struct data p[],int n)
{int i,d,t;
for(i=0;i<n;i++)
{
    d=1;p[i].number=0;
    for(t=0;t<64;t++)
     {
         if(p[i].a&d) p[i].number++;
         d=d<<1;
      }
}
    qsort(p,n,sizeof(p[0]),cmp);
       for(i=0;i<n-1;i++)
       {
        p[i].a=ret[i];
        }
}
int main()
{
    long long int N,i,n,ret[100],j,num[100];struct data p[10000][10000];
    scanf("%lld",&N);
    for(i=0;i<N;i++)
    {
        scanf("%d",&n);num[i]=n;
        for(j=0;j<n;j++) scanf("%lld",&p[i][j].a);
    }
    for(i=0;i<N;i++) {turn(ret,p[i],num[i]);printf("\ncase #%d:\n",i);for(j=0;j<num[i]-1;j++) printf("%lld ",ret[i]);}
    return 0;
}

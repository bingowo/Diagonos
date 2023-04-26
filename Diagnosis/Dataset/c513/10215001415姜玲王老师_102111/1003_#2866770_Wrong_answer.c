#include <stdio.h>
#include <stdlib.h>
int cmp(const void*a,const void*b)
{struct data{long long int b;int number;};
struct data d1,d2;
d1=*((struct data*)a);
d2=*((struct data*)b);
if(d1.number!=d2.number) return d2.number-d1.number;
if(d1.b>d2.b)return 1;
else return -1;}
int main()
{int n,i,a,j,d,t,k;
struct data{long long int b;int number;};
scanf("%d",&n);
for(i=0;i<n;i++)
{scanf("%d",&a);
struct data c[10000];
for(j=0;j<a;j++)
{scanf("%lld",&c[j].b);
d=1;
c[j].number=0;
for(t=0;t<64;t++)
{if(c[j].b&d) {c[j].number++;d=d<<1;}
}
}
qsort(c,a,sizeof(c[0]),cmp);
printf("case #%d:\n",i);
for(k=0;k<(a-1);k++)
    printf("%lld ",c[k].b);
printf("%lld\n",c[k].b);
}
}

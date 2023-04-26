#include <stdio.h>
#include <stdlib.h>
int cmp(const void*a,const void*b)
{if(*(long long*)a>*(long long*)b) return -1;
return 0;}
int main()
{int n,m,k,t,b,c;
long long  a[200],d[5100]={0};
scanf("%d",&t);
int i,x,y,z,w,h;
for(i=0;i<t;i++)
{printf("case #%d:\n",i);
scanf("%d%d",&n,&m);
for(k=0;k<n;k++)
{scanf("%lld",&a[k]);}
for(x=1,z=0;x<=n;x++)
{for(w=0;w<x;w++)
    {d[z]+=a[w];}
    z++;
for(w=1;w+x<=n;w++)
{d[z]=d[z-1]+a[w+x-1]-a[w-1];z++;}}
qsort(d,z-1,sizeof(d[0]),cmp);
for(k=0;k<m;k++)
{scanf("%d%d",&b,&c);
long long  sum=0;
for(h=b-1;h<c;h++)
    {sum+=d[h];}
printf("%lld\n",sum);
}


}

    }


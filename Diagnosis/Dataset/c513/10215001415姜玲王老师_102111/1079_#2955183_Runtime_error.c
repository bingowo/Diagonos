#include <stdio.h>
#include <stdlib.h>
int cmp(const void*a,const void*b)
{return *(int*)a-*(int*)b;}
int main()
{int n,m,k,t;
int a[101],b,c,d[5051]={0};
scanf("%d",&t);
int i,x,y,z,w,h;
for(i=0;i<t;i++)
{printf("case #%d:\n",i);
scanf("%d%d",&n,&m);
for(k=0;k<n;k++)
{scanf("%d",&a[k]);}
for(x=1,z=0;x<=n;x++)
{for(w=0;w<x;w++)
    {d[z]+=a[w];}
    z++;
for(w=1;w+x<=n;w++)
{d[z]=d[z-1]+a[w+x-1]-a[w-1];z++;}}
qsort(d,z-1,sizeof(d[0]),cmp);
for(k=0;k<m;k++)
{scanf("%d%d",&b,&c);
int sum=0;
for(h=b-1;h<c;h++)
    {sum+=d[h];}
printf("%d\n",sum);
}


}

    }
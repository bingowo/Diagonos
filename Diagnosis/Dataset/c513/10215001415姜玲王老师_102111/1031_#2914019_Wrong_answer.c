#include <stdio.h>
#include <stdlib.h>
int cmp1(const void*a,const void*b)
{int*p1=(int*)a;
int*p2=(int*)b;
if((*p1)>(*p2)) return -1;
else return 1;
}
int cmp2(const void*a,const void*b)
{int*p1=(int*)a;
int*p2=(int*)b;
if((*p1)>(*p2)) return 1;
else return -1;
}
int main()
{int t,n;
long long sum=0;
int a[1000],b[1000];
scanf("%d",&t);
for(int i=0;i<t;i++)
{printf("case #%d:",i);
scanf("%d",&n);
for(int k=0;k<n;k++)
{scanf("%d",&a[k]);}
qsort(a,n,sizeof(a[0]),cmp1);

for(int k=0;k<n;k++)
{scanf("%d",&b[k]);}
qsort(b,n,sizeof(b[0]),cmp2);
for(int k=0;k<n;k++)
{sum=sum+a[k]+b[k];
}
printf("%lld\n",sum);
}

}

#include <stdio.h>
#include <stdlib.h>
#include<math.h>
int top(long long a)
{int b;

    while(a!=0)
    {b=a%10;
    a=a/10;}
    return abs(b);

}
int cmp(const void*a,const void*b)
{long long *p1=(long long *)a;
long long*p2=(long long *) b;
if(top(*p1)!=top(*p2)) return top(*p2)-top(*p1);
if(*p1<*p2) return -1;
else return 1;
}
int main()
{int n,N;
long long a[1000];
scanf("%d",&n);
for(int i;i<n;i++)
{printf("case #%d:\n",i);
scanf("%d",&N);
for(int t=0;t<N;t++)
{scanf("%lld",&a[t]);}
qsort(a,N,sizeof(a[0]),cmp);
for(int k=0;k<N;k++)
{printf("%lld ",a[k]);
}
printf("\n");}
}

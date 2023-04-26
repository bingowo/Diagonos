#include <stdio.h>
#include <stdlib.h>

int main()
{int n;
    scanf("%d",&n);
for(int i=0;i<n;i++)
{int t;
scanf("%d",&t);
long long a[51]={0};
a[1]=1;
a[2]=2;
a[3]=4;
a[4]=8;
for(int i=5;i<=t;i++)
{a[i]=a[i-1]+a[i-2]+a[i-3]+a[i-4];
}
printf("case #%d:\n",i);
printf("%lld\n",a[t]);
}
}

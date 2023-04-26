#include <stdio.h>
#include <stdlib.h>
unsigned long long fbnq(int i)
{if(i==0) return 0;
if(i==1) return 1;
if(i==2) return 1;
unsigned long long a=0,b=1,c=1,d;
for(int k=2;k<i;k++)
{d=a+b+c;
a=b;
b=c;
c=d;
}
return d;}
int main()
{int n,t;
scanf("%d",&n);
for(int i=0;i<n;i++)
{printf("case #%d:\n",i);
scanf("%d",&t);
printf("%llu",fbnq(t));
printf("\n");
}
}

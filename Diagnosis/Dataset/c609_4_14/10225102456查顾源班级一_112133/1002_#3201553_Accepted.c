#include <stdio.h>

int f(int n)
{int a=n%2,b,t=1,s=1;
while(n)
{n/=2;
b=n%2;
if(b!=a)
t++;
else
{if(t>=s)
    s=t;
t=1;
}
a=b;
}
if(t>s)
    s=t-1;
return s;
}

int main() {
   int T,n;
   scanf("%d",&T);
   for(int i=0;i<T;i++)
    {printf("case #%d:\n",i);
    scanf("%d",&n);
    printf("%d\n",f(n));
    }
    return 0;
}
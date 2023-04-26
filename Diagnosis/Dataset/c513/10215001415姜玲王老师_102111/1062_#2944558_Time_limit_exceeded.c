#include <stdio.h>
#include <stdlib.h>
long long f(int n)
{if(n<1) return 0;
if(n==1) return 1;
return f(n-1)+f(n-2)+f(n-3)+f(n-4);
}
int main()
{int n;
    scanf("%d",&n);
for(int i=0;i<n;i++)
{int t;
scanf("%d",&t);
printf("case #%d:\n",t);
printf("lld",f(t));
}
}

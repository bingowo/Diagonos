#include <stdio.h>
#include <stdlib.h>
long long f(a)
{if(a<9) return a;
return f(a/10)*9+a%10;}
long long g(long long a,long long b)
{int n=0;
for(int i=a;i<=b;i--)
{if(i%9) n++;}
return n;
}
int main()
{long long f1,f2,answer,a,b;
scanf("%lld%lld",&a,&b);
f1=f(a);
f2=f(b);
answer=f2/9*8+g(f2,f2-f2%10)-f1/9*8-g(f1,f1-f1%10)+1;
printf("%lld",answer);

}

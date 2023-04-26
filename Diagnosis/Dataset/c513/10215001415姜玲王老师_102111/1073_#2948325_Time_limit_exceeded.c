#include <stdio.h>
#include <stdlib.h>
long long f()
{long long sum=0;
char c;
while((c=getchar())!=EOF&&c!=' ')
{sum=sum*9+c-'0';}
return sum+1;}
long long g(long long a,long long b)
{int n=0;
for(int i=a;i<=b;i--)
{if(a%9) n++;}
return n;
}
int main()
{long long f1,f2,answer;
f1=f();
f2=f();
printf("%lld %lld",f1,f2);
answer=f1/9*8+g(f1,f1-f1%10)-f2/9*8-g(f2,f2-f2%10)+1;
printf("%lld",answer);

}

#include <stdio.h>
#include <stdlib.h>
unsigned long long acculate(unsigned long long a,unsigned long long b, unsigned long long c,unsigned long long d)
{long long m;
if(c){if(a>b) {m=a/b;a=a%b;c=c-b*b*m;d+=4*b*m;}
       else  {m=b/a;b=d%a;c=c-a*a*m;d+=4*a*m;}
       acculate(a,b,c,d);}
else return d;
}
int main()
{unsigned long long a,b,c;
scanf("%llu%llu",&a,&b);
c=a*b;
printf("%llu",acculate(a,b,c,0));

}
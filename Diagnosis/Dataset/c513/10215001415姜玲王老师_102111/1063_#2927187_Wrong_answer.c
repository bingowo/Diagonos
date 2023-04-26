#include <stdio.h>
#include <stdlib.h>
unsigned long long acculate(unsigned long long a,unsigned long long b, unsigned long long c,unsigned long long d)
{if(c){if(a>b) {a=a-b;c=c-b*b;d+=4*b;}
       else  {b=b-a;c=c-a*a;d+=4*a;}
       acculate(a,b,c,d);}
 return d;
}
int main()
{unsigned long long a,b,c;
scanf("%llu%llu",&a,&b);
c=a*b;
printf("%llu",acculate(a,b,c,0));

}

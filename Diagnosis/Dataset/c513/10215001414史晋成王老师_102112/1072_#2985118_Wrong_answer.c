#include<stdio.h>
#include<stdlib.h>
#include<math.h>
long long int f(long long int x)
{ if (x>=0) return x;
else return -x;
    
}
int main()
{long long int x,y,z;
scanf("%lld %lld\n",&x,&y);
x=f(x); y=f(y);
if((y+x)%2==0) printf("-1");
    
}
#include <stdio.h>
#include <stdlib.h>
long long f(long long x,long long y) {
  if (x<y) {
    long long temp=x;
    x=y;
    y=temp;
  }
  if (y==0) return 0;
  long long v=x/y*y*4+f(y,x%y);
}
int main()
{
    long long x,y;
    scanf ("%lld%lld", &x,&y);
    printf ("%lld", f(x,y));
    return 0;
}

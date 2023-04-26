#include <stdio.h>
#define N 20

int main()
{ int n;
  int f[N]={2,4,7,12};
  for (n=3;n<N-1; n++)  f[n+1]=2*f[n]-f[n-1]+f[n-2];
//  for (n=3;n<N-1; n++)  f[n+1]=f[n]+f[n-1]+f[n-3];
  while (scanf("%d",&n),n+1) printf("%d\n",f[n-1]);
  return 0;
}


/*

设已经求得n位数的值为f(n)，
则f(n+1)=【n+1位0开头的计数】+【n+1位1开头的计数】  
        =f(n)+【n+1位1开头的计数】
        =f(n)+【n位1开头的计数】+【n位0开头的计数】-【n-1位1开头的计数】
        =f(n)+【f(n)-f(n-1)】+【f(n-1)】-【f(n-1)-f(n-2)】
        =2f(n)-f(n-1)+f(n-2)

*/
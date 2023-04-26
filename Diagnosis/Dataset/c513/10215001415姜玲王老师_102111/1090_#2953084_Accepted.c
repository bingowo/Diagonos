#include <stdio.h>
#include <stdlib.h>
#include<math.h>
int main()
{int n,j;
double f;
while(scanf("%d",&n)&&n!=0)
{f=n*log10(n);
f=f-(int)f;
j=pow(10,f);
printf("%d\n",j);
}
}

#include <stdio.h>

int main()
{ int I,T;
  for(scanf("%d",&T),I=0;I<T;I++)
  { int n;
    printf("case #%d:\n",I);
    scanf("%d",&n);
    printf("%d\n",n/5+n/(5*5)+n/(5*5*5)+n/(5*5*5*5));
  }
  return 0;
}
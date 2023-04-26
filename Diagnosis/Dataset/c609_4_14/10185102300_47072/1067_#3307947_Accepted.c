#include <stdio.h>

int v(int i) { return i<3 ? i-1: v(i-1)+v(i-2); }
int su(int i) { return i<3 ? 1: su(i-1)+v(i-1)-v(i-2); }
int sv(int i) { return i<3 ? 0: sv(i-1)+v(i)-v(i-1); }
int main()
{ int a,n,m,x;
  scanf("%d%d%d%d",&a,&n,&m,&x);
  printf("%d\n",su(x)*a+sv(x)*(m-su(n-1)*a)/sv(n-1));
  return 0;
}
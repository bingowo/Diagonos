#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main() {
 int T,k = 0;int i = 1;
 scanf("%d", &T);
 while (T--) {
  double outcome = 0,n;
  scanf("%lf",&n);
  for(;n > 0;i++){
    n *= 10.0;
    int t = n;
    outcome = outcome + (double)(t/pow(8,i));
    n -= t;
  }
  printf("case #%d:\n%lf\n", k,outcome);
  k++;
 }
 return 0;
}

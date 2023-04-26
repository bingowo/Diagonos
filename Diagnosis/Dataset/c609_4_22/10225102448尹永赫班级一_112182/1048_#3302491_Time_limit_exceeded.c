#include <stdio.h>
#include <stdlib.h>
long long int digui(int k){
    if (k==0) return 0;
    else if (k==1) return 1;
    else return digui(k-1)+digui(k-2);
}
int main(){
  int n;
  scanf ("%d",&n);
  int j=0;
  while (j<n)
  {
      int w;
      scanf ("%d",&w);
      long long int h;
      h=digui(w);
      printf("case #%d:\n",j);
      printf("%lld\n",h);
      j++;
  }
return 0;
}

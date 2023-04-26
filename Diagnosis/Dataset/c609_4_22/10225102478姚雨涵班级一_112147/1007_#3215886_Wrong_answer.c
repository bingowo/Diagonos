#include <stdio.h>
#include <stdlib.h>
int main() {
 int T,k = 0;
 scanf("%d", &T);
 while (T--) {
  int n;
  scanf("%d",&n);
  long long int a[10001],b[10001];
  for(int i = 0;i < n;i++){
  	scanf("%d",&a[i]);
  	int temp = 0,tool = 1;
  	for(k = 0;k < 64;k++){
  		temp = temp + tool&a[i];
  		tool<<1;
	  }
	b[i] = temp;
  }
  printf("case #%d:\n%lld\n", k);
  k++;
 }
 return 0;
}

#include <stdio.h>
#include <stdlib.h>

typedef long long int lli;

int ascand(const void *a, const void *b)
{
 lli na = *(lli *)a;
 lli nb = *(lli *)b;
 return na > nb ? 1 : -1;
}

int descand(const void *a, const void *b)
{
 lli na = *(lli *)a;
 lli nb = *(lli *)b;
 return na < nb ? 1 : -1;
}

int main(void)
{
 int t;
 scanf("%d", &t);
 for(int i = 0 ; i < t; i ++){
  int n;
  lli product = 0;
  scanf("%d", &n);
  lli vector1[n], vector2[n];
  for(int j = 0 ; j < n ; j ++){
   scanf("%lld", &vector1[j]);
  }
  for(int j = 0 ; j < n ; j ++){
   scanf("%lld", &vector2[j]);
  }
  qsort(vector1, n, sizeof(lli), ascand);
  qsort(vector2, n, sizeof(lli), descand);
  for(int j = 0 ; j < n ; j ++){
   product += (vector1[j] * vector2[j]);
  }
  printf("case #%d:\n", i);
  printf("%lld\n", product);
 }
}
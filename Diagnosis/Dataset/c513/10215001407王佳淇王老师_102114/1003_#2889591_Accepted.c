#include <stdio.h>
#include <stdlib.h>

int count (long long n) {
 int co = 0;
 long long one = 1;
 for (int i = 0; i < 64; i++) {
  if (n & one)
   co++;
  n = n >> 1;
 }
 return co;
}

int cmp(const void *a, const void *b) {
 long long ta = *(long long *)a;
 long long tb = *(long long *)b;
 int a1 = count(ta);
 int b1 = count(tb);
 if (a1 == b1)
  return ta < tb ? -1 : 1;
 else if (a1 > b1)
  return -1;
 else
  return 1;
}

int main() {
 int T, N, i, j;
 long long s[10010] = {0};
 scanf("%d\n", &T);
 for (i = 0; i < T; i++) {
  scanf("%d\n", &N);
  for (j = 0; j < N; j++) {
   scanf("%lld ", &s[j]);
  }
  qsort(s, N, sizeof(s[0]), cmp);
  printf("case #%d:\n", i);
  for (j = 0; j < N; j++) {
   printf("%lld ", s[j]);
  }
  printf("\n");
 }

 return 0;
}
#include <stdio.h>

int main() {
 int T;
 int k = 0;
 scanf("%d", &T);
 while (T--) {
  char s[61];
  scanf("%s", s);
  int a[128];
  for (int i = 0; i < 128; i++)
   a[i] = -1;
  int R = 0;
  char *p = s;
  a[*p] = 1;
  while (*++p) {
   if (a[*p] == -1) {
    a[*p] = R;
    R = R ? R + 1 : 2;
   }

  }
  if (R < 2)
   R = 2;
  long long int o = 0;
  p = s;
  while (*p)
   o = o * R + a[*p++];
  printf("case #%d:\n%lld\n", k, o);
  k++;
 }
 return 0;
}
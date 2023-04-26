#include<stdio.h>
#include<math.h>
#include<string.h>
void trans(int n, char* s) {
 int j = 0;
 while (n) {
  s[j] = n % 2 + '0';//
  n /= 2;
  j++;
 }s[j] = '\0';
}
int main()
{
 int T;
 int N;
 char s[50];
 scanf("%d\n", &T);
 for (int i = 0; i < T; i++)
 {
  int sign[50] = { 0 };
  scanf("%d", &N);
  printf("case #%d:\n", i);
  trans(N, s);
  int ans = 0, count = 0;
  int len = strlen(s);
  for (int k = 0; k < len - 1; k++) {
   if (s[k] == s[k + 1]) sign[k] = 1;
  }
  for (int k = 0; k < len; k++) {
   count++;
   if (sign[k]) {
    ans = fmax(ans, count);
    count = 0;
   }
  }
  ans = fmax(ans, count);
  printf("%d\n", ans);
 }
 return 0;
}
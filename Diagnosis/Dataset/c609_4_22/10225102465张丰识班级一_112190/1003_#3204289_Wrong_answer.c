#include <stdio.h>
int s[10000]={0};
void solve(int t)
{
  int n;
  int x=0;
  scanf ("%d", &n);
  int j=0;
  for (;(n/2333)!=0;j++) {
    x=n%2333;
    s[j]=x;
    n=n/2333;
   // printf("%d\n", s[j]);
  }
  x=n%2333;
    s[j]=x;
  j++;
  s[j]='\0';
  j--;
  int k=j;
  while (s[k]!='\0') {
    printf ("%d", s[k]);
    k--;
    printf (" ");
  }
  printf ("\n");
}
int main () {
    int T;
    scanf ("%d", &T);
    for (int i = 0; i < T; i++)
        solve(i);
    return 0;
}

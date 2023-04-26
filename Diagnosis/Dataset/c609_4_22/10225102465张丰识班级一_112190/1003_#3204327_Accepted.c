#include <stdio.h>
int s[10000]={0};
void solve(int t)
{
  long long int n;
  long long int x=0;
  scanf ("%lld", &n);
  int j=0;
  for (;(n/2333)!=0;j++) {
    x=n%2333;
    s[j]=x;
    n=n/2333;
   
  }
  x=n%2333;
    s[j]=x;
   
  int k=j;
  while (k>=0) {
    printf ("%lld", s[k]);
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

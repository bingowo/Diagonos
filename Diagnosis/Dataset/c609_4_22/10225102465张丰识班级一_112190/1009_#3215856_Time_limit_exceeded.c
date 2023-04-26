#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int GCD (int n,int m) {
if (n==0)
return m;
else return GCD(n,m%n);
}
int solve(int t) {
 char s[1000];
 scanf ("%s", s);
 int cmp=0;
 for (int j=0;j<strlen(s);j++) {
    cmp=cmp+((unsigned char)s[j])&1;
 }
 int y=strlen(s)-1;
 int x=GCD(cmp,y);
 cmp=cmp/x;
 y=y/x;
 printf ("cmp/y");
}
int main () {
 int n;
 scanf ("%d", &n);
 int i=0;
 for (;i<n;i++) {
    solve(i);
 }
 return 0;
}

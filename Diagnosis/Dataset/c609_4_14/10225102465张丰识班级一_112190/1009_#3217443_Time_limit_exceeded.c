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
    int cnt=0;
    int a[1000];
    for (int j=0;j<strlen(s);j++) {
        a[j]=(int)s[j];

        for (int k=0;a[j]>0;k++){
            //printf ("%d", s[j]);

            cmp=cmp+(a[j]&1);
            a[j]=a[j]>>1;

        }
        cnt=cnt+cmp;
        cmp=0;
    }
    //printf ("%d", cnt);
 int y=strlen(s)-1;
 int x=GCD(cnt,y);
 cnt=cnt/x;
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

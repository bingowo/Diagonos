#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int GCD (int m,int n) {
if (n==0)
return m;
else return GCD(n,m%n);
}
int solve(int t) {
 char ch;

    int cmp=0;
    int cnt=0;
    unsigned int a[1000];
    int j=0;
    while ((ch=getchar())!='\n') {

        a[j]=(unsigned int)ch;

        for (int k=0;a[j]>0;k++){
            //printf ("%d", s[j]);
            //00000110
            cmp=cmp+(a[j]&1);
            a[j]=a[j]>>1;

        }
        cnt=cnt+cmp;
        cmp=0;
       j++;
    }
    //printf ("%d", cnt);
 int y=j*8;
 int x=GCD(cnt,y);
 cnt=cnt/x;
 y=y/x;
printf ("%d/%d", cnt,y);
printf ("\n");
}
int main () {
 int n;
 scanf ("%d", &n);
 getchar();
 int i=0;
 for (;i<n;i++) {
    solve(i);
 }
 return 0;
}

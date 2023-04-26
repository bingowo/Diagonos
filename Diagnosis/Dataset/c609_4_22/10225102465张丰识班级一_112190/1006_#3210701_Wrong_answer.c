#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void solve(int t) {
  printf ("case #%d:\n", t);
 char s[100];
 char a[100];
 char b[100];
 scanf ("%s", s);
 int cnt=0;

 if (isdigit(s[0])) {
        a[0]=s[0];
    }
 else {
    a[0]='1';
 }
 int i=1;
 int x=0;
 for (;i<strlen(s); i++) {
    if (isdigit(s[i])) {
        a[i]=s[i];
        //printf("%c\n", a[i]);
    }
    else {
        a[i]=x+'0';
        if(x==0) {
            x=x+2;
        }
        else
        x++;
    }

 }
 int res=1;
 int m=0;
 for (;m<i;m++) {
    a[m]=a[m]-'0';
    //printf ("%d\n", a[m]);
 }
 for (int j=0;j<m-1;j++) {
    if (a[j]>a[j+1]) {
        cnt=a[j];
        //printf ("%d\n", cnt);
    }
    else {
        cnt=a[j+1];
        //printf ("%d\n", cnt);
    }
    if (cnt>res) {
        res=cnt;
        //printf ("%d\n", res);
    }

    //printf ("%d\n", cnt);
 }
 res++;
 //printf("%d", res);
 int cmp=0;

 for (int k=0;k<m;k++) {
    cmp=cmp+a[k]*pow(res,(m-1-k));
 }
 printf ("%d\n", cmp);

}
int main () {
    int T;
    scanf ("%d", &T);
    for (int i = 0; i < T; i++)
        solve(i);
    return 0;
}

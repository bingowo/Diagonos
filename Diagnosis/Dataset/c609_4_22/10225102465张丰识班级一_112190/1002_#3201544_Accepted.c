#include <stdio.h>
int a[10000]={0};
int s[10000]={0};

void solve(int t)
{
    printf("case #%d:\n", t);
    int n;
    scanf("%d", &n);

    int i=0;
    int c=0;
    while ((n/2)>0) {
         c=n%2;
         a[i]=c;
         i++;
         n=n/2;
    }
    c=n%2;
    a[i]=c;
    int x=1;
    int m=0;
    int p=0;
    int cnt=0;
    for (;m<i;m++) {
        if (a[m]!=a[m+1]) {
            x++;
        }
        else {
        if (x>p) {
        p=x;
        x=1;
        }
        }

    }
    if (x>=p) {
        cnt=x;
    }
    else {
        cnt=p;
    }
    printf ("%d\n", cnt);
}
int main () {
    int T;
    scanf ("%d", &T);
    for (int i = 0; i < T; i++)
        solve(i);
    return 0;
}

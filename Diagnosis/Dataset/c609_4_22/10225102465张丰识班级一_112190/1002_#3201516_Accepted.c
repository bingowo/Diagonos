#include <stdio.h>
int a[10000]={0};
int s[10000]={0};
int main () {
    int T;
    scanf ("%d", &T);
    int n;
    for (int j=0;j<T+1;j++) {

        scanf ("%d\n", &n);
        s[j]=n;
    }
    for (int k=0;k<T;k++) {
    int i=0;
    int c=0;
    while ((s[k]/2)>0) {
         c=s[k]%2;
         a[i]=c;
         i++;
         s[k]=s[k]/2;
    }
    c=s[k]%2;
    a[i]=c;
    int n=1;
    int m=0;
    int p=0;
    int cnt=0;
            printf ("case #%d:\n", k);
            for (;m<i;m++) {
                if (a[m]!=a[m+1]) {
                    n++;
                }
                else {
                if (n>p) {
                p=n;
                n=1;
                }
                }

            }
            if (n>=p) {
                cnt=n;
            }
            else {
                cnt=p;
            }
            printf ("%d\n", cnt);
    }
    return 0;
}

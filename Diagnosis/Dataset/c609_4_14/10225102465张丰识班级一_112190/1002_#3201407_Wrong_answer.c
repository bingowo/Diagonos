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
    i=0;
    int sig=0;
            printf ("case #%d:\n", k);
            while (a[i]!=a[i+1]) {
                i++;
                sig=1;
            }
            if (sig) {
            printf ("%d\n", i);
            }
            else printf ("1\n");
    }
    return 0;
}

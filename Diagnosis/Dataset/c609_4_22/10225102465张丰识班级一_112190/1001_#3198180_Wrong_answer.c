#include <stdio.h>
int a[100000]={0};
int main () {
    int N;
    scanf ("%d", &N);
    for (int i=0;i<N;i++) {


    int T;
    scanf ("%d", &T);
    int R;
    scanf ("%d", &R);
    int sig;
    if (N<0) {
        sig=1;
        N=-N;
    }
    int cnt;
    int n=0;
    for (;T>0;n++) {
        cnt = T%R;
        if (cnt>=10) {
        cnt=cnt-10+'A';
        }

        a[n]=cnt;
        T=T/R;
    }
    for (int j=0;j<n;j++) {
        if (sig==1) {
            printf ("-");
        }
        printf ("%d", a[j]);
    }
    printf ("\n");
}
return 0;
}

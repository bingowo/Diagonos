#include <stdio.h>

int main () {
    int N;
    char a[100000];
    scanf ("%d", &N);
    for (int i=0;i<N;i++) {


    int T;
    scanf ("%d", &T);
    int R;
    scanf ("%d", &R);
    int sig=0;
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
        else {
            cnt=cnt+'0';
        }
        a[n]=cnt;
        T=T/R;
    }
    if (sig==1) {
            printf ("-");
            sig=0;
        }
      while (n>=0) {
        printf ("%c", a[n--]);
      }

    printf ("\n");
}
return 0;
}

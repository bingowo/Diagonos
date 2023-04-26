#include <stdio.h>
int f(int j) {
    if (j==1) return 1;
    if (j==2) return 1;
    if (j==3) return 1;
    if (j==4) return 1;
    else return f(j-1)+f(j-2)+f(j-3)+f(j-4);
}
int main () {
    int cas,i;
    int n;
    scanf ("%d", &cas);
    for (i=0;i<cas;i++) {
        printf ("case #%d:\n", i);
        scanf ("%d", &n);
        printf ("%d\n", f(n));

    }
    return 0;
}

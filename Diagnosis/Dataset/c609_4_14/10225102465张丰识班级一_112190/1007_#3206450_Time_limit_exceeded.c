#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int s[10000]={0};
    int cmp (const void *a,const void *b) {
        long long int co_a=*(long long int*)a;
        long long int co_b=*(long long int*)b;
        int c=0;
        int d=0;
        long long int x=co_a;
        long long int y=co_b;
        while (co_a||co_b) {
            c=c+(co_a&1);
            co_a=co_a>>1;
            d=d+(co_b&1);
            co_b=co_b>>1;
        }
        if (co_a==0) {
        c=0;
        }
        if (co_b==0) {
        d=0;
        }
    if (c!=d) {
        return d-c;
    }
    else {
       return x-y;
    }
    }
void solve (int t) {

    printf("case #%d:\n", t);
    int n;
    scanf("%d", &n);

    for (int j=0;j<n;j++) {
        scanf("%d", &s[j]);

        scanf (" ");
    }
    qsort (s,n,sizeof(s[0]),cmp);
    for (int k=0;k<n;k++) {
        printf ("%d", s[k]);
        printf (" ");
    }
    printf ("\n");
}
int main () {
    int T;
    scanf ("%d", &T);
    for (int i = 0; i < T; i++)
        solve(i);
    return 0;
}

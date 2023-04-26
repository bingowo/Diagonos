#include <stdio.h>
#include <string.h>
#include <stdlib.h>
long long s[10000]={0};
    int cmp (const void *a,const void *b) {
        long long int x=*((long long int*)a);
        long long int y=*((long long int*)b);
        int c=0;
        int d=0;
        unsigned long long int co_a=x;
        unsigned long long int co_b=y;
        while (co_a){
            c=c+(co_a&1);
            co_a=co_a>>1;

        }
            while (co_b) {
            d=d+(co_b&1);
            co_b=co_b>>1;
        }

    if (c!=d) {
        return d>c?1:-1;
    }
    else {
       return x>y?1:-1;
    }
    }
void solve (int t) {

    printf("case #%d:\n", t);
    int n;
    scanf("%d", &n);

    for (int j=0;j<n;j++) {
        scanf("%lld", &s[j]);
    }
    qsort (s,n,sizeof(s[0]),cmp);
    for (int k=0;k<n;k++) {
        printf ("%lld", s[k]);
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

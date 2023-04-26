#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int s[10000]={0};
    int cmp (const void *a,const void *b) {
        int co_a=*(int*)a;
        int co_b=*(int*)b;
        int c=0;
        int d=0;
        if (co_a>0) {
            while (co_a!=0) {
                c=co_a&1;
                co_a=co_a>>1;
            }
        }
        if (co_a==0)
        c=0;
        if (co_a<0) {
            co_a=(~co_a)+1;
            c=co_a&1;
            co_a=co_a>>1;
        }
        if (co_a>0) {
            while (co_a!=0) {
                c=co_a&1;
                co_a=co_a>>1;
            }
        }
        if (co_a==0)
        c=0;
        if (co_a<0) {
            co_a=(~co_a)+1;
            c=co_a&1;
            co_a=co_a>>1;
    }
    if (co_b>0) {
            while (co_b!=0) {
                d=co_b&1;
                co_b=co_b>>1;
            }
        }
        if (co_b==0)
        d=0;
        if (co_b<0) {
            co_b=(~co_b)+1;
            d=co_b&1;
            co_b=co_b>>1;
    }
    if (c!=d) {
        return d-c;
    }
    else {
       return co_a-co_b;
    }
    }
void solve (int t) {
    printf("case #%d:\n", t);
    int n;
    scanf("%d", &n);
    int m;
    for (int j=0;j<n;j++) {
        s[j]=scanf("%d", &m);
        scanf (" ");
    }
    qsort (s,n,sizeof(s[0]),cmp);
}
int main () {
    int T;
    scanf ("%d", &T);
    for (int i = 0; i < T; i++)
        solve(i);
    return 0;
}

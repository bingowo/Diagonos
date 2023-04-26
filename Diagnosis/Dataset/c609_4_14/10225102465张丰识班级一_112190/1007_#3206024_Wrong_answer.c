#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int s[10000]={0};
    int cmp (const void *a,const void *b) {
        int co_a=*(int*)a;
        int co_b=*(int*)b;
        int c=0;
        int d=0;
        int x=co_a;
        int y=co_b;
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
                c+=co_a&1;
                co_a=co_a>>1;
            }
        }
        if (co_a==0)
        c=0;
        if (co_a<0) {
            co_a=(~co_a)+1;
            c+=co_a&1;
            co_a=co_a>>1;
    }
    if (co_b>0) {
            while (co_b!=0) {
                d+=co_b&1;
                co_b=co_b>>1;
            }
        }
        if (co_b==0)
        d=0;
        if (co_b<0) {
            co_b=(~co_b)+1;
            d+=co_b&1;
            co_b=co_b>>1;
    }
    if (c!=d) {
        return d-c;
    }
    else {
       return x-y;
    }
    }
void solve (int t) {
    printf ("\n");
    printf("case #%d:\n", t);
    int n;
    scanf("%d", &n);

    for (int j=0;j<n;j++) {
        scanf("%d", &s[j]);
        //printf ("%d", s[j]);
        scanf (" ");
    }
    qsort (s,n,sizeof(s[0]),cmp);
    for (int k=0;k<n;k++) {
        printf ("%d", s[k]);
        printf (" ");
    }
}
int main () {
    int T;
    scanf ("%d", &T);
    for (int i = 0; i < T; i++)
        solve(i);
    return 0;
}

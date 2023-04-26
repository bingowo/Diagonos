#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int cal(int n)
{
    int j=63;
    int a[64];
    int res=0;
    for (int i = 0; i < 64; ++i) {
        a[i]=(n>>j)&1;
        j--;
    }
    for (int j = 0; j < 64; ++j) {
        if(a[j]==1) res++;
        else continue;
    }
    return res;
}

int cmp(const void *a,const void *b)
{
    int m, n;
    m=*(int *)a;
    n=*(int *)b;
    return cal(m)>cal(n);
}


int main() {
    int t;
    scanf("%d",&t);
    for (int i = 0; i < t; ++i) {
        printf("case #%d:\n",i);
        int n;
        scanf("%d",&n);
        long long a[n];
        for (int j = 0; j < n ; ++j) {
            scanf("%lld",&a[j]);
        }
        qsort(a,n,sizeof(a[0]),cmp);
        for (int j = 0; j < n ; ++j) {
            printf("%d",a[i]);
        }
        printf("\n");
    }
    return 0;
}
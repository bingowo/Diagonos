#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int cal(int n)
{
    int res=0;
    int j=1;
    if(n&j) {
        res++;
        j<<1;
    }
    return res;
}

int cmp(const void *a,const void *b)
{
    int m,int n;
    m=*(int *)a;
    n=*(int *)b;
    return cal(a)>cal(b);
}


int main() {
    int t;
    scanf("%d",&t);
    for (int i = 0; i < t; ++i) {
        printf("case #%d:\n",i);
        int n;
        scanf("%d",&n);
        int a[n];
        for (int j = 0; j < n ; ++j) {
            scanf("%d",&a[j]);
        }
        qsort(a,n,sizeof (a[0]),cmp);
        printf("\n");
    }
    return 0;
}
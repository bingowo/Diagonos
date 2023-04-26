#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int cal(int n)
{
    int res=0;
    int j=1;
    for(int i=0;i<64;i++){
        if(n&j) {
            res++;
        }
        else {
            continue;
        }
        j<<1;
    }
    return res;
}

int cmp(const void *a,const void *b)
{
    int m, n;
    m=*((int *)a);
    n=*((int *)b);
    return cal(m)>cal(n)?1:0;
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
            printf("%lld",a[i]);
        }
        printf("\n");
    }
    return 0;
}
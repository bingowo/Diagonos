#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct num{
    long long int data;
    int total;
}num;


int cal(struct num n)
{
    n.total=0;
    long long int j=1;
    for(int i=0;i<64;i++){
        if(n.data&j) 
            n.total++;
        j<<1;
    }
    return n.total;
}

int cmp(const void *a,const void *b)
{
    struct num m,n;
    m=*((struct num *)a);
    n=*((struct num *)b);
    if (m.total!=n.total) return m.total-n.total;
    else return m.data-n.data;
}


int main() {
    int t;
    scanf("%d",&t);
    for (int i = 0; i < t; ++i) {
        printf("case #%d:\n",i);
        int n;
        scanf("%d",&n);
        struct num a[n];
        for (int j = 0; j < n ; ++j) {
            scanf("%d ",&a[j].data);
        }
        for (int j = 0; j < n ; ++j) {
            cal(a[j]);
        }
        qsort(a,n,sizeof(a[0]),cmp);
        for (int j = 0; j < n ; ++j) {
            printf("%d ",a[j].data);
        }
        printf("\n");
    }
    return 0;
}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct in{
    long long int data;
    int total;
};


int cal(in n)
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
    in m, n;
    m=*((in *)a);
    n=*((in *)b);
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
        in a[n];
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
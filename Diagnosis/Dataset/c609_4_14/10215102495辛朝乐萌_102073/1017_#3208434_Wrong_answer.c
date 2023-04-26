#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int cmp1(const void *a,const void *b)
{
    int m,n;
    m=*((int *)a);
    n=*((int *)b);
    return m-n;
}

int cmp2(const void *a,const void *b)
{
    int m,n;
    m=*((int *)a);
    n=*((int *)b);
    return n-m;
}


int main()
{
    char c;
    scanf("%c",&c);
    int a[10000];
    int n=0;
    while(scanf("%d",&a[n])!=EOF){n++;}

    if (c=='A'){ qsort(a,n,sizeof(a[0]),cmp1);}

    else {
        qsort(a,n,sizeof(a[0]),cmp2);

    }
    for (int i = 0; i < n; ++i) {
        printf("%d ",a[i]);
    }

    return 0;
}

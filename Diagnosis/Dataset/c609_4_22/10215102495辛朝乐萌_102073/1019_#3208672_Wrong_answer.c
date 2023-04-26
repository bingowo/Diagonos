#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int cal(int n)
{
    if (n<0) n=-n;
    int num=0;
    while (n!=0){
        num++;
        n=n/10;
    }
    return num;
}

int cmp(const void *a,const void *b)
{
    int m,n;
    m=*((int *)a);
    n=*((int *)b);
    return cal(m)- cal(n);
}

int main()
{
    int a[100000];
    int n=0;
    while (scanf("%d",&a[n])!=EOF){n++;}
    qsort(a,n,sizeof(a[0]),cmp);
    for (int i = 0; i < n; ++i) {
        scanf("%d ",a[i]);
    }
    
    return 0;
}
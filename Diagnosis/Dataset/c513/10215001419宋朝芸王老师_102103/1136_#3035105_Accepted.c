#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 20001

int cmp(const void *a, const void *b){
    return *(int*)a - *(int*)b;
}

int main()
{
    int n,zero,k = 0;
    scanf("%d",&n);

    int a[N] = {0}, b[N] = {0}, res[N];
    for(int i = 0; i < n; i++)
        scanf("%d",&a[i]);

    for(int i = 0; i < n; i++)
        if(a[i] == 0) b[k++] = i;
    zero = k;

    for(int i = 0; i < n; i++)
        if(a[i] == 1) b[k++] = i;

    for(int i = 0, t = b[0]; i < n; i++){
        res[i] = a[t];
        t = b[t];
    }

    int nzero = 0;
    for(int i = 0; i < n; i++)
        if(res[i] == 0) nzero++;

    //case 1
    if(nzero != zero) {printf("-1\n");return 0;}
    //case other
    else for(int i = 0; i < n; i++){
        if(i == 0) printf("%d",res[i]);
        else printf(" %d",res[i]);
    }


    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a,const void *b){
    int *a1 = (int*)a;
    int *b1 = (int*)b;
    return *a1 - *b1;
}

int main()
{
    int n;
    scanf("%d",&n);
    int *a = (int*)malloc(n * sizeof(int));
    for(int i = 0;i < n;i++){
        scanf("%d",&a[i]);
    }
    qsort(a,n,sizeof(int),cmp);
    int ans = 0;
    for(int i = 0;i < n/2;i++){
        ans += a[2 * i + 1] - a[2 * i];
    }
    printf("%d",ans);
    return 0;
}

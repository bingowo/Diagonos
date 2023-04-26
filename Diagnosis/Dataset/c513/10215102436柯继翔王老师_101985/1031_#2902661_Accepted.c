#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a,const void *b){
    int *a1 = (int*)a,*b1 = (int*)b;
    return *a1 - *b1;
}

int main()
{
    int T,n,a[1000],b[1000],ans;
    scanf("%d",&T);
    for(int i = 0;i < T;i++){
        scanf("%d",&n);
        for(int j = 0;j < n;j++){
            scanf("%d",&a[j]);
        }
        for(int j = 0;j < n;j++){
            scanf("%d",&b[j]);
        }
        qsort(a,n,sizeof(a[0]),cmp);
        qsort(b,n,sizeof(b[0]),cmp);
        ans = 0;
        for(int j = 0;j < n;j++){
            ans += a[j] * b[n - 1 - j];
        }
        printf("case #%d:\n",i);
        printf("%d\n",ans);
    }
    return 0;
}

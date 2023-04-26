#include <stdio.h>
#include <stdlib.h>
#define MAXN 10000
int cmp(const void*a, const void*b)
{
    int* p1 = (int*)a;
    int* p2 = (int*)b;
    int cnt1 = 0, cnt2 = 0;

    for (; *p1 != 0; *p1 /= 2){
        if((*p1 & 1) == 1)
        cnt1++;
    }
    for (;*p2 != 0; *p2 /= 2){
        if((*p2 &1) == 1)
        cnt2++;
    }
    return cnt1 - cnt2;
}
int main()
{
    int t, n;

    scanf("%d", &t);
    for (int i = 0; i < t; i++){
        scanf("%d", &n);
        int a[n];
        for (int j = 0; j < n; j++){
            scanf("%d",&a[j]);
        }
        qsort(a,n,sizeof(a[0]),cmp);
        printf("case #%d:\n",i);
        for (int j = 0; a[j]; j++){
            printf("%d ", a[j]);
        }
    }
}

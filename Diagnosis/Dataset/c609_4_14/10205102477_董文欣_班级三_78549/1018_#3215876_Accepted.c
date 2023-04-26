#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int val[100001];
int cmp (const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}

//先排序，然后相邻的两个数之间肯定是最小的差，相加即可
int main()
{
    //输入
    int n;
    scanf("%d",&n);

    memset(val,0,sizeof(val));
    for (int i = 0; i < n; i++) {
        scanf ("%d",&val[i]);
    }

    qsort(val,n,sizeof(val[0]),cmp);

    int ans = 0;
    for (int i = 1; i < n; i+=2) {
        ans+= val[i] - val[i-1];
    }

    printf("%d\n",ans);
    return 0;
}

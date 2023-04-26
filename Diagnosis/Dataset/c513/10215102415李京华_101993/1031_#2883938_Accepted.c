#include <stdio.h>
#include <stdlib.h>

//升序
int cmp1(const void*a, const void*b){
    return *((int *)a) - *((int *)b); 
}
//降序
int cmp2(const void*a, const void*b){
    return *((int *)b) - *((int *)a);
}


int main()
{
    int t, T;
    scanf("%d", &T);
    for (t = 0; t < T; t++){
        int n;
        scanf("%d", &n);
        int a[n], b[n];
        int i;
        //输入
        for (i = 0; i < n; i++)
            scanf("%d", &a[i]);
        for (i = 0; i < n; i++)
            scanf("%d", &b[i]);        

        //排序
        qsort(a, n, sizeof(a[0]), cmp1);
        qsort(b, n, sizeof(b[0]), cmp2);

        //计算
        int ans = 0;
        for (i = 0; i < n; i++)
            ans += a[i] * b[i];

        //debug

        //输出
        printf("case #%d:\n", t);
        printf("%d\n", ans);
    }
    return 0;
}
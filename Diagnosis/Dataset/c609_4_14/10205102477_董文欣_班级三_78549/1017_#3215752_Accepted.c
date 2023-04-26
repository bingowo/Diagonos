#include <stdio.h>
#include <stdlib.h>

int cmp_A (const void *a, const void *b) {
    return *(int*)a - *(int*)b; //从小到大
}

int cmp_D (const void *a, const void *b) {
    return *(int*)b - *(int*)a; //从大到小
}

int main()
{
    char c;
    scanf("%c",&c);
    int a[101]={0};
    int i = 0;
    while (scanf("%d",&a[i]) != EOF) {i++;}
    int n = i; //整数个数
    //输出
    if (c == 'A') {
        qsort (a,n,sizeof(a[0]),cmp_A);
        for (i = 0; i < n; i++) {
            while (a[i+1] == a[i]) i++;
            printf("%d ",a[i]);
        }
    }

    if (c == 'D') {
        qsort (a,n,sizeof(a[0]),cmp_D);
        for (i = 0; i < n; i++) {
            while (a[i+1] == a[i]) i++;
            printf("%d ",a[i]);
        }
    }
    return 0;
}

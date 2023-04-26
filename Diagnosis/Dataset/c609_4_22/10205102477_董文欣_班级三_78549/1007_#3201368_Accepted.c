#include <stdio.h>
#include <stdlib.h>

struct data {
    long long int a; //整数
    int cnt; //64位二进制补码表示中1的位数
};

int cmp(const void *a,const void *b) {
    struct data d1,d2;
    d1 = *((struct data *)a);
    d2 = *((struct data *)b);
    if (d2.cnt != d1.cnt) return d2.cnt - d1.cnt;
    else {
        if (d1.a > d2.a) return 1;
        else return -1;
    }
}

int main()
{
    int T;
    scanf("%d",&T);

    for (int i = 0; i < T; i++) {
        struct data p[10000];
        int n;
        scanf("%d",&n);
        for (int j = 0; j < n; j++) {
            scanf("%lld",&p[j].a);
            p[j].cnt = 0;
            long long int tmp = 1;
            for (int k = 0; k < 64; k++) {
                if (p[j].a & tmp) p[j].cnt++; //与1相与结果为1说明末尾数字为1
                tmp = tmp << 1; //左移一位
            }
        }

        qsort(p,n,sizeof(p[0]),cmp);

        printf("case #%d:\n",i);
        for (int j = 0; j < n; j++) {
            printf("%lld ",p[j].a);
        }
        printf("\n");
    }
    return 0;
}

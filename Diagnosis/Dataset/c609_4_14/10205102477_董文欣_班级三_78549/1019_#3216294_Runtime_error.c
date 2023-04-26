#include <stdio.h>
#include <stdlib.h>

struct data {
    int val; //整数值
    int cnt; //位数
}num[101];

int cmp (const void *a, const void *b) {
    struct data *a1 = (struct data *)a;
    struct data *b1 = (struct data *)b;
    if (a1->cnt != b1->cnt) {
        return b1->cnt - a1->cnt;
    }
    return a1->val - b1->val;
}

int main()
{
    int n = 0;//表示整数个数
    while (scanf("%d",&num[n].val) != EOF) {n++;}
    //printf("%d\n",n);

    //计算整数的位数
    for (int i = 0; i < n; i++) {
        int number = 0;
        int tmp = num[i].val;
        while (tmp) {
            tmp /= 10;
            number++;
        }
        num[i].cnt = number;
        //printf("%d ",number);
        //printf("\n");
    }

    qsort(num,n,sizeof(num[0]),cmp);

    for (int i = 0; i < n; i++) {
        printf("%d ",num[i].val);
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct liist {
    long long num1 = 0;
    long long digit = 0;
} Liist;

struct liist L[1000];

int cmp(const void *a, const void *b) {
    struct liist *A = (Liist *) a;
    struct liist *B = (Liist *) b;
    if (A->num1 != B->num1) {
        return (int) (B->num1 - A->num1);//big first <0
    } else {
        return (int) (A->digit - B->digit);//small first > 0
    }
}

int main() {
    int set = 0;
    scanf("%d", &set);
    for (int i = 0; i < set; i++) { //不同的组数
        int rangenum = 0;//一共有多少数字
        scanf("%d", &rangenum);
        for (int j = 0; j < rangenum; j++) {
            int flag = 0;
            long long figure = 0;
            scanf("%lld", &figure);
            //初始化十转二
            long long temp[64];
            for (int k = 0; k < 64; k++) {
                temp[k] = 0;
            }


            L[j].digit = figure;
            if (figure < 0) {//需要取反加一
                figure = -figure;
                flag = 1;
            }
            //十转二
            int idx = 0;
            while (figure > 0) {
                temp[idx] = figure % 2;
                figure = figure / 2;
                idx++;
            }
            int carry = 1;
            if (flag == 1) {
                //reverse
                for (int m = 0; m < 64; m++) {
                    if (temp[m] == 0) {
                        temp[m] = 1;
                    } else {
                        temp[m] = 0;
                    }
                }
                //plus 1
                for (int n = 0; n <= 64; n++) {
                    if (temp[n] == 1 && carry == 1) {
                        temp[n] = 0;
                        carry = 1;
                    } else if (temp[n] == 0 && carry == 1) {
                        temp[n] = 1;
                        carry = 0;
                    } else if (temp[n] == 0 && carry == 0) {
                        temp[n] = 0;
                        carry = 0;
                    } else if (temp[n] == 1 && carry == 0) {
                        temp[n] = 1;
                        carry = 0;
                    }
                }
            }

            int one = 0;
            for (int s = 0; s < 64; s++) {
                if (temp[s] == 1) {
                    one++;
                }
            }
            L[j].num1 = one;

        }
        qsort(L, rangenum, sizeof(L[0]), cmp);
        printf("case #%d:\n", i);
        for (int kk = 0; kk < rangenum; kk++) {
            printf("%lld ", L[kk].digit);
        }
        printf("\n");

    }


}
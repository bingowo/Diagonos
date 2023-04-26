#include<stdio.h>
#include<string.h>

#define N 500

typedef struct {
    int cnt, v[N];
} BIGINT;

int main() {
    char m[500], n[500], z[500];
    char ss[1200];
    while (gets(ss) && ss[0]!=0) {
        BIGINT S = {0, {0}}, T = {0, {0}}, R = {0, {0}};
        int bb = 0;
        while ((m[bb] =ss[bb]) != ' ')
            bb++;
        m[bb]='\0';
        bb++;
        int cc=0;
        while ((n[cc]=ss[bb]) !='\0') {
            cc++;
            bb++;
        }
        n[cc]='\0';
        int l1 = strlen(m), l2 = strlen(n);
        if (l1 < l2) {
            printf("-");
            strcpy(z, n);
            strcpy(n, m);
            strcpy(m, z);
        }//判断大小并完成交换
        else if (l1 == l2) {
            for (int i = 0; i < l1; i++)
                if ((m[i] - '0') < (n[i] - '0')) {
                    printf("-");
                    strcpy(z, n);
                    strcpy(n, m);
                    strcpy(m, z);
                    break;
                }
        }
        S.cnt = strlen(m);
        T.cnt = strlen(n);
        for (int i = 0; i < S.cnt; i++)S.v[S.cnt - 1 - i] = m[i] - '0';
        for (int j = 0; j < T.cnt; j++)T.v[T.cnt - 1 - j] = n[j] - '0';
        while (T.cnt < S.cnt)T.v[T.cnt++] = 0;//补0
        for (int i = 0; i < S.cnt; i++) {
            if (S.v[i] >= T.v[i]) { R.v[i] = S.v[i] - T.v[i]; }
            else {
                R.v[i] = S.v[i] - T.v[i] + 10;
                S.v[i + 1]--;
            }
        }
        R.cnt = S.cnt;
        while (R.v[R.cnt - 1] == 0)R.cnt--; //最高位0不统计在一个大整数的位数
        for (int i = R.cnt - 1; i >= 0; i--)printf("%d", R.v[i]);
        printf("\n");
    }
    return 0;
}
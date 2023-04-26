#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    int *aa = (int *)a;
    int *bb = (int *)b;
    int cmp1 = bb[0] - aa[0];
    int cmp2 = bb[1] - aa[1];
    int cmp3 = aa[2] - bb[2];
    int cmp4 = aa[3] - bb[3];
    if (cmp1) return cmp1;
    else if (cmp2) return cmp2;
    else if (cmp3) return cmp3;
    else return cmp4;
}


int main()
{
    int n,m; // n代表球队数量， m代表比赛场数。
    while (scanf("%d %d",&n,&m) != EOF && n != 0) {
        int a,b,c;
        int point[n+1][4];
        for (int i = 1; i <= n; i++) {
            point[i][0] = 0;//积分
            point[i][1] = 0;//胜场数
            point[i][2] = 0;//负场数
            point[i][3] = i;//编号
        }

        for (int i = 0; i < m; i++) {
            scanf("%d %d %d", &a, &b, &c);
            if (c == 1) {//a胜b
                point[a][0] += 3;
                point[a][1]++;
                point[b][0]--;
                point[b][2]++;

            }
            if (c == -1) {//b胜a
                point[b][0] += 3;
                point[b][1]++;
                point[a][0]--;
                point[a][2]++;
            }
            if (c == 0) {//平局
                point[a][0]++;
                point[b][0]++;
            }
        }

        qsort(point+1, n, sizeof(point[0]), cmp);

        for (int i = 1; i <= n; i++) {
            printf("%d ", point[i][3]);
        }
        printf("\n");
    }
    return 0;
}

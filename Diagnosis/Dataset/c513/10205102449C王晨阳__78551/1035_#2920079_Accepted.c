#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b);

int cmp1(const void *a, const void *b);

int cmp2(const void *a, const void *b);

int main() {
    int n, m;
    long long a[1000][3];
    long long sum = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%lld %lld", &a[i][0], &a[i][1]);
        a[i][2] = 2 * a[i][0] * a[i][1];
    }
    qsort(a, n, sizeof(a[0]), cmp1);
    for (int j = 0; j < m; j++)
        sum += a[j][2];
    qsort(a, m, sizeof(a[0]), cmp);
    long long r_min = a[0][2];
    for (int l = 1; l < m; l++) {
        if (a[l][2] < r_min)
            r_min = a[l][2];
    }
    long long temp = 0;
    for (int k = m; k < n; k++) {
        if (a[k][0] >= a[0][0] && (a[k][2] + a[k][0] * a[k][0]) > (r_min + a[0][0] * a[0][0]) &&
            a[k][2] + a[k][0] * a[k][0] > temp) {
            temp = a[k][2] + a[k][0] * a[k][0];
        }
    }
    if (temp) {
        sum -= r_min;
        sum += temp;
    } else
        sum += a[0][0] * a[0][0];
    printf("%lld", sum);
    return 0;
}

int cmp(const void *a, const void *b) {
    if (((long long *) a)[0] == ((long long *) b)[0]) //对半径进行排序,半径一样，侧面积小的排前
    {
        if (((long long *) a)[2] <= ((long long *) b)[2])
            return -1;
        else return 1;
    } else if (((long long *) b)[0] < ((long long *) a)[0])
        return -1;
    else
        return ((long long *) b)[0] - ((long long *) a)[0];
}

int cmp1(const void *a, const void *b) {
    if (((long long *) b)[2] < ((long long *) a)[2])   //对侧面积进行排序
        return -1;
    else return 1;
}

int cmp2(const void *a, const void *b)  //对侧面积和底面积之和排序
{
    if (2 * ((long long *) b)[0] * ((long long *) b)[1] + ((long long *) b)[0] * ((long long *) b)[0] <=
        (2 * ((long long *) a)[0] * ((long long *) a)[1] + ((long long *) a)[0] * ((long long *) a)[0]))
        return -1;
    else return 1;
}
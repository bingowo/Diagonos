#include<stdio.h>
#include<stdlib.h>

typedef struct{
    long long x;
    long long y;
    unsigned long long dis;
}point;


void Input(point *arr, int n){
    for (int i = 0; i != n; ++i){
        scanf("%lld%lld", &arr[i].x, &arr[i].y);
        arr[i].dis = (unsigned long long)llabs(arr[i].x) + llabs(arr[i].y);
    }
}

int cmp(const void *p1, const void *p2){
    point p_1 = *(point*)p1, p_2 = *(point*)p2;
    if (p_1.dis == p_2.dis){
        if (p_1.x == p_2.x)
            return (p_1.y > p_2.y? 1: -1);
        return (p_1.x > p_2.x? 1: -1);
    }
    return (p_1.dis < p_2.dis? 1: -1);
}

unsigned long long cal_dis(long long n, long long m){
    unsigned long long res = 0;
    if ((m > 0 && n < 0) || (m < 0 && n > 0))
        res = (unsigned long long)llabs(m) + llabs(n);
    else res = llabs(n - m);
    return res;
}

unsigned long long sort(point *arr, int n){
    qsort(arr, n, sizeof(point), cmp);
    return cal_dis(arr[0].x, arr[1].x) + cal_dis(arr[0].y, arr[1].y);
}

int cal_step_p2p(point p_1, point p_2){
    unsigned long long x = cal_dis(p_1.x, p_2.x), y = cal_dis(p_1.y, p_2.y);
    unsigned long long dis = x + y;
    if (dis == 0) return 0;
    if (dis % 2 == 0) return -1;
    int cnt = 0;
    while(dis){
        dis >>= 1;
        ++cnt;
    }
    return cnt;
}

int cal_step(point *arr, int n){
    int res = 0;
    for (int i = 0; i != n - 1; ++i){
        int temp = cal_step_p2p(arr[i], arr[i + 1]);
        if (temp == -1) return res;
        res += temp;
    }
    return res;
}

int main(){
    int n; scanf("%d", &n);
    point arr_pt[100];
    Input(arr_pt, n);
    printf("%llu\n", sort(arr_pt, n));
    printf("%d\n", cal_step(arr_pt, n));
    return 0;
}
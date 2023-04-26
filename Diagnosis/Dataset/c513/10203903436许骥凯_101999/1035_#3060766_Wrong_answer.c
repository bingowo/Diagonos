#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int R;
    int H;
    long long lateral;
    long long area;
}cylinder;

void Input(cylinder * arr, int n){
    for (int i = 0; i != n; ++i){
        scanf("%d%d", &arr[i].R, &arr[i].H);
        arr[i].lateral = (long long)arr[i].H * arr[i].R * 2;
        arr[i].area = (long long)arr[i].R * arr[i].R + arr[i].lateral;
    }
}

unsigned long long cal_area(cylinder *arr, int m, int max_r){
    unsigned long long res = 0;
    for (int i = 0; i != m; ++i)
        res += arr[i].lateral;
    res += max_r;
    return res;
}

unsigned long long exchange(cylinder *arr, int lo, int hi, int max_r, unsigned long long res){
    for (int i = lo; i != hi; ++i){
        if (arr[i].R <= max_r) return res;
        long long dis = arr[i].area - max_r * max_r;
        if (dis > arr[lo - 1].lateral){
            res = res + dis - arr[lo - 1].lateral;
            arr[lo - 1].lateral = arr[i].lateral;
            max_r = arr[i].R;
        }
    }
    return res;
}

int cmp_by_lateral(const void *p1, const void *p2){
    cylinder cy_1 = *(cylinder*)p1, cy_2 = *(cylinder*)p2;
    return ((cy_1.lateral < cy_2.lateral)? 1: -1);
}

int cmp_by_R_D(const void *p1, const void *p2){
    cylinder cy_1 = *(cylinder*)p1, cy_2 = *(cylinder*)p2;
    return cy_2.R - cy_1.R;
}

int cmp_by_R_A(const void *p1, const void *p2){
    return cmp_by_R_D(p2, p1);
}

void Print(cylinder *arr, int n){
    for (int i = 0; i != n; ++i){
        printf("%llu %d\n", arr[i].lateral, arr[i].R);
    }
}

int find_max(cylinder* arr, int m){
    int res = 0;
    for (int i = 0; i != m; ++i)
        if (arr[i].R > res) res = arr[i].R;
    return res;
}

unsigned long long process(cylinder *arr, int n, int m){
    qsort(arr, n, sizeof(cylinder), cmp_by_lateral);
    int cyl_bottom_r = find_max(arr, m);
    unsigned long long res = cal_area(arr, m, cyl_bottom_r);
    qsort(arr + m, n - m, sizeof(cylinder), cmp_by_R_D);
    return exchange(arr, m, n, cyl_bottom_r, res);
}

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    cylinder arr_cyl[1000];
    Input(arr_cyl, n);
    printf("%llu\n", process(arr_cyl, n, m));
    return 0;
}
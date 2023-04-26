#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int R;
    int H;
    unsigned long long lateral;
    unsigned long long area;
}cylinder;

void Input(cylinder * arr, int n){
    for (int i = 0; i != n; ++i){
        scanf("%d%d", &arr[i].R, &arr[i].H);
        arr[i].lateral = (unsigned long long)arr[i].H * arr[i].R * 2;
        //printf("%llu\n", arr[i].lateral);
        arr[i].area = (unsigned long long )arr[i].R * arr[i].R + arr[i].lateral;
    }
}

unsigned long long cal_area(cylinder *arr, int m){
    unsigned long long res = 0;
    for (int i = 0; i != m - 1; ++i)
        res += arr[i].lateral;
    res += arr[m -1].area;
    return res;
}

unsigned long long exchange(cylinder *arr, int lo, int hi, unsigned long long res){
    int R = arr[lo - 1].R;
    unsigned long long area = arr[lo - 1].area;
    for (int i = lo; i != hi; ++i){
        if (arr[i].R <= R) return res;
        if (arr[i].area <= area) continue;
        res += arr[i].area - area;
        area = arr[i].area;
    }
    return res;
}

int cmp_by_lateral(const void *p1, const void *p2){
    cylinder cy_1 = *(cylinder*)p1, cy_2 = *(cylinder*)p2;
    return (cy_1.lateral < cy_2.lateral)? 1: -1;
}

int cmp_by_R_D(const void *p1, const void *p2){
    cylinder cy_1 = *(cylinder*)p1, cy_2 = *(cylinder*)p2;
    return cy_2.R - cy_1.R;
}

int cmp_by_R_A(const void *p1, const void *p2){
    return cmp_by_R_D(p2, p1);
}

// void Print(cylinder *arr, int n){
//     for (int i = 0; i != n; ++i){
//         printf("%llu %d\n", arr[i].lateral, arr[i].R);
//     }
// }

unsigned long long process(cylinder *arr, int n, int m){
    qsort(arr, n, sizeof(cylinder), cmp_by_lateral);
    //Print(arr, n);
    qsort(arr, m ,sizeof(cylinder), cmp_by_R_A);
    //Print(arr, m);
    unsigned long long res = cal_area(arr, m);
    qsort(arr + m, n - m, sizeof(cylinder), cmp_by_R_D);
    return exchange(arr, m, n, res);
}

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    cylinder arr_cyl[1000];
    Input(arr_cyl, n);
    //Print(arr_cyl, n);
    printf("%llu\n", process(arr_cyl, n, m));
    return 0;
}
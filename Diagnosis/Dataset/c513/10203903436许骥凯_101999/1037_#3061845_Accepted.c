#include<stdio.h>
#include<stdlib.h>

void Input(long long *arr, int n){
    for (int i = 0; i != n; ++i)
        scanf("%lld", &arr[i]);
}

int cmp(const void *p1, const void *p2){
    long long ll_1 = *(long long *)p1, ll_2 = *(long long *)p2;
    return (ll_1 > ll_2? 1: -1);
}

long long cal_sub_sum(long long *arr, int n, long long subbed){
    long long res = 0;
    for (int i = 0; i != n; ++i)
        res += subbed - arr[i];
    return res;
}

// void Print(long long *arr, int n){
//     for (int i = 0; i != n; ++i)
//         printf("%lld ", arr[i]);
//     printf("\n");
// }

long long cal(long long *arr, int n, int m){
    //Print(arr, n);
    long long res = 0, subbed = arr[m - 1];
    res = cal_sub_sum(arr, m - 1, subbed);
    long long temp = res;
    for (int i = m; i != n; ++i){
        temp = temp - (subbed - arr[i - m]) + (m - 1) * (arr[i] - subbed);
        if (temp < res)
            res = temp;
        subbed = arr[i];
    }
    return res;
}


int main(){
    int n, m; scanf("%d%d", &n, &m);
    long long *arr_num = (long long *)malloc(sizeof(long long) * n);
    Input(arr_num, n);
    qsort(arr_num, n, sizeof(long long), cmp);
    printf("%lld\n", cal(arr_num, n, m));
    free(arr_num);
    return 0;
}
#include<stdio.h>
#include<stdlib.h>

typedef struct{
    char ch;
    int cnt;
}my_char;

int resolute_ch(const char *s, my_char *res){
    int len = 0;
    res[len].ch = s[0];
    res[len++].cnt = 1;
    for (int i = 1; s[i]; ++i)
        if (s[i] != s[i - 1]){
            res[len].ch = s[i];
            res[len++].cnt = 1;
        }
        else ++res[len - 1].cnt;
    return len;
}

int impossible(my_char *s, my_char *t, int len){
    for (int i = 0; i != len; ++i)
        if (s[i].ch != t[i].ch) return 1;
    return 0;  
}

int abs(int a){
    return (a >= 0? a: -a);
}

int min(int a, int b){
    return (a > b? b: a);
}

int cmp(const void *p1, const void *p2){
    return *(int *)p1 - *(int *)p2;
}

void cal_mid(my_char (*arr)[100], int index, int n, int *mid_1, int *mid_2){
    int *num = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i != n; ++i)
        num[i] = arr[i][index].cnt;
    qsort(num, n, sizeof(int), cmp);
    *mid_1 = num[n / 2]; *mid_2 = num[n / 2 + n % 2];
    free(num);
}


int cal_total_step(my_char (*arr)[100], int row, int col){
    int res_1 = 0, res_2 = 0;
    for (int i = 0; i != col; ++i){
        int mid_1, mid_2;
        cal_mid(arr, i, row, &mid_1, &mid_2);
        for (int j = 0; j != row; ++j){
            res_1 += abs(arr[j][i].cnt - mid_1);
            res_2 += abs(arr[j][i].cnt - mid_2);
        }
    }
    return min(res_1, res_2);
}

int main(){
    int n; scanf("%d", &n);
    my_char (*arr)[100] = (my_char (*)[100]) malloc(sizeof(my_char[100]) * n);
    char s[101]; scanf("%s", s);
    int each_len = resolute_ch(s, arr[0]), i = 1;
    for (; i != n; ++i){
        scanf("%s", s);
        int temp_len = resolute_ch(s, arr[i]);
        if (each_len != temp_len || impossible(arr[i - 1], arr[i], each_len)){
            printf("-1\n");
            break;
        }
    }
    if (i == n) printf("%d\n", cal_total_step(arr, n, each_len));
    free(arr);
    return 0;
}
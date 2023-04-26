#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char first_bit;
    long long value;
} MyInt;

int cmp(const void *p1, const void *p2){
    MyInt mI_1 = *(MyInt*)p1, mI_2 = *(MyInt*)p2;
    if (mI_1.first_bit == mI_2.first_bit)
        return (mI_1.value > mI_2.value ? 1 : -1);
    return mI_2.first_bit - mI_1.first_bit;
}

int main() {
    int T;
    scanf("%d", &T);
    for (int i = 0; i != T; ++i){
        int n;
        scanf("%d", &n);
        MyInt* arr_mt = (MyInt*)malloc(sizeof(MyInt) * n);
        for (int j = 0; j != n; ++j) {
            char s[20];
            scanf("%s", s);
            arr_mt[j].value = atoll(s);
            if (s[0] == '-')
                arr_mt[j].first_bit = s[1];
            else
                arr_mt[j].first_bit = s[0];
        }
        qsort(arr_mt, n, sizeof(MyInt), cmp);
        printf("case #%d:\n", i);
        for (int j = 0; j != n; ++j)
            printf("%lld%c", arr_mt[j].value, j == n - 1 ? '\n' : ' ');
    }
    return 0;
}
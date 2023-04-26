#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int v[51];
    int cnt;
}Row;

int cmp(const void *p1, const void *p2){
    Row r_1 = *(Row*)p1, r_2 = *(Row*)p2;
    int i = 0;
    for (; i != r_1.cnt && i != r_2.cnt && r_1.v[i] == r_2.v[i]; ++i);
    if (i != r_1.cnt && i != r_2.cnt)
        return r_2.v[i] - r_1.v[i];
    else if (i != r_1.cnt)
        return -1;
    else return 1;
}

int main(){
    int T; scanf("%d", &T);
    for (int i = 0; i != T; ++i){
        Row nums[1000];
        int n; scanf("%d", &n);
        for (int j = 0; j != n; ++j){
            nums[j].cnt = 0;
            while(1){
                scanf("%d", &(nums[j].v[nums[j].cnt]));
                if (nums[j].v[nums[j].cnt] == -1)
                    break;
                else ++nums[j].cnt;
            }
        }
        qsort(nums, n, sizeof(Row), cmp);
        for (int j = 0; j != n; ++j)
            for (int k = 0; k != nums[j].cnt; ++k)
                printf("%d%c", nums[j].v[k], k == nums[j].cnt - 1? '\n': ' ');
    }
    return 0;
}
#include <stdio.h>
#include<stdlib.h>

struct number {
    long long int value;
    int cnt_of_1;
};
int get_cnt(long long int a) {
    long long int d = 1;
    int number = 0;
    for (int t = 0; t < 64; t++)
    {
        if (a & d) number++;
        d = d << 1;
    }
    return number;

}

int cmp(struct number a, struct number b) {
    if (a.cnt_of_1 == b.cnt_of_1) return (a.value < b.value);
    return (a.cnt_of_1 > b.cnt_of_1);
    
}
int main() {

    int n, i, j;
    long long int x;
    scanf("%d",&n);
    number obj[10001];
    for (i = 0; i < n; i++) {
        int num;
        scanf("%d",&num);
        for (j = 0; j < num; j++) {
            scanf("%d",&x);
            obj[j].value = x;
            obj[j].cnt_of_1 = get_cnt(x);
        }
        getchar();
        sort(obj, obj + num, cmp);
        printf("case #%d:\n",i);
        for (j = 0; j < num; j++)
            printf("%d ",obj[j].value)
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stu {
    char number[11];
    int score;
};
struct stu STU[501];

long long my_atoi(char *a) {
    int y = 0;
    long long temp, sum = 0;
    while (a[0] == '0')
        y++;
    for (; y < strlen(a); y++) {
        temp = a[y] - '0';
        sum = sum * 10 + temp;
    }
    return sum;
}

int cmp(const void *a, const void *b) {
    struct stu *a1 = (struct stu *) a, *b1 = (struct stu *) b;
    if (a1->score != b1->score)
        return b1->score - a1->score;
    else {
        if (my_atoi(a1->number) > my_atoi(b1->number))
            return 1;
        return -1;
    }
}

int main() {
    int T;
    scanf("%d",&T);
    for (int t = 0; t < T; t++) {
        int N, M, G;
        scanf("%d%d%d", &N, &M, &G);
        int s[M];
        int S;
        s[0] = 0;
        for (int x = 0; x < N; x++)
            STU[x].score = 0;
        for (int i = 1; i <= M; i++) {
            scanf("%d", &s[i]);
        }
        for (int j = 0; j < N; j++) {
            scanf("%s", STU[j].number);
            scanf("%d", &S);
            int c[S];
            for (int k = 0; k < S; k++) {
                scanf("%d", &c[k]);
                STU[j].score += s[c[k]];
            }
        }
        qsort(STU, N, sizeof(STU[0]), cmp);
        int count;
        for (int z = 0; ; z++) {
            if (STU[z].score < G){
                count = z;
                break;
            }
            else
                continue;
        }
        printf("case #%d:\n%d\n",t,count);
        for (int z = 0; z < count; z++) {
            printf("%s %d\n",STU[z].number,STU[z].score);
        }
    }


}
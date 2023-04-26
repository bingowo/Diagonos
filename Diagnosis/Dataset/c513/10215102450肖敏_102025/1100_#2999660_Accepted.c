#include <stdio.h>
#include <string.h>

struct point {
    int a;
    int b;
};

int solution(int t, int r) {
    if (t == 0 && r != 0) return -2;
    if (t == 0 && r == 0) return -1;
    if (r % t != 0 || r / t < 0) return -2;
    return r / t;
}

int main() {
    struct point pos[101];
    char s[101];
    scanf("%s", s);
    int len = strlen(s);
    pos[0].a = pos[0].b = 0;//原点
    for (int i = 1; i <= len; i++) {
        switch (s[i - 1]) {
            case 'U':
                pos[i].a = pos[i - 1].a;
                pos[i].b = pos[i - 1].b + 1;
                break;
            case 'D':
                pos[i].a = pos[i - 1].a;
                pos[i].b = pos[i - 1].b - 1;
                break;
            case 'L':
                pos[i].a = pos[i - 1].a - 1;
                pos[i].b = pos[i - 1].b;
                break;
            case 'R':
                pos[i].a = pos[i - 1].a + 1;
                pos[i].b = pos[i - 1].b;
                break;
        }
    }
    int q, a, b;
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        scanf("%d%d", &a, &b);
        int flag = 0;
        int m1, m2;
        for (int j = 0; j <= len; j++) {
            m1 = solution(-pos[len].a, pos[j].a - a);
            m2 = solution(-pos[len].b, pos[j].b - b);
            if (m1 == -2 || m2 == -2) continue;
            if (m1 == -1 || m2 == -1 || m1 == m2) {
                flag = 1;
                break;
            }
        }
        if (flag == 1)
            printf("Yes\n");
        else
            printf("No\n");
    }

    return 0;
}

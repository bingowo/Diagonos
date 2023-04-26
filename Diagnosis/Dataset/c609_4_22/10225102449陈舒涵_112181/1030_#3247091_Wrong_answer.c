#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char l;
    double f;
} LETTER;

int cmp (const void *a1, const void *b1)
{
    LETTER a = *(LETTER*)a1;
    LETTER b = *(LETTER*)b1;
    if (a.f != b.f){
        if (a.f > b.f) return -1;
        else return 1;
    }
    else {
        return b.l - a.l;
    }
}

int main()
{
    int T;
    char c;
    double st[26];  //st数组用于存储每个字母的使用频率
    scanf("%d", &T);
    LETTER *a = (LETTER*)malloc(sizeof(LETTER) * 100);
    for (int t = 0; t < T; t ++){
        for (int i = 0 ; i < 26; i ++){
            scanf("%lf", &st[i]);
        }
        getchar();
        int n = 0;
        while ((c = getchar()) != '\n'){
            a[n].l = c;
            if (c >= 'A' && c <= 'Z'){
                a[n].f = st[c - 'A'];
            }
            else{
                a[n].f = st[c - 'a'];
            }
            n ++;
        }
        qsort(a, n, sizeof(LETTER), cmp);
        printf("case #%d:\n", t);
        for (int i = 0; i < n; i ++){
            printf("%c", a[i].l);
        }
        printf("\n");
    }
    free(a);
    return 0;
}
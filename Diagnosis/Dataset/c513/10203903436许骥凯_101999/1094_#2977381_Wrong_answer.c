#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 200

typedef struct{
    int cnt, v[N];
}BIG;

BIG StoB(char *s){
    BIG res = {0,{0}};
    int len = strlen(s);
    for (int i = 0; i != len; i++)
        res.v[res.cnt++] = s[len - 1 - i] - '0';
    return res;
}

BIG sub(BIG s1, BIG s2){
    int lend = 0;
    BIG res = {s1.cnt, {0}};
    for (int i = 0; i != s2.cnt; i++){
        int t = s1.v[i] - s2.v[i] - lend;
        res.v[i] = (10 + t) % 10;
        lend = t >= 0? 0: 1;
    }
    for (int i = s2.cnt; i < s1.cnt; i++){
        int t = s1.v[i] - lend;
        res.v[i] = (10 + t) % 10;
        lend = t >= 0? 0: 1;
    }
    if (res.v[res.cnt - 1] == 0) res.cnt--;
    return res;
}

int cmp(const void *p1, const void *p2){
    BIG s1 = *(BIG*)p1, s2 = *(BIG*)p2;
    if (s1.cnt < s2.cnt) return -1;
    else if (s1.cnt == s2.cnt){
        for (int i = s1.cnt - 1; i >= 0; i--){
            if (s1.v[i] > s2.v[i]) return 1;
            else if (s1.v[i] < s2.v[i]) return -1;
        }
        return -1;
    }
    return 1;
}

int main(){
    int n; scanf("%d", &n);
    BIG *vb = (BIG*)malloc(sizeof(BIG) * n);
    for (int i = 0; i != n; i++){
        char s[200]; scanf("%s", s);
        vb[i] = StoB(s);   
    }
    qsort(vb, n, sizeof(vb[0]), cmp);
    BIG res = sub(vb[n-1], vb[0]);
    free(vb);
    for (int i = res.cnt - 1; i >= 0; i--)
        printf("%d", res.v[i]);
    printf("\n");
    return 0;
}
#include<stdio.h>
#include<string.h>
#define N 501

typedef struct{
    int cnt, v[N];
}BIGINT;

BIGINT StoBIG(char* s){
    int len = strlen(s);
    BIGINT temp = {len, {0}};
    for (int i = 0; i != len; i++)
        temp.v[i] = s[len - i - 1] - '0';
    return temp;
}

void exch(BIGINT* b1, BIGINT *b2){
    BIGINT temp = *b1;
    *b1 = *b2;
    *b2 = temp;
}

BIGINT Sub(BIGINT b1, BIGINT b2){
    int flag = 0; 
    if (b1.cnt < b2.cnt){
        flag = 1;
        exch(&b1, &b2);
    }
    else if (b1.cnt == b2.cnt){
        int idx = b1.cnt - 1;
        while(idx >= 0 && b1.v[idx] >= b2.v[idx]) idx--;
        if (idx > 0){
            flag = 1;
            exch(&b1, &b2);
        }
    } 
    BIGINT temp = {b1.cnt, {0}};
    int lend = 0;
    for (int i = 0; i != b2.cnt; i++){
        int t = b1.v[i] - b2.v[i] - lend;
        if (t < 0){
            lend = 1;
            temp.v[i] = 10 + t;
        }
        else{
            lend = 0;
            temp.v[i] = t;
        }
    }
    int k = b2.cnt;
    while(lend){
        int t = b1.v[k] - lend;
        if (t < 0){
            lend = 1;
            temp.v[k++] = 10 + t;
        }
        else{
            lend = 0;
            temp.v[k++] = t;
        }
    }
    while (temp.cnt > 1 && temp.v[temp.cnt-1] == 0) temp.cnt--;
    if (flag) printf("-");
    return temp;
}

int main(){
    char s1[501], s2[501];
    while(scanf("%s%s", s1, s2)){
        BIGINT b1 = StoBIG(s1), b2 = StoBIG(s2);
        BIGINT res = Sub(b1, b2);
        for (int i = res.cnt - 1; i >= 0; i--)
            printf("%d", res.v[i]);
        printf("\n");
    }
    return 0;
}
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
        for (int i = b1.cnt - 1; i >= 0; i--){
            if (b1.v[i] > b2.v[i]) break;
            else if (b1.v[i] < b2.v[i]){
                flag = 1;
                exch(&b1, &b2);
                break;
            }
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

    for(int k = b2.cnt; k < b1.cnt; k++){
        int t = b1.v[k] - lend;
        if (t < 0){
            lend = 1;
            temp.v[k] = 10 + t;
        }
        else{
            lend = 0;
            temp.v[k] = t;
        }
    }
    if (flag) printf("-");
    while (temp.cnt > 1 && temp.v[temp.cnt-1] == 0) temp.cnt--;
    for (int i = temp.cnt - 1; i >= 0; i--)
        printf("%d", temp.v[i]);
    printf("\n");
}

int main(){
    char s1[501], s2[501];
    while(~scanf("%s%s", s1, s2)){
        BIGINT b1 = StoBIG(s1), b2 = StoBIG(s2);
        Sub(b1, b2);
    }
    return 0;
}
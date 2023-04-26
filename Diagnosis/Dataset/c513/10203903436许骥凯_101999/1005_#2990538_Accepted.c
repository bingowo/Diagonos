#include<stdio.h>
#include<string.h>
#define N 200

typedef struct{
    int cnt, v[N];
}BIG;

BIG atoB(char *s){
    int slen = strlen(s);
    BIG res = {0, {0}};
    for (int i = slen - 1; i >= 2; i--)
        res.v[res.cnt++] = s[i] - '0';
    return res;
}

BIG trans(BIG bt){
    BIG res = {bt.cnt * 3, {0}};
    for (int i = 0; i != bt.cnt; i++){
        int carry = bt.v[i];
        for (int j = 0; j != (i + 1) * 3; j++){
            int temp = carry * 10 + res.v[j];
            res.v[j] = temp / 8;
            carry = temp % 8;
        }
    }
    while(res.v[res.cnt-1] == 0) res.cnt--;
    return res; 
}

int main(){
    int pro; scanf("%d", &pro);
    for (int i = 0; i != pro; i++){
        printf("case #%d:\n", i);
        char s[55]; scanf("%s", s);
        BIG res = trans(atoB(s));
        printf("0.");
        for (int i = 0; i != res.cnt; i++)
            printf("%d", res.v[i]);
        printf("\n");
    }
    return 0;
}
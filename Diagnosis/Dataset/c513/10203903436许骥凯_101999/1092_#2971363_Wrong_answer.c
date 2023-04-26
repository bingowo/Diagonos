#include<stdio.h>
#include<string.h>

#define N 200

typedef struct{
    int cnt, v[N];
}BIG;

BIG ItoB(int i){
    BIG res = {0, {0}};
    do{
        res.v[res.cnt++] = i % 10;
        i /= 10;
    }while(i);
    return res;
}

BIG mul(BIG T, int fac){
   BIG res = {T.cnt, {0}};
   int carry = 0;
   for (int i = 0; i != T.cnt; i++){
       int t = fac * T.v[i] + carry;
       res.v[i] = t % 10;
       carry = t / 10;
   } 
   if (carry) res.v[res.cnt++] = carry;
   return res;
}

BIG process(char *s, int len){
    if (len == 0) return ItoB(1);
    BIG res;
    if (s[0] == s[1]) res = ItoB(1);
    else res = ItoB(2);
    for (int i = 1; i < len - 1; i++){
        int item = 3;
        if (s[i] == s[i-1]) item--;
        if (s[i] == s[i+1]) item--;
        res = mul(res, item);
    }
    if (s[len - 1] != s[len - 2]) res = mul(res, 2);
    return res;
}

int main(){
    char s[1001]; scanf("%s", s);
    int len = strlen(s);
    BIG res = process(s, len);
    for (int i = res.cnt - 1; i >= 0; i--)
        printf("%d", res.v[i]);
    printf("\n");
    return 0;
}
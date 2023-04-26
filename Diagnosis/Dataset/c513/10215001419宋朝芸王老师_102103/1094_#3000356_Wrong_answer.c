#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M 122

typedef struct{
    int v[M];
    int cnt;
}BIG;

BIG convert(char *a, int len){
    BIG res = {{0},0};
    res.cnt = len;
    for(int i = len-1; i >= 0; i--){
        res.v[len-1-i] = a[i] - '0';
    }
    return res;
}

int cmp(const void *x, const void *y){  //if same, return 0;
                        //else if a is bigger, return 1; else return -1;
    BIG a = *(BIG*)x, b = *(BIG*)y;
    if(a.cnt != b.cnt) return a.cnt > b.cnt ? 1 : -1;
    for(int i = 0; i < a.cnt; i++){
        if(a.v[i] != b.v[i])
            return a.v[i] > b.v[i] ? 1 : -1;
    }
    return 0;
}

BIG minus(BIG a, BIG b){
    BIG res = {{0},0};
    res.cnt = a.cnt;
    int t,carry = 0;
    for(int i = a.cnt-1; i >= 0; i--){
        if(a.v[i] < b.v[i]) carry = 1;
        t = a.v[i] - b.v[i] + 10*carry;
        res.v[i] = t;
    }
    return res;
}

int main()
{
    int t;
    scanf("%d",&t);

    BIG *big = (BIG*)malloc(t*sizeof(BIG));

    for(int i = 0; i < t; i++){
        char input[M];
        scanf("%s",input);
        big[i] = convert(input,strlen(input));
    }
    qsort(big,t,sizeof(BIG),cmp);

    BIG res = {{0},0};

    res = minus(big[t-1],big[0]);
    for(int i = res.cnt-1; i >= 0; i--)
        printf("%d",res.v[i]);

    return 0;
}

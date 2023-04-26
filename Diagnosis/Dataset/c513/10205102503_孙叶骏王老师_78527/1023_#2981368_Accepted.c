#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct str{
    char s[35];
    long long num;
}S;

int cmp(const void *A, const void *B){
    S Q = *(S*)A;
    S P = *(S*)B;
    if(Q.num ==  P.num) return strcmp(Q.s, P.s);
    else return Q.num - P.num;
}

int main(){
    S strs[105];
    for(int i = 0; i < 105; i++)
        strs[i].num = -1;
    int k = 0;
    while(scanf("%s", strs[k].s)!=EOF){
        int slen = strlen(strs[k].s);
        long long n = 0, flag = 0;
        for(int i = 0; i < slen; i++){
            if(strs[k].s[i]<='9' && strs[k].s[i]>='0'){
                n = n*10 + strs[k].s[i] - 48;
                flag = 1;
            }
        }
        if(flag)
            strs[k++].num = n;
        else
            strs[k++].num = -1;
    }
    qsort(strs, k, sizeof(S), cmp);
    for(int i = 0; i < k; i++)
        printf("%s ", strs[i].s);
    return 0;
}
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

long long mypow(long long a, long long b){
    long long res = a;
    for (int i = 1; i < b; i++){
        res *= a;
    }
    if (b == 0){
        return 1; 
    }
    return res;
}

int main(){
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++){
        char s[65];
        int have[256] = {0};
        long long res = 0;
        scanf("%s", &s);
        int wei = 0, len = 0;//wei是不同位数，len是s长度
        for (int j = 0; j < sizeof(s); j++){
            if (s[j] == '\0') {
                len = j;
                break;
            }
            if (have[s[j]] == 0) {//第一次碰到该符号
                wei++;
                have[s[j]] = wei;
            }
        }
        if (len == 1){//单个符号特判为1
            printf("case #%d:\n1\n", i);
            continue;
        } 
        if (wei == 1){//单种符号特判为二进制
            while (len){
                len--;
                res += pow(2, len);
            }
            printf("case #%d:\n%lld\n", i, res);
            continue;
        }
        int templen = len;
        for (int j = 0; j < templen; j++){
            len--;
            if (have[s[j]] == 2) continue;
            else if (have[s[j]] > 2){
                res += (have[s[j]]-1) * mypow(wei, len);
            }
            else if (have[s[j]] == 1){
                res += mypow(wei, len);
            }
            
        }
        printf("case #%d:\n%lld\n", i, res);
    }
    return 0;
}
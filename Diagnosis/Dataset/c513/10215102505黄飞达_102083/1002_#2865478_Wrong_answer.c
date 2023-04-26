#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++){
        char s[65];
        int have[256] = {0};
        long long res = 0;
        scanf("%s", &s);
        int wei = 0, len = 0;
        for (int j = 0; j < sizeof(s); j++){
            if (s[j] == '\0') {
                len = j;
                break;
            }
            if (have[s[j]] == 0) {
                wei++;
                have[s[j]] = wei;
            }
        }
        if (len == 1){
            printf("case #%d:\n0\n", i);
            continue;
        } 
        int templen = len;
        //printf("wei:%d len:%d\n", wei, len);
        if (wei == 1){
            while (len){
                len--;
                res += pow(2, len);
            }
            printf("case #%d:\n%lld\n", i, res);
            continue;
        }
        for (int j = 0; j < templen; j++){
            len--;
            if (have[s[j]] == 2) continue;
            else if (have[s[j]] > 2){
                res += (have[s[j]]-1) * pow(wei, len);
            }
            else if (have[s[j]] == 1){
                res += pow(wei, len);
            }
            
        }
        printf("case #%d:\n%lld\n", i, res);
    }
    return 0;
}
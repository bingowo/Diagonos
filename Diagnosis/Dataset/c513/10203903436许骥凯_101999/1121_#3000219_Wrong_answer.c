#include<stdio.h>
#include<string.h>
int main(){
    int n; scanf("%d", &n);
    char s[1000] = {0};
    int res[10][2000], rlen = 0, sum = 0;
    res[0][1000] = 1;
    for (int i = 0; i < n; i++, rlen++){
        int t; scanf("%d", &t);
        sum += t;
        for (int j = 0; j != 2000; j++){
            if (res[rlen][j] > 0){
                res[rlen+1][j - t] = res[rlen][j];  
                res[rlen+1][j] = res[rlen][j];
                res[rlen+1][j + t] = res[rlen][j];
            }
        }
    }
    for (int i = 0; i != sum; i++) s[i] = '0';
    for (int i = 1001; i != 2000; i++)
        if (res[n][i]) s[i % 1000 - 1] = '1';
    printf("%s\n", s);
}
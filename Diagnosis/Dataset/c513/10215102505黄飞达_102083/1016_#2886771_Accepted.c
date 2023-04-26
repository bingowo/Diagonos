#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define ll long long

char table[21] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J'};

int main(){
    int n, r, index=0;
    int res[100] = {0};
    scanf("%d %d", &n, &r);
    while(n){
        int mod = n % r;
        n /= r;
        if (mod < 0){
            n++;
            mod -= r;
        }
        res[index++] = mod;
    }
    int i = index - 1;
    while (i>0 && res[i] == 0) i--;
    if (i < 0) printf("0");
    else{
        for (i; i >= 0; i--) printf("%c", table[res[i]]);
    }
    return 0;
}
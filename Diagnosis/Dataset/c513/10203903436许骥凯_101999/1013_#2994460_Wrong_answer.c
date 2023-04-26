#include<stdio.h>
#include<string.h>

int gcd(int a, int b){
    return a == 0? b: gcd(b % a, a);
}

int main(){
    int table[128]; table['0'] = 0, table['1'] = 1, table['2'] = -1;
    char s[100]; scanf("%s", s);
    int i = 0, slen = strlen(s); 
    int resI = 0;
    for (; i < slen && s[i] != '.'; i++)
        resI = resI * 3 + table[s[i]];
    if (s[i] != '.') printf("%d\n", resI);
    else{
        i++;
        int resFz = 0, resFm = 1;
        for (; i < slen; i++){
            resFz = resFz * 3 + table[s[i]];
            resFm *= 3;
        }
        if (resFz < 0 && resI > 0) resI--, resFz += resFm;
        else if (resFz > 0 && resI < 0) resI++, resFz = resFm - resFz;

        if (resI) printf("%d ", resI);
        printf("%d %d\n", resFz, resFm);
    }
    return 0;
}
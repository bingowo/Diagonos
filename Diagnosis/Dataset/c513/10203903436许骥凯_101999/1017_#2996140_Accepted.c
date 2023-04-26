#include<stdio.h>

int main(){
    int table[128];
    table['I'] = 1; table['V'] = 5; table['X'] = 10; table['L'] = 50;
    table['C'] = 100; table['D'] = 500; table['M'] = 1000;
    char s[50]; scanf("%s", s);
    
    long long sc[50]; int slen = 0; 
    long long fac = 1; 
    for (int i = 0; s[i]; i++){
        switch(s[i]){
            case '(': fac *= 1000; break;
            case ')': fac /= 1000; break;
            default: sc[slen++] = table[s[i]] * fac;
        }
    }

    long long res = 0; 
    for (int i = slen - 1; i >= 0; i--){
        res += sc[i];
        if (i == 0) break;
        if (sc[i] > sc[i-1]) res -= sc[--i];
    }
    printf("%lld\n", res);
}
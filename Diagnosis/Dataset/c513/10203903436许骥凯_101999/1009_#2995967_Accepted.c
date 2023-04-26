#include<stdio.h>
#include<string.h>

int gcd(int a, int b){
    return a == 0? b: gcd(b % a, a); 
}
int main(){
    int T; scanf("%d", &T); getchar();
    while(T--){
        char s[120], c; int slen = 0;
        while((c = getchar()) != '\n') s[slen++] = c;
        int Fz = 0, Fm = sizeof(char) * slen * 8;
        for (int i = 0; i != slen; i++){
            for (int j = 0; j != 8; j++){
                if (s[i] & 1) Fz++;
                s[i] >>= 1;
            }
        }
        printf("%d/%d\n", Fz / gcd(Fz, Fm), Fm / gcd(Fz, Fm));
    }
    return 0;
}
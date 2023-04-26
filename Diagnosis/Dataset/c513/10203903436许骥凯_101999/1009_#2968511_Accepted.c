#include<stdio.h>
#include<string.h>

int gcd(int a, int b){
    if (!(b % a)) return a;
    return gcd(b % a, a);
}

int main(){
    int pro; scanf("%d", &pro); getchar();
    for (int i = 0; i != pro; i++){
        char s[200], c; int idx = 0;
        while((c = getchar()) != '\n')
            s[idx++] = c;
        s[idx] = 0;
        int cnt = 0, total = 0;
        for (int i = 0; i != strlen(s); i++){
            unsigned char c = s[i];
            while(c){
                cnt += (c & 1);
                c >>= 1;
            }
            total += 8;
        }
        int mod = gcd(cnt, total);
        printf("%d/%d\n", cnt / mod, total / mod);
    }
    return 0;
}
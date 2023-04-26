#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int count(char c);
int GCD(int m, int n);
int main()
{
    int n;
    scanf("%d", &n);
    char c = getchar();
    while(n-- > 0){
        char* line = (char*)malloc(121*sizeof(char));
        scanf("%[^\n]", line);
        c=getchar();
        int len = strlen(line);
        int cnt = 0;
        int frac = 8*len;
        for(int i = 0; i < len; i++){
            cnt += count(line[i]);
        }
        int gcd = GCD(cnt, frac);
        printf("%d/%d\n", cnt/gcd, frac/gcd);
        free(line);
    }
    return 0;
}
int count(char c){
    int result = 0;
    for(int i = 0; i < 8; i++){
        if(( (int)c >> i) & 1){
            result ++;
        }
    }
    return result;
}
int GCD(int m, int n){
    int bigger = (m>=n)? m : n;
    int smaller = (m>=n)? n : m;
    int mod = bigger % smaller;
    if(mod == 0){
        return smaller;
    }
    return GCD(smaller, mod);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char base[64];
void setBase(void){
    for(int i=0; i<26; ++i) base[i] = 'A' + i;
    for(int i=26; i<52; ++i) base[i] = 'a'+i-26;
    for(int i=52; i<62; ++i) base[i] = '0'+i-52;
    base[62] = '+'; base[63] = '/';
}

int main()
{
    int T;
    scanf("%d",&T);
    getchar();
    setBase();
    for(int j=0; j<T; ++j) {
        char s[101];
        gets(s);
        int b[805] = {0};
        for(int i=0; s[i]; ++i) {
            int n = (int)s[i];
            for(int k=i*8+7; k>=8*i; --k){
                b[k] = n % 2;
                n /= 2;
            }
        }
        printf("case #%d:\n", j);
        int cnt = 8 * strlen(s);
        while(cnt % 6) ++cnt;
        for(int i=0; i<cnt; i+=6) {
            int n = 0;
            for(int k=i; k<i+6; ++k){
                n = n*2 + b[k];
            }
            printf("%c",base[n]);
        }
        for(; cnt%24; cnt+=6) printf("=");
        printf("\n");
    }
    return 0;
}

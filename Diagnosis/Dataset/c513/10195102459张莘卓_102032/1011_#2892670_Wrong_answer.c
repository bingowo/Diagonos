#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main()
{
    char s[100];
    scanf("0x%s",s);
    int num[400] = {0};
    for(int i=0; s[i]; ++i) {
        int n = isdigit(s[i]) ? s[i]-'0' : s[i]-'A'+10;
        num[i*4]=(n>>3)&1; num[i*4+1]=(n>>2)&1;
        num[i*4+2]=(n>>1)&1; num[i*4+3]=n&1;
    }
    long long a=0, b=0;
    for(int i=0; i<4*strlen(s); ++i) {
        long long t = num[i] - a - b;
        b = a - b;
        a = t;
    }
    if(a==0 && b==0){
        printf("0\n"); return 0;
    }
    if(b == 0) printf("%lld",a);
    else{
        if(a) printf("%lld",a);
        if(b > 0) printf("+");
        if(b==1) printf("i");
        else if(b == -1) printf("-i");
        else printf("%lldi",b);
    }
    printf("\n");
    return 0;
}

#include <stdio.h>
#include<stdlib.h>


int main()
{
    char s[61];
    int a[128];
    long long ans = 0;
    int digit = 0,N= 1;
    char *p = s;
    a[*p] = 1;
    while (*++p) {
        if(a[*p] == -1){
            a[*p] = digit;
            digit = digit?digit+1:2;
            N++;
        }
    }
    if(N<2) N = 2;
    scanf("%s",s);
    
    for(int i = 0;i<128;i++){
        a[i] = -1;
    }
    while (*p) {
        ans = ans*N+a[*p++];
    }
    printf("%lld",ans);
    return 0;
}

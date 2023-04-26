#include <stdio.h>
#include <stdlib.h>


int main()
{
    char s[61];
    int a[128];
    long long ans = 0;
    int digit = 0,N= 1;
    char *p = s;
    a[*p] = 1;
    scanf("%d",n);
    scanf("%d",n);
    while (*++p) {
        if(a[*p] == -1){
            a[*p] = digit;
            digit = digit?digit+1:2;
            N++;
        }
    }
    if(N<2) N = 2;
    
    for(int i = 0;i<128;i++){
        a[i] = -1;
    }
    while (*p) {
        ans = ans*N+a[*p++];
    }
    for(i=0;i<n;i++){
        printf("case #%d:%lld",i,ans);
        printf("\n");
    }
    return 0;
}

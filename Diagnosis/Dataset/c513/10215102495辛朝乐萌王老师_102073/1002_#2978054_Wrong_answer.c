#include <stdio.h>
#include<stdlib.h>
#include <string.h>

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        char s[61];
        scanf("%s",s);
        int a[129];
        for (int j=0;j<128; j++) {
            a[j] =-1;
        }
        int digit=0,N=1;
        char *p=s;
        a[*p]=1;
        while (*++p) {
            if(a[*p] == -1){
                a[*p] = digit;
                digit=digit?digit+1:2;
                N++;
            }
            if(N<2) N=2;
        }
        long long ans=0;
        p=s;
        while (*p) {
            ans = ans*N+a[*++p];
        }
        printf("case #%d:\n",i);
        printf("%lld\n",ans);
    }
    return 0;
}

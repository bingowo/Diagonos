#include <stdio.h>
#include <stdlib.h>

int main()
{
    char s[61];
    int a[128]={-1};
    int m,b,c;
    scanf("%d",&m);
    for(int j=0;j<m;j++){
        long long ans =0;
        for(int n=0;n<128;n++) a[n]=-1;
        scanf("%s",s);
        int digit=0,N=1,i;
        char*p=s;
        a[*p]=1;
        while(*++p){
            if(a[*p]==-1){
                a[*p] =digit;
                digit = digit?digit+1:2;
                N++;
            }
        }
        if(N<2) N=2;
        p=s;
        while (*p){
            ans = ans*N+a[*p++];
        }
        printf("case #%d:\n%lld\n",j,ans);
    }

    return 0;
}

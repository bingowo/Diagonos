#include <stdio.h>
#include <stdlib.h>

int main()
{

    char s[61]={0};
    int digit=0,N=1,i;
    int a[128];
    char *p=s;
    int cnt = 0;

    long long ans=0;
    while(scanf("%s",&s)!=EOF){
        for(i=0;i<128;i++){
            a[i]=-1;
        }

        a[*p]=1;

        while (*++p){
            if(a[*p]==-1){
                a[*p]=digit;
                digit=digit?digit+1:2;
                N++;
            }
            if(N<2){
                N=2;
            }
            p=s;
            while(*p){
                ans=ans*N+a[*p++];
            }
            
        }
        printf("case #%d:\n%lld\n",cnt,ans);
        digit=0;
        N=1;
        cnt++;
    }
    return 0;
}


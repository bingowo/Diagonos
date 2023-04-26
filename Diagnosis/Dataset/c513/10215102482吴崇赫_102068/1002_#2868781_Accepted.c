#include <stdio.h>
#include<string.h>


int main()
{
    int T,x=0;
    scanf("%d\n",&T);
    while(x<T){
        char s[61];
        scanf("%s",s);
        int a[128];
        for(int i=0;i<128;++i)a[i]=-1;
        char* p=s;
        int digit=0,N=1;a[*p]=1;
        while(*++p){
           if(a[*p]==-1){
                a[*p]=digit;++N;
                digit=digit?digit+1:2;
         }
        }
        if(N<2)N=2;
        long long sum=0; p=s;
        while(*p)sum=sum*N+a[*p++];
        printf("case #%d:\n%lld\n",x++,sum);
    }
    return 0;
}

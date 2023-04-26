#include <stdlib.h>
#include <string.h>
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        char a[1000];
        int N=1;
        scanf("%s",a);
        int s[1000];
        for(int i=0;i<1000;i++){
            s[i]=-1;
        }
        int len=strlen(a);
        char *p=a;
        int d=0;
        s[*p]=1;
        while(*++p){
            if(s[*p]==-1){
                    s[*p]=d;
                    d=d?d+1:2;
                    N++;

            }
        }
        if (N<2) N=2;  //不可能是一进制
        long long int ans=0;
        p=a;
        while(*p){
            ans=ans*N+s[*p++];
        }
        printf("case #%d:\n",i);
        printf("%lld\n",ans);
        }

    return 0;
}

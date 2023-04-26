#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T,cnt;
    long long ans;
    scanf("%d",&T);
    char s[61];
    int a[128];
    for(int i=0;i<T;i++){
        scanf("%s",s);
        cnt=0,ans=0;
        char *p=s;
        for(int j=0;j<128;j++)  a[j]=-1;
        a[*p]=1;
        while(*++p){
            if(a[*p]==-1){
                a[*p]=cnt;
                cnt=cnt ? cnt+1 : 2;
            }
        }
        if(cnt<2)   cnt=2;
        p=s;
        while(*p)   ans=ans*cnt+a[*p++];
        printf("case #%d:\n%lld\n",i,ans);
    }
    return 0;
}

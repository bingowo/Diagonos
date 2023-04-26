#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T;
    scanf("%d",&T);
    for(int cas=0;cas<T;cas++){
        char s[61];
        scanf("%s",s);
        int a[128];
        for (int i=0;i<128;i++)
            a[i]=-1;
        int digit=0,N=1,i; char *p=s;
        a[*p]=1;
        while (*++p)
        if (a[*p]==-1){
                a[*p]=digit;
                digit=digit+1;
                N++;}
        if (N<2) N=2;  //不可能是一进制
        long long ans=0;
        p=s; while (*p) ans=ans*N+a[*p++];
        printf("case #%d:\n",cas);
        printf("%lld\n",ans);


    }
    return 0;
}

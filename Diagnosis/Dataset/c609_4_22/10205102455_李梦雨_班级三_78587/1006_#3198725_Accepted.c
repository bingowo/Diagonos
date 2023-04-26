#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        printf("case #%d:\n",i);
        char s[61];
        scanf("%s",s);
        int a[128];
        for(int j=0;j<128;j++) a[j]=-1;//j=某字符在ASCII表中对应的数字，a[j]=-1说明未遇到过该种字符
        int digit=0,n=1,i;//n为字符串中的字符种类数，即n进制
        char *p=s;
        a[*p]=1;
        while(*++p)
            if(a[*p]==-1)
            {
                a[*p]=digit;
                digit=digit?digit+1:2;//若digit非0，则=digit+1；否则为2
                n++;
            }
        if(n<2) n=2;
        long long ans=0;
        p=s;
        while(*p)
            ans=ans*n+a[*p++];
        printf("%lld\n",ans);
    }
    return 0;
}
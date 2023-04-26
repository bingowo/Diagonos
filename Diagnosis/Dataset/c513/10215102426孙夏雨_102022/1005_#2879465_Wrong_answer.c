#define __USE_MINGW_ANSI_STDIO 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int T;
    scanf("%d",&T);
    for (int i=0;i<T;i++){
        char s[53];
        scanf("%s",s);
        int len=strlen(s),w=0;
        long double ans=0;
        for (int j=0;j<len-2;j++){
            ans=(ans+s[len-1-j]-'0')/8;
            if ((s[len-1]-'0')%2==0) w=-1;
        }
        printf("case #%d:\n",i);
        int len1=3*(len-2)+w;
        printf("%.*Lf\n",len1,ans);
    }
    return 0;
}

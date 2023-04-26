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
        long long int x=1;
        long long int ans=0;
        for (int j=2;j<len;j++){
            ans=ans*8+s[j]-'0';
            x*=8;
            if ((j==len-1)&&((s[j]-'0')%2==0)) w=-1;
        }
        long double ans1=((long double)ans)/x;
        printf("case #%d:\n",i);
        int len1=3*(len-2)+w;
        printf("%.*Lf\n",len1,ans1);
    }
    return 0;
}

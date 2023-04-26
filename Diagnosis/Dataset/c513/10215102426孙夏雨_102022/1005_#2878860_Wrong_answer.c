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
        int len=strlen(s);
        double x=1.0/8,ans=0.0;
        for (int j=2;j<len;j++){
            ans+=(s[j]-'0')*x;
            x/=8;
        }
        printf("case #%d:\n",i);
        int len1=3*(len-2);
        printf("%.*f\n",len1,ans);
    }
    return 0;
}

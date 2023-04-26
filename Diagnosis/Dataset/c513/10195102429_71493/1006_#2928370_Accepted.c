#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int main()
{
    int T;
    scanf("%d",&T);
    for(int cas=0;cas<T;cas++){
            char s[111];
            scanf("%s",s);
            unsigned int p=0;
            long long ansA=0;
            for (;p<strlen(s);p++) {//整数部分
                if (s[p]=='.') break;
                ansA = ansA *3;
                if (s[p]=='1') ansA += 1;
                if (s[p]=='-') ansA -= 1;
             }
            p++;

    printf("case #%d:\n",cas);
    printf("%lld\n",ansA);
    
}
return 0;
}
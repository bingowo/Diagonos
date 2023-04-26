#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
   int T;
   scanf("%d",&T);
   char s[30];
   for(int i = 0;i < T;i++){
        scanf("%s",s);
        long long ans=0,m=1;
        for(int j = strlen(s)-1;j >= 0;j--){
            ans += m * ((s[j] == '-')?-1:(long long)(s[j] - '0'));
            m *= 3;
        }
        printf("case #%d:\n",i);
        printf("%lld\n",ans);
   }
    return 0;
}

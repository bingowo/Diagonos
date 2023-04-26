#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        printf("case #%d:\n",t);
        char s[100] = {};
        scanf("%s",s);
        int len = strlen(s);
        int ans = 0;
        for(int j=0;j<len;j++){
            if(s[j]=='1')ans = ans * 3 + 1;
            else if(s[j]=='-')ans = ans * 3 - 1;
            else if(s[j]=='0')ans *= 3;
        }
        printf("%d\n",ans);
    }
    return 0;
}

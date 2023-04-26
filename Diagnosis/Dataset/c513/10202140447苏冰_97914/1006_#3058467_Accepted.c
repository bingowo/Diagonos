#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
int main()
{
    int T;
    scanf("%d",&T);
    for(int cas=0;cas<T;cas++)
    {
        char s[100];
        scanf("%s",s);
        int ans=0;
        for(int i=0;i<strlen(s);i++)
        {
            int x;
            if(s[i]=='0') x=0;
            else if(s[i]=='1') x=1;
            else if(s[i]=='-') x=-1;
            ans=ans*3+x;
        }
        printf("case #%d:\n",cas);
        printf("%d\n",ans);
    }
    return 0;
}


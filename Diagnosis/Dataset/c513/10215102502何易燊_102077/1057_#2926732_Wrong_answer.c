#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// if (s[i]>='a'&&s[i]<='z') s[i] += 'A' - 'a';

main()
{
    char s[5001] = {}; scanf("%s",s);
    char ans[5001] = {}; ans[0] = toupper(s[0]);
    char buf[5001] = {};
    for (int i=1;s[i];i++) 
    {
        if (toupper(s[i])>=s[0])
        {
            buf[0] = toupper(s[i]); s[1] = 0;
            strcat(buf,ans);
            memset(ans,0,sizeof(ans));
            strcpy(ans,buf);
            memset(buf,0,sizeof(buf));
        }
        else
        {
            buf[0] = toupper(s[i]);
            strcat(ans,buf);
            memset(buf,0,sizeof(buf));
        }
    }
    printf("%s",ans);
    return 0;
}
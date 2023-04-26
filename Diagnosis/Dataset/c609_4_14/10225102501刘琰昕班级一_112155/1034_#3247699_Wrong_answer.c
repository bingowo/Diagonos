#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    char *s; int flag=0;
    s=(char *)malloc(1001*sizeof(char));
    scanf("%s",s);
    for(int i=0;s[i];i++)
    {
        if(s[i]=='0'&&s[i+1]=='x'&&((s[i+2]>='a'&&s[i+2]<='f')||(s[i+2]>='0'&&s[i+2]<='9')))
        {
            unsigned int ans=0;
            for(i=i+2;(s[i]>='0'&&s[i]<='9')||(s[i]>='a'&&s[i]<='f');i++)
            {
                if(s[i]>='0'&&s[i]<='9')ans=ans*16+s[i]-'0';
                else if(s[i]>='a'&&s[i]<='f') ans=ans*16+s[i]-'a'+10;
            };
            printf("%u ",ans);
            flag=1;
        }
    }
    if(!flag)printf("-1");
    return 0;
}

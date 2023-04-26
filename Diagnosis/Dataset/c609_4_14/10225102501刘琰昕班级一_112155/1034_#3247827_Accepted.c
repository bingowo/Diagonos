#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    char *s; int flag=0;
    s=(char *)malloc(1000001*sizeof(char));
    scanf("%s",s);
    for(int i=0;s[i];i++)
    {
        if(s[i]=='0'&&s[i+1]=='x'&&isxdigit(s[i+2]))
        {
            unsigned int ans=0;
            i+=2;
            while(isxdigit(s[i]))
            {
                if(s[i]>='0'&&s[i]<='9')ans=ans*16+s[i]-'0';
                else if(s[i]>='a'&&s[i]<='f') ans=ans*16+s[i]-'a'+10;
                i++;
            };
            printf("%u ",ans);
            flag=1;
        }
    }
    if(!flag)printf("-1");
    free(s);
    return 0;
}

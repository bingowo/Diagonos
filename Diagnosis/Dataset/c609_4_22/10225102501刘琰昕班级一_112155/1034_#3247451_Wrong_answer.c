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
        if(s[i]=='0'&&s[i+1]=='x')
        {
            long long ans=0;
            for(int j=i+2;isxdigit(s[j]);j++)
            {
                if(isdigit(s[j]))ans=ans*16+s[j]-'0';
                else ans=ans*16+s[j]-'a'+10;
            };
            printf("%d ",ans);
            flag=1;
        }
    }
    if(!flag)printf("-1");
    return 0;
}

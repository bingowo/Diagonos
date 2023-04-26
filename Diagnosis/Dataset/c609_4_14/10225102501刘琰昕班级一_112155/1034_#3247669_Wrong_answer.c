#include <stdio.h>
#include <stdlib.h>

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
            for(int j=i+2;s[j]>='a'&&s[j]<='f';j++)
            {
                if(s[j]>='0'&&s[j]<='9')ans=ans*16+s[j]-'0';
                else if(s[j]>='a'&&s[j]<='f') ans=ans*16+s[j]-'a'+10;
            };
            printf("%u ",ans);
            flag=1;
        }
    }
    if(!flag)printf("-1");
    return 0;
}

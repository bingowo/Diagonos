#include <stdio.h>
#include <stdlib.h>

int main()
{
    char s[100]={0};
    while(gets(s))
    {
        int i=0;
        for(i=0;s[i];i++)
        {
            if(s[i]=='/' && s[i+1] && s[i+1]=='/')
            {
                if(s[i-1] && s[i-1]=='"');
                else s[i]='\0';
                break;
            }
            else if(s[i]=='/'  && s[i+1]&& s[i+1]=='*')
            {
                s[i]='\0';printf("%s",s);
                while(1)
                {  char k[100]={0};int l=0,m=0;
                    scanf("%s",k);
                    for(l=0;k[l];l++)
                    if(k[l]=='*' && k[l+1] &&k[l+1]=='/')break;
                    if(k[l]=='*' && k[l+1] &&k[l+1]=='/'){for(m=0,l=l+2;k[l];m++,l++)s[m]=k[l];i=0;break;}
                }
            }

        }
        printf("%s\n",s);
    }
    return 0;
}

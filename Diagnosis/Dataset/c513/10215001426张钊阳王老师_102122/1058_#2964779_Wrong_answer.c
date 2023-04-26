#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    unsigned char s[10000];
    memset(s,'\0',10000);
    char a[1000];
    while(gets(a))
    {
        int l0=strlen(a);
        a[l0]='\n';
        a[l0+1]='\0';
        strcat(s,a);
    }
    int i,l;
    l=strlen(s);

    int start,end;

    for(i=0;i<l;i++)
    {
        if(s[i]=='/'&&s[i+1]=='/')
        {
            start=i;
            while(!(s[i]==';'&&s[i+1]=='\n')&&!(s[i]=='"'&&s[i+1]==';'))
            {
                if(s[i]=='\n')
                {
                    end=i;
                    i++;
                    for(int j=start;j<=end-1;j++)
                    {
                        s[j]='+';
                    }
                    break;
                }
                i++;
            }
        }

        if(s[i]=='/'&&s[i+1]=='*')
        {
            start=i;
            while(!(s[i]==';'&&s[i+1]=='\n'))
            {
                if(s[i]=='*'&&s[i+1]=='/')
                {
                    end=i;
                    i++;
                    for(int j=start;j<=end+1;j++)
                    {
                        s[j]='+';
                    }
                    break;
                }
                i++;
            }
        }
    }

    for(int z=0;z<l-1;z++)
    {
        if(s[z]!='+')
        printf("%c",s[z]);
    }
    return 0;
}

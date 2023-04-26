#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    unsigned char s[1000];
    memset(s,'\0',1000);
    char a[100];
    while(gets(a))
    {
        int l0=strlen(a);
        a[l0]='\n';
        a[l0+1]='\0';
        strcat(s,a);

    }
    printf("%c",s[11]);
    int i,l;
    l=strlen(s);

    int start,end;

    for(i=0;i<l;i++)
    {
        if(s[i]=='/'&&s[i+1]=='/')
        {
            start=i;
            while(!(s[i]==';'&&s[i+1]=='\n'))
            {
                if(s[i]=='\n')
                {
                    end=i;
                    i++;
                    for(int j=start;j<=end;j++)
                    {
                        s[j]='\0';
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
                if(s[i]=='*'&&s[i]=='/')
                {
                    end=i;
                    i++;
                    for(int j=start;j<=end;j++)
                    {
                        s[j]='-1';
                    }
                    break;
                }
            }
        }
    }

    for(int z=0;z<l;z++)
    {
        printf("%c",s[z]);
    }
    return 0;
}

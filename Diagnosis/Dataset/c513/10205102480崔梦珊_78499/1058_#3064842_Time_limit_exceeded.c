#include<stdio.h>
#include<string.h>
int main()
{
    char c;
    char s[1000000]={0};
    int i=0;
    while((c=getchar())!=EOF)
    {
        s[i]=c;
        i++;
    }
    int len=strlen(s);
    for(int i=0;i<len;i++)
    {
            if(s[i]=='/'&&s[i+1]=='/')
            {
                i=i+2;
                while(s[i]!='\n')
                {
                    i++;
                }
                i--;
                continue;
            }
            if(s[i]=='/'&&s[i+1]=='*')
            {
                i=i+2;
                while(!(s[i]=='*'&&s[i+1]=='/'))
                {
                    i++;
                }
                i=i+1;
                continue;
            }
            if(s[i]=='\'')
            {
                for(int j=0;j<=3;j++)
                {
                    printf("%c",s[i+j]);
                }
                i=i+3;
                continue;
            }
            if(s[i]=='"')
            {
                int j=i;
                int k=i;
                while(s[i]!='\n')
                {
                    if(s[i]=='"')
                    {
                        k=i;
                    }
                    i++;
                }
                for(int p=j;p<=k;p++)
                {
                    printf("%c",s[p]);
                }
                i=k-1;
                continue;
            }
            else
            {
                printf("%c",s[i]);
            }
    }
    return 0;

}

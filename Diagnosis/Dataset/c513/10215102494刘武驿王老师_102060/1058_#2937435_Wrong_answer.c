#include<stdio.h>
#include<string.h>
int main()
{
    char s[1000][100];
    int i=0;
    while(gets(s[i++]));
    int test=0;
    for(int j=0;j<i-1;j++)
    {
        int len=strlen(s[j]);
        if(test==0)
        {
            for(int x=0;x<len;x++)
            {
                if(s[j][x]=='"')
                {
                    x++;
                    while(s[j][x++]!='"');
                    x-=1;
                    if(s[j][len-2]=='"') continue;
                }
                if(s[j][x]=='\'')
                {
                    x++;
                    while(s[j][x++]!='\'');
                    x-=1;
                }
                if(s[j][x]=='/'&&s[j][x+1]=='/')
                {
                    s[j][x]='\0';
                    continue;
                }
                if(s[j][x]=='/'&&s[j][x+1]=='*')
                {
                    int tmp=x;
                    while ((s[j][x]!='*'||s[j][x+1]!='/')&&s[j][x])
                    {
                        x++;
                    }
                    if(x>=len)
                    {
                        s[j][tmp]='~';
                        test=1;
                        continue;
                    }
                    else
                    {
                        s[j][tmp]='~';
                        s[j][x+1]='~';
                    }
                }
            }
        }
        else
        {
            int m=0;
            while ((s[j][m]!='*'||s[j][m+1]!='/')&&s[j][m]) m++;
            if(m>=len)
            {
                s[j][0]='\0';
                continue;
            }
            else
            {
                test=0;
                s[j][m+1]='~';
                for(int x=m;x<len;x++)
                {
                    if(s[j][x]=='"')
                    {
                        x++;
                        while(s[j][x++]!='"');
                        x-=1;
                        if(s[j][len-2]=='"') continue;
                    }
                    if(s[j][x]=='\'')
                    {
                        x++;
                        while(s[j][x++]!='\'');
                        x-=1;
                    }
                    if(s[j][x]=='/'&&s[j][x+1]=='/')
                    {
                        s[j][x]='\0';
                        continue;
                    }
                    if(s[j][x]=='/'&&s[j][x+1]=='*')
                    {
                        int tmp=x;
                        while ((s[j][x]!='*'||s[j][x+1]!='/')&&s[j][x])
                        {
                            x++;
                        }
                        if(x>=len)
                        {
                            s[j][tmp]='~';
                            continue;
                            test=1;
                        }
                        else
                        {
                            s[j][tmp]='~';
                            s[j][x]='~';
                        }
                }
            }
            }
        }
    }
    test=0;
    for(int j=0;j<i-1;j++)
    {
        for(int w=0;w<strlen(s[j]);w++)
        {
            if(s[j][w]=='~')
            {
                test=(test+1)%2;
                continue;
            }
            if(test==0) printf("%c",s[j][w]);
        }
        if(test==0) printf("\n");
    }
}

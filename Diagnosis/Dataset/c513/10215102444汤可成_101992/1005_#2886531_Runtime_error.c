#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void divide(char* ss, char c)
{
    int flag = 1;
    char ch = c;
    int n = 0;
    int i = 2;
    do
    {
        char tmp = 0;
        if(i == 2)
        {
            tmp = (ch-'0')*10 + (ss[2]>='0'? ss[2]-'0':ss[2]);
            ss[2] = tmp/8 + '0';
            if(tmp!=0 && tmp%8 == 0 &&ss[3] == 0) flag = 0;
            else n = tmp%8;
        }
        else
        {
            if(ss[i] == 0) ss[i] = '0';
            tmp = n*10 + (ss[i]-'0');
            ss[i] = tmp/8 + '0';
            if(tmp!=0 && tmp%8 == 0 && ss[i+1] == 0) flag = 0;
            else n = tmp%8;

        }
        i++;
    }
    while(flag);
    ss[i] = 0;
}

void convert(char* s, char*ss, int len)
{
    int i = 0;
    for(i = len-1; i>=2; i--)
    {
        divide(ss, s[i]);

    }
}

int main()
{
    int T = 0;
    scanf("%d",&T);
    int i = 0;
    for (i = 0; i<T; i++)
    {
        printf("case #%d:\n", i);
        char s[50] = {0};
        char ss[153] = {0};
        ss[0] = '0';
        ss[1] = '.';
        scanf("%s",s);
        int len = strlen(s);
        convert(s,ss,len);
        printf("%s\n", ss);
    }
    return 0;
}

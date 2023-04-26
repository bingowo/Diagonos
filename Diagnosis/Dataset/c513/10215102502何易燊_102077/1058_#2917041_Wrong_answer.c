#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int find(char s[])
{
    for (int i=strlen(s)-1;i>=0;i--) if (s[i]=='\"') return i;
    return 0;
}

main()
{
    char s[100] = {};
    int state2 = 1;
    int buffer = 0;
    while (gets(s)!=NULL)
    {
        strcat(s," ");
        for (int i=strlen(s);!isspace(s[i]);i--) s[i] = '\0';
        int state1 = 1, state3 = 0;
        if (buffer==1&&s[0]=='/') state2 = 0;
        for (int i=0;s[i];i++)
        {
            if (s[i]=='"'&&!state3&&state2) state3 = 1;
            if (find(s)!=0&&i==find(s)) state3 = 0;
            if (s[i-2]=='*'&&s[i-1]=='/'&&!state2) state2 = 1;
            if (s[i]=='/'&&s[i+1]=='*'&&state2) state2 = 0;
            if (s[i]=='/'&&s[i+1]=='/'&&!state3&&state2) state1 = 0;
            if ((state1&&state2)||state3) printf("%c",s[i]); 
        }
        if (s[strlen(s)-1]=='*') buffer = 1;
        else buffer = 0;
        if (state2) printf("\n");
    }
    system("pause");
    return 0;
}
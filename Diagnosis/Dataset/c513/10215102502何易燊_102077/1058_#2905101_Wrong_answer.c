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
    //char *str = (char*)malloc(100);
    //int p = 0;
    int state2 = 1;
    while (gets(s)!=NULL)
    {
        strcat(s," ");
        for (int i=strlen(s);!isspace(s[i]);i--) s[i] = '\0';
        int state1 = 1, state3 = 0;
        for (int i=0;s[i];i++)
        {
            if (s[i]=='"'&&!state3) state3 = 1;
            //else if (s[i]=='"'&&state3) state3 = 0;
            if (find(s)!=0&&i==find(s)) state3 = 0;
            if (s[i]=='/'&&s[i+1]=='/'&&!state3) state1 = 0;
            if (s[i]=='/'&&s[i+1]=='*'&&state2) state2 = 0;
            if (s[i-2]=='*'&&s[i-1]=='/'&&!state2) state2 = 1;
            if ((state1&&state2)||state3) printf("%c",s[i]); 
        }
        if (state2) printf("\n");
    }
    system("pause");
    return 0;
}
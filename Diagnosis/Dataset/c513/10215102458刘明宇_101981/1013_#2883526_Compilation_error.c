#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s[100];
    gets(s);
    char *buf[2];
    int num;
    int A,B,C;
    if(strchr(s,'.'))
    {
        char *p;
        int i = 0;
        p = NULL;
        p = strtok(s, ".");
        while(p)
        {
            buf[i] = p;
            i++;
            p = strtok(NULL, ".");
        }
        num = 2;

    }
    else
    {
        buf[0] = s;
        num = 1;
    }
    //for(int i = 0;i < num;i++)
    //{
    //   printf("%s\n",buf[i]);
    //}
    if(num == 1)
    {
        char s1 = buf[0];
        int mul;
        int top;
        for(int j = 1;j < strlen(s1);j++)
        {
            top *= 3;
        }
        for(int i = 0;i < strlen(s1);i++)
        {
            if(s1[0] == '1') mul = 1;
            if(s1[0] == '0') mul = 0;
            if(s1[0] == '2') mul = -1;
            A += top * mul;
            top = top / 3;
        }
        printf("%d\n", A);
    }
    if(num == 2)
    {
        char s1 = buf[0];
        int mul;
        int top;
        for(int j = 1;j < strlen(s1);j++)
        {
            top *= 3;
        }
        for(int i = 0;i < strlen(s1);i++)
        {
            if(s1[0] == '1') mul = 1;
            if(s1[0] == '0') mul = 0;
            if(s1[0] == '2') mul = -1;
            A += top * mul;
            top = top / 3;
        }
        char s2 = buf[1];
    }
    return 0;

}
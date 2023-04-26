#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char s[101] = {}; scanf("%s",s);
    int a = 0,b = 0; char c;
    for (int i=0;s[i];i++) if (isalpha(s[i])) {printf("%c=",s[i]); break;}
    char *t = strchr(s,'=')+1;
    *(t-1) = '\0';
    char buf[100] = {}; int p = 0;
    for (int i=0;s[i];i++)
    {
        if (s[i]!='+'&&s[i]!='-') buf[p++] = s[i];
        else
        {
            if (isdigit(buf[p-1])) b += atoi(buf);
            else
            {
                if (p==2&&buf[0]=='+') a += 1;
                else if (p==2&&buf[0]=='-') a-= 1;
                else if (p==1) a += 1;
                else {buf[p-1] = '\0'; a += atoi(buf);}
            }
            memset(buf,0,sizeof(buf)); p = 0; buf[p++] = s[i];
        }
    }
    if (isdigit(buf[p-1])) b += atoi(buf);
    else
    {
        if (p==2&&buf[0]=='+') a += 1;
        else if (p==2&&buf[0]=='-') a-= 1;
        else if (p==1) a += 1;
        else {buf[p-1] = '\0'; a += atoi(buf);}
    }
    memset(buf,0,sizeof(buf)); p = 0;
    for (int i=0;t[i];i++)
    {
        if (t[i]!='+'&&t[i]!='-') buf[p++] = t[i];
        else
        {
            if (isdigit(buf[p-1])) b -= atoi(buf);
            else
            {
                if (p==2&&buf[0]=='+') a -= 1;
                else if (p==2&&buf[0]=='-') a += 1;
                else if (p==1) a -= 1;
                else {buf[p-1] = '\0'; a -= atoi(buf);}
            }
            memset(buf,0,sizeof(buf)); p = 0; buf[p++] = t[i];
        } 
    }
    if (isdigit(buf[p-1])) b -= atoi(buf);
    else
    {
        if (p==2&&buf[0]=='+') a -= 1;
        else if (p==2&&buf[0]=='-') a += 1;
        else if (p==1) a -= 1;
        else {buf[p-1] = '\0'; a -= atoi(buf);}
    }
    printf("%.3lf\n",c,-b*1.0/a);
    return 0;
}
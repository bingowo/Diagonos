#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int hour, min, sec;
void func(char* s)
{
    char* p, * q;
    int len = strlen(s), w, i, t1, t2, t3, val, compar;
    for (i = 0;i < len;i++)
    {
        if (s[i] == ',')
            s[i] = 0;
    }
    p = s - 1;              //p指向该字段的前一个字符
    q = strchr(p + 1, 0);  //q指向该字段的后一个字符，当p+1=q时，该字段无字符
    w = 0;                //记录是第几个字段
    while (p != s + len)
    {
        if (w == 0 && strcmp(p + 1, "$GPRMC") != 0)
        {
            break;
        }
        else if (w == 1)
        {
            t1 = (*(p + 1) - '0') * 10 + *(p + 2) - '0';
            t2 = (*(p + 3) - '0') * 10 + *(p + 4) - '0';
            t3 = (*(p + 5) - '0') * 10 + *(p + 6) - '0';
        }
        else if (w == 2 && strcmp(p + 1, "A") != 0)
        {
            break;
        }
        else if(w>2)
        {
            val = 0;
            for (i = 1;i < len;i++)
            {
                if (s[i] == '*')
                {
                    sscanf(s + i + 1, "%X", &compar);
                    break;
                }
                else
                {
                    val = val ^ s[i];
                }
            }
            if (val == compar)
            {
                hour = t1+8;
                min = t2;sec = t3;
                if (hour > 24)
                    hour -= 24;
                else if (hour == 24)
                {
                    if (min ==0 &&sec == 0);
                    else
                        hour -= 24;
                }


            }
        }
        w++;
        p = q;
        q = strchr(p + 1, 0);
    }
}
int main()
{
    char s[1000];
    while (scanf("%s", s))
    {
        if (strcmp(s, "END") != 0)
        {
            func(s);
        }
        else
        {
            printf("%02d:%02d:%02d", hour, min, sec);
            break;
        }
    }

    return 0;
}

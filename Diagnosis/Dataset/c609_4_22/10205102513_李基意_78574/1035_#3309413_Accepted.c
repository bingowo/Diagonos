#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char stack[105] = { 1 };

void remov(char* str)
{
    for (int i = 0; i < 105; ++i)   stack[i] = 0;
    int len = strlen(str);
    int e = 0;
    for (int i = 0; i < len; i++)
   {
        if (i == 0)
       {
            if (str[i] == str[i + 1]);
            else stack[e++] = str[i];
       }
        else if (i == len - 1)
       {
            if (str[i] == str[i - 1]);
            else stack[e++] = str[i];
       }
        else
       {
            if (str[i] == str[i + 1] || str[i] == str[i - 1]);
            else stack[e++] = str[i];
       }
   }
    int llen = strlen(stack);
    if (len == llen)
   {
        stack[0] = 0;
        return;
   }
    else
   {
        int i = 0;
        for (i = 0; i < llen; ++i)  str[i] = stack[i];
        str[i] = 0;
        stack[0] = 1;
   }
    return;
}
int main()
{
    int cases;
    scanf("%d", &cases);
    for (int cas = 0; cas < cases; ++cas)
   {
        int maxll=0;
        stack[0] = 1;
        char str1[105] = { 0 };
        scanf("%s", str1);
        int len = strlen(str1)+1;
        char str[105] = {0};
        for (int i = 0;i<=len;++i)
       {
            for (char c = 'A';c<'D';++c)
           {
                int j = 0;
                for (j = 0;j<=len;++j)
               {
                    if (j<i)   str[j] = str1[j];
                    else if (i == j)   str[j] = c;
                    else  str[j] = str1[j-1];
               }
                str[j] = 0;
                while (stack[0] != 0)
               {
                    remov(str);
               }
                stack[0] = 1;
                int llen = strlen(str);
                maxll = maxll > len-llen?maxll:len-llen;
           }
       }
        printf("case #%d:\n", cas);
        printf("%d\n", maxll);
   }
    return 0;
}       
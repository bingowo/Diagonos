#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char s[100000];
    scanf("%s", s); 
    int len = strlen(s);
    if (s[len - 1] == '\n') //去掉末尾换行符
        s[len - 1] = '\0';
    int flag = 0;//标记是否是十六进制
    for (int i = 0; s[i]; i++) 
    {
        if (s[i] == '0' && s[i + 1] == 'x' && isxdigit(s[i + 2])) 
        {
            unsigned int end = 0;
            i += 2;//跳过0x
            while (isxdigit(s[i])) 
            {  
                if (s[i] >= '0' && s[i] <= '9') 
                    end = end * 16 + s[i] - '0';
                else 
                    end = end * 16 + s[i] - 'a' + 10; 
                i++;
            }
            printf("%u ", end);
            flag = 1;
        }
    }
    if (!flag)  printf("-1");
    return 0;
}
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

//int check(char c)
//{
//    if((c >= 'a' && c <= 'f') || (c == 'x'))
//        return 1;
//    if(isdigit(c))
//        return 1;
//    return 0;
//}
//
//int check1(char c)
//{
//    if(c >= 'a' && c <= 'f')
//        return 1;
//    if(isdigit(c))
//        return 1;
//    return 0;
//}

int main()
{
    char s1[20001] = {0};
    char s2[20001] = {0};
    scanf("%s",s1);unsigned len = strlen(s1);
    int cnt = 0;int sig = 0;
    for(int i = 0;i < len;i++)
    {
        if((s1[i] == '0') && (s1[i+1] == 'x'))
        {
            for(int j = i+2;j < len;j++)
            {
                if((!isdigit(s1[j]))&&(s1[j] > 'f'))
                {
                    if(s2[0] == '\0')
                        break;
                    long long num = 0;
                    for(int p = 0;p < strlen(s2);p++)
                    {
                        int k = strlen(s2)-1-p;
                        int y;
                        if(isdigit(s2[p]))
                            y = s2[p]-'0';
                        else
                            y = s2[p]-'a'+10;
                        num += (int)pow(16,k)*y;
                    }
                    printf("%lld ",num);
                    sig = 1;
                    cnt = 0;
                    i = j;
                    memset(s2,'\0',sizeof(s2));
                    break;
                }
                else
                {
                    s2[cnt++] = s1[j];
                }
            }
        }
    }
    if(s2[0] != '\0')
    {
        long long num = 0;
        for(int p = 0;p < strlen(s2);p++)
        {
            int k = strlen(s2)-1-p;
            int y;
            if(isdigit(s2[p]))
                y = s2[p]-'0';
            else
                y = s2[p]-'a'+10;
            num += (int)pow(16,k)*y;
        }
        printf("%lld ",num);
        sig = 1;
    }
    if(sig == 0)
        printf("-1\n");
    return 0;
}
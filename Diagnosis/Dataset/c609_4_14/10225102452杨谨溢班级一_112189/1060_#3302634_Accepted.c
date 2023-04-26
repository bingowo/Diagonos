#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 100

char *R(char* s)
{
    if (*s)
    {
        char t[2*N+1];
        char c = *s; // 第一组相同字符
        char *ps = s,*pt = t;
        int cnt;  // 个数
        while (*++ps == c);
        R(ps);
        if (c<*ps) strcpy(pt+(cnt = (ps-s)*2),ps),memset(pt,c,cnt),strcpy(s,t);
    }
    return s;
}

int main()
{
    char str[2*N+1];
    printf("%s\n",(scanf("%s",str),R(str)));
    return 0;
}

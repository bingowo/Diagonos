#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 100

char *R(char* s)
{
    if (*s)
    {
        char t[2*N+1];
        if (strcmp(((*t = *(t+1) = *s),strcpy(t+2,(R(s+1))-2)),s)<0)   strcpy(s,t);
    }
    return s;
}

int main()
{
    char str[2*N+1];
    //char strr[101];
    //scanf("%s",str);
    printf("%s\n",(scanf("%s",str),R(str)));
    return 0;
}

// 这段代码简直奇怪到爆炸？！

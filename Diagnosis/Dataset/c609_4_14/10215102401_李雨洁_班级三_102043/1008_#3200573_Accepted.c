#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void solveint(int n)
{
    int c = sizeof(n);
    unsigned char *p = (unsigned char *)&n;
    while (c--) printf("%02x ", *p++);
    printf("\n");
}
void solvedouble(double d)
{
    int c = sizeof(d);
    unsigned char *p = (unsigned char *)&d;
    while (c--) printf("%02x ", *p++);
    printf("\n");
}
int main()
{
    char s[31]={0};
    while(scanf("%s",s) != EOF)
        if(strchr(s,'.')) solvedouble(atof(s));//atof字符串转化为浮点数
        else solveint(atoi(s));//atoi字符串转为整型数
    return 0;
}
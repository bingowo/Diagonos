#include<stdio.h>
void solveint(int n) //字节转换
{
    int c = sizeof(n);
    unsigned char* p = (unsigned char*)&n;
    while (c--) printf("%02x ", *p++);
    printf("\n");
}
void solvedouble(double d)//字节转换
{
    int c = sizeof(d);
    unsigned char* p = (unsigned char*)&d;
    while (c--)
        printf("%02x ", *p++);
    printf("\n");
}
int main()
{
    char s[31];
    while (scanf("%s", s) != EOF)
    if (strchr(s, '.') == 0)
        solveint(atoi(s));
    else
        solvedouble(atof(s));
    return 0;
}

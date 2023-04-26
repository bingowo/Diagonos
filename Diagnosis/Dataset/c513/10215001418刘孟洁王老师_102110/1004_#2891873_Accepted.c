#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 1000
void solveint(int c)
{
    int n=sizeof(c);
    unsigned char *p=(unsigned char*)&c;/*将这个数所储存的地址拿出来放到指针p中*/
    for(n=sizeof(c)-1;n>=0;n--)
    printf("%02x%c"/*%02x表示两个字符两个字符地输出，并且空余用0填充*/,*p++,n==0?'\n':' ');

}
void solvedouble(double c)
{
    int n=sizeof(c);
    unsigned char *p=(unsigned char*)&c;
    for(n=sizeof(c)-1;n>=0;n--)
    printf("%02x%c",*p++,n==0?'\n':' ');

}

int main()
{
    char s[N];
    while(scanf("%s",s)!=EOF)
    {
        if(strchr(s,'.')==0)/*判断数组中是否有'.'，strchr是判断字符在数组中出现的首位置*/
            solveint(atoi(s));
        else solvedouble(atof(s));
    }
    return 0;
}

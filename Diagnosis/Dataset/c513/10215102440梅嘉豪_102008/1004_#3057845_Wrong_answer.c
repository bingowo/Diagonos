#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int int_print(int a);
int double_print(double a);
int main()
{
    char s[100];
    while (scanf("%s",s)!=EOF)
    {
        if(strchr(s,'.'))   double_print(atof(s));//strchr 用法
        else    int_print(atoi(s));
    }
}
int int_print(int a)
{
    unsigned char *p=&a;
    int i=sizeof(int);
    while(i--)  printf("%.2X ",*p++);//输出控制符？大端、小端内存表示？
    printf("\n");
}  
int double_print(double a)
{
    unsigned char *p=&a;
    int i=sizeof(double);
    while(i--)  printf("%.2X ",*p++);
    printf("\n");
}
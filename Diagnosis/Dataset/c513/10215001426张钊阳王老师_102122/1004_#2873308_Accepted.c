#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//补充一些string类函数的用法：strcpy + strlen + strcat + strcmp +  strchr
//strchr用法：函数原型：char* strchr(char* str,char ch)  c='a'; ptr=strrchr(string,c);返回的是字符a在字符串中的位置
//strcmp用法：函数原型:  int strncmp(char *str1,char *str2,int count)
//函数功能:  对str1和str2中的前count个字符按字典顺序比较
//函数返回:  小于0：str1<str2，等于0：str1=str2，大于0：str1>str2
//strlen用法较为熟悉

//补充atoi和atof两个函数的用法：头文件     #include<stdlib.h>
//定义函数     int atoi(const  char *nptr） ！返回的是整数 就是字符串转整数
//atoi()函数会扫描参数nptr字符串，跳过最前面的空格字符，直到遇见数字或正负符号才开始转换，直到遇见非数字或字符串结束符（‘\0’）时才结束转换，并将结果返回。

int main()
{
    void solveint(int a);
    void solvedouble(double d);
    char s[31];
    while(scanf("%s",s)!=EOF)
    {
        if(strchr(s,'.'))
           solvedouble(atof(s));
        else
           solveint(atoi(s));
    }
    return 0;
}
void solveint(int a)
{
    int c=sizeof(int);
    unsigned char *p=(unsigned char*)&a;//如果不用unsigned char会使得得到的内存字节只有7位
    while(c--)
        printf("%02x ",*p++);
    printf("\n");
}
void solvedouble(double d){
    int c = sizeof(double);
    unsigned char* p = (unsigned char*)&d;
    while (c--)
        printf("%02x ", *p++);
    printf("\n");
}
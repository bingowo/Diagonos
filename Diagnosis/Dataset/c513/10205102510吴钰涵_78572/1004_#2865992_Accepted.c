#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void int1(int i)
{
    int a=sizeof(i);   //sizeof为操作符，不是函数，返回类型为输入数据的类型
    unsigned char* p = (unsigned char*)&i;
    while(a--)
        printf("%02x ",*p++);   //x：表示以十六进制形式输出，02：表示不足两位，前面补0输出，如果超过两位，则以实际输出
    printf("\n");
}

void double1(double d)
{
    double b=sizeof(d);
    unsigned char* p = (unsigned char*)&d;
    while(b--)
        printf("%02x ",*p++);
    printf("\n");
}

int main()
{
    char s[100];
    while(scanf("%s",s)!=EOF)
    {
        if(strchr(s,'.')!=NULL)   //在字符串s中寻找字符'.'第一次出现的位置，并返回其位置；若不存在则返回NULL
            double1(atof(s));   //字符串中有小数点，读入数据需存放在double类型数据变量中，atof将字符串转换为douoble类型
        else
            int1(atoi(s));   //字符串中没有小数点，读入数据需存放在int类型数据变量中，atof将字符串转换为int类型
    }
}
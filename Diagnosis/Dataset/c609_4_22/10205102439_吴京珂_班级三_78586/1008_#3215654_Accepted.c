#include <stdio.h>
#include <stdlib.h>

void toInt(int a)
{
    int n=sizeof(a);
    unsigned char* p = (unsigned char*)&a;
    while(n--) printf("%02x ",*p++);
    printf("\n");

}

void toDouble(double a)
{
    int n=sizeof(a);
    unsigned char* p = (unsigned char*)&a;
    while(n--) printf("%02x ",*p++);
    printf("\n");

}

int main()
{
    char s[105];
    while(scanf("%s",&s)!=EOF)
    {
        //s中未搜索到'.'，字符串转换为整数
        if(strchr(s,'.')==0) toInt(atoi(s));
        else toDouble(atof(s));
    }


    return 0;
}

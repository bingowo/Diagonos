#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void solveint(int n);
void solvedouble(double d);

int main() {
    char s[31];
    while (scanf("%s", s) != EOF)//伟大输入法
        if (strchr(s, '.') == 0)
            solveint(atoi(s));
        else
            solvedouble(atof(s));
    return 0;
    //一些伟大函数，atoi指的是将字符型转换成整数，atof指的是将字符型转换成浮点型
    //strchr是指在s中寻找某一个字符，找不到返回0
}
void solveint(int n) {
    int c = sizeof(n);
    unsigned char* p = (unsigned char*)&n;
    while (c--)
        printf("%02x ", *p++);
    printf("\n");
}
void solvedouble(double d){
    int c = sizeof(d);
    unsigned char* p = (unsigned char*)&d;
    while (c--)
        printf("%02x ", *p++);
    printf("\n");
}
//这俩函数还是不明白
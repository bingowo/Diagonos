#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void solveint(int n);
void solvedouble(double d);

int main() {                             //判断读入的字符串类型，送入不同的处理函数
    char s[31];
    while (scanf("%s", s) != EOF)
        if (strchr(s, '.') == 0)        //在字符串中查找某个字符，返回首次出现c的位置的指针,若无返回NULL

            solveint(atoi(s));
                                        //字符串转换：
        else                              // double atof (const char*);
                                          // int atoi (const char*);
            solvedouble(atof(s));
    return 0;
}

void solveint(int n) {
    int c = sizeof(n);
    unsigned char* p = (unsigned char*)&n;  //如果数据要用于显示，那就有区别。
                                            //比如0xFF，在unsigned char用printf打印出来是255，而char是-1
                                            //har能表示的数据范围是-128~127，unsigned char没有符号位，因此能表示的数据范围是0~255
    while (c--)
        printf("%02x ", *p++);            //x 表示以十六进制形式输出；02 表示不足两位，前面补0输出；
    printf("\n");
}

void solvedouble(double d){
    int c = sizeof(d);
    unsigned char* p = (unsigned char*)&d;
    while (c--)
        printf("%02x ", *p++);
    printf("\n");
}